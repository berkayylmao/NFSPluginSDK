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

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/GTimer.h>

namespace OpenSpeed::MW05 {
  struct GRacerInfo {
    HSIMABLE__*    mhSimable;
    GCharacter*    mGameCharacter;
    const char*    mName;
    std::int32_t   mIndex;
    std::int32_t   mRanking;
    std::int32_t   mAiRanking;
    float          mPctRaceComplete;
    bool           mKnockedOut;
    bool           mTotalled;
    bool           mEngineBlown;
    bool           mBusted;
    bool           mChallengeComplete;
    bool           mFinishedRacing;
    bool           mCameraDetached;
    float          mPctLapComplete;
    std::int32_t   mLapsCompleted;
    std::int32_t   mCheckpointsHitThisLap;
    std::int32_t   mTollboothsCrossed;
    float          mTimeRemainingToBooth[16];
    std::int32_t   mSpeedTrapsCrossed;
    float          mSpeedTrapSpeed[16];
    std::int32_t   mSpeedTrapPosition[16];
    float          mDistToNextCheckpoint;
    float          mDistanceDriven;
    float          mTopSpeed;
    float          mFinishingSpeed;
    float          mPoundsNOSUsed;
    float          mTimeCrossedLastCheck;
    float          mTotalUpdateTime;
    std::int32_t   mNumPerfectShifts;
    std::int32_t   mNumTrafficCarsHit;
    float          mSpeedBreakerTime;
    float          mPointTotal;
    float          mZeroToSixtyTime;
    float          mQuarterMileTime;
    float          mSplitTimes[4];
    std::int32_t   mSplitRankings[4];
    GTimer         mRaceTimer;
    GTimer         mLapTimer;
    GTimer         mCheckTimer;
    UMath::Vector3 mSavedPosition;
    float          mSavedHeatLevel;
    UMath::Vector3 mSavedDirection;
    float          mSavedSpeed;
    bool           mDNF;
  };
}  // namespace OpenSpeed::MW05
