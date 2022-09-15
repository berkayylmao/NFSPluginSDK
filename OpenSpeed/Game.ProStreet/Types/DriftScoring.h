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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_DRIFTSCORING_H
#define OPENSPEED_GAME_PROSTREET_TYPES_DRIFTSCORING_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DriftScoreReport.h>

namespace OpenSpeed::ProStreet {
  struct DriftScoring {
    bool                        mHitAWall;
    bool                        mDriftScoringEngaged;
    bool                        mFinalized;
    bool                        mInDriftSection;
    bool                        mWasDrifting;
    bool                        mWentOffTrack;
    bool                        mStayedOnTrackBonusAwarded;
    bool                        mNOSBonusAwarded;
    bool                        mNOSWasEngaged;
    bool                        mNOSTimerStarted;
    bool                        mHighSpeedBonusAwarded;
    std::int32_t                mCurrentSectionIndex;
    std::int32_t                mCurrentLapIndex;
    eDriftDirection             mDriftDirection;
    float                       mTimeSinceLastDirectionChange;
    float                       mCountDownAfterHitAWall;
    float                       mCountDownAfterSpanOut;
    float                       mTimeSinceDriftDisengaged;
    float                       mCurrentSectionEntryBonusMultiplier;
    float                       mTimeSinceNOSWasActivated;
    UMath::Vector3              mLastPosition;
    eastl::list<DriftChainInfo> mDriftChains;
    DriftScoreReport            mDriftScoreReport;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_DRIFTSCORING_H
