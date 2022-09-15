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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_GAMEPLAY_H
#define OPENSPEED_GAME_PROSTREET_TYPES_GAMEPLAY_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>

namespace OpenSpeed::ProStreet::Gameplay {
  struct GHubRecord {
    enum class ePlayMode : std::uint32_t { Solo, Split, Multiplayer };
    enum class eCarMode : std::uint32_t { Grip, Drift, Drag, Speed, Backup, Invalid };

    struct GEventRecord {
      std::uint32_t Key;
      std::uint32_t Laps;
      std::uint32_t Heats;
    };

    std::uint32_t mTrackKey;
    std::uint32_t mDifficulty;
    std::uint32_t mRepairMarkerCount;
    std::uint32_t mEventCount;
    GEventRecord  mEvents[8];
    char          mSaveName[32];
    ePlayMode     mPlayMode;
    std::int32_t  mIsShared;
    bool          mIsSaved;
    char          mGUID[21];
    std::uint32_t mPresetCars[5];
    eCarMode      mBackupCarMode;
    bool          mIsChallengeCustomHub;
    std::uint32_t mCreatorFeslID;
  };
}  // namespace OpenSpeed::ProStreet::Gameplay

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_GAMEPLAY_H
