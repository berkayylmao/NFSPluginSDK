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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_PROSTREET_H
#define NFSPLUGINSDK_GAME_PROSTREET_PROSTREET_H
#pragma once

#include <NFSPluginSDK/Core/MemoryFieldWrapper.hpp>
#include <NFSPluginSDK/Game.ProStreet/_IncludeAllTypes.h>

namespace NFSPluginSDK::ProStreet::Variables {
  static inline MemoryFieldWrapper<bool>           CarGuysForceLODS{0xBFBC43, false};
  static inline MemoryFieldWrapper<std::uint32_t*> CarPartTypeNameHashTable{0xAEB774, nullptr};
  static inline MemoryFieldWrapper<Math::Matrix4>  CarScaleMatrix{0xAEE180, Math::Matrix4()};
  static inline MemoryFieldWrapper<bool>           DrawCars{0xA79CDC, true};
  static inline MemoryFieldWrapper<bool>           EnableEnvMap{0xA61884, true};
  static inline MemoryFieldWrapper<CARPART_LOD>    ForceCarLOD{0xA79D7C, CARPART_LOD::A};
  static inline MemoryFieldWrapper<bool>           ForceCarLODPrint{0xAEB6E2, false};
  static inline MemoryFieldWrapper<CARPART_LOD>    ForceTireLOD{0xA79D80, CARPART_LOD::A};
  static inline MemoryFieldWrapper<bool>           IsGameplayPaused{0xAB0EDC, false};
  static inline MemoryFieldWrapper<bool>           IsRacing{0xAACF5F, false};
  static inline MemoryFieldWrapper<float>          RealTimeElapsed{0xABB048, 0.0f};
  static inline MemoryFieldWrapper<bool>           RearViewModel{0xAEB728, false};
  static inline MemoryFieldWrapper<bool>           ShowAllCarsInFE{0xBFBC6E, false};
  static inline MemoryFieldWrapper<bool>           ShowCarLODScreenPrint{0xAEB6E0, false};
  static inline MemoryFieldWrapper<bool>           SkipCareerIntro{0xBFBC6C, false};
  static inline MemoryFieldWrapper<bool>           SkipFE{0xBFBC08, false};
  static inline MemoryFieldWrapper<GameFlowState>  TheGameFlowManager{0xABB510, GameFlowState::InFrontEnd};
  static inline MemoryFieldWrapper<float>          Tweak_GameBreakerCollisionMass{0xA9B678, 2.0f, FLT_MIN, FLT_MAX};
  static inline MemoryFieldWrapper<bool>           UnlockAllThings{0xBFBC5B, false};
}  // namespace NFSPluginSDK::ProStreet::Variables

#endif  // NFSPLUGINSDK_GAME_PROSTREET_PROSTREET_H
