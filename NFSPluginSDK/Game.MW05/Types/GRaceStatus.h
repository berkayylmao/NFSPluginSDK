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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_GRACESTATUS_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_GRACESTATUS_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/GRacerInfo.h>
#include <NFSPluginSDK/Game.MW05/Types/IVehicleCache.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct GRaceStatus : UTL::COM::Object, IVehicleCache {
    enum class Context : std::uint32_t { QuickRace, Online, Career };
    enum class PlayMode : std::uint32_t { Roaming, Racing };

    GRacerInfo               mRacerInfo[16];
    std::int32_t             mRacerCount;
    bool                     mIsLoading;
    PlayMode                 mPlayMode;
    Context                  mRaceContext;
    GRaceParameters*         mRaceParms;
    GRaceBin*                mRaceBin;
    GTimer                   mRaceMasterTimer;
    bool                     mPlayerPursuitInCooldown;
    float                    mBonusTime;
    float                    mTaskTime;
    bool                     mSuddenDeathMode;
    bool                     mTimeExpiredMsgSent;
    bool                     mActivelyRacing;
    std::int32_t             mLastSecondTickSent;
    WorldModel*              mCheckpointModel;
    EmitterGroup*            mCheckpointEmitter;
    bool                     mQueueBinChange;
    std::uint32_t            mWarpWhenInFreeRoam;
    std::int32_t             mNumTollbooths;
    bool                     mScriptWaitingForLoad;
    bool                     mRefreshBinAfterRace;
    eastl::vector<GTrigger*> mCheckpoints;
    GTrigger*                mNextCheckpoint;
    float                    mLapTimes[10][16];
    float                    mCheckTimes[10][16][16];
    float                    mSegmentLengths[18];
    float                    fRaceLength;
    float                    fFirstLapLength;
    float                    fSubsequentLapLength;
    bool                     mCaluclatedAdaptiveGain;
    float                    fCatchUpIntegral;
    float                    fCatchUpDerivative;
    float                    fCatchUpAdaptiveBonus;
    float                    fAveragePercentComplete;
    std::int32_t             nCatchUpSkillEntries;
    float                    aCatchUpSkillData[11];
    std::int32_t             nCatchUpSpreadEntries;
    float                    aCatchUpSpreadData[11];
    std::int32_t             nSpeedTraps;
    GTrigger*                aSpeedTraps[16];
    bool                     mVehicleCacheLocked;
    bool                     bRaceRouteError;
    eTrafficDensity          mTrafficDensity;
    std::uint32_t            mTrafficPattern;
    bool                     mHasBeenWon;

    static void DisableBarriers() { reinterpret_cast<void(__cdecl*)()>(0x5DBF00)(); }

    static inline GRaceStatus** g_mThis = reinterpret_cast<GRaceStatus**>(0x91E000);
    static GRaceStatus*         Get() {
              if (!g_mThis) return nullptr;
      return *g_mThis;
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_GRACESTATUS_H
