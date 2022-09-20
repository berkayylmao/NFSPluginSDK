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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_TIMEOFDAY_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_TIMEOFDAY_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>

namespace NFSPluginSDK::Carbon {
  struct TimeOfDay {
    float        mUpdateRate;
    std::int32_t mUpdateDirection;
    float        mCurrentTimeOfDay;
    float        mSunAzimuth;
    float        mSunLatitude;

    static inline TimeOfDay** g_ppInstance = reinterpret_cast<TimeOfDay**>(0xB77F34);
    static TimeOfDay*         GetInstance() {
              if (g_ppInstance && *g_ppInstance) return *g_ppInstance;

      return nullptr;
    }
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_TIMEOFDAY_H
