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

#ifndef NFSPLUGINSDK_GAME_MW05_EXTENSIONS_H
#define NFSPLUGINSDK_GAME_MW05_EXTENSIONS_H
#pragma once

#include <functional>  // std::function

#include <NFSPluginSDK/Core/MemoryEditor.hpp>  // ValidateMemory

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleCopCar.h>  // AIVehicleCopCar, AIVehiclePursuit, AIVehiclePid, AIVehicle
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleEmpty.h>   // AIVehicleEmpty
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleHelicopter.h>  // AIVehicleHelicopter
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleHuman.h>       // AIVehicleHuman, AIVehicleRacecar
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleTraffic.h>     // AIVehicleTraffic
#include <NFSPluginSDK/Game.MW05/Types/DamageCopCar.h>     // DamageCopCar, DamageVehicle, IDamageable, IDamageableVehicle
#include <NFSPluginSDK/Game.MW05/Types/DamageDragster.h>   // DamageDragster, DamageRacer, ISpikeable
#include <NFSPluginSDK/Game.MW05/Types/DamageHeli.h>       // DamageHeli
#include <NFSPluginSDK/Game.MW05/Types/GRaceStatus.h>      // GRaceStatus
#include <NFSPluginSDK/Game.MW05/Types/InputPlayer.h>      // InputPlayer, PInput, IInput
#include <NFSPluginSDK/Game.MW05/Types/LocalPlayer.h>      // LocalPlayer, IPlayer
#include <NFSPluginSDK/Game.MW05/Types/PVehicle.h>         // PVehicle
#include <NFSPluginSDK/Game.MW05/Types/RBSmackable.h>      // RBSmackable, RigidBody, IRigidBody
#include <NFSPluginSDK/Game.MW05/Types/RBTractor.h>        // RBTractor, RBVehicle
#include <NFSPluginSDK/Game.MW05/Types/SimpleRigidBody.h>  // SimpleRigidBody, ISimpleBody

