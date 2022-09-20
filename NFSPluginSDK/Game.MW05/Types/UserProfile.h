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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_USERPROFILE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_USERPROFILE_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/CareerSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/FEPlayerCarDB.h>
#include <NFSPluginSDK/Game.MW05/Types/HighScoresDatabase.h>
#include <NFSPluginSDK/Game.MW05/Types/JukeboxEntry.h>
#include <NFSPluginSDK/Game.MW05/Types/OptionsSettings.h>

namespace NFSPluginSDK::MW05 {
  struct UserProfile {
    char               m_aProfileName[32];
    bool               m_bNamed;
    OptionsSettings    mTheOptionsSettings;
    CareerSettings     mTheCareerSettings;
    JukeboxEntry       mPlaylist[30];
    FEPlayerCarDB      mPlayersCarStable;
    bool               mCareerModeHasBeenCompletedAtLeastOnce;
    HighScoresDatabase mHighScores;

    inline OptionsSettings&    GetOptions() { return mTheOptionsSettings; }
    inline CareerSettings&     GetCareer() { return mTheCareerSettings; }
    inline HighScoresDatabase& GetHighScores() { return mHighScores; }
    inline void                SetProfileNamed(bool isNamed) { m_bNamed = isNamed; }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_USERPROFILE_H
