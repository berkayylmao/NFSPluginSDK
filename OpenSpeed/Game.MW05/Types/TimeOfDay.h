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

#ifndef OPENSPEED_GAME_MW05_TYPES_TIMEOFDAY_H
#define OPENSPEED_GAME_MW05_TYPES_TIMEOFDAY_H
#pragma once

#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05 {
  struct TimeOfDay {
    float        mUpdateRate;
    std::int32_t mUpdateDirection;
    float        mCurrentTimeOfDay;
    float        mSunAzimuth;
    float        mSunLatitude;

    static TimeOfDay* GetInstance() {
      static TimeOfDay** ppInstance = reinterpret_cast<TimeOfDay**>(0x9B392C);
      if (ppInstance) return *ppInstance;

      return nullptr;
    }

    TimeOfDay() :
        mUpdateRate(1.0f), mUpdateDirection(1), mCurrentTimeOfDay(0.0f), mSunAzimuth(0.0f), mSunLatitude(0.0f) {}
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_TIMEOFDAY_H
