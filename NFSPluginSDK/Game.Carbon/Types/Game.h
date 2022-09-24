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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_GAME_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_GAME_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>

namespace NFSPluginSDK::Carbon::Game {
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
}  // namespace NFSPluginSDK::Carbon::Game

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_GAME_H
