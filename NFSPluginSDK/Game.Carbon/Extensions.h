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

#ifndef NFSPLUGINSDK_GAME_CARBON_EXTENSIONS_H
#define NFSPLUGINSDK_GAME_CARBON_EXTENSIONS_H
#pragma once

#include <functional>  // std::function

#include <NFSPluginSDK/Core/MemoryEditor.hpp>  // ValidateMemory

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleCopCar.h>  // AIVehicleCopCar, AIVehiclePursuit, AIVehiclePid, AIVehicle
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleEmpty.h>    // AIVehicleEmpty
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleGhost.h>    // AIVehicleGhost
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleHuman.h>    // AIVehicleHuman, AIVehicleRacecar
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleTraffic.h>  // AIVehicleTraffic
#include <NFSPluginSDK/Game.Carbon/Types/GRaceStatus.h>       // GRaceStatus
#include <NFSPluginSDK/Game.Carbon/Types/IPlayer.h>           // IPlayer
#include <NFSPluginSDK/Game.Carbon/Types/PVehicle.h>          // PVehicle
#include <NFSPluginSDK/Game.Carbon/Types/IRigidBody.h>        // IRigidBody

namespace NFSPluginSDK::Carbon {
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
      inline PVehicle* operator|(PVehicle* pvehicle, ValidatePVehicle_t ext) { return ext(pvehicle); }
    }  // namespace details

    // Validate PVehicle pointer
    // Usage: PVehicle* myptr = GetPVehiclePtr() | PVehicleEx::ValidatePVehicle;
    inline const details::ValidatePVehicle_t ValidatePVehicle;

    // Get a pointer to the player PVehicle instance
    inline PVehicle* GetPlayerInstance() {
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
    inline void ForEachInstance(const std::function<void(PVehicle* p)>& fn) {
      auto** pInstance = PVehicle::g_mInstances;
      if (!pInstance) return;

      auto* instance = *pInstance;
      while (instance != reinterpret_cast<bTNode<PVehicle>*>(pInstance)) {
        if (auto* pvehicle = static_cast<PVehicle*>(instance) | ValidatePVehicle) fn(pvehicle);
        instance = instance->GetNext();
      }
    }

    // Change target PVehicle model
    inline details::ChangedPVehicleInfo ChangePVehicleInto(
        PVehicle* target, const Attrib::Gen::pvehicle& instance, VehicleCustomizations* customizations,
        eVehicleParamFlags flags           = eVehicleParamFlags::SnapToGround | eVehicleParamFlags::CalcPerformance,
        bool               killAfterChange = true) {
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
          VehicleParams(pvehicle->GetDriverClass(), instance, direction, position, customizations, flags, race_status));
      if (!new_pvehicle) return ret;

      // Pass on details
      new_pvehicle->Attach(player);
      new_pvehicle->GetRigidBody()->SetLinearVelocity(linear_vel);
      new_pvehicle->GetRigidBody()->SetAngularVelocity(angular_vel);

      // Change handles if in race (values will sync at the next checkpoint)
      if (race_status->mRacerCount > 0) {
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
    inline details::ChangedPVehicleInfo ChangePVehicleInto(
        PVehicle* target, std::uint32_t vehicleKey, VehicleCustomizations* customizations,
        eVehicleParamFlags flags           = eVehicleParamFlags::SnapToGround | eVehicleParamFlags::CalcPerformance,
        bool               killAfterChange = true) {
      return ChangePVehicleInto(target, Attrib::Gen::pvehicle::TryGetInstance(vehicleKey), customizations, flags,
                                killAfterChange);
    }
  }  // namespace PVehicleEx

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
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C3D80) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehicle* operator|(IVehicleAI* i, AIVehicleCast_t ext) { return ext(i); }

      //                               //
      // Verified AIVehicleCopCar cast //
      //                               //

      struct AIVehicleCopCarCast_t {
        AIVehicleCopCar* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleCopCar*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C4A40) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehicleCopCar* operator|(IVehicleAI* i, AIVehicleCopCarCast_t ext) { return ext(i); }

      //                              //
      // Verified AIVehicleEmpty cast //
      //                              //

      struct AIVehicleEmptyCast_t {
        AIVehicleEmpty* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleEmpty*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C47D0) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehicleEmpty* operator|(IVehicleAI* iAI, AIVehicleEmptyCast_t ext) { return ext(iAI); }

      //                                   //
      // Verified AIVehicleHelicopter cast //
      //                                   //

      struct AIVehicleGhostCast_t {
        AIVehicleGhost* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleGhost*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C45E0) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehicleGhost* operator|(IVehicleAI* i, AIVehicleGhostCast_t ext) { return ext(i); }

      //                              //
      // Verified AIVehicleHuman cast //
      //                              //

      struct AIVehicleHumanCast_t {
        AIVehicleHuman* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleHuman*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C5260) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehicleHuman* operator|(IVehicleAI* i, AIVehicleHumanCast_t ext) { return ext(i); }

      //                            //
      // Verified AIVehiclePid cast //
      //                            //

      struct AIVehiclePidCast_t {
        AIVehiclePid* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehiclePid*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C3F70) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehiclePid* operator|(IVehicleAI* i, AIVehiclePidCast_t ext) { return ext(i); }

      //                                //
      // Verified AIVehiclePursuit cast //
      //                                //

      struct AIVehiclePursuitCast_t {
        AIVehiclePursuit* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehiclePursuit*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C4360) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehiclePursuit* operator|(IVehicleAI* i, AIVehiclePursuitCast_t ext) { return ext(i); }

      //                                //
      // Verified AIVehicleRacecar cast //
      //                                //

      struct AIVehicleRacecarCast_t {
        AIVehicleRacecar* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleRacecar*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C4F58) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehicleRacecar* operator|(IVehicleAI* i, AIVehicleRacecarCast_t ext) { return ext(i); }

      //                                //
      // Verified AIVehicleTraffic cast //
      //                                //

      struct AIVehicleTrafficCast_t {
        AIVehicleTraffic* operator()(IVehicleAI* iAI) const {
          if (!iAI || !MemoryEditor::Get().ValidateMemory(iAI)) return nullptr;
          // Verify cast
          auto* ai = static_cast<AIVehicleTraffic*>(iAI);
          if (*reinterpret_cast<std::uintptr_t*>(ai) == 0x9C4170) return ai;
          // Bad cast
          return nullptr;
        }
      };
      inline AIVehicleTraffic* operator|(IVehicleAI* i, AIVehicleTrafficCast_t ext) { return ext(i); }
    }  // namespace details

    // Try-get IVehicleAI as AIVehicle
    // Usage: AIVehicle* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicle;
    inline const details::AIVehicleCast_t AsAIVehicle;

    // Try-get IVehicleAI as AIVehicleCopCar
    // Usage: AIVehicleCopCar* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleCopCar;
    inline const details::AIVehicleCopCarCast_t AsAIVehicleCopCar;

    // Try-get IVehicleAI as AIVehicleEmpty
    // Usage: AIVehicleEmpty* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleEmpty;
    inline const details::AIVehicleEmptyCast_t AsAIVehicleEmpty;

    // Try-get IVehicleAI as AIVehicleGhost
    // Usage: AIVehicleGhost* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleGhost;
    inline const details::AIVehicleGhostCast_t AsAIVehicleGhost;

    // Try-get IVehicleAI as AIVehicleHuman
    // Usage: AIVehicleHuman* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleHuman;
    inline const details::AIVehicleHumanCast_t AsAIVehicleHuman;

    // Try-get IVehicleAI as AIVehiclePid
    // Usage: AIVehiclePid* myptr = GetAIPtr() | AIVehicleEx::AsAIVehiclePid;
    inline const details::AIVehiclePidCast_t AsAIVehiclePid;

    // Try-get IVehicleAI as AIVehiclePursuit
    // Usage: AIVehiclePursuit* myptr = GetAIPtr() | AIVehicleEx::AsAIVehiclePursuit;
    inline const details::AIVehiclePursuitCast_t AsAIVehiclePursuit;

    // Try-get IVehicleAI as AIVehicleRaceCar
    // Usage: AIVehicleRaceCar* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleRaceCar;
    inline const details::AIVehicleRacecarCast_t AsAIVehicleRacecar;

    // Try-get IVehicleAI as AIVehicleTraffic
    // Usage: AIVehicleTraffic* myptr = GetAIPtr() | AIVehicleEx::AsAIVehicleTraffic;
    inline const details::AIVehicleTrafficCast_t AsAIVehicleTraffic;

    // Get a pointer to the player IVehicleAI instance
    inline IVehicleAI* GetPlayerInstance() {
      auto* pvehicle = PVehicleEx::GetPlayerInstance();
      if (pvehicle) return pvehicle->GetAIVehiclePtr();

      return nullptr;
    }
  }  // namespace AIVehicleEx

  //        //
  // IInput //
  //        //

  namespace InputEx {
    namespace details {
      //                   //
      // Validate IInput //
      //                   //

      struct ValidateIInput_t {
        IInput* operator()(IInput* input) const {
          if (!input || !MemoryEditor::Get().ValidateMemory(input)) return nullptr;
          // Validate ptr
          auto vfptr = *reinterpret_cast<std::uintptr_t*>(input);
          // type: AIVehicle
          if (vfptr == 0x9C3BF8) return input;
          // type: AIVehiclePid
          if (vfptr == 0x9C3DE8) return input;
          // type: AIVehicleEmpty
          if (vfptr == 0x9C4648) return input;
          // type: AIVehicleGhost
          if (vfptr == 0x9C4458) return input;
          // type: AIPerpVehicle
          if (vfptr == 0x9C4B48) return input;
          // type: AIVehicleRaceCar
          if (vfptr == 0x9C4DD0) return input;
          // type: AIVehicleHuman
          if (vfptr == 0x9C50D8) return input;
          // type: AIVehiclePursuit
          if (vfptr == 0x9C41D8) return input;
          // type: AIVehicleCopCar
          if (vfptr == 0x9C48B8) return input;
          // Bad cast
          return nullptr;
        }
      };
      inline IInput* operator|(IInput* input, ValidateIInput_t ext) { return ext(input); }

      //                       //
      // Validate IInputPlayer //
      //                       //

      struct ValidateIInputPlayer_t {
        IInputPlayer* operator()(IInputPlayer* inputplayer) const {
          if (!inputplayer || !MemoryEditor::Get().ValidateMemory(inputplayer)) return nullptr;
          // Validate ptr
          if (*reinterpret_cast<std::uintptr_t*>(inputplayer) == 0x9C4FF0) return inputplayer;
          // Bad cast
          return nullptr;
        }
      };
      inline IInputPlayer* operator|(IInputPlayer* inputplayer, ValidateIInputPlayer_t ext) { return ext(inputplayer); }
    }  // namespace details

    // Validate IInput pointer
    // Usage: IInput* myptr = GetIInputPtr() | InputEx::ValidateIInput;
    inline const details::ValidateIInput_t ValidateIInput;

    // Validate IInputPlayer pointer
    // Usage: IInputPlayer* myptr = GetIInputPlayerPtr() | InputEx::ValidateIInputPlayer;
    inline const details::ValidateIInputPlayer_t ValidateIInputPlayer;

    // Get a pointer to the player IInput instance
    inline IInput* GetPlayerInput() {
      auto* ai = AIVehicleEx::GetPlayerInstance() | AIVehicleEx::AsAIVehicleHuman;
      if (!ai) return nullptr;

      return static_cast<IInput*>(ai) | ValidateIInput;
    }

    // Get a pointer to the player IInputPlayer instance
    inline IInputPlayer* GetPlayerInputPlayer() {
      auto* ai = AIVehicleEx::GetPlayerInstance() | AIVehicleEx::AsAIVehicleHuman;
      if (!ai) return nullptr;

      return static_cast<IInputPlayer*>(ai) | ValidateIInputPlayer;
    }
  }  // namespace InputEx
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_EXTENSIONS_H
