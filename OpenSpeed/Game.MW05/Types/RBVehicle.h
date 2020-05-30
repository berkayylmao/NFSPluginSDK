// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/_ptr.h>
#include <OpenSpeed/Game.MW05/Types/IRBVehicle.h>
#include <OpenSpeed/Game.MW05/Types/RigidBody.h>

namespace OpenSpeed::MW05 {
  struct RBVehicle : RigidBody, IRBVehicle {
    IVehicle*                                     mVehicle;
    IChassis*                                     mChassis;
    BehaviorSpecsPtr<Attrib::Gen::rigidbodyspecs> mSpecs;
    float                                         mDeadOnWheels;
    CollisionGeometry::Collection*                mGeoms;
    std::uint32_t                                 mFrame;
    UMath::Vector3                                mCollisionCOG;
    float                                         mCollisionMass;
    bool                                          mObjectCollisionsEnabled;
    bool                                          mVehicleCollisionsEnabled;
    bool                                          mTumblingFlag;
    std::uint32_t                                 mTumblingIndex;
    eInvulnerability                              mInvulnerableState;
    float                                         mInvulnerableTimer;
    float                                         mLastPenetration;
    Attrib::Gen::collisionreactions               mReactions[10];

    virtual ~RBVehicle();
  };
}  // namespace OpenSpeed::MW05
