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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_GAME_H
#define OPENSPEED_GAME_PROSTREET_TYPES_GAME_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>

namespace OpenSpeed::ProStreet::Game {
  // ECameraShake
  static inline void ShakeCamera() { reinterpret_cast<void(__cdecl*)()>(0x69A020)(); }
  // ERefreshHUD
  static inline void RefreshHUD() { reinterpret_cast<void(__cdecl*)()>(0x69DE30)(); }
  // Game_AbandonRace
  static inline void AbandonRace() { reinterpret_cast<void(__cdecl*)()>(0x6E5570)(); }
  // Game_BlowEngine
  static inline void BlowEngine(ISimable* pTarget) { reinterpret_cast<void(__cdecl*)(ISimable*)>(0x6E5730)(pTarget); }
  // Game_ClearAIControl
  static inline void ClearAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x6EA760)(_unk); }
  // Game_ForceAIControl
  static inline void ForceAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x6EA6F0)(_unk); }
  // Game_KnockoutRacer
  static inline void KnockoutRacer(ISimable* racer) { reinterpret_cast<void(__cdecl*)(ISimable*)>(0x6E99B0)(racer); }
  // Game_JumpToCarLot
  static inline void JumpToCarLot() { reinterpret_cast<void(__cdecl*)()>(0x6DEE30)(); }
  // Game_JumpToSafehouse
  static inline void JumpToSafehouse() { reinterpret_cast<void(__cdecl*)()>(0x6DEEA0)(); }
  // Game_NavigatePlayerTo
  static inline void NavigatePlayerTo(GRuntimeInstance* to, GTrigger* trigger) {
    reinterpret_cast<void(__cdecl*)(GRuntimeInstance*, GTrigger*)>(0x6DEF40)(to, trigger);
  }
  // Game_SabotageEngine
  static inline void SabotageEngine(ISimable* pTarget, float durationInSeconds) {
    reinterpret_cast<void(__cdecl*)(ISimable*, float)>(0x6E5760)(pTarget, durationInSeconds);
  }
  // Game_ShowPauseMenu
  static inline void ShowPauseMenu() { reinterpret_cast<void(__cdecl*)()>(0x6DEBA0)(); }
  // Game_TotalRacer
  static inline void TotalRacer(ISimable* racer) { KnockoutRacer(racer); }

  // custom hashing
  static inline std::uint32_t bStringHash(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x436680)(cstring);
  }
  static inline std::uint32_t bStringHashUpper(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x4366E0)(cstring);
  }

  // custom hashing for fe
  static inline std::uint32_t FEHashUpper(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x6241D0)(cstring);
  }

  // uses 0xABCDEF00 magic
  static inline std::uint32_t stringhash32(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x465020)(cstring);
  }
}  // namespace OpenSpeed::ProStreet::Game

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_GAME_H
