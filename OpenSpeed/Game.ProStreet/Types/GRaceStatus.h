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
#include <OpenSpeed/Core/EASTL/EASTL/map.h>
#include <OpenSpeed/Core/EASTL/EASTL/vector.h>

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/GHurryUpTimer.h>
#include <OpenSpeed/Game.ProStreet/Types/GRaceBin.h>
#include <OpenSpeed/Game.ProStreet/Types/GRaceParameters.h>
#include <OpenSpeed/Game.ProStreet/Types/GRacerInfo.h>
#include <OpenSpeed/Game.ProStreet/Types/IVehicleCache.h>
#include <OpenSpeed/Game.ProStreet/Types/ISelectionSet.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct GRaceStatus : UTL::COM::Object, IVehicleCache, ISelectionSet {
    enum class eAdaptiveGainReason : std::uint32_t {
      FromEngineBlown,
      FromVehicleDestroyed,
      FromFinalizeRace,
      FromRacerKOed,
      FromRacerFinished,
      FromRestart
    };
    enum class PlayMode : std::uint32_t { Roaming, Racing };

    GRacerInfo                                                   mRacerInfo[8];
    GRacerInfo*                                                  mLazyRankingInfo[8];
    std::int32_t                                                 mRacerCount;
    eastl::vector<std::uint32_t>                                 mOpponents;
    float                                                        mRaceHandicap;
    bool                                                         mIsLoading;
    PlayMode                                                     mPlayMode;
    GRace::Context                                               mRaceContext;
    GRaceParameters*                                             mRaceParams;
    GRaceBin*                                                    mRaceBin;
    GTimer                                                       mRaceMasterTimer;
    bool                                                         mPlayerPursuitInCooldown;
    float                                                        mBonusTime;
    float                                                        mTaskTime;
    bool                                                         mSuddenDeathMode;
    bool                                                         mTimeExpiredMsgSent;
    bool                                                         mActivelyRacing;
    std::int32_t                                                 mLastSecondTickSent;
    WorldModel*                                                  mCheckpointModel;
    AcidEffect*                                                  mCheckpointEmitter;
    bool                                                         mQueueBinChange;
    std::uint32_t                                                mWarpWhenInFreeRoam;
    std::int32_t                                                 mNumTimeBonusCheckpoints;
    bool                                                         mScriptWaitingForLoad;
    bool                                                         mRefreshBinAfterRace;
    bool                                                         mWaitForMusicTransition;
    eastl::vector<GTrigger*>                                     mCheckpoints;
    GTrigger*                                                    mNextCheckpoint;
    GTrigger*                                                    mEncounterFinish;
    std::int32_t                                                 mNumRaceSegments;
    float                                                        mLapTimes[10][8];
    float                                                        mCheckTimes[10][16][8];
    float                                                        mSegmentLengths[18];
    float                                                        fRaceLength;
    float                                                        fFirstLapLength;
    float                                                        fSubsequentLapLength;
    eastl::map<std::uint16_t, float, eastl::less<std::uint16_t>> mRaceDistanceMap;
    unsigned char                                                _pad[4];
    std::int8_t                                                  mRevealedShortcuts[32];
    std::int16_t                                                 mSideRoutes[32];
    std::int8_t                                                  mSlowcuts[32];
    std::int32_t                                                 mShortcutPairs[32];
    std::int8_t                                                  mShortcutsExitSegmentReachedByActivatedPathy[32];
    std::int8_t                                                  mShortcutsExittedByActivatedPathy[32];
    std::int32_t                                                 mIndexOfLastShortcutInRace;
    bool                                                         mCalculatedAdaptiveGain;
    float                                                        fCatchUpIntegral;
    float                                                        fCatchUpDerivative;
    float                                                        fCatchUpAdaptiveBonus;
    float                                                        fAveragePercentComplete;
    std::int32_t                                                 nCatchUpSkillEntries;
    float                                                        aCatchUpSkillData[11];
    std::int32_t                                                 nCatchUpSpreadEntries;
    float                                                        aCatchUpSpreadData[11];
    std::int32_t                                                 nSpeedTraps;
    GTrigger*                                                    aSpeedTraps[16];
    float                                                        mStartTimeOfBestLap;
    bool                                                         mVehicleCacheLocked;
    GRace::RaceRouteFlags                                        mRaceRouteFlags;
    eTrafficDensity                                              mTrafficDensity;
    std::uint32_t                                                mTrafficPattern;
    bool                                                         mHasBeenWon;
    UMath::Vector3                                               mSavedEngagePos;
    std::uint32_t                                                mFinishFlareState;
    bool                                                         mRestartAllowed;
    bool                                                         mStatsArbitrating;
    GTimer                                                       mFreeRoamTimer;
    GHurryUpTimer                                                mHurryUpTimer;
    std::uint32_t                                                mSectorOwner[4];
    float                                                        mSectorTime[4];
    float                                                        mSectorBestPoints[4];
    float                                                        mSectorDistance[4];
    std::uint32_t                                                mNumSectors;
    bool                                                         mSkippedPartOfRace;
    bool                                                         mMultiClassDidSetup;
    float                                                        mMultiClassSecondGroupDelay;
    bool(__cdecl* mRankingFuncs[11])(GRacerInfo*, GRacerInfo*);
    GRace::Type mRecentRaceType;

    virtual ~GRaceStatus();
    virtual const char*         GetCacheName() override;
    virtual eVehicleCacheResult OnQueryVehicleCache(const IVehicle*      removethis,
                                                    const IVehicleCache* whosasking) override;
    virtual void                OnRemovedVehicleCache(IVehicle* ivehicle) override;
    virtual void GetEnabledSelectionSets(GPresentationController&, eastl::list<std::uint32_t>&, bool) override;

    static GRaceStatus* Get() {
      static GRaceStatus** g_This = reinterpret_cast<GRaceStatus**>(0xAB9D7C);
      if (!g_This) return nullptr;

      return *g_This;
    }
  };
}  // namespace OpenSpeed::ProStreet
