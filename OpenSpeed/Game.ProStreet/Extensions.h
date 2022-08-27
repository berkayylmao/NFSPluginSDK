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

#include <OpenSpeed/Core/MemoryEditor.hpp>  // ValidateMemory

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DamageCopCar.h>  // DamageCopCar, DamageVehicle, IDamageable, IDamageableVehicle
#include <OpenSpeed/Game.ProStreet/Types/DamageRacer.h>   // DamageRacer
#include <OpenSpeed/Game.ProStreet/Types/PVehicle.h>      // PVehicle
#include <OpenSpeed/Game.ProStreet/Types/RBSmackable.h>   // RBSmackable, RigidBody, IRigidBody
#include <OpenSpeed/Game.ProStreet/Types/RBVehicle.h>     // RBVehicle

namespace OpenSpeed::ProStreet {
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
          if (!pvehicle || !MemoryEditor::Get().ValidateMemory(pvehicle)) return nullptr;
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
        RigidBody* operator()(IRigidBody* iRB) const {
          if (!iRB || !MemoryEditor::Get().ValidateMemory(iRB)) return nullptr;
          // Verify cast
          auto* rb    = static_cast<RigidBody*>(iRB);
          auto  vfptr = *reinterpret_cast<std::uintptr_t*>(rb);
          // type: RigidBody
          if (vfptr == 0x9F4ACC) return rb;
          // type: RBSmackable
          if (vfptr == 0x992F24) return rb;
          // type: RBVehicle
          if (vfptr == 0x9F50C4) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static RigidBody* operator|(IRigidBody* iRB, RigidBodyCast_t ext) { return ext(iRB); }

      //                           //
      // Verified RBSmackable cast //
      //                           //

      struct RBSmackableCast_t {
        RBSmackable* operator()(IRigidBody* iRB) const {
          if (!iRB || !MemoryEditor::Get().ValidateMemory(iRB)) return nullptr;
          // Verify cast
          auto* rb = static_cast<RBSmackable*>(iRB);
          if (*reinterpret_cast<std::uintptr_t*>(rb) == 0x992F24) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static RBSmackable* operator|(IRigidBody* iRB, RBSmackableCast_t ext) { return ext(iRB); }

      //                         //
      // Verified RBVehicle cast //
      //                         //

      struct RBVehicleCast_t {
        RBVehicle* operator()(IRigidBody* iRB) const {
          if (!iRB || !MemoryEditor::Get().ValidateMemory(iRB)) return nullptr;
          // Verify cast
          auto* rb    = static_cast<RBVehicle*>(iRB);
          auto  vfptr = *reinterpret_cast<std::uintptr_t*>(rb);
          // type: RBVehicle
          if (vfptr == 0x9F50C4) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static RBVehicle* operator|(IRigidBody* iRB, RBVehicleCast_t ext) { return ext(iRB); }
    }  // namespace details

    // Try-get IRigidBody as RigidBody
    // Usage: RigidBody* myptr = GetRigidBodyPtr() | RigidBodyEx::AsRigidBody;
    static inline const details::RigidBodyCast_t AsRigidBody;

    // Try-get IRigidBody as RBSmackable
    // Usage: RBSmackable* myptr = GetRigidBodyPtr() | RigidBodyEx::RBSmackable;
    static inline const details::RBSmackableCast_t AsRBSmackable;

    // Try-get IRigidBody as RBVehicle
    // Usage: RBVehicle* myptr = GetRigidBodyPtr() | RigidBodyEx::AsRBVehicle;
    static inline const details::RBVehicleCast_t AsRBVehicle;

    // Get a pointer to the player IRigidBody instance
    static IRigidBody* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->GetRigidBody();

      return nullptr;
    }
  }  // namespace RigidBodyEx

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
          if (!iDamageable || !MemoryEditor::Get().ValidateMemory(iDamageable)) return nullptr;
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
          if (!iDamageable || !MemoryEditor::Get().ValidateMemory(iDamageable)) return nullptr;
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
          if (!iDamageable || !MemoryEditor::Get().ValidateMemory(iDamageable)) return nullptr;
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
