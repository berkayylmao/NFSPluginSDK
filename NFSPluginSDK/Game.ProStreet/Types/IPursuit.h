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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_IPURSUIT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_IPURSUIT_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct IPursuit : UTL::COM::IUnknown {
    virtual ~IPursuit();

    virtual bool                        IsTarget(AITarget* aitarget)                   = 0;
    virtual AITarget*                   GetTarget()                                    = 0;
    virtual std::int32_t                GetNumCops()                                   = 0;
    virtual std::int32_t                GetNumHeliSpawns()                             = 0;
    virtual std::int32_t                GetNumCopsFullyEngaged()                       = 0;
    virtual float                       GetPursuitDuration()                           = 0;
    virtual float                       GetEvadeLevel()                                = 0;
    virtual float                       GetCoolDownTimeRemaining()                     = 0;
    virtual float                       GetCoolDownTimeRequired()                      = 0;
    virtual bool                        IsPerpInSight()                                = 0;
    virtual bool                        IsPursuitBailed()                              = 0;
    virtual bool                        IsCollapseActive()                             = 0;
    virtual bool                        AttemptingToReAcquire()                        = 0;
    virtual const UMath::Vector3&       GetLastKnownLocation()                         = 0;
    virtual IRoadBlock*                 GetRoadBlock()                                 = 0;
    virtual IVehicle*                   GetNearestCopInRoadblock(float* distance)      = 0;
    virtual GroundSupportRequest*       RequestGroundSupport()                         = 0;
    virtual void                        ClearGroundSupportRequest()                    = 0;
    virtual bool                        IsSupportVehicle(IVehicle* iv)                 = 0;
    virtual const char*                 CopRequest()                                   = 0;
    virtual bool                        PendingRoadBlockRequest()                      = 0;
    virtual bool                        IsFinisherActive()                             = 0;
    virtual float                       TimeToFinisherAttempt()                        = 0;
    virtual float                       TimeUntilBusted()                              = 0;
    virtual bool                        PursuitMeterCanShowBusted()                    = 0;
    virtual FormationType               GetFormationType()                             = 0;
    virtual void                        EndCurrentFormation()                          = 0;
    virtual bool                        ShouldEnd()                                    = 0;
    virtual bool                        IsPerpBusted()                                 = 0;
    virtual bool                        AddVehicle(IVehicle* vehicle)                  = 0;
    virtual bool                        RemoveVehicle(IVehicle* vehicle)               = 0;
    virtual void                        AddRoadBlock(IRoadBlock* roadblock)            = 0;
    virtual std::int32_t                RequestRoadBlock()                             = 0;
    virtual bool                        IsHeliInPursuit()                              = 0;
    virtual bool                        IsPlayerPursuit()                              = 0;
    virtual bool                        ContingentHasActiveCops()                      = 0;
    virtual std::int32_t                GetNumCopsDamaged()                            = 0;
    virtual std::int32_t                GetNumCopsDestroyed()                          = 0;
    virtual void                        IncNumCopsDestroyed(IVehicle* ivehicle)        = 0;
    virtual std::int32_t                GetTotalNumCopsInvolved()                      = 0;
    virtual std::int32_t                GetNumRoadblocksDodged()                       = 0;
    virtual std::int32_t                GetNumRoadblocksDeployed()                     = 0;
    virtual std::int32_t                GetValueOfPropertyDamaged()                    = 0;
    virtual std::int32_t                GetNumPropertyDamaged()                        = 0;
    virtual std::int32_t                GetNumTrafficCarsHit()                         = 0;
    virtual std::int32_t                GetNumSpikeStripsDodged()                      = 0;
    virtual std::int32_t                GetNumSpikeStripsDeployed()                    = 0;
    virtual std::int32_t                GetNumHeliSpikeStripDeployed()                 = 0;
    virtual std::int32_t                GetNumCopCarsDeployed()                        = 0;
    virtual std::int32_t                GetNumSupportVehiclesDeployed()                = 0;
    virtual std::int32_t                GetNumCopsInWave()                             = 0;
    virtual std::int32_t                GetNumCopsRemainingInWave()                    = 0;
    virtual std::int32_t                GetCopDestroyedBonusMultiplier()               = 0;
    virtual std::int32_t                GetMostRecentCopDestroyedRepPoints()           = 0;
    virtual UCrc32                      GetMostRecentCopDestroyedType()                = 0;
    virtual std::uint32_t               CalcTotalCostToState()                         = 0;
    virtual void                        AddVehicleToContingent(IVehicle* ivehicle)     = 0;
    virtual void                        NotifyRoadblockDodged()                        = 0;
    virtual void                        NotifyRoadblockDeployed()                      = 0;
    virtual void                        NotifyCopDamaged(IVehicle* ivehicle)           = 0;
    virtual void                        NotifyPropertyDamaged(std::int32_t cost)       = 0;
    virtual void                        NotifyTrafficCarHit()                          = 0;
    virtual void                        NotifySpikeStripsDodged(std::int32_t num)      = 0;
    virtual void                        NotifySpikeStripDeployed()                     = 0;
    virtual void                        NotifyHeliSpikeStripDeployed(std::int32_t num) = 0;
    virtual void                        NotifyCopCarDeployed()                         = 0;
    virtual void                        NotifySupportVehicleDeployed()                 = 0;
    virtual void                        BailPursuit()                                  = 0;
    virtual ePursuitStatus              GetPursuitStatus()                             = 0;
    virtual float                       GetTimeToBackupSpawned()                       = 0;
    virtual bool                        SkidHitEnabled()                               = 0;
    virtual float                       GetBackupETA()                                 = 0;
    virtual bool                        GetIsAJerk()                                   = 0;
    virtual float                       GetMinDistanceToTarget()                       = 0;
    virtual void                        SpikesHit(IVehicleAI* ivai)                    = 0;
    virtual void                        EndPursuitEnteringSafehouse()                  = 0;
    virtual bool                        GetEnterSafehouseOnDone()                      = 0;
    virtual void                        LockInPursuitAttribs()                         = 0;
    virtual void                        SetBustedTimerToZero()                         = 0;
    virtual Attrib::Gen::pursuitlevels* GetPursuitLevelAttrib()                        = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4038C0)(); }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_IPURSUIT_H
