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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AICOPMANAGER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AICOPMANAGER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AISpawnManager.h>
#include <NFSPluginSDK/Game.MW05/Types/ICopMgr.h>
#include <NFSPluginSDK/Game.MW05/Types/IVehicleCache.h>
#include <NFSPluginSDK/Game.MW05/Types/Sim.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL/Listable.h>

namespace NFSPluginSDK::MW05 {
  struct AICopManager : Sim::Activity, AISpawnManager, ICopMgr, IVehicleCache {
    struct BreakerZone {
      UMath::Vector3 mPosition;
      float          mEndtime;
      float          mRadius;
    };
    struct SpawnCopRequest {
      UMath::Vector3 mInitialPos;
      UMath::Vector3 mInitialVec;
      char           mVehicleName[32];
      bool           mInPursuit;
      bool           mInRoadBlock;
    };

    eastl::list<SpawnCopRequest>       mSpawnRequests;
    eastl::list<BreakerZone>           mBreakerZones;
    HSIMTASK__*                        mSimulateTask;
    std::int32_t                       mMaxCopCars;
    std::int32_t                       mMaxCopHelicopters;
    std::int32_t                       mPlatformBudgetCopCars;
    std::int32_t                       mMaxPatrolCopCars;
    std::int32_t                       mNumActiveCopCars;
    std::int32_t                       mMaxActiveCopCars;
    std::int32_t                       mNumActiveCopHelicopters;
    std::int32_t                       mMaxActiveCopHelicopters;
    std::int32_t                       mPursuitsInARow;
    std::int32_t                       mTotalCopsDestroyed;
    float                              mLockoutTimer;
    float                              mHeavySupportDelayTimer;
    bool                               mNoNewPursuitsOrCops;
    std::int32_t                       mNumCopsForLatchedRoadblockReq;
    IPursuit*                          mIPursuitWithLatchedRoadblockReq;
    IVehicle*                          mPursuitRequestVehicle;
    UTL::Listable<IVehicle*, 10>::List mIVehicleList;
    eastl::list<IPursuit*>             mIPursuitList;
    eastl::list<IRoadBlock*>           mRoadBlockList;
    ActionQueue*                       mActionQ;
    IActivity*                         mSpeech;
    AttributeSet*                      mAttributes;
    std::uint32_t*                     mMessSpawnCop;
    std::uint32_t*                     mMessSetAutoSpawn;
    std::uint32_t*                     mMessSetCopsEnabled;
    std::uint32_t*                     mMessBreakerStopCops;
    std::uint32_t*                     mMessForcePursuitStart;

    virtual ~AICopManager();
    virtual void OnDebugDraw();

#pragma region overrides
    virtual bool        OnTask(HSIMTASK__* p, float) override;
    virtual void        OnAttached(IAttachable* pOther) override;
    virtual void        OnDetached(IAttachable* pOther) override;
    virtual bool        VehicleSpawningEnabled(bool isDespawn) override;
    virtual void        ResetCopsForRestart(bool release) override;
    virtual void        SetAllBustedTimersToZero() override;
    virtual void        PursuitIsEvaded(IPursuit* ipursuit) override;
    virtual bool        IsCopRequestPending() override;
    virtual bool        IsCopSpawnPending() override;
    virtual void        SpawnCop(UMath::Vector3& initialPos, UMath::Vector3& initialVec, const char* vehicleName,
                                 bool inPursuit, bool roadBlock) override;
    virtual bool        PlayerPursuitHasCop() override;
    virtual bool        CanPursueRacers() override;
    virtual bool        IsPlayerPursuitActive() override;
    virtual void        LockoutCops(bool lockout) override;
    virtual void        NoNewPursuitsOrCops() override;
    virtual void        PursueAtHeatLevel(int minHeatLevel) override;
    virtual float       GetLockoutTimeRemaining() override;
    virtual const char* GetCacheName() override;
    virtual eVehicleCacheResult OnQueryVehicleCache(const IVehicle*      removethis,
                                                    const IVehicleCache* whosasking) override;
    virtual void                OnRemovedVehicleCache(IVehicle* ivehicle) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AICOPMANAGER_H
