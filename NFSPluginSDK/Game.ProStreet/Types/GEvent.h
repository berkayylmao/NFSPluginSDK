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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GEVENT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GEVENT_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/sort.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GRacerInfo.h>

namespace NFSPluginSDK::ProStreet {
  struct GEvent {
    GActivity*                                                                          mEventActivity;
    eastl::vector<std::uint32_t>                                                        mOpponents;
    eastl::map<std::uint32_t, GRacerInfo::GRacerHeatStats*, eastl::less<std::uint32_t>> mOpponentStats;
    unsigned char                                                                       __pad1[4];
    eastl::map<std::uint32_t, GRacerInfo::GRacerPoints*, eastl::less<std::uint32_t>>    mOpponentPoints;
    unsigned char                                                                       __pad2[4];
    GRacerInfo::GRacerHeatStats                                                         mHeatStats[8][4];
    GRacerInfo::GRacerPoints                                                            mPoints[8];
    std::int32_t                                                                        mNumHeats;
    std::int32_t                                                                        mCurrentHeat;
    bool                                                                                mAscending;

    void AssignGridNumbersBasedOnPerformance() { reinterpret_cast<void(__thiscall*)(GEvent*)>(0x68B5D0)(this); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GEVENT_H
