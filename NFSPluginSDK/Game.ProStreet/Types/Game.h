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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GAME_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GAME_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::Game {
  // ECameraShake
  inline void ShakeCamera() { reinterpret_cast<void(__cdecl*)()>(0x69A020)(); }
  // ERefreshHUD
  inline void RefreshHUD() { reinterpret_cast<void(__cdecl*)()>(0x69DE30)(); }
  // Game_AbandonRace
  inline void AbandonRace() { reinterpret_cast<void(__cdecl*)()>(0x6E5570)(); }
  // Game_BlowEngine
  inline void BlowEngine(ISimable* pTarget) { reinterpret_cast<void(__cdecl*)(ISimable*)>(0x6E5730)(pTarget); }
  // Game_ClearAIControl
  inline void ClearAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x6EA760)(_unk); }
  // Game_ForceAIControl
  inline void ForceAIControl(bool _unk = true) { reinterpret_cast<void(__cdecl*)(bool)>(0x6EA6F0)(_unk); }
  // Game_IsPracticeMode
  inline bool IsPracticeMode() { reinterpret_cast<bool(__cdecl*)()>(0x6DFAC0)(); }
  // Game_JumpToCarLot
  inline void JumpToCarLot() { reinterpret_cast<void(__cdecl*)()>(0x6DEE30)(); }
  // Game_JumpToSafehouse
  inline void JumpToSafehouse() { reinterpret_cast<void(__cdecl*)()>(0x6DEEA0)(); }
  // Game_KnockoutRacer
  inline void KnockoutRacer(ISimable* racer) { reinterpret_cast<void(__cdecl*)(ISimable*)>(0x6E99B0)(racer); }
  // Game_NavigatePlayerTo
  inline void NavigatePlayerTo(GRuntimeInstance* to, GTrigger* trigger) {
    reinterpret_cast<void(__cdecl*)(GRuntimeInstance*, GTrigger*)>(0x6DEF40)(to, trigger);
  }
  // Game_SabotageEngine
  inline void SabotageEngine(ISimable* pTarget, float durationInSeconds) {
    reinterpret_cast<void(__cdecl*)(ISimable*, float)>(0x6E5760)(pTarget, durationInSeconds);
  }
  // Game_SetAIGoal
  inline void SetAIGoal(ISimable* pTarget, const char* goal) {
    reinterpret_cast<void(__cdecl*)(ISimable*, const char*)>(0x6E5810)(pTarget, goal);
  }
  // Game_ShowPauseMenu
  inline void ShowPauseMenu() { reinterpret_cast<void(__cdecl*)()>(0x6DEBA0)(); }
  // Game_TotalRacer
  inline void TotalRacer(ISimable* racer) { KnockoutRacer(racer); }

  // custom hashing
  inline std::uint32_t bStringHash(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x436680)(cstring);
  }
  inline std::uint32_t bStringHashUpper(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x4366E0)(cstring);
  }

  // custom hashing for fe
  inline std::uint32_t FEHashUpper(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x6241D0)(cstring);
  }

  // uses 0xABCDEF00 magic
  inline std::uint32_t stringhash32(const char* cstring) {
    return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x465020)(cstring);
  }
}  // namespace NFSPluginSDK::ProStreet::Game

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GAME_H
