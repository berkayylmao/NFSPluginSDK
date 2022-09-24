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

#ifndef NFSPLUGINSDK_GAME_CARBON_CARBON_H
#define NFSPLUGINSDK_GAME_CARBON_CARBON_H
#pragma once

#include <NFSPluginSDK/Core/MemoryFieldWrapper.hpp>
#include <NFSPluginSDK/Game.Carbon/_IncludeAllTypes.h>

namespace NFSPluginSDK::Carbon::Variables {
  static MemoryFieldWrapper<Math::Matrix4>  CarScaleMatrix{0xB778D0, Math::Matrix4()};
  static MemoryFieldWrapper<bool>           DrawCars{0xA73008, true};
  static MemoryFieldWrapper<bool>           DrawCarsReflections{0xA7300C, true};
  static MemoryFieldWrapper<bool>           DrawCarShadow{0xA73010, true};
  static MemoryFieldWrapper<bool>           DrawLightFlares{0xA6C088, true};
  static MemoryFieldWrapper<float>          FogCurrentBrightness{0xA650E0, 1.0f, 0.5f, 18.0f};
  static MemoryFieldWrapper<CARPART_LOD>    ForceCarLOD{0xA7309C, CARPART_LOD::A};
  static MemoryFieldWrapper<CARPART_LOD>    ForceTireLOD{0xA730A0, CARPART_LOD::A};
  static MemoryFieldWrapper<bool>           IsGameplayPaused{0xA8AD18, false};
  static MemoryFieldWrapper<bool>           IsInNIS{0xB42EBC, false};
  static MemoryFieldWrapper<std::uint16_t>  NOSFOVWidening{0xA8AB60, 0x666, 0x001, 0x3500};
  static MemoryFieldWrapper<ePrecullerMode> PrecullerMode{0xA72C28, ePrecullerMode::On};
  static MemoryFieldWrapper<bool>           StopUpdatingCamera{0xA888D8, false};
  static MemoryFieldWrapper<AICopManager*>  TheOneCopManager{0xA83A58, nullptr};
  static MemoryFieldWrapper<GameFlowState>  TheGameFlowManager{0xA99BBC, GameFlowState::InFrontEnd};
  static MemoryFieldWrapper<float>          Tweak_GameBreakerCollisionMass{0xA71278, 2.0f, FLT_MIN, FLT_MAX};
  static MemoryFieldWrapper<float>          Tweak_GameSpeed{0xA712AC, 1.0f, FLT_MIN, FLT_MAX};
  static MemoryFieldWrapper<bool>           Tweak_InfiniteRaceBreaker{0xB4D86C, false};
  static MemoryFieldWrapper<bool>           Tweak_PauseCameraLock{0xA995CC, false};
  static MemoryFieldWrapper<bool>           Tweak_TrafficStopSpawning{0xA83A4C, false};
  static MemoryFieldWrapper<bool>           WindowHasLostFocus{0xAB0B3C, false};
}  // namespace NFSPluginSDK::Carbon::Variables

#endif  // NFSPLUGINSDK_GAME_CARBON_CARBON_H
