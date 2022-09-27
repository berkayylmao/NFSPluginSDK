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

#ifndef NFSPLUGINSDK_GAME_MW05_MW05_H
#define NFSPLUGINSDK_GAME_MW05_MW05_H
#pragma once

#include <NFSPluginSDK/Core/MemoryFieldWrapper.hpp>
#include <NFSPluginSDK/Game.MW05/_IncludeAllTypes.h>

namespace NFSPluginSDK::MW05::Variables {
  static inline MemoryFieldWrapper<float>                  AnimationSpeed{0x904AEC, 45.0f, FLT_MIN, FLT_MAX};
  static inline MemoryFieldWrapper<Math::Matrix4>          CarScaleMatrix{0x9B34B0, Math::Matrix4()};
  static inline MemoryFieldWrapper<bool>                   DrawCars{0x903320, true};
  static inline MemoryFieldWrapper<bool>                   DrawCarsReflections{0x903324, true};
  static inline MemoryFieldWrapper<bool>                   DrawCarShadow{0x903328, true};
  static inline MemoryFieldWrapper<bool>                   DrawHUD{0x57CAA8, true};
  static inline MemoryFieldWrapper<bool>                   DrawLightFlares{0x8F2918, true};
  static inline MemoryFieldWrapper<CARPART_LOD>            ForceCarLOD{0x903384, CARPART_LOD::A};
  static inline MemoryFieldWrapper<CARPART_LOD>            ForceTireLOD{0x903388, CARPART_LOD::A};
  static inline MemoryFieldWrapper<bool>                   IsFadeScreenOn{0x91CAE4, false};
  static inline MemoryFieldWrapper<bool>                   IsInNIS{0x91606C, false};
  static inline MemoryFieldWrapper<std::uint16_t>          NOSFOVWidening{0x91112C, 0x666, 0x001, 0x3500};
  static inline MemoryFieldWrapper<ePrecullerMode>         PrecullerMode{0x8FAE44, ePrecullerMode::On};
  static inline MemoryFieldWrapper<bool>                   SkipFE{0x926064, false};
  static inline MemoryFieldWrapper<bool>                   SkipFEDisableCops{0x8F86C0, true};
  static inline MemoryFieldWrapper<bool>                   SkipFEDisableTraffic{0x926094, true};
  static inline MemoryFieldWrapper<const char*>            SkipFEPlayerCar{0x8F86A8, "bmwm3gtre46"};
  static inline MemoryFieldWrapper<ePlayerSettingsCameras> SkipFEPOVType{0x8F86C4, ePlayerSettingsCameras::Close};
  static inline MemoryFieldWrapper<float>                  SkipFETrafficDensity{0x926090, 0.0f};
  static inline MemoryFieldWrapper<bool>                   StopUpdatingCamera{0x911020, false};
  static inline MemoryFieldWrapper<AICopManager*>          TheOneCopManager{0x90D5F4, nullptr};
  static inline MemoryFieldWrapper<GameFlowState>          TheGameFlowManager{0x925E90, GameFlowState::InFrontEnd};
  static inline MemoryFieldWrapper<float> Tweak_GameBreakerCollisionMass{0x901AEC, 2.0f, FLT_MIN, FLT_MAX};
  static inline MemoryFieldWrapper<float> Tweak_GameSpeed{0x901B1C, 1.0f, FLT_MIN, FLT_MAX};
  static inline MemoryFieldWrapper<bool>  Tweak_InfiniteNOS{0x937804, false};
  static inline MemoryFieldWrapper<bool>  Tweak_InfiniteRaceBreaker{0x988E1C, false};
  static inline MemoryFieldWrapper<bool>  Tweak_PauseCameraLock{0x92584C, false};
  static inline MemoryFieldWrapper<bool>  WindowHasLostFocus{0x982C50, false};
}  // namespace NFSPluginSDK::MW05::Variables

#endif  // NFSPLUGINSDK_GAME_MW05_MW05_H
