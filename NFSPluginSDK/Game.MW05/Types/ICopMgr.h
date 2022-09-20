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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ICOPMGR_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ICOPMGR_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct ICopMgr : UTL::COM::IUnknown {
    virtual ~ICopMgr();

    virtual bool  VehicleSpawningEnabled(bool isDespawn)   = 0;
    virtual void  ResetCopsForRestart(bool release)        = 0;
    virtual void  SetAllBustedTimersToZero()               = 0;
    virtual void  PursuitIsEvaded(IPursuit* ipursuit)      = 0;
    virtual bool  IsCopRequestPending()                    = 0;
    virtual bool  IsCopSpawnPending()                      = 0;
    virtual void  SpawnCop(UMath::Vector3& initialPos, UMath::Vector3& initialVec, const char* vehicleName,
                           bool inPursuit, bool roadBlock) = 0;
    virtual bool  PlayerPursuitHasCop()                    = 0;
    virtual bool  CanPursueRacers()                        = 0;
    virtual bool  IsPlayerPursuitActive()                  = 0;
    virtual void  LockoutCops(bool lockout)                = 0;
    virtual void  NoNewPursuitsOrCops()                    = 0;
    virtual void  PursueAtHeatLevel(int minHeatLevel)      = 0;
    virtual float GetLockoutTimeRemaining()                = 0;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ICOPMGR_H
