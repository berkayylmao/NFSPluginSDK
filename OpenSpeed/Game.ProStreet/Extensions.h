// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <mail@berkay.link>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <functional>  // std::function

#include <OpenSpeed/Core/MemoryEditor/MemoryEditor.hpp>  // ValidateMemoryIsInitialized

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DamageCopCar.h>  // DamageCopCar, DamageVehicle, IDamageable, IDamageableVehicle
#include <OpenSpeed/Game.ProStreet/Types/DamageRacer.h>   // DamageRacer
#include <OpenSpeed/Game.ProStreet/Types/GRaceStatus.h>   // GRaceStatus
#include <OpenSpeed/Game.ProStreet/Types/IPlayer.h>       // IPlayer
#include <OpenSpeed/Game.ProStreet/Types/IRigidBody.h>    // IRigidBody
#include <OpenSpeed/Game.ProStreet/Types/PVehicle.h>      // PVehicle
#include <OpenSpeed/Game.ProStreet/Types/RideInfo.h>      // RideInfo

namespace OpenSpeed::ProStreet {
  //          //
  // PVehicle //
  //          //

  namespace PVehicleEx {
    namespace details {
      //                  //
      // Internal structs //
      //                  //

      struct ChangedPVehicleInfo {
        // Whether the change attempt was successful
        bool WasSuccessful;
        // The new PVehicle pointer, if the change was successful
        PVehicle* NewPVehiclePtr;

        ChangedPVehicleInfo() : WasSuccessful(false), NewPVehiclePtr(nullptr) {}
      };

      //                   //
      // Validate PVehicle //
      //                   //

      struct ValidatePVehicle_t {
        PVehicle* operator()(PVehicle* pvehicle) const {
          if (!pvehicle || !MemoryEditor::Get().ValidateMemoryIsInitialized(pvehicle)) return nullptr;
          // Validate ptr
          if (pvehicle->mObjType != SimableType::Invalid && pvehicle->mDirty == false &&
              pvehicle->mRigidBody != nullptr)
            return pvehicle;
          // Bad ptr
          return nullptr;
        }
      };
      static PVehicle* operator|(PVehicle* pvehicle, ValidatePVehicle_t ext) { return ext(pvehicle); }
    }  // namespace details

    // Validate PVehicle pointer
    // Usage: PVehicle* myptr = GetPVehiclePtr() | PVehicleEx::ValidatePVehicle;
    static inline const details::ValidatePVehicle_t ValidatePVehicle;

    // Get a pointer to the player PVehicle instance
    static PVehicle* GetPlayerInstance() {
      auto** pInstance = PVehicle::g_mInstances;
      if (!pInstance) return nullptr;

      auto* instance = *pInstance;
      while (instance != reinterpret_cast<bTNode<PVehicle>*>(pInstance)) {
        if (auto* pvehicle = static_cast<PVehicle*>(instance) | ValidatePVehicle) {
          if (pvehicle->IsPlayer() && pvehicle->IsOwnedByPlayer()) return pvehicle;
        }
        instance = instance->GetNext();
      }
      return nullptr;
    }

    // Run a function on all PVehicle instances
    static void ForEachInstance(const std::function<void(PVehicle* p)>& fn) {
      auto** pInstance = PVehicle::g_mInstances;
      if (!pInstance) return;

      auto* instance = *pInstance;
      while (instance != reinterpret_cast<bTNode<PVehicle>*>(pInstance)) {
        if (auto* pvehicle = static_cast<PVehicle*>(instance) | ValidatePVehicle) fn(pvehicle);
        instance = instance->GetNext();
      }
    }

