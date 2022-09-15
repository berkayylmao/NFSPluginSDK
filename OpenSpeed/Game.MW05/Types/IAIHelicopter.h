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

#ifndef OPENSPEED_GAME_MW05_TYPES_IAIHELICOPTER_H
#define OPENSPEED_GAME_MW05_TYPES_IAIHELICOPTER_H
#pragma once

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct IAIHelicopter : UTL::COM::IUnknown {
    virtual ~IAIHelicopter();
    virtual float          GetDesiredHeightOverDest()                                                  = 0;
    virtual void           SetDesiredHeightOverDest(float height)                                      = 0;
    virtual void           SetLookAtPosition(UMath::Vector3 pos)                                       = 0;
    virtual UMath::Vector3 GetLookAtPosition()                                                         = 0;
    virtual void           SetDestinationVelocity(const UMath::Vector3& velocity)                      = 0;
    virtual void           SteerToNav(WRoadNav* road_nav, float height, float speed, bool bStopAtDest) = 0;
    virtual bool           StartPathToPoint(UMath::Vector3& point)                                     = 0;
    virtual bool           StrafeToDestIsSet()                                                         = 0;
    virtual void           SetStrafeToDest(bool strafe)                                                = 0;
    virtual bool           FilterHeliAltitude(UMath::Vector3& point)                                   = 0;
    virtual void           RestrictPointToRoadNet(UMath::Vector3& seekPosition)                        = 0;
    virtual void           SetFuelFull()                                                               = 0;
    virtual float          GetFuelTimeRemaining()                                                      = 0;
    virtual void           SetShadowScale(float scale)                                                 = 0;
    virtual float          GetShadowScale()                                                            = 0;
    virtual void           SetDustStormIntensity(float intensity)                                      = 0;
    virtual float          GetDustStormIntensity()                                                     = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x404060)(); }
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_IAIHELICOPTER_H
