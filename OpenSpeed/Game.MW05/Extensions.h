// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/GRaceStatus.h>  // GRaceStatus
#include <OpenSpeed/Game.MW05/Types/IPlayer.h>      // IPlayer
#include <OpenSpeed/Game.MW05/Types/PVehicle.h>     // PVehicle
#include <OpenSpeed/Game.MW05/Types/RBTractor.h>    // RBTractor, RBVehicle, RigidBody, IRigidBody

namespace OpenSpeed::MW05 {
  //          //
  // PVehicle //
  //          //

  namespace PVehicleEx {
    namespace details {
      //                   //
      // Validate PVehicle //
      //                   //

      struct ValidatePVehicle_t {
        PVehicle* operator()(PVehicle* pvehicle) const {
          if (!pvehicle) return nullptr;
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
      auto* _instance = PVehicle::g_mInstances;
      while (auto* pvehicle = ((_instance++)->mInstance | ValidatePVehicle))
        if (pvehicle->IsPlayer() && pvehicle->IsOwnedByPlayer()) return pvehicle;

      return nullptr;
    }

    // Run a function on all PVehicle instances
    static void ForEachInstance(const std::function<void(PVehicle* p)>& fn) {
      auto* _instance = PVehicle::g_mInstances;
      while (auto* pvehicle = ((_instance++)->mInstance | ValidatePVehicle)) fn(pvehicle);
    }

    // Change target PVehicle model
    static bool ChangePVehicleInto(PVehicle* target, Attrib::StringKey vehicleKey,
                                   FECustomizationRecord* customizations,
                                   eVehicleParamFlags     flags = eVehicleParamFlags::SnapToGround |
                                                              eVehicleParamFlags::CalcPerformance,
                                   bool killAfterChange = true) {
      // Validate ptr
      PVehicle* pvehicle = target | ValidatePVehicle;
      if (!pvehicle) return false;

      // if GRaceStatus is not ready, the PVehicle isn't ready either
      auto* race_status = GRaceStatus::Get();
      if (!race_status) return false;

      // Get PVehicle details
      HSIMABLE__*    handle   = pvehicle->GetOwnerHandle();
      IPlayer*       player   = pvehicle->GetPlayer();
      UMath::Vector3 position = pvehicle->GetPosition();
      UMath::Vector3 direction;
      pvehicle->GetRigidBody()->GetOrientation().ExtractZAxis(&direction);
      UMath::Vector3 linear_vel;
      pvehicle->GetLinearVelocity(linear_vel);
      UMath::Vector3 angular_vel;
      pvehicle->GetAngularVelocity(angular_vel);

      // Create new PVehicle
      auto* new_pvehicle =
          PVehicle::Construct(VehicleParams(pvehicle->GetDriverClass(), vehicleKey, direction, position, customizations,
                                            flags, static_cast<IVehicleCache*>(race_status)));
      if (!new_pvehicle) return false;

      // Pass on details
      new_pvehicle->Attach(player);
      new_pvehicle->GetRigidBody()->SetLinearVelocity(linear_vel);
      new_pvehicle->GetRigidBody()->SetAngularVelocity(angular_vel);

      // Change handles if in race (values will sync at the next checkpoint)
      if (race_status->mPlayMode == GRaceStatus::PlayMode::Racing) {
        for (std::int32_t i = 0; i < race_status->mRacerCount; i++) {
          auto& racer_handle = race_status->mRacerInfo[i].mhSimable;
          if (racer_handle == handle) {
            racer_handle = new_pvehicle->GetOwnerHandle();
            break;
          }
        }
      }

      // Get rid of old PVehicle
      pvehicle->Detach(player);
      if (killAfterChange) pvehicle->Kill();
    }
  }  // namespace PVehicleEx

  //            //
  // IRigidBody //
  //            //

  namespace RigidBodyEx {
    namespace details {
      //                         //
      // Verified RigidBody cast //
      //                         //

      struct RigidBodyCast_t {
        RigidBody* operator()(IRigidBody* irb) const {
          if (!irb) return nullptr;
          // Verify cast
          auto* rb = static_cast<RigidBody*>(irb);
          if (*reinterpret_cast<std::uintptr_t*>(rb) == static_cast<std::uintptr_t>(0x8AC448)) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static RigidBody* operator|(IRigidBody* rb, RigidBodyCast_t ext) { return ext(rb); }

      //                         //
      // Verified RBVehicle cast //
      //                         //

      struct RBVehicleCast_t {
        RBVehicle* operator()(IRigidBody* irb) const {
          if (!irb) return nullptr;
          // Verify cast
          auto* rb = static_cast<RBVehicle*>(irb);
          if (*reinterpret_cast<std::uintptr_t*>(rb) == static_cast<std::uintptr_t>(0x8AC938)) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static RBVehicle* operator|(IRigidBody* rb, RBVehicleCast_t ext) { return ext(rb); }

      //                         //
      // Verified RBTractor cast //
      //                         //

      struct RBTractorCast_t {
        RBTractor* operator()(IRigidBody* irb) const {
          if (!irb) return nullptr;
          // Verify cast
          auto* rb = static_cast<RBTractor*>(irb);
          if (*reinterpret_cast<std::uintptr_t*>(rb) == static_cast<std::uintptr_t>(0x8ACBA8)) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static RBTractor* operator|(IRigidBody* rb, RBTractorCast_t ext) { return ext(rb); }
    }  // namespace details

    // Try-get IRigidBody as RigidBody
    // Usage: RigidBody* myptr = GetRigidBodyPtr() | RigidBodyEx::AsRigidBody;
    static inline const details::RigidBodyCast_t AsRigidBody;

    // Try-get IRigidBody as RBVehicle
    // Usage: RigidBody* myptr = GetRigidBodyPtr() | RigidBodyEx::AsRBVehicle;
    static inline const details::RBVehicleCast_t AsRBVehicle;

    // Try-get IRigidBody as RBTractor
    // Usage: RigidBody* myptr = GetRigidBodyPtr() | RigidBodyEx::AsRBTractor;
    static inline const details::RBTractorCast_t AsRBTractor;

    // Get a pointer to the player IRigidBody instance
    static IRigidBody* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->GetRigidBody();

      return nullptr;
    }
  }  // namespace RigidBodyEx
}  // namespace OpenSpeed::MW05
