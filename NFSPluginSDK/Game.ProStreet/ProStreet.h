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
  inline MemoryFieldWrapper<bool>           CarGuysForceLODS{0xBFBC43, false};
  inline MemoryFieldWrapper<std::uint32_t*> CarPartTypeNameHashTable{0xAEB774, nullptr};
  inline MemoryFieldWrapper<Math::Matrix4>  CarScaleMatrix{0xAEE180, Math::Matrix4()};
  inline MemoryFieldWrapper<bool>           DisableTotalledState{0xAB9DCD, false};
  inline MemoryFieldWrapper<bool>           DrawCars{0xA79CDC, true};
  inline MemoryFieldWrapper<bool>           EnableEnvMap{0xA61884, true};
  inline MemoryFieldWrapper<CARPART_LOD>    ForceCarLOD{0xA79D7C, CARPART_LOD::A};
  inline MemoryFieldWrapper<bool>           ForceCarLODPrint{0xAEB6E2, false};
  inline MemoryFieldWrapper<CARPART_LOD>    ForceTireLOD{0xA79D80, CARPART_LOD::A};
  inline MemoryFieldWrapper<bool>           IsGameplayPaused{0xAB0EDC, false};
  inline MemoryFieldWrapper<bool>           IsRacing{0xAACF5F, false};
  inline MemoryFieldWrapper<float>          RealTimeElapsed{0xABB048, 0.0f};
  inline MemoryFieldWrapper<bool>           RearViewModel{0xAEB728, false};
  inline MemoryFieldWrapper<bool>           ShowAllCarsInFE{0xBFBC6E, false};
  inline MemoryFieldWrapper<bool>           ShowCarLODScreenPrint{0xAEB6E0, false};
  inline MemoryFieldWrapper<bool>           SkipCareerIntro{0xBFBC6C, false};
  inline MemoryFieldWrapper<bool>           SkipFE{0xBFBC08, false};
  inline MemoryFieldWrapper<GameFlowState>  TheGameFlowManager{0xABB510, GameFlowState::InFrontEnd};
  inline MemoryFieldWrapper<bool>           TrannyOnAllCars{0xAB09B8, false};
  inline MemoryFieldWrapper<float>          Tweak_GameBreakerCollisionMass{0xA9B678, 2.0f, FLT_MIN, FLT_MAX};
  inline MemoryFieldWrapper<bool>           UnlockAllThings{0xBFBC5B, false};
}  // namespace NFSPluginSDK::ProStreet::Variables

#endif  // NFSPLUGINSDK_GAME_PROSTREET_PROSTREET_H