namespace NFSPluginSDK::MW05 {
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
    static details::ChangedPVehicleInfo ChangePVehicleInto(
        PVehicle* target, std::uint32_t vehicleKey, FECustomizationRecord* customizations,
        eVehicleParamFlags flags           = eVehicleParamFlags::SnapToGround | eVehicleParamFlags::CalcPerformance,
        bool               killAfterChange = true) {
      details::ChangedPVehicleInfo ret;

      // Validate ptr
      PVehicle* pvehicle = target | ValidatePVehicle;
      if (!pvehicle) return ret;

      // if GRaceStatus is not ready, the PVehicle isn't ready either
      auto* race_status = GRaceStatus::Get();
      if (!race_status) return ret;

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
      if (!new_pvehicle) return ret;

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

      ret.WasSuccessful  = true;
      ret.NewPVehiclePtr = new_pvehicle;
      return ret;
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
          if (vfptr == 0x8AC448) return rb;
          // type: RBSmackable
          if (vfptr == 0x8AA6D0) return rb;
          // type: RBVehicle
          if (vfptr == 0x8AC938) return rb;
          // type: RBTractor
          if (vfptr == 0x8ACBA8) return rb;
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
          if (*reinterpret_cast<std::uintptr_t*>(rb) == 0x8AA6D0) return rb;
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
          if (vfptr == 0x8AC938) return rb;
          // type: RBTractor
          if (vfptr == 0x8ACBA8) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static RBVehicle* operator|(IRigidBody* iRB, RBVehicleCast_t ext) { return ext(iRB); }

      //                         //
      // Verified RBTractor cast //
      //                         //

      struct RBTractorCast_t {
        RBTractor* operator()(IRigidBody* iRB) const {
          if (!iRB || !MemoryEditor::Get().ValidateMemory(iRB)) return nullptr;
          // Verify cast
          auto* rb = static_cast<RBTractor*>(iRB);
          if (*reinterpret_cast<std::uintptr_t*>(rb) == 0x8ACBA8) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static RBTractor* operator|(IRigidBody* iRB, RBTractorCast_t ext) { return ext(iRB); }

      //                               //
      // Verified SimpleRigidBody cast //
      //                               //

      struct SimpleRigidBodyCast_t {
        SimpleRigidBody* operator()(IRigidBody* iRB) const {
          if (!iRB || !MemoryEditor::Get().ValidateMemory(iRB)) return nullptr;
          // Verify cast
          auto* rb = static_cast<SimpleRigidBody*>(iRB);
          if (*reinterpret_cast<std::uintptr_t*>(rb) == 0x8AC5FC) return rb;
          // Bad cast
          return nullptr;
        }
      };
      static SimpleRigidBody* operator|(IRigidBody* iRB, SimpleRigidBodyCast_t ext) { return ext(iRB); }
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

    // Try-get IRigidBody as RBTractor
    // Usage: RBTractor* myptr = GetRigidBodyPtr() | RigidBodyEx::AsRBTractor;
    static inline const details::RBTractorCast_t AsRBTractor;

    // Try-get IRigidBody as SimpleRigidBody
    // Usage: SimpleRigidBody* myptr = GetRigidBodyPtr() | RigidBodyEx::AsSimpleRigidBody;
    static inline const details::SimpleRigidBodyCast_t AsSimpleRigidBody;

    // Get a pointer to the player IRigidBody instance
    static IRigidBody* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->GetRigidBody();

      return nullptr;
    }

    // Run a function on all RigidBody::Volatile instances
    static void ForEachInstance(const std::function<void(RigidBody::Volatile* p)>& fn) {
      auto* _instance = RigidBody::Volatile::g_mInstances;
      while (auto* volatileData = *(_instance++))
        if (MemoryEditor::Get().ValidateMemory(volatileData)) fn(volatileData);
    }
  }  // namespace RigidBodyEx

  //             //
  // ISimpleBody //
  //             //

  namespace SimpleBodyEx {
    namespace details {

      //                               //
      // Verified SimpleRigidBody cast //
      //                               //

      struct SimpleRigidBodyCast_t {
        SimpleRigidBody* operator()(ISimpleBody* iSRB) const {
          if (!iSRB || !MemoryEditor::Get().ValidateMemory(iSRB)) return nullptr;
          // Verify cast
          auto* srb = static_cast<SimpleRigidBody*>(iSRB);
          if (*reinterpret_cast<std::uintptr_t*>(srb) == 0x8AC5FC) return srb;
          // Bad cast
          return nullptr;
        }
      };
      static SimpleRigidBody* operator|(ISimpleBody* iSRB, SimpleRigidBodyCast_t ext) { return ext(iSRB); }
    }  // namespace details

    // Try-get ISimpleBody as SimpleRigidBody
    // Usage: SimpleRigidBody* myptr = GetSimpleBodyPtr() | SimpleBodyEx::AsSimpleRigidBody;
    static inline const details::SimpleRigidBodyCast_t AsSimpleRigidBody;

    // Run a function on all SimpleRigidBody::Volatile instances
    static void ForEachInstance(const std::function<void(SimpleRigidBody::Volatile* p)>& fn) {
      auto* _instance = SimpleRigidBody::Volatile::g_mInstances;
      while (auto* volatileData = *(_instance++))
        if (MemoryEditor::Get().ValidateMemory(volatileData)) fn(volatileData);
    }
  }  // namespace SimpleBodyEx

  //        //
  // IInput //
  //        //

  namespace InputEx {
    namespace details {
      //                      //
      // Verified PInput cast //
      //                      //

      struct PInputCast_t {
        PInput* operator()(IInput* iInput) const {
          if (!iInput || !MemoryEditor::Get().ValidateMemory(iInput)) return nullptr;
          // Verify cast
          auto* pi = static_cast<PInput*>(iInput);
          if (*reinterpret_cast<std::uintptr_t*>(pi) == 0x8AB598) return pi;
          // Bad cast
          return nullptr;
        }
      };
      static PInput* operator|(IInput* iInput, PInputCast_t ext) { return ext(iInput); }

      //                           //
      // Verified InputPlayer cast //
      //                           //

      struct InputPlayerCast_t {
        InputPlayer* operator()(IInput* iInput) const {
          if (!iInput || !MemoryEditor::Get().ValidateMemory(iInput)) return nullptr;
          // Verify cast
          auto* ip = static_cast<InputPlayer*>(iInput);
          if (*reinterpret_cast<std::uintptr_t*>(ip) == 0x8AC6BC) return ip;
          // Bad cast
          return nullptr;
        }
      };
      static InputPlayer* operator|(IInput* iInput, InputPlayerCast_t ext) { return ext(iInput); }
    }  // namespace details

    // Try-get IInput as PInput
    // Usage: PInput* myptr = GetInputPtr() | InputEx::AsPInput;
    static inline const details::PInputCast_t AsPInput;

    // Try-get IInput as InputPlayer
    // Usage: InputPlayer* myptr = GetInputPtr() | InputEx::AsInputPlayer;
    static inline const details::InputPlayerCast_t AsInputPlayer;

    // Get a pointer to the player IInput instance
    static IInput* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->mInput;

      return nullptr;
    }
  }  // namespace InputEx

