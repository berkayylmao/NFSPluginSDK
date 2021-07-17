// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05::Game {
  static inline auto BeginGameFlowUnloadTrack() { reinterpret_cast<void(__cdecl*)()>(0x667340)(); }
  // ECameraShake
  static inline void ShakeCamera() { reinterpret_cast<void(__cdecl*)()>(0x62B110)(); }
  // EForcePursuitBail
  static inline void ForcePursuitBail() { reinterpret_cast<void(__cdecl*)()>(0x62ACE0)(); }
  // EForcePursuitStart, also sets the heat level to max
  static inline void ForcePursuitStart() { reinterpret_cast<void(__cdecl*)()>(0x60AAC0)(); }
  // Game_AbandonRace
  static inline void AbandonRace() { reinterpret_cast<void(__cdecl*)()>(0x60DEB0)(); }
  // Game_BlowEngine
  static inline void BlowEngine(ISimable* pTarget) { reinterpret_cast<void(__cdecl*)(ISimable*)>(0x60AB30)(pTarget); }
  // Game_ClearAIControl
  static inline void ClearAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x612420)(_unk); }
  // Game_ForceAIControl
  static inline void ForceAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x6123B0)(_unk); }
  // Game_JumpToCarLot
  static inline void JumpToCarLot() { reinterpret_cast<void(__cdecl*)()>(0x605250)(); }
  // Game_JumpToSafehouse
  static inline void JumpToSafehouse() { reinterpret_cast<void(__cdecl*)()>(0x6052B0)(); }
  // Game_SabotageEngine
  static inline void SabotageEngine(ISimable* pTarget, float durationInSeconds) {
    reinterpret_cast<void(__cdecl*)(ISimable*, float)>(0x60AB60)(pTarget, durationInSeconds);
  }
  // Game_SetCopsEnabled
  static inline void SetCopsEnabled(bool copsEnabled) { reinterpret_cast<void(__cdecl*)(bool)>(0x604F40)(copsEnabled); }
  // Game_SetWorldHeat
  static inline void SetWorldHeat(float newHeatLevel) {
    reinterpret_cast<void(__cdecl*)(float)>(0x612660)(newHeatLevel);
  }
  // Game_ShowPauseMenu
  static inline void ShowPauseMenu() { reinterpret_cast<void(__cdecl*)()>(0x6050F0)(); }

  static inline auto stringhash32(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x5CC240)(cstring);
  }
}  // namespace OpenSpeed::MW05::Game
