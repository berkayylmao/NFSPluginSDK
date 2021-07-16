// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Math.h>

namespace OpenSpeed::MW05 {
  struct TimeOfDay {
    float         mSkyboxSpeedMultiplier;
    std::int32_t  mTimeOfDaySpeedMultiplier;
    float         mTimeOfDayValue;
    Math::Vector2 mSunOrbitAxis;

    void operator=(const TimeOfDay& rhs) {
      mSkyboxSpeedMultiplier    = rhs.mSkyboxSpeedMultiplier;
      mTimeOfDaySpeedMultiplier = rhs.mTimeOfDaySpeedMultiplier;
      mTimeOfDayValue           = rhs.mTimeOfDayValue;
      mSunOrbitAxis.x           = rhs.mSunOrbitAxis.x;
      mSunOrbitAxis.y           = rhs.mSunOrbitAxis.y;
    }

    static inline TimeOfDay** g_ppInstance = reinterpret_cast<TimeOfDay**>(0x9B392C);
    static TimeOfDay*         GetInstance() {
      if (g_ppInstance && *g_ppInstance) return *g_ppInstance;

      return nullptr;
    }
  };
}  // namespace OpenSpeed::MW05
