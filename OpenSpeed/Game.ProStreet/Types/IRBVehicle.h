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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_IRBVEHICLE_H
#define OPENSPEED_GAME_PROSTREET_TYPES_IRBVEHICLE_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct IRBVehicle : UTL::COM::IUnknown {
    virtual ~IRBVehicle();
    virtual void             SetTargetPosition(const UMath::Vector3& position)                    = 0;
    virtual void             SetCollisionMass(float mass)                                         = 0;
    virtual void             SetCollisionCOG(const UMath::Vector3& newCenterOfGravity)            = 0;
    virtual void             EnableObjectCollisions(bool isEnabled)                               = 0;
    virtual bool             AreObjectCollisionsEnabled()                                         = 0;
    virtual void             EnableVehicleCollisions(bool isEnabled)                              = 0;
    virtual void             SetInvulnerability(eInvulnerability type, float durationInSeconds)   = 0;
    virtual eInvulnerability GetInvulnerability()                                                 = 0;
    virtual void             SetPlayerReactions(const Attrib::Gen::collisionreactions& reactions) = 0;
    virtual const Attrib::Gen::collisionreactions& GetPlayerReactions()                           = 0;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_IRBVEHICLE_H
