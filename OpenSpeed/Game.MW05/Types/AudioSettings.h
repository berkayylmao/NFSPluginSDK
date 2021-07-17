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

namespace OpenSpeed::MW05 {
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

    float GetMasteredSpeechVol() { return SpeechVol * MasterVol; }
    float GetMasteredFEMusicVol() { return FEMusicVol * MasterVol; }
    float GetMasteredIGMusicVol() { return IGMusicVol * MasterVol; }
    float GetMasteredSoundEffectsVol() { return SoundEffectsVol * MasterVol; }
    float GetMasteredEngineVol() { return EngineVol * MasterVol; }
    float GetMasteredCarVol() { return CarVol * MasterVol; }
    float GetMasteredAmbientVol() { return AmbientVol * MasterVol; }
    float GetMasteredSpeedVol() { return SpeedVol * MasterVol; }
  };
}  // namespace OpenSpeed::MW05