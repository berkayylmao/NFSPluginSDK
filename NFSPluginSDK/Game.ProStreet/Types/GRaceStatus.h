// clang-format off
//
//    BSD 3-Clause License
//    Copyright (c) 2022, Berkay Yigit (berkayylmao) <mail@berkay.link>
//    All rights reserved.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    You should have received a copy of the BSD 3-Clause License along with
//    this program. If not, see <https://opensource.org/licenses/BSD-3-Clause/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACESTATUS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACESTATUS_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GHurryUpTimer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GRaceBin.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GRaceParameters.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GRacerInfo.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IVehicleCache.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ISelectionSet.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
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

    std::array<GRacerInfo, 8>                                    mRacerInfo;
    std::array<GRacerInfo*, 8>                                   mLazyRankingInfo;
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
      static GRaceStatus** fObj = reinterpret_cast<GRaceStatus**>(0xAB9D7C);
      return *fObj;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACESTATUS_H
