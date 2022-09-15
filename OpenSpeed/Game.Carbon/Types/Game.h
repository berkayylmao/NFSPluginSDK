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

#ifndef OPENSPEED_GAME_CARBON_TYPES_GAME_H
#define OPENSPEED_GAME_CARBON_TYPES_GAME_H
#pragma once

#include <OpenSpeed/Game.Carbon/Types.h>

namespace OpenSpeed::Carbon::Game {
  // ECameraShake
  static inline void ShakeCamera() { reinterpret_cast<void(__cdecl*)()>(0x66C240)(); }
  // EForcePursuitBail
  static inline void ForcePursuitBail() { reinterpret_cast<void(__cdecl*)()>(0x66BBF0)(); }
  // EForcePursuitStart, also sets the heat level to max
  static inline void ForcePursuitStart() { reinterpret_cast<void(__cdecl*)()>(0x651430)(); }
  // Game_AbandonRace
  static inline void AbandonRace() { reinterpret_cast<void(__cdecl*)()>(0x656300)(); }
  // Game_BlowEngine
  static inline void BlowEngine(ISimable* pTarget) { reinterpret_cast<void(__cdecl*)(ISimable*)>(0x6515A0)(pTarget); }
  // Game_ClearAIControl
  static inline void ClearAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x65C330)(_unk); }
  // GPS_Disengage
  static inline void DisengageGPS() { reinterpret_cast<void(__cdecl*)()>(0x41ECB0)(); }
  // GPS_Engage
  static inline void EngageGPS(UMath::Vector3* to, float _unk = 0.0f) {
    reinterpret_cast<void(__cdecl*)(UMath::Vector3*, float)>(0x433AB0)(to, _unk);
  }
  // Game_ForceAIControl
  static inline void ForceAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x65C2C0)(_unk); }
  // Game_JumpToCarLot
  static inline void JumpToCarLot() { reinterpret_cast<void(__cdecl*)()>(0x64B7A0)(); }
  // Game_JumpToSafehouse
  static inline void JumpToSafehouse() { reinterpret_cast<void(__cdecl*)()>(0x64B800)(); }
  // Game_NavigatePlayerTo
  static inline void NavigatePlayerTo(GRuntimeInstance* to, GTrigger* trigger, float _unk = 0.0f, bool setGPS = true) {
    reinterpret_cast<void(__cdecl*)(GRuntimeInstance*, GTrigger*, float, bool)>(0x64B8C0)(to, trigger, _unk, setGPS);
  }
  // Game_SabotageEngine
  static inline void SabotageEngine(ISimable* pTarget, float durationInSeconds) {
    reinterpret_cast<void(__cdecl*)(ISimable*, float)>(0x6515D0)(pTarget, durationInSeconds);
  }
  // Game_SetCopsEnabled
  static inline void SetCopsEnabled(bool copsEnabled) { reinterpret_cast<void(__cdecl*)(bool)>(0x6513E0)(copsEnabled); }
  // Game_SetWorldHeat
  static inline void SetWorldHeat(float newHeatLevel) {
    reinterpret_cast<void(__cdecl*)(float)>(0x65C550)(newHeatLevel);
  }
  // Game_ShowPauseMenu
  static inline void ShowPauseMenu() { reinterpret_cast<void(__cdecl*)()>(0x64B620)(); }

  // custom hashing
  static inline std::uint32_t bStringHash(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x471050)(cstring);
  }

  // uses 0xABCDEF00 magic
  static inline std::uint32_t stringhash32(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x606B60)(cstring);
  }
}  // namespace OpenSpeed::Carbon::Game

#endif  // OPENSPEED_GAME_CARBON_TYPES_GAME_H
