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
#include <OpenSpeed/Game.MW05/Types/Timer.h>

namespace OpenSpeed::MW05 {
  struct RaceParameters {
    enum class RaceTypes : std::uint8_t {
      None,
      SingleRace,
      TimeTrial,
      LapKnockout,
      RaceRnockout,
      Tournament,
      CarShow,
      GetAway
    };

    std::int32_t          TrackNumber;
    eTrackDirection       TrackDirection;
    eTrafficDensity       TrafficDensity;
    float                 TrafficOncoming;
    bool                  AIDemoMode;
    bool                  ReplayDemoMode;
    RaceTypes             RaceType;
    std::int32_t          Point2Point;
    float                 RollingStartSpeed;
    std::int32_t          NumLapsInRace;
    std::int32_t          NumPlayerCars;
    std::int32_t          NumAICars;
    std::int32_t          NumOnlinePlayerCars;
    std::int32_t          NumOnlineAICars;
    std::int8_t           PlayerStartPosition[2];
    bool                  DamageEnabled;
    eHandlingMode         HandlingMode;
    std::int32_t          FinishLineNumber;
    bool                  bDragRaceFlag;
    bool                  bDriftRaceFlag;
    bool                  bBurnoutFlag;
    bool                  bShortRaceFlag;
    bool                  bOnlineRace;
    bool                  bCarShowFlag;
    bool                  bGamebreakerOn;
    std::int32_t          PlayerJoyports[2];
    std::int32_t          nMaxCops;
    eOpponentStrength     CopStrength;
    float                 DriftOpponentScoreMultiplier;
    eOpponentStrength     OpponentStrength;
    std::int32_t          Boost;
    float                 BoostScale[2];
    eAIDifficultyModifier AIDifficultyModifier;
    std::int32_t          PlayerDriverNumber[2];
    std::int32_t          NumDriverInfo;
    Timer                 TimeTrialTime;
    bool                  bCareerEventRace;
  };
}  // namespace OpenSpeed::MW05