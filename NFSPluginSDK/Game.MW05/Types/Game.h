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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_GAME_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_GAME_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05::Game {
  static inline void BeginGameFlowUnloadTrack() { reinterpret_cast<void(__cdecl*)()>(0x667340)(); }
  // ECameraShake
  static inline void ShakeCamera() { reinterpret_cast<void(__cdecl*)()>(0x62B110)(); }
  // EForcePursuitBail
  static inline void ForcePursuitBail() { reinterpret_cast<void(__cdecl*)()>(0x62ACE0)(); }
  // EForcePursuitStart, also sets the heat level to max
  static inline void ForcePursuitStart() { reinterpret_cast<void(__cdecl*)()>(0x60AAC0)(); }
  // Game_AbandonRace
  static inline void AbandonRace() { reinterpret_cast<void(__cdecl*)()>(0x60DEB0)(); }
  // Game_AwardPlayerBounty
  static inline void AwardPlayerBounty(std::int32_t amount) {
    reinterpret_cast<void(__cdecl*)(std::int32_t)>(0x612220)(amount);
  }
  // Game_BlowEngine
  static inline void BlowEngine(ISimable* pTarget) { reinterpret_cast<void(__cdecl*)(ISimable*)>(0x60AB30)(pTarget); }
  // Game_ClearAIControl
  static inline void ClearAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x612420)(_unk); }
  // GPS_Disengage
  static inline void DisengageGPS() { reinterpret_cast<void(__cdecl*)()>(0x41ACE0)(); }
  // GPS_Engage
  static inline void EngageGPS(UMath::Vector3* to, float _unk = 0.0f) {
    reinterpret_cast<void(__cdecl*)(UMath::Vector3*, float)>(0x42C830)(to, _unk);
  }
  // Game_ForceAIControl
  static inline void ForceAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x6123B0)(_unk); }
  // Game_JumpToCarLot
  static inline void JumpToCarLot() { reinterpret_cast<void(__cdecl*)()>(0x605250)(); }
  // Game_JumpToSafehouse
  static inline void JumpToSafehouse() { reinterpret_cast<void(__cdecl*)()>(0x6052B0)(); }
  // Game_NavigatePlayerTo
  static inline void NavigatePlayerTo(GRuntimeInstance* to, GTrigger* trigger, float _unk = 0.0f, bool setGPS = true) {
    reinterpret_cast<void(__cdecl*)(GRuntimeInstance*, GTrigger*, float, bool)>(0x605360)(to, trigger, _unk, setGPS);
  }
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

  // custom hashing
  static inline std::uint32_t bStringHash(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x460BF0)(cstring);
  }

  // uses 0xABCDEF00 magic
  static inline std::uint32_t stringhash32(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x5CC240)(cstring);
  }
}  // namespace NFSPluginSDK::MW05::Game

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_GAME_H