  //            //
  // IVehicleAI //
  //            //

  namespace AIVehicleEx {
    namespace details {
      //                         //
      // Verified AIVehicle cast //
      //                         //

      struct AIVehicleCast_t {
        AIVehicle* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicle*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x891A80) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehicle* operator|(IVehicleAI* i, AIVehicleCast_t ext) { return ext(i); }

      //                               //
      // Verified AIVehicleCopCar cast //
      //                               //

      struct AIVehicleCopCarCast_t {
        AIVehicleCopCar* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleCopCar*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x892560) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehicleCopCar* operator|(IVehicleAI* i, AIVehicleCopCarCast_t ext) { return ext(i); }

      //                              //
      // Verified AIVehicleEmpty cast //
      //                              //

      struct AIVehicleEmptyCast_t {
        AIVehicleEmpty* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleEmpty*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x892E28) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehicleEmpty* operator|(IVehicleAI* iAI, AIVehicleEmptyCast_t ext) { return ext(iAI); }

      //                                   //
      // Verified AIVehicleHelicopter cast //
      //                                   //

      struct AIVehicleHelicopterCast_t {
        AIVehicleHelicopter* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleHelicopter*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x8920D8) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehicleHelicopter* operator|(IVehicleAI* i, AIVehicleHelicopterCast_t ext) { return ext(i); }

      //                              //
      // Verified AIVehicleHuman cast //
      //                              //

      struct AIVehicleHumanCast_t {
        AIVehicleHuman* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleHuman*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x892AD0) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehicleHuman* operator|(IVehicleAI* i, AIVehicleHumanCast_t ext) { return ext(i); }

      //                            //
      // Verified AIVehiclePid cast //
      //                            //

      struct AIVehiclePidCast_t {
        AIVehiclePid* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehiclePid*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x891BB8) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehiclePid* operator|(IVehicleAI* i, AIVehiclePidCast_t ext) { return ext(i); }

      //                                //
      // Verified AIVehiclePursuit cast //
      //                                //

      struct AIVehiclePursuitCast_t {
        AIVehiclePursuit* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehiclePursuit*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x891EC0) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehiclePursuit* operator|(IVehicleAI* i, AIVehiclePursuitCast_t ext) { return ext(i); }

      //                                //
      // Verified AIVehicleRacecar cast //
      //                                //

      struct AIVehicleRacecarCast_t {
        AIVehicleRacecar* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleRacecar*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x892720) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehicleRacecar* operator|(IVehicleAI* i, AIVehicleRacecarCast_t ext) { return ext(i); }

      //                                //
      // Verified AIVehicleTraffic cast //
      //                                //

