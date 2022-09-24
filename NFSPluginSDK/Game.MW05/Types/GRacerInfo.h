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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_GRACERINFO_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_GRACERINFO_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/GTimer.h>

namespace NFSPluginSDK::MW05 {
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
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_GRACERINFO_H
