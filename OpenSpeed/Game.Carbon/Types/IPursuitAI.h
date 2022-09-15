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

#ifndef OPENSPEED_GAME_CARBON_TYPES_IPURSUITAI_H
#define OPENSPEED_GAME_CARBON_TYPES_IPURSUITAI_H
#pragma once

#include <OpenSpeed/Game.Carbon/Types.h>
#include <OpenSpeed/Game.Carbon/Types/UTL.h>

namespace OpenSpeed::Carbon {
  struct IPursuitAI : UTL::COM::IUnknown {
    virtual ~IPursuitAI();

    virtual void                  StartPatrol()                                            = 0;
    virtual void                  StartRoadBlock()                                         = 0;
    virtual void                  StartFlee()                                              = 0;
    virtual void                  SetInPursuit(bool inPursuit)                             = 0;
    virtual bool                  GetInPursuit()                                           = 0;
    virtual void                  StartPursuit(AITarget* target, ISimable* itargetSimable) = 0;
    virtual void                  DoInPositionGoal()                                       = 0;
    virtual void                  EndPursuit()                                             = 0;
    virtual AITarget*             GetPursuitTarget()                                       = 0;
    virtual bool                  StartSupportGoal()                                       = 0;
    virtual AITarget*             PursuitRequest()                                         = 0;
    virtual void                  SetInFormation(bool inFormation)                         = 0;
    virtual bool                  GetInFormation()                                         = 0;
    virtual void                  SetInPosition(bool inPosition)                           = 0;
    virtual bool                  GetInPosition()                                          = 0;
    virtual void                  SetInPositionGoal(const UCrc32& ipg)                     = 0;
    virtual const UCrc32&         GetInPositionGoal()                                      = 0;
    virtual void                  SetInPositionOffset(const UMath::Vector3& offset)        = 0;
    virtual const UMath::Vector3& GetInPositionOffset()                                    = 0;
    virtual void                  SetBreaker(bool breaker)                                 = 0;
    virtual bool                  GetBreaker()                                             = 0;
    virtual void                  SetDamagedByPerp(bool damaged)                           = 0;
    virtual bool                  GetDamagedByPerp()                                       = 0;
    virtual SirenState            GetSirenState()                                          = 0;
    virtual float                 GetTimeSinceTargetSeen()                                 = 0;
    virtual void                  ClearTimeSinceTargetSeen()                               = 0;
    virtual bool                  CanSeeTarget(AITarget* target)                           = 0;
    virtual const UCrc32&         GetSupportGoal()                                         = 0;
    virtual void                  SetSupportGoal(UCrc32 sg)                                = 0;
    virtual void                  SetWithinEngagementRadius()                              = 0;
    virtual bool                  WasWithinEngagementRadius()                              = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4055B0)(); }
  };
}  // namespace OpenSpeed::Carbon

#endif  // OPENSPEED_GAME_CARBON_TYPES_IPURSUITAI_H
