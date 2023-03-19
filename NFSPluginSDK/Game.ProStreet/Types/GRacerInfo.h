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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACERINFO_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACERINFO_H
#pragma once

#ifdef _WIN32
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DriftScoring.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GCallbackTimer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GIOpponent.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GTimer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Timeline.h>

namespace NFSPluginSDK::ProStreet {
  struct GRacerInfo : GElapsedCallback {
    enum class FinishReason : std::uint32_t {
      Unknown,
      Completed          = 2,
      CrossedFinish      = 6,
      DidNotFinish       = 10,
      KnockedOut         = 26,
      Totalled           = 42,
      EngineBlown        = 74,
      Busted             = 138,
      ChallengeCompleted = 258,
      Disconnected       = 522,
      FalseStart         = 1034
    };
    enum class RacerStateFlag : std::uint32_t {
      ClearAll,
      DisableCountdown = 1 << 1,
      CameraDetached   = 1 << 8,
      ControllingAI    = 1 << 11,
      StartedRace      = 1 << 12,
      RaceInit         = StartedRace
    };
    enum class RecordingState : std::uint32_t { Reset, Recording, Done };
    enum class State : std::uint32_t {
      None,
      Initial,
      NIS,
      PreStaging,
      Staging,
      PostStaging,
      Handicap,
      Countdown,
      Racing,
      RaceOver,
      Spectate,
      Done
    };
    enum class Type : std::uint32_t { None, Human, Artificial };

    struct GArbitratedRacerStats {
      FinishReason mFinishReason;
      float        mPointTotal;
      float        mRaceTime;
      std::int32_t mLapsCompleted;
      float        mTopSpeed;
      float        mAvgSpeed;
      float        mBestLapTime;
      float        mPoundsNOSUsed;
      float        mBestSectorPoints;
      float        mCheckpointTopSpeeds[16];
      float        mRaceResult;
      float        mAccumulatedCheckpointSpeeds;
      float        mDragWheelieDistance;
    };
    struct GLocalRacerStats {
      float         mPctRaceComplete;
      float         mPctLapComplete;
      float         mPctRaceCompleteHighWaterMark;
      std::int32_t  mCheckpointsHitThisLap;
      float         mTimeRemainingToBooth[16];
      float         mDistToNextCheckpoint;
      float         mDistanceDriven;
      float         mDeltaXP;
      float         mTimeFacingWrongWay;
      float         mPercentTimes[100];
      float         mFinishedBackwards;
      std::int32_t  mSkillLevel;
      float         mCurrentAirTime;
      float         mLastLapTime;
      float         mTimeCrossedLastCheck;
      float         mTotalUpdateTime;
      float         mHandicap;
      float         mDriftFactor;
      bool          mDominatedSectorShootout;
      std::int32_t  mSpeedTrapsCrossed;
      float         mSpeedTrapSpeed[16];
      std::int32_t  mSpeedTrapPosition[16];
      float         mFinishingSpeed;
      std::int32_t  mNumPerfectShifts;
      std::int32_t  mNumTrafficCarsHit;
      float         mSpeedBreakerTime;
      float         mZeroToSixtyTime;
      float         mZeroToHundredTime;
      float         mSeventyToHundredFiftyTime;
      float         mSixtyFeetTime;
      float         mQuarterMileTime;
      float         mEighthMileTime;
      float         mReactionTime;
      float         mSplitTimes[4];
      std::int32_t  mSplitRankings[4];
      float         mLongestAirTime;
      std::int32_t  mTollboothsCrossed;
      std::int32_t  mNumRaceBreakersActivated;
      std::uint32_t mRacerGroup;
      float         mLastRollOverTime;
      std::int32_t  mPotentialTargetPoints;
      float         mDistanceToStartLine;
      float         mSectorDynamicTargetTime[4];
    };
    struct GRacerStats {
      GArbitratedRacerStats arbitrated;
      GLocalRacerStats      local;
    };
    struct GRacerHeatStats {
      std::int32_t mRanking;
      std::int32_t mPlayerIndex;
      float        mResult;
      float        mPoints;
      float        mRaceTime;
      FinishReason mReason;
    };
    struct GRacerPoints {
      std::int32_t mRankingPoints;
      std::int32_t mDamagePoints;
      std::int32_t mEventBonus;
    };

