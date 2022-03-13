// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types/CareerSettings.h>
#include <OpenSpeed/Game.MW05/Types/FEPlayerCarDB.h>
#include <OpenSpeed/Game.MW05/Types/HighScoresDatabase.h>
#include <OpenSpeed/Game.MW05/Types/JukeboxEntry.h>
#include <OpenSpeed/Game.MW05/Types/OptionsSettings.h>

namespace OpenSpeed::MW05 {
  struct UserProfile {
    char               m_aProfileName[32];
    bool               m_bNamed;
    OptionsSettings    TheOptionsSettings;
    CareerSettings     TheCareerSettings;
    JukeboxEntry       Playlist[30];
    FEPlayerCarDB      PlayersCarStable;
    bool               CareerModeHasBeenCompletedAtLeastOnce;
    HighScoresDatabase HighScores;

    OptionsSettings*    GetOptions() { return &TheOptionsSettings; }
    CareerSettings*     GetCareer() { return &TheCareerSettings; }
    HighScoresDatabase* GetHighScores() { return &HighScores; }
    void                SetProfileNamed(bool isNamed) { m_bNamed = isNamed; }
  };
}  // namespace OpenSpeed::MW05