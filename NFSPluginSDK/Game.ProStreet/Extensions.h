// clang-format off
//
//    BSD 3-Clause License
//    Copyright (c) 2022, Berkay Yigit (berkayylmao) <mail@berkay.link>
//    All rights reserved.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    You should have received a copy of the BSD 3-Clause License along with
//    this program. If not, see <https://opensource.org/licenses/BSD-3-Clause/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_PROSTREET_EXTENSIONS_H
#define NFSPLUGINSDK_GAME_PROSTREET_EXTENSIONS_H
#pragma once

#include <functional>  // std::function

#include <NFSPluginSDK/Core/MemoryEditor.hpp>  // ValidateMemory

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DamageCopCar.h>  // DamageCopCar, DamageVehicle, IDamageable, IDamageableVehicle
#include <NFSPluginSDK/Game.ProStreet/Types/DamageRacer.h>   // DamageRacer
#include <NFSPluginSDK/Game.ProStreet/Types/FEngHud.h>       // FEngHud, IHud
#include <NFSPluginSDK/Game.ProStreet/Types/PVehicle.h>      // PVehicle
#include <NFSPluginSDK/Game.ProStreet/Types/RBSmackable.h>   // RBSmackable, RigidBody, IRigidBody
#include <NFSPluginSDK/Game.ProStreet/Types/RBVehicle.h>     // RBVehicle

namespace NFSPluginSDK::ProStreet {
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

  //             //
  // IDamageable //
  //             //

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

  //      //
  // IHud //
  //      //

  namespace HudEx {
    namespace details {
      //                       //
      // Verified FEngHud cast //
      //                       //

      struct FEngHudCast_t {
        FEngHud* operator()(IHud* iHud) const {
          if (!iHud || !MemoryEditor::Get().ValidateMemory(iHud)) return nullptr;
          // Verify cast
          auto* hud   = static_cast<FEngHud*>(iHud);
          auto  vfptr = *reinterpret_cast<std::uintptr_t*>(hud);
          // type: FEngHud
          if (vfptr == 0x97F7D4) return hud;
          // Bad cast
          return nullptr;
        }
      };
      static FEngHud* operator|(IHud* i, FEngHudCast_t ext) { return ext(i); }
    }  // namespace details

    // Try-get IHud as FEngHud
    // Usage: FEngHud* myptr = GetHudPtr() | HudEx::AsFEngHud;
    static inline const details::FEngHudCast_t AsFEngHud;

    // Get a pointer to the player IHud instance
    static IHud* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle && pvehicle->mPlayer) return pvehicle->mPlayer->GetHud();

      return nullptr;
    }
  }  // namespace HudEx
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_EXTENSIONS_H
