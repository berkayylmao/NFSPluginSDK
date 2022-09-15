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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_RBVEHICLE_H
#define OPENSPEED_GAME_PROSTREET_TYPES_RBVEHICLE_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/IRBVehicle.h>
#include <OpenSpeed/Game.ProStreet/Types/RigidBody.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Gen/collisionreactions.h>

namespace OpenSpeed::ProStreet {
  struct RBVehicle : RigidBody, IRBVehicle {
    IVehicle*                                     mVehicle;
    IChassis*                                     mChassis;
    BehaviorSpecsPtr<Attrib::Gen::rigidbodyspecs> mSpecs;
    float                                         mDeadOnWheels;
    CollisionGeometry::Collection*                mGeoms;
    std::uint32_t                                 mFrame;
    unsigned char                                 _pad[4];
    UMath::Vector3                                mCollisionCenterOfGravity;
    float                                         mCollisionMass;
    bool                                          mObjectCollisionsEnabled;
    bool                                          mVehicleCollisionsEnabled;
    bool                                          mTumblingFlag;
    std::int32_t                                  mTumblingIndex;
    eInvulnerability                              mInvulnerableState;
    float                                         mInvulnerableTimer;
    float                                         mLastPenetration;
    Attrib::Gen::collisionreactions               mReactions[10];

    virtual ~RBVehicle();
    virtual void             SetTargetPosition(const UMath::Vector3& position) override;
    virtual void             SetCollisionMass(float mass) override;
    virtual void             SetCollisionCOG(const UMath::Vector3& newCenterOfGravity) override;
    virtual void             EnableObjectCollisions(bool isEnabled) override;
    virtual bool             AreObjectCollisionsEnabled() override;
    virtual void             EnableVehicleCollisions(bool isEnabled) override;
    virtual void             SetInvulnerability(eInvulnerability type, float durationInSeconds) override;
    virtual eInvulnerability GetInvulnerability() override;
    virtual void             SetPlayerReactions(const Attrib::Gen::collisionreactions& reactions) override;
    virtual const Attrib::Gen::collisionreactions& GetPlayerReactions() override;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_RBVEHICLE_H
