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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::Physics {
  struct Tunings {
    enum class Path { Steering, Handling, Brakes, RideHeight, Aerodynamics, NOS, Induction };

    float mSteering;
    float mHandling;
    float mBrakes;
    float mRideHeight;
    float mAerodynamics;
    float mNOS;
    float mInduction;

    explicit Tunings() :
        mSteering(0.0f),
        mHandling(0.0f),
        mBrakes(0.0f),
        mRideHeight(0.0f),
        mAerodynamics(0.0f),
        mNOS(0.0f),
        mInduction(0.0f) {}
    explicit Tunings(float steering, float handling, float brakes, float rideHeight, float aerodynamics, float nos,
                     float induction) :
        mSteering(steering),
        mHandling(handling),
        mBrakes(brakes),
        mRideHeight(rideHeight),
        mAerodynamics(aerodynamics),
        mNOS(nos),
        mInduction(induction) {}

    static inline const float g_GameDisplayMultiplier = 5.0f;
  };

  namespace Info {
    struct AbsolutePerformanceStats {
      float performanceTypeMap[47];
    };
    struct PerformanceLevels {
      float performanceTypeMap[47];
    };

    struct Performance {
      AbsolutePerformanceStats absolutePerformanceStats;
      PerformanceLevels        performanceLevels;
      BluePrintType            bluePrintType;
    };

    struct PerformanceMatching {
      ePerformanceType performanceType;
      bool             isPerformanceLevel;
      float            performanceValue;
    };

    struct CorrectedPerformance {
      AbsolutePerformanceStats absolutePerformanceStats;
      PerformanceLevels        performanceLevels;
      Performance              stockMeasuredPerformance;
      Performance              highendMeasuredPerformance;
      BluePrintType            bluePrintType;
      Performance              stockFastPerformance;
      Performance              highendFastPerformance;
    };
  }  // namespace Info

  namespace Upgrades {
    struct Part {
      std::int32_t mLevel;
      std::int32_t mOptions;
    };

    struct Package {
      Part mTires;
      Part mBrakes;
      Part mChassis;
      Part mTransmission;
      Part mEngine;
      Part mInduction;
      Part mNOS;
    };

    struct Tuning {
      float lowerBound;
      float upperBound;
      float position;
    };
  };  // namespace Upgrades
}  // namespace NFSPluginSDK::ProStreet::Physics

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICS_H