      struct AIVehicleTrafficCast_t {
        AIVehicleTraffic* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleTraffic*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x891CF8) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehicleTraffic* operator|(IVehicleAI* i, AIVehicleTrafficCast_t ext) { return ext(i); }
    }  // namespace details

    // Try-get IVehicleAI as AIVehicle
    // Usage: AIVehicle* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicle;
    static inline const details::AIVehicleCast_t AsAIVehicle;

    // Try-get IVehicleAI as AIVehicleCopCar
    // Usage: AIVehicleCopCar* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleCopCar;
    static inline const details::AIVehicleCopCarCast_t AsAIVehicleCopCar;

    // Try-get IVehicleAI as AIVehicleEmpty
    // Usage: AIVehicleEmpty* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleEmpty;
    static inline const details::AIVehicleEmptyCast_t AsAIVehicleEmpty;

    // Try-get IVehicleAI as AIVehicleHelicopter
    // Usage: AIVehicleHelicopter* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleHelicopter;
    static inline const details::AIVehicleHelicopterCast_t AsAIVehicleHelicopter;

    // Try-get IVehicleAI as AIVehicleHuman
    // Usage: AIVehicleHuman* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleHuman;
    static inline const details::AIVehicleHumanCast_t AsAIVehicleHuman;

    // Try-get IVehicleAI as AIVehiclePid
    // Usage: AIVehiclePid* myptr = GetAIPtr() | AIVehicleEx::AsAIVehiclePid;
    static inline const details::AIVehiclePidCast_t AsAIVehiclePid;

    // Try-get IVehicleAI as AIVehiclePursuit
    // Usage: AIVehiclePursuit* myptr = GetAIPtr() | AIVehicleEx::AsAIVehiclePursuit;
    static inline const details::AIVehiclePursuitCast_t AsAIVehiclePursuit;

    // Try-get IVehicleAI as AIVehicleRaceCar
    // Usage: AIVehicleRaceCar* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleRaceCar;
    static inline const details::AIVehicleRacecarCast_t AsAIVehicleRacecar;

    // Try-get IVehicleAI as AIVehicleTraffic
    // Usage: AIVehicleTraffic* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleTraffic;
    static inline const details::AIVehicleTrafficCast_t AsAIVehicleTraffic;

    // Get a pointer to the player IVehicleAI instance
    static IVehicleAI* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->GetAIVehiclePtr();

