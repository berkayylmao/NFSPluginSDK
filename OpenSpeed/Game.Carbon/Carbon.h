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
#include <OpenSpeed/Core/MemoryFieldWrapper/MemoryFieldWrapper.hpp>
#include <OpenSpeed/Game.Carbon/Types.h>

namespace OpenSpeed {
  namespace Carbon::Variables {
    static MemoryFieldWrapper<Math::Matrix4> CarScaleMatrix{0xB778D0, Math::Matrix4()};
    static MemoryFieldWrapper<bool>          DrawCars{0xA73008, true};
    static MemoryFieldWrapper<bool>          DrawCarsReflections{0xA7300C, true};
    static MemoryFieldWrapper<bool>          DrawCarShadow{0xA73010, true};
    // static MemoryFieldWrapper<bool>           DrawHUD{0x57CAA8, true};
    static MemoryFieldWrapper<bool>          DrawLightFlares{0xA6C088, true};
    static MemoryFieldWrapper<CARPART_LOD>   ForceCarLOD{0xA7309C, CARPART_LOD::A};
    static MemoryFieldWrapper<CARPART_LOD>   ForceTireLOD{0xA730A0, CARPART_LOD::A};
    static MemoryFieldWrapper<bool>          IsGameplayPaused{0xA8AD18, false};
    static MemoryFieldWrapper<bool>          IsInNIS{0xB42EBC, false};
    static MemoryFieldWrapper<std::uint16_t> NOSFOVWidening{0xA8AB60, 0x666, 0x001, 0x3500};
    static MemoryFieldWrapper<bool>          StopUpdatingCamera{0xA888D8, false};
    static MemoryFieldWrapper<AICopManager*> TheOneCopManager{0xA83A58, nullptr};
    static MemoryFieldWrapper<GameFlowState> TheGameFlowManager{0xA99BBC, GameFlowState::InFrontEnd};
    static MemoryFieldWrapper<float>         Tweak_GameBreakerCollisionMass{0xA71278, 2.0f, FLT_MIN, FLT_MAX};
    static MemoryFieldWrapper<float>         Tweak_GameSpeed{0xA712AC, 1.0f, FLT_MIN, FLT_MAX};
    static MemoryFieldWrapper<bool>          Tweak_InfiniteRaceBreaker{0xB4D86C, false};
    static MemoryFieldWrapper<bool>          Tweak_PauseCameraLock{0xA995CC, false};
    static MemoryFieldWrapper<bool>          Tweak_TrafficStopSpawning{0xA83A4C, false};
    static MemoryFieldWrapper<bool>          WindowHasLostFocus{0xAB0B3C, false};
  }  // namespace Carbon::Variables
}  // namespace OpenSpeed
