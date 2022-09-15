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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FESTATS_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FESTATS_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/EA.h>

namespace OpenSpeed::ProStreet {
  struct FEStats : EA::Memcard::IMemcardSavable {
    float mTimeInCareer;
    float mNumberOfCareerGames;
    float mCareerTotalledCount;
    float mNumberOfCareerWins;
    float mGripRaces;
    float mGripWins;
    float mDriftpRaces;
    float mDriftpWins;
    float mDragRaces;
    float mDragWins;
    float mSpeedRaces;
    float mSpeedWins;
    float mCareerStarted;
    float mMapSeen;
    float mHasSavedOnce;
    float mProfileStatTest;
    float mCareerRaceDayMapSeen;
    float mRaceDayRankedWarningSeen;
    float mRaceDayUnrankedWarningSeen;
    float mProfileTunerLeaderboardSeen;

    static FEStats* Get() {
      static FEStats** ppinstance = reinterpret_cast<FEStats**>(0xAB0EBC);
      if (!ppinstance) return nullptr;

      return *ppinstance;
    }
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FESTATS_H