      return nullptr;
    }
  }  // namespace AIVehicleEx

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
          if (vfptr == 0x8AD2CC) return damageable;
          // type: DamageCopCar
          if (vfptr == 0x8AD438) return damageable;
          // type: DamageHeli
          if (vfptr == 0x8AD3C4) return damageable;
          // type: DamageRacer
          if (vfptr == 0x8AD350) return damageable;
          // type: DamageDragster
          if (vfptr == 0x8AD6AC) return damageable;
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
          if (*reinterpret_cast<std::uintptr_t*>(damageable) == 0x8AD438) return damageable;
          // Bad cast
          return nullptr;
        }
      };
      static DamageCopCar* operator|(IDamageable* i, DamageCopCarCast_t ext) { return ext(i); }

      //                          //
      // Verified DamageHeli cast //
      //                          //

      struct DamageHeliCast_t {
        DamageHeli* operator()(IDamageable* iDamageable) const {
          if (!iDamageable || !MemoryEditor::Get().ValidateMemory(iDamageable)) return nullptr;
          // Verify cast
          auto* damageable = static_cast<DamageHeli*>(iDamageable);
          if (*reinterpret_cast<std::uintptr_t*>(damageable) == 0x8AD3C4) return damageable;
          // Bad cast
          return nullptr;
        }
      };
      static DamageHeli* operator|(IDamageable* i, DamageHeliCast_t ext) { return ext(i); }

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
          if (vfptr == 0x8AD350) return damageable;
          // type: DamageDragster
          if (vfptr == 0x8AD6AC) return damageable;
          // Bad cast
          return nullptr;
        }
      };
      static DamageRacer* operator|(IDamageable* i, DamageRacerCast_t ext) { return ext(i); }

      //                              //
      // Verified DamageDragster cast //
      //                              //

      struct DamageDragsterCast_t {
        DamageDragster* operator()(IDamageable* iDamageable) const {
          if (!iDamageable || !MemoryEditor::Get().ValidateMemory(iDamageable)) return nullptr;
          // Verify cast
          auto* damageable = static_cast<DamageDragster*>(iDamageable);
          if (*reinterpret_cast<std::uintptr_t*>(damageable) == 0x8AD6AC) return damageable;
          // Bad cast
          return nullptr;
        }
      };
      static DamageDragster* operator|(IDamageable* i, DamageDragsterCast_t ext) { return ext(i); }
    }  // namespace details

    // Try-get IDamageable as DamageVehicle
    // Usage: DamageVehicle* myptr = GetDamagePtr() | DamageableEx::AsDamageVehicle;
    static inline const details::DamageVehicleCast_t AsDamageVehicle;

    // Try-get IDamageable as DamageCopCar
    // Usage: DamageCopCar* myptr = GetDamagePtr() | DamageableEx::AsDamageCopCar;
    static inline const details::DamageCopCarCast_t AsDamageCopCar;

    // Try-get IDamageable as DamageHeli
    // Usage: DamageHeli* myptr = GetDamagePtr() | DamageableEx::AsDamageHeli;
    static inline const details::DamageHeliCast_t AsDamageHeli;

    // Try-get IDamageable as DamageRacer
    // Usage: DamageRacer* myptr = GetDamagePtr() | DamageableEx::AsDamageRacer;
    static inline const details::DamageRacerCast_t AsDamageRacer;

    // Try-get IDamageable as DamageDragster
    // Usage: DamageDragster* myptr = GetDamagePtr() | DamageableEx::AsDamageDragster;
    static inline const details::DamageDragsterCast_t AsDamageDragster;

    // Get a pointer to the player IDamageable instance
    static IDamageable* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->mDamage;

      return nullptr;
    }
  }  // namespace DamageableEx

  //            //
  // IPlayer //
  //            //

  namespace PlayerEx {
    namespace details {
      //                  //
      // Validate IPlayer //
      //                  //

      struct ValidatePlayer_t {
        IPlayer* operator()(IPlayer* player) const {
          if (!player || !MemoryEditor::Get().ValidateMemory(player)) return nullptr;
          // LocalPlayer
          if (*reinterpret_cast<std::uintptr_t*>(player) == 0x8B0B10) return player;
          // Bad ptr
          return nullptr;
        }
      };
      static IPlayer* operator|(IPlayer* player, ValidatePlayer_t ext) { return ext(player); }

      //                           //
      // Verified LocalPlayer cast //
      //                           //

      struct LocalPlayerCast_t {
        LocalPlayer* operator()(IPlayer* player) const {
          if (!player || !MemoryEditor::Get().ValidateMemory(player)) return nullptr;
          // Verify cast
          auto* local_player = static_cast<LocalPlayer*>(player);
          // LocalPlayer
          if (*reinterpret_cast<std::uintptr_t*>(local_player) == 0x8B0BB0) return local_player;
          // Bad cast
          return nullptr;
        }
      };
      static LocalPlayer* operator|(IPlayer* i, LocalPlayerCast_t ext) { return ext(i); }
    }  // namespace details

    // Validate IPlayer pointer
    // Usage: IPlayer* myptr = GetPlayerPtr() | PlayerEx::ValidateIPlayer;
    static inline const details::ValidatePlayer_t ValidatePlayer;

    // Try-get IPlayer as LocalPlayer
    // Usage: LocalPlayer* myptr = GetPlayerPtr() | PlayerEx::AsLocalPlayer;
    static inline const details::LocalPlayerCast_t AsLocalPlayer;

    // Get a pointer to the player IPlayer instance
    static IPlayer* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->mPlayer | ValidatePlayer;

      return nullptr;
    }
  }  // namespace PlayerEx

}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_EXTENSIONS_H
