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
#include <OpenSpeed/Core/EASTL/EASTL/vector.h>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/GRacerInfo.h>
#include <OpenSpeed/Game.MW05/Types/IVehicleCache.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
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
}  // namespace OpenSpeed::MW05
