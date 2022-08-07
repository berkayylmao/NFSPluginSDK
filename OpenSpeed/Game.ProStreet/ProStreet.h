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
#include <OpenSpeed/Game.ProStreet/Types.h>

namespace OpenSpeed {
  namespace ProStreet::Variables {
    static MemoryFieldWrapper<bool>          CarGuysForceLODS{0xBFBC43, false};
    static MemoryFieldWrapper<Math::Matrix4> CarScaleMatrix{0xAEE180, Math::Matrix4()};
    static MemoryFieldWrapper<bool>          DrawCars{0xA79CDC, true};
    static MemoryFieldWrapper<bool>          EnableEnvMap{0xA61884, true};
    static MemoryFieldWrapper<CARPART_LOD>   ForceCarLOD{0xA79D7C, CARPART_LOD::A};
    static MemoryFieldWrapper<bool>          ForceCarLODPrint{0xAEB6E2, false};
    static MemoryFieldWrapper<CARPART_LOD>   ForceTireLOD{0xA79D80, CARPART_LOD::A};
    // DALPauseStates::mPauseRequest
    static MemoryFieldWrapper<bool>          IsGameplayPaused{0xAB0EDC, false};
    static MemoryFieldWrapper<bool>          IsRacing{0xAACF5F, false};
    static MemoryFieldWrapper<bool>          RearViewModel{0xAEB728, false};
    static MemoryFieldWrapper<bool>          ShowCarLODScreenPrint{0xAEB6E0, false};
    static MemoryFieldWrapper<GameFlowState> TheGameFlowManager{0xABB510, GameFlowState::InFrontEnd};
    static MemoryFieldWrapper<float>         Tweak_GameBreakerCollisionMass{0xA9B678, 2.0f, FLT_MIN, FLT_MAX};
  }  // namespace ProStreet::Variables
}  // namespace OpenSpeed
