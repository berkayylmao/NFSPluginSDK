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
#include <Game.MW05/Types.h>
#include <Game.MW05/Types/Behavior.h>
#include <Game.MW05/Types/bNode.h>
#include <Game.MW05/Types/CollisionGeometry.h>
#include <Game.MW05/Types/ICollisionBody.h>
#include <Game.MW05/Types/IDynamicsEntity.h>
#include <Game.MW05/Types/IRigidBody.h>
#include <Game.MW05/Types/WCollisionMgr.h>

namespace OpenSpeed::MW05 {
  struct RigidBody : Behavior,
                     IRigidBody,
                     ICollisionBody,
                     IDynamicsEntity,
                     WCollisionMgr::ICollisionHandler,
                     CollisionGeometry::IBoundable,
                     bTNode<RigidBody> {
    struct State {
      UMath::Vector4 orientation;
      UMath::Vector3 position;
      StatusType     statusPrev;
      UMath::Vector3 linearVelocity;
      float          mass;
      UMath::Vector3 angularVelocity;
      float          oom;            // OOMass
      UMath::Vector3 InertiaTensor;  // PrincipalInertia
      StatusType     status;
      UMath::Vector3 force;
      int8_t         leversInContact;
      int8_t         mode;
      int8_t         index;
      int8_t         __unused2;
      UMath::Vector3 torque;
      float          radius;
      UMath::Matrix4 bodyMatrix;

      bool GetStatus(StatusType status) { return (this->status & status) == status; }
      void SetStatus(StatusType status) { this->status |= status; }
      void RemoveStatus(StatusType status) { this->status ^= status; }
    };

    static inline const RigidBody** mMaps = reinterpret_cast<RigidBody**>(0x92D0E8);

    ScratchPtr<State>                             mState;
    BehaviorSpecsPtr<Attrib::Gen::rigidbodyspecs> mSpecs;
    UMath::Matrix4                                mInvWorldTensor;
    UMath::Vector4                                mGroundNormal;
    UMath::Vector3                                mDimension;
    WCollider*                                    mWCollider;
    UMath::Vector3                                mCOG;
    const CollisionGeometry::Bounds*              mGeoms;
    /* RBGrid*/ void*                             mGrid;
    unsigned int                                  mCollisionMask;
    SimableType                                   mSimableType;
    float                                         mDetachForce;
    // RigidBody::PrimList                           mPrimitives;
    // RigidBody::MeshList                           mMeshes;

    virtual ~RigidBody();
    virtual void OnDebugDraw();
    virtual void OnBeginFrame(float);
    virtual void OnEndFrame(float);
    virtual void ModifyCollision(const RigidBody&, const Dynamics::Collision::Plane&,
                                 const Dynamics::Collision::Moment&);
    virtual void ModifyCollision(const SimSurface&, const Dynamics::Collision::Plane&,
                                 const Dynamics::Collision::Moment&);
    virtual void DoPenetration(RigidBody& targetRigidBody);
    virtual bool ShouldSleep();
    virtual void ResolveWorldCollision(const UMath::Vector3&, const UMath::Vector3&,
                                       Sim::Collision::Info*, Attrib::Collection*,
                                       const SimSurface&, const UMath::Vector3&);
    virtual bool CanCollideWith(const RigidBody& targetRigidBody);
    virtual bool CanCollideWithWorld();
    virtual bool CanCollideWithGround();
    virtual bool CanCollideWithObjects();
  };
}  // namespace OpenSpeed::MW05
