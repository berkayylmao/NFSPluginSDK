// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <Game.MW05/Types.h>
#define FIELDWRAPPER_DEFINE_MEMORYFIELDWRAPPER 1
#include <Core/FieldWrapper/FieldWrapper.hpp>

namespace OpenSpeed {
  namespace MW05::Variables {
    static MemoryFieldWrapper<float> AnimationSpeed{"AnimationSpeed", 0x904AEC, 45.0f, 0.001f,
                                                    1000.0f};
    static MemoryFieldWrapper<bool>  DrawHUD{"DrawHUD", 0x57CAA8, true};
    static MemoryFieldWrapper<bool>  IsFadeScreenOn{"IsFadeScreenOn", 0x91CAE4, false};
    static MemoryFieldWrapper<std::uint_least16_t> NOSFOVWidening{"NOSFOVWidening", 0x91112C, 0x666,
                                                                  0x001, 0x3500};
    static MemoryFieldWrapper<GameFlowState> TheGameFlowManager{"TheGameFlowManager", 0x925E90,
                                                                GameFlowState::InFrontEnd};
    static MemoryFieldWrapper<float>         Tweak_GameBreakerCollisionMass{
        "Tweak_GameBreakerCollisionMass", 0x901AEC, 2.0f, 0.0f, 100.0f};
    static MemoryFieldWrapper<float> Tweak_GameSpeed{"Tweak_GameSpeed", 0x901B1C, 1.0f, 0.01f,
                                                     3.0f};
    static MemoryFieldWrapper<bool>  Tweak_InfiniteNOS{"Tweak_InfiniteNOS", 0x937804, false};
    static MemoryFieldWrapper<bool>  WindowHasLostFocus{"WindowHasLostFocus", 0x982C50, false};

    namespace Config {
      static MemoryFieldWrapper<std::uint_least8_t> KeyAccelerate{"KeyAccelerate", 0x91F420, 0x00};
      static MemoryFieldWrapper<std::uint_least8_t> KeyBrake{"KeyBrake", 0x91F454, 0x00};
      static MemoryFieldWrapper<std::uint_least8_t> KeyShiftDown{"KeyShiftDown", 0x91F58C, 0x00};
      static MemoryFieldWrapper<std::uint_least8_t> KeyShiftUp{"KeyShiftUp", 0x91F5C0, 0x00};
    }  // namespace Config
  }    // namespace MW05::Variables
}  // namespace OpenSpeed
