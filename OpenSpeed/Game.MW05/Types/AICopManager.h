// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types/AISpawnManager.h>
#include <OpenSpeed/Game.MW05/Types/ICopMgr.h>
#include <OpenSpeed/Game.MW05/Types/IVehicleCache.h>
#include <OpenSpeed/Game.MW05/Types/Sim.h>

namespace OpenSpeed::MW05 {
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

    eastl::list<SpawnCopRequest> mSpawnRequests;
    eastl::list<BreakerZone>     mBreakerZones;
    HSIMTASK__*                  mSimulateTask;
    std::int32_t                 mMaxCopCars;
    std::int32_t                 mMaxCopHelicopters;
    std::int32_t                 mPlatformBudgetCopCars;
    std::int32_t                 mMaxPatrolCopCars;
    std::int32_t                 mNumActiveCopCars;
    std::int32_t                 mMaxActiveCopCars;
    std::int32_t                 mNumActiveCopHelicopters;
    std::int32_t                 mMaxActiveCopHelicopters;
    std::int32_t                 mPursuitsInARow;
    std::int32_t                 mTotalCopsDestroyed;
    float                        mLockoutTimer;
    float                        mHeavySupportDelayTimer;
    bool                         mNoNewPursuitsOrCops;
    std::int32_t                 mNumCopsForLatchedRoadblockReq;
    IPursuit*                    mIPursuitWithLatchedRoadblockReq;
    IVehicle*                    mPursuitRequestVehicle;
    UTL::List<IVehicle*, 10>     mIVehicleList;
    eastl::list<IPursuit*>       mIPursuitList;
    eastl::list<IRoadBlock*>     mRoadBlockList;
    ActionQueue*                 mActionQ;
    IActivity*                   mSpeech;
    AttributeSet*                mAttributes;
    std::uint32_t*               mMessSpawnCop;
    std::uint32_t*               mMessSetAutoSpawn;
    std::uint32_t*               mMessSetCopsEnabled;
    std::uint32_t*               mMessBreakerStopCops;
    std::uint32_t*               mMessForcePursuitStart;

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
}  // namespace OpenSpeed::MW05
