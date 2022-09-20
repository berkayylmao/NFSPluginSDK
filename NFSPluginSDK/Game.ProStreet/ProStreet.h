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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_PROSTREET_H
#define NFSPLUGINSDK_GAME_PROSTREET_PROSTREET_H
#pragma once

#include <NFSPluginSDK/Core/MemoryFieldWrapper.hpp>
#include <NFSPluginSDK/Game.ProStreet/_IncludeAllTypes.h>

namespace NFSPluginSDK::ProStreet::Variables {
  static inline MemoryFieldWrapper<bool>           CarGuysForceLODS{0xBFBC43, false};
  static inline MemoryFieldWrapper<std::uint32_t*> CarPartTypeNameHashTable{0xAEB774, nullptr};
  static inline MemoryFieldWrapper<Math::Matrix4>  CarScaleMatrix{0xAEE180, Math::Matrix4()};
  static inline MemoryFieldWrapper<bool>           DrawCars{0xA79CDC, true};
  static inline MemoryFieldWrapper<bool>           EnableEnvMap{0xA61884, true};
  static inline MemoryFieldWrapper<CARPART_LOD>    ForceCarLOD{0xA79D7C, CARPART_LOD::A};
  static inline MemoryFieldWrapper<bool>           ForceCarLODPrint{0xAEB6E2, false};
  static inline MemoryFieldWrapper<CARPART_LOD>    ForceTireLOD{0xA79D80, CARPART_LOD::A};
  static inline MemoryFieldWrapper<bool>           IsGameplayPaused{0xAB0EDC, false};
  static inline MemoryFieldWrapper<bool>           IsRacing{0xAACF5F, false};
  static inline MemoryFieldWrapper<float>          RealTimeElapsed{0xABB048, 0.0f};
  static inline MemoryFieldWrapper<bool>           RearViewModel{0xAEB728, false};
  static inline MemoryFieldWrapper<bool>           ShowAllCarsInFE{0xBFBC6E, false};
  static inline MemoryFieldWrapper<bool>           ShowCarLODScreenPrint{0xAEB6E0, false};
  static inline MemoryFieldWrapper<bool>           SkipCareerIntro{0xBFBC6C, false};
  static inline MemoryFieldWrapper<GameFlowState>  TheGameFlowManager{0xABB510, GameFlowState::InFrontEnd};
  static inline MemoryFieldWrapper<float>          Tweak_GameBreakerCollisionMass{0xA9B678, 2.0f, FLT_MIN, FLT_MAX};
  static inline MemoryFieldWrapper<bool>           UnlockAllThings{0xBFBC5B, false};
}  // namespace NFSPluginSDK::ProStreet::Variables

#endif  // NFSPLUGINSDK_GAME_PROSTREET_PROSTREET_H
