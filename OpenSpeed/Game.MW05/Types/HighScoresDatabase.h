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

#ifndef OPENSPEED_GAME_MW05_TYPES_HIGHSCORESDATABASE_H
#define OPENSPEED_GAME_MW05_TYPES_HIGHSCORESDATABASE_H
#pragma once

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/CareerPursuitScores.h>
#include <OpenSpeed/Game.MW05/Types/CostToStateScores.h>
#include <OpenSpeed/Game.MW05/Types/PursuitScore.h>
#include <OpenSpeed/Game.MW05/Types/RaceTypeHighScores.h>
#include <OpenSpeed/Game.MW05/Types/TopEvadedPursuitDetail.h>
#include <OpenSpeed/Game.MW05/Types/TrackHighScore.h>

namespace OpenSpeed::MW05 {
  struct HighScoresDatabase {
    TrackHighScore         TrackHighScoreTable[320];
    float                  TotalOdometer;
    std::int32_t           TotalStarts;
    std::int32_t           TotalWins;
    std::int32_t           TotalLosses;
    RaceTypeHighScores     RaceTypeScores[2];
    RaceTypeHighScores     SplitScreenScores;
    std::int32_t           TotalDragTotalled;
    TopEvadedPursuitDetail TopEvadedPursuitScores[5];
    CareerPursuitScores    CareerPursuitDetails;
    PursuitScore           BestPursuitRankings[10];
    CostToStateScores      CostToStateDetails;
    std::uint32_t          PreviouslyPursuedCarFEKey;
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_HIGHSCORESDATABASE_H
