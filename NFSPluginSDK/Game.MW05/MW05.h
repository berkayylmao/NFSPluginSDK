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

#ifndef NFSPLUGINSDK_GAME_MW05_MW05_H
#define NFSPLUGINSDK_GAME_MW05_MW05_H
#pragma once

#include <NFSPluginSDK/Core/MemoryFieldWrapper.hpp>
#include <NFSPluginSDK/Game.MW05/_IncludeAllTypes.h>

namespace NFSPluginSDK::MW05::Variables {
  static inline MemoryFieldWrapper<float>          AnimationSpeed{0x904AEC, 45.0f, FLT_MIN, FLT_MAX};
  static inline MemoryFieldWrapper<Math::Matrix4>  CarScaleMatrix{0x9B34B0, Math::Matrix4()};
  static inline MemoryFieldWrapper<bool>           DrawCars{0x903320, true};
  static inline MemoryFieldWrapper<bool>           DrawCarsReflections{0x903324, true};
  static inline MemoryFieldWrapper<bool>           DrawCarShadow{0x903328, true};
  static inline MemoryFieldWrapper<bool>           DrawHUD{0x57CAA8, true};
  static inline MemoryFieldWrapper<bool>           DrawLightFlares{0x8F2918, true};
  static inline MemoryFieldWrapper<CARPART_LOD>    ForceCarLOD{0x903384, CARPART_LOD::A};
  static inline MemoryFieldWrapper<CARPART_LOD>    ForceTireLOD{0x903388, CARPART_LOD::A};
  static inline MemoryFieldWrapper<bool>           IsFadeScreenOn{0x91CAE4, false};
  static inline MemoryFieldWrapper<bool>           IsInNIS{0x91606C, false};
  static inline MemoryFieldWrapper<std::uint16_t>  NOSFOVWidening{0x91112C, 0x666, 0x001, 0x3500};
  static inline MemoryFieldWrapper<ePrecullerMode> PrecullerMode{0x8FAE44, ePrecullerMode::On};
  static inline MemoryFieldWrapper<bool>           StopUpdatingCamera{0x911020, false};
  static inline MemoryFieldWrapper<AICopManager*>  TheOneCopManager{0x90D5F4, nullptr};
  static inline MemoryFieldWrapper<GameFlowState>  TheGameFlowManager{0x925E90, GameFlowState::InFrontEnd};
  static inline MemoryFieldWrapper<float>          Tweak_GameBreakerCollisionMass{0x901AEC, 2.0f, FLT_MIN, FLT_MAX};
  static inline MemoryFieldWrapper<float>          Tweak_GameSpeed{0x901B1C, 1.0f, FLT_MIN, FLT_MAX};
  static inline MemoryFieldWrapper<bool>           Tweak_InfiniteNOS{0x937804, false};
  static inline MemoryFieldWrapper<bool>           Tweak_InfiniteRaceBreaker{0x988E1C, false};
  static inline MemoryFieldWrapper<bool>           Tweak_PauseCameraLock{0x92584C, false};
  static inline MemoryFieldWrapper<bool>           WindowHasLostFocus{0x982C50, false};
}  // namespace NFSPluginSDK::MW05::Variables

#endif  // NFSPLUGINSDK_GAME_MW05_MW05_H
