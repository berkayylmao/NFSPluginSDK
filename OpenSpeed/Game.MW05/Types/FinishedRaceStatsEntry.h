// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types/Timer.h>

namespace OpenSpeed::MW05 {
  struct FinishedRaceStatsEntry {
    std::int32_t FinishPosition;
    std::int32_t DriverNumber;
    std::int32_t FinishReason;
    Timer        RaceTime;
    Timer        BestLapTime;
    std::int32_t HandlingMode;
    float        TopSpeed;
    float        AverageSpeed;
    Timer        LapTimes[11];
    Timer        LapRunningTimes[11];
    std::int32_t NumLapsCompleted;
    float        NumLapsCompletedExact;
    std::int32_t PositionPerLap[8];
    std::int32_t NumLapsLead;
    float        Odometer;
    Timer        ZeroToSixtyTime;
    Timer        QuarterMileTime;
    float        QuarterMileSpeed;
    float        LongestJump;
    float        LongestPowerSlide;
    std::int32_t WasRecordBreaker;
  };
}  // namespace OpenSpeed::MW05
