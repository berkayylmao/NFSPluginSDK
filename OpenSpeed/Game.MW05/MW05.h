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
#include <OpenSpeed/Core/MemoryFieldWrapper/MemoryFieldWrapper.hpp>
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed {
  namespace MW05::Variables {
    static MemoryFieldWrapper<float>          AnimationSpeed{0x904AEC, 45.0f, FLT_MIN, FLT_MAX};
    static MemoryFieldWrapper<UMath::Matrix4> CarScaleMatrix{0x9B34B0, UMath::Matrix4()};
    static MemoryFieldWrapper<bool>           DrawCars{0x903320, true};
    static MemoryFieldWrapper<bool>           DrawCarsReflections{0x903324, true};
    static MemoryFieldWrapper<bool>           DrawCarShadow{0x903328, true};
    static MemoryFieldWrapper<bool>           DrawHUD{0x57CAA8, true};
    static MemoryFieldWrapper<bool>           DrawLightFlares{0x8F2918, true};
    static MemoryFieldWrapper<CARPART_LOD>    ForceCarLOD{0x903384, CARPART_LOD::A};
    static MemoryFieldWrapper<CARPART_LOD>    ForceTireLOD{0x903388, CARPART_LOD::A};
    static MemoryFieldWrapper<bool>           IsFadeScreenOn{0x91CAE4, false};
    static MemoryFieldWrapper<bool>           IsInNIS{0x91606C, false};
    static MemoryFieldWrapper<std::uint16_t>  NOSFOVWidening{0x91112C, 0x666, 0x001, 0x3500};
    static MemoryFieldWrapper<bool>           StopUpdatingCamera{0x911020, false};
    static MemoryFieldWrapper<AICopManager*>  TheOneCopManager{0x90D5F4, nullptr};
    static MemoryFieldWrapper<GameFlowState>  TheGameFlowManager{0x925E90, GameFlowState::InFrontEnd};
    static MemoryFieldWrapper<float>          Tweak_GameBreakerCollisionMass{0x901AEC, 2.0f, FLT_MIN, FLT_MAX};
    static MemoryFieldWrapper<float>          Tweak_GameSpeed{0x901B1C, 1.0f, FLT_MIN, FLT_MAX};
    static MemoryFieldWrapper<bool>           Tweak_InfiniteNOS{0x937804, false};
    static MemoryFieldWrapper<bool>           Tweak_InfiniteRaceBreaker{0x988E1C, false};
    static MemoryFieldWrapper<bool>           Tweak_PauseCameraLock{0x92584C, false};
    static MemoryFieldWrapper<bool>           WindowHasLostFocus{0x982C50, false};

    namespace Config {
      static MemoryFieldWrapper<std::uint8_t> KeyAccelerate{0x91F420, 0x00};
      static MemoryFieldWrapper<std::uint8_t> KeyBrake{0x91F454, 0x00};
      static MemoryFieldWrapper<std::uint8_t> KeyShiftDown{0x91F58C, 0x00};
      static MemoryFieldWrapper<std::uint8_t> KeyShiftUp{0x91F5C0, 0x00};
    }  // namespace Config
  }    // namespace MW05::Variables
}  // namespace OpenSpeed