    State          mState;
    RacerStateFlag mFlags;
    GIOpponent*    mOpponent;
    HSIMABLE__*    mhSimable;
    GCharacter*    mGameCharacter;
    char           mName[32];
    char           mGroupName[32];
    std::int32_t   mIndex;
    std::int32_t   mRanking;
    std::int32_t   mRankChange;
    std::int32_t   mAiRanking;
    GRacerStats    mStats;
    GTimer         mRaceTimer;
    GTimer         mLapTimer;
    GTimer         mCheckTimer;
    GTimer         mCrashTimer;
    GTimer         mSectorTimer;
    GCallbackTimer mTimers[1];
    float          mSectorTargetTime;
    RecordingState mRecording70To150;
    float          mCurrent70To150;
    unsigned char  _pad1[8];
    UMath::Vector3 mSavedPosition;
    float          mSavedHeatLevel;
    UMath::Vector3 mSavedDirection;
    float          mSavedSpeed;
    UMath::Vector3 mCrashPosition;
    unsigned char  _pad2[4];
    UMath::Vector3 mCrashDirection;
    bool           mPlayerLapGhostCars;
    bool           mCarIsInWheelie;
    bool           mCarHasWheelied;
    UMath::Vector3 mDragWheelieLastPosition;
    float          mDragDistanceWheelied;
    DriftScoring   mDriftScoring;
    Timeline*      mRecordTimeline;
    Timeline*      mPlaybackTimelines[7];
    bool           mOffRoad;
    unsigned char  _pad3[11];
    UMath::Vector3 mLastOnRoadPosition;
    unsigned char  _pad4[4];
    UMath::Vector3 mLastOnRoadDirection;
    float          mFirstLapTimeEstimate;
    float          mSubsequentLapTimesEstimate;

    virtual void Elapsed(GCallbackTimer* pTimer) override {
      reinterpret_cast<void(__thiscall*)(GRacerInfo*, GCallbackTimer*)>(0x65D190)(this, pTimer);
    }

    bool IsFinishReason(FinishReason reason) {
      return reinterpret_cast<bool(__thiscall*)(GRacerInfo*, FinishReason)>(0x656AD0)(this, reason);
    }
    float     GetDragWheelieDistance() { return mStats.arbitrated.mDragWheelieDistance; }
    float     GetDriftTotalPoints() { return mStats.arbitrated.mPointTotal; }
    bool      GetIsHuman() { return reinterpret_cast<bool(__thiscall*)(GRacerInfo*)>(0x66C940)(this); }
    bool      GetIsLocalPlayer() { return reinterpret_cast<bool(__thiscall*)(GRacerInfo*)>(0x66C9C0)(this); }
    float     GetRaceTime() { return reinterpret_cast<float(__thiscall*)(GRacerInfo*)>(0x404C90)(this); }
    ISimable* GetSimable() { return reinterpret_cast<ISimable*(__thiscall*)(GRacerInfo*)>(0x667290)(this); }
    void      SetFinishReason(FinishReason reason) {
      reinterpret_cast<void(__thiscall*)(GRacerInfo*, FinishReason)>(0x68D980)(this, reason);
    }
    void TotalVehicle() { reinterpret_cast<void(__thiscall*)(GRacerInfo*)>(0x671B90)(this); }
  };

#ifdef _WIN32
  DEFINE_ENUM_FLAG_OPERATORS(GRacerInfo::RacerStateFlag);
#endif
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACERINFO_H
