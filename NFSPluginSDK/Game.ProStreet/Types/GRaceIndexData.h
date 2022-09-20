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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEINDEXDATA_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEINDEXDATA_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet {
  struct GRaceIndexData {
    std::uint32_t mKey;
    char          mEventID[10];
    std::uint32_t mRaceHash;
    std::uint32_t mFlags;
    float         mLength;
    std::int16_t  mLocalizationTag;
    float16       mCash;
    std::uint16_t mRivalBest;  // 16-bit 10.2 fixed point
    std::int8_t   mNumLaps;
    GRace::Type   mRaceType;
    std::int8_t   mNumHeats;
    std::uint32_t mPlayerCarTypeHash;
    float         mTrackRecord;
    std::uint32_t mTrack;
    std::uint32_t mTrackLayout;
    std::uint32_t mParentKey;
    std::uint32_t mTrackRecordHolder;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEINDEXDATA_H
