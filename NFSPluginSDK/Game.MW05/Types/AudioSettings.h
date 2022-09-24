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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AUDIOSETTINGS_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AUDIOSETTINGS_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05 {
  struct AudioSettings {
    float        MasterVol;
    float        SpeechVol;
    float        FEMusicVol;
    float        IGMusicVol;
    float        SoundEffectsVol;
    float        EngineVol;
    float        CarVol;
    float        AmbientVol;
    float        SpeedVol;
    std::int32_t AudioMode;
    std::int32_t InteractiveMusicMode;
    std::int32_t EATraxMode;
    std::int32_t PlayState;

    inline float GetMasteredSpeechVol() { return SpeechVol * MasterVol; }
    inline float GetMasteredFEMusicVol() { return FEMusicVol * MasterVol; }
    inline float GetMasteredIGMusicVol() { return IGMusicVol * MasterVol; }
    inline float GetMasteredSoundEffectsVol() { return SoundEffectsVol * MasterVol; }
    inline float GetMasteredEngineVol() { return EngineVol * MasterVol; }
    inline float GetMasteredCarVol() { return CarVol * MasterVol; }
    inline float GetMasteredAmbientVol() { return AmbientVol * MasterVol; }
    inline float GetMasteredSpeedVol() { return SpeedVol * MasterVol; }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AUDIOSETTINGS_H
