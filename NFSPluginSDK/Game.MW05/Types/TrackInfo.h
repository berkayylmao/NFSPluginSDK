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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_TRACKINFO_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_TRACKINFO_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05 {
  struct TrackInfo {
    char             Name[32];
    char             TrackDirectory[32];
    char             RegionName[8];
    char             RegionDirectory[32];
    std::int32_t     LocationNumber;
    char             LocationDirectory[16];
    eLocationName    LocationName;
    eDriftType       DriftType;
    bool             IsValid;
    bool             Point2Point;
    bool             ReverseVersionExists;
    bool             Unused;
    bool             IsPerformanceTuning;
    std::int16_t     TrackNumber;
    std::int16_t     SameAsTrackNumber;
    std::uint32_t    SunInfoNameHash;
    std::uint32_t    UsageFlags;
    std::uint32_t    TrackLength;
    float            TimeToBeatForwards_ms;
    float            TimeToBeatReverse_ms;
    std::int32_t     ScoreToBeatForwards_DriftOnly;
    std::int32_t     ScoreToBeatReverse_DriftOnly;
    bVector2         TrackMapCalibrationUpperLeft;
    float            TrackMapCalibrationMapWidthMetres;
    std::uint16_t    TrackMapCalibrationRotation;
    std::uint16_t    TrackMapStartLineAngle;
    std::uint16_t    TrackMapFinishLineAngle;
    float            TrackMapZoomFactor;
    eTrackDifficulty ForwardDifficulty;
    eTrackDifficulty ReverseDifficulty;
    std::int16_t     OverrideStartingRouteForAI[2][4];
    std::int16_t     NumSecondsBeforeShortcutsAllowed;
    std::int16_t     nDriftSecondsMin;
    std::int16_t     nDriftSecondsMax;
    std::int16_t     pad2[1];
    std::int8_t      MaxTrafficCars[4][2];
    std::int8_t      TrafficAllowedNearStartLine[2];
    char             CarRaceStartConfig;
    char             padbyte;
    float            TrafficMinInitialDistanceFromStartLine[2];
    float            TrafficMinInitialDistanceBetweenCars[2];
    float            TrafficOncomingFraction[4];
    Math::Vector2    TrackMapZoomTopLeft;
    float            TrackMapZoomWidth;
    bool             TrackMapStartZoomed;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_TRACKINFO_H
