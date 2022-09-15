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

#ifndef OPENSPEED_GAME_MW05_TYPES_AUDIOSETTINGS_H
#define OPENSPEED_GAME_MW05_TYPES_AUDIOSETTINGS_H
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

    inline float GetMasteredSpeechVol() { return SpeechVol * MasterVol; }
    inline float GetMasteredFEMusicVol() { return FEMusicVol * MasterVol; }
    inline float GetMasteredIGMusicVol() { return IGMusicVol * MasterVol; }
    inline float GetMasteredSoundEffectsVol() { return SoundEffectsVol * MasterVol; }
    inline float GetMasteredEngineVol() { return EngineVol * MasterVol; }
    inline float GetMasteredCarVol() { return CarVol * MasterVol; }
    inline float GetMasteredAmbientVol() { return AmbientVol * MasterVol; }
    inline float GetMasteredSpeedVol() { return SpeedVol * MasterVol; }
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_AUDIOSETTINGS_H