    // Change target PVehicle model
    static details::ChangedPVehicleInfo ChangePVehicleInto(
        PVehicle* target, const Attrib::Gen::pvehicle& instance, RideInfo* rideInfo,
        eVehicleParamFlags flags           = eVehicleParamFlags::SnapToGround | eVehicleParamFlags::ComputePerformance,
        bool               killAfterChange = false) {
      details::ChangedPVehicleInfo ret;
      if (!instance.mCollection) return ret;

      // if GRaceStatus is not ready, the PVehicle isn't ready either
      auto* race_status = GRaceStatus::Get();
      if (!race_status) return ret;

      // Validate ptr
      PVehicle* pvehicle = target | ValidatePVehicle;
      if (!pvehicle) return ret;

      // Get PVehicle details
      HSIMABLE__*    handle   = pvehicle->GetOwnerHandle();
      IPlayer*       player   = pvehicle->GetPlayer();
      UMath::Vector3 position = pvehicle->GetPosition();
      UMath::Vector3 direction;
      pvehicle->GetRigidBody()->GetForwardVector(direction);
      UMath::Vector3 linear_vel;
      pvehicle->GetLinearVelocity(linear_vel);
      UMath::Vector3 angular_vel;
      pvehicle->GetAngularVelocity(angular_vel);

      // Create new PVehicle
      auto* new_pvehicle = PVehicle::Construct(
          VehicleParams(pvehicle->GetDriverClass(), instance, direction, position, rideInfo, flags, race_status));
      if (!new_pvehicle) return ret;

      // Pass on details
      new_pvehicle->Attach(player);
      new_pvehicle->GetRigidBody()->SetLinearVelocity(linear_vel);
      new_pvehicle->GetRigidBody()->SetAngularVelocity(angular_vel);

      // Get rid of old PVehicle
      pvehicle->Detach(player);
      if (killAfterChange) {
        if (race_status->mRacerCount > 0)
          pvehicle->Deactivate();
        else
          pvehicle->Kill();
      }

      ret.WasSuccessful  = true;
      ret.NewPVehiclePtr = new_pvehicle;
      return ret;
    }
    static details::ChangedPVehicleInfo ChangePVehicleInto(
        PVehicle* target, Attrib::StringKey vehicleKey, RideInfo* rideInfo,
        eVehicleParamFlags flags           = eVehicleParamFlags::SnapToGround | eVehicleParamFlags::ComputePerformance,
        bool               killAfterChange = false) {
      return ChangePVehicleInto(target, Attrib::Gen::pvehicle::TryGetInstance(vehicleKey), rideInfo, flags,
                                killAfterChange);
    }
  }  // namespace PVehicleEx

  //            //
  // IDamageable //
  //            //

  namespace DamageableEx {
    namespace details {
      //                             //
      // Verified DamageVehicle cast //
      //                             //

      struct DamageVehicleCast_t {
        DamageVehicle* operator()(IDamageable* iDamageable) const {
          if (!iDamageable || !MemoryEditor::Get().ValidateMemoryIsInitialized(iDamageable)) return nullptr;
          // Verify cast
          auto* damageable = static_cast<DamageVehicle*>(iDamageable);
          auto  vfptr      = *reinterpret_cast<std::uintptr_t*>(damageable);
          // type: DamageVehicle
          if (vfptr == 0x9F5EA0) return damageable;
          // type: DamageCopCar
          if (vfptr == 0x9F6330) return damageable;
          // type: DamageRacer
          if (vfptr == 0x9F6214) return damageable;
          // Bad cast
          return nullptr;
        }
      };
      static DamageVehicle* operator|(IDamageable* i, DamageVehicleCast_t ext) { return ext(i); }

      //                            //
      // Verified DamageCopCar cast //
      //                            //

      struct DamageCopCarCast_t {
        DamageCopCar* operator()(IDamageable* iDamageable) const {
          if (!iDamageable || !MemoryEditor::Get().ValidateMemoryIsInitialized(iDamageable)) return nullptr;
          // Verify cast
          auto* damageable = static_cast<DamageCopCar*>(iDamageable);
          if (*reinterpret_cast<std::uintptr_t*>(damageable) == 0x9F6330) return damageable;
          // Bad cast
          return nullptr;
        }
      };
      static DamageCopCar* operator|(IDamageable* i, DamageCopCarCast_t ext) { return ext(i); }

      //                           //
      // Verified DamageRacer cast //
      //                           //

      struct DamageRacerCast_t {
        DamageRacer* operator()(IDamageable* iDamageable) const {
          if (!iDamageable || !MemoryEditor::Get().ValidateMemoryIsInitialized(iDamageable)) return nullptr;
          // Verify cast
          auto* damageable = static_cast<DamageRacer*>(iDamageable);
          auto  vfptr      = *reinterpret_cast<std::uintptr_t*>(damageable);
          // type: DamageRacer
          if (vfptr == 0x9F6214) return damageable;
          // Bad cast
          return nullptr;
        }
      };
      static DamageRacer* operator|(IDamageable* i, DamageRacerCast_t ext) { return ext(i); }
    }  // namespace details

    // Try-get IDamageable as DamageVehicle
    // Usage: DamageVehicle* myptr = GetDamagePtr() | DamageableEx::AsDamageVehicle;
    static inline const details::DamageVehicleCast_t AsDamageVehicle;

    // Try-get IDamageable as DamageCopCar
    // Usage: DamageCopCar* myptr = GetDamagePtr() | DamageableEx::AsDamageCopCar;
    static inline const details::DamageCopCarCast_t AsDamageCopCar;

    // Try-get IDamageable as DamageRacer
    // Usage: DamageRacer* myptr = GetDamagePtr() | DamageableEx::AsDamageRacer;
    static inline const details::DamageRacerCast_t AsDamageRacer;

    // Get a pointer to the player IDamageable instance
    static IDamageable* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->mDamage;

      return nullptr;
    }
  }  // namespace DamageableEx
}  // namespace OpenSpeed::ProStreet
