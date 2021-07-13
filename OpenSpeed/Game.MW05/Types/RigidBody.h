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
#include <OpenSpeed/Game.MW05/Types/Behavior.h>
#include <OpenSpeed/Game.MW05/Types/bNode.h>
#include <OpenSpeed/Game.MW05/Types/CollisionGeometry.h>
#include <OpenSpeed/Game.MW05/Types/ICollisionBody.h>
#include <OpenSpeed/Game.MW05/Types/IDynamicsEntity.h>
#include <OpenSpeed/Game.MW05/Types/IRigidBody.h>
#include <OpenSpeed/Game.MW05/Types/WCollisionMgr.h>

namespace OpenSpeed::MW05 {
  struct RigidBody : Behavior,
                     IRigidBody,
                     ICollisionBody,
                     IDynamicsEntity,
                     WCollisionMgr::ICollisionHandler,
                     CollisionGeometry::IBoundable,
                     bTNode<RigidBody> {
    struct State {
      enum class StatusType : std::uint32_t {
        NoTrigger         = 1 << 0,
        Attached          = 1 << 1,
        CollisionWorld    = 1 << 2,
        CollisionObject   = 1 << 3,
        EnableDrag        = 1 << 5,
        CheckWorld        = 1 << 6,
        FixedCG           = 1 << 7,
        Animating         = 1 << 8,
        Initiliazed       = 1 << 9,
        Integrating       = 1 << 10,
        EnableDragAngular = 1 << 11,
        DisableIntegrator = 1 << 12,
        ModifyPrims       = 1 << 13,
        Inactive          = 1 << 14,
        CollisionGround   = 1 << 15
      };

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

      bool GetStatus(StatusType status) {
        return (static_cast<std::uint32_t>(this->status) & static_cast<std::uint32_t>(status)) ==
               static_cast<std::uint32_t>(status);
      }
      void SetStatus(StatusType status) {
        this->status =
            static_cast<StatusType>(static_cast<std::uint32_t>(this->status) | static_cast<std::uint32_t>(status));
      }
      void RemoveStatus(StatusType status) {
        this->status =
            static_cast<StatusType>(static_cast<std::uint32_t>(this->status) ^ static_cast<std::uint32_t>(status));
      }
    };

    static inline RigidBody** g_mMaps = reinterpret_cast<RigidBody**>(0x92D0E8);

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
    virtual void ResolveWorldCollision(const UMath::Vector3&, const UMath::Vector3&, Sim::Collision::Info*,
                                       Attrib::Collection*, const SimSurface&, const UMath::Vector3&);
    virtual bool CanCollideWith(const RigidBody& targetRigidBody);
    virtual bool CanCollideWithWorld();
    virtual bool CanCollideWithGround();
    virtual bool CanCollideWithObjects();
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(RigidBody::State::StatusType)
#endif
}  // namespace OpenSpeed::MW05
