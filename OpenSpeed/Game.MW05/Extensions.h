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

#include <OpenSpeed/Core/MemoryEditor/MemoryEditor.hpp>  // ValidateMemoryIsInitialized

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/AIVehicleCopCar.h>  // AIVehicleCopCar, AIVehiclePursuit, AIVehiclePid, AIVehicle
#include <OpenSpeed/Game.MW05/Types/AIVehicleEmpty.h>   // AIVehicleEmpty
#include <OpenSpeed/Game.MW05/Types/AIVehicleHelicopter.h>  // AIVehicleHelicopter
#include <OpenSpeed/Game.MW05/Types/AIVehicleHuman.h>       // AIVehicleHuman, AIVehicleRacecar
#include <OpenSpeed/Game.MW05/Types/AIVehicleTraffic.h>     // AIVehicleTraffic
#include <OpenSpeed/Game.MW05/Types/GRaceStatus.h>          // GRaceStatus
#include <OpenSpeed/Game.MW05/Types/InputPlayer.h>          // InputPlayer, PInput, IInput
#include <OpenSpeed/Game.MW05/Types/IPlayer.h>              // IPlayer
#include <OpenSpeed/Game.MW05/Types/PVehicle.h>             // PVehicle
#include <OpenSpeed/Game.MW05/Types/RBSmackable.h>          // RBSmackable, RigidBody, IRigidBody
#include <OpenSpeed/Game.MW05/Types/RBTractor.h>            // RBTractor, RBVehicle
#include <OpenSpeed/Game.MW05/Types/SimpleRigidBody.h>      // SimpleRigidBody, ISimpleBody

namespace OpenSpeed::MW05 {
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
        PVehicle* target, Attrib::StringKey vehicleKey, FECustomizationRecord* customizations,
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
          if (!iRB || !MemoryEditor::Get().ValidateMemoryIsInitialized(iRB)) return nullptr;
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
          if (!iRB || !MemoryEditor::Get().ValidateMemoryIsInitialized(iRB)) return nullptr;
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
          if (!iRB || !MemoryEditor::Get().ValidateMemoryIsInitialized(iRB)) return nullptr;
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
          if (!iRB || !MemoryEditor::Get().ValidateMemoryIsInitialized(iRB)) return nullptr;
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
          if (!iRB || !MemoryEditor::Get().ValidateMemoryIsInitialized(iRB)) return nullptr;
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
        if (MemoryEditor::Get().ValidateMemoryIsInitialized(volatileData)) fn(volatileData);
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
          if (!iSRB || !MemoryEditor::Get().ValidateMemoryIsInitialized(iSRB)) return nullptr;
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
        if (MemoryEditor::Get().ValidateMemoryIsInitialized(volatileData)) fn(volatileData);
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
          if (!iInput || !MemoryEditor::Get().ValidateMemoryIsInitialized(iInput)) return nullptr;
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
          if (!iInput || !MemoryEditor::Get().ValidateMemoryIsInitialized(iInput)) return nullptr;
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

    // Get a pointer to the player IRigidBody instance
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
          if (!iAI || !MemoryEditor::Get().ValidateMemoryIsInitialized(iAI)) return nullptr;
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
          if (!iAI || !MemoryEditor::Get().ValidateMemoryIsInitialized(iAI)) return nullptr;
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
          if (!iAI || !MemoryEditor::Get().ValidateMemoryIsInitialized(iAI)) return nullptr;
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
          if (!iAI || !MemoryEditor::Get().ValidateMemoryIsInitialized(iAI)) return nullptr;
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
          if (!iAI || !MemoryEditor::Get().ValidateMemoryIsInitialized(iAI)) return nullptr;
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
          if (!iAI || !MemoryEditor::Get().ValidateMemoryIsInitialized(iAI)) return nullptr;
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
          if (!iAI || !MemoryEditor::Get().ValidateMemoryIsInitialized(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehiclePursuit*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x891EC0) return ai;
          // Bad cast
          return nullptr;
        }
      };
      static AIVehiclePursuit* operator|(IVehicleAI* i, AIVehiclePursuitCast_t ext) { return ext(i); }

      //                                //
      // Verified AIVehicleTraffic cast //
      //                                //

      struct AIVehicleTrafficCast_t {
        AIVehicleTraffic* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemoryIsInitialized(iAI)) return nullptr;
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

    // Try-get IVehicleAI as AIVehicleTraffic
    // Usage: AIVehicleTraffic* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleTraffic;
    static inline const details::AIVehicleTrafficCast_t AsAIVehicleTraffic;

    // Get a pointer to the player IRigidBody instance
    static IVehicleAI* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->GetAIVehiclePtr();

      return nullptr;
    }
  }  // namespace AIVehicleEx

}  // namespace OpenSpeed::MW05
