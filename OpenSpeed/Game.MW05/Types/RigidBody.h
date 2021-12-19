// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types/_ptr.h>
#include <OpenSpeed/Game.MW05/Types/Behavior.h>
#include <OpenSpeed/Game.MW05/Types/bList.h>
#include <OpenSpeed/Game.MW05/Types/CollisionGeometry.h>
#include <OpenSpeed/Game.MW05/Types/ICollisionBody.h>
#include <OpenSpeed/Game.MW05/Types/IDynamicsEntity.h>
#include <OpenSpeed/Game.MW05/Types/IRigidBody.h>
#include <OpenSpeed/Game.MW05/Types/Math.h>
#include <OpenSpeed/Game.MW05/Types/RBGrid.h>
#include <OpenSpeed/Game.MW05/Types/WCollisionMgr.h>

namespace OpenSpeed::MW05 {
  struct RigidBody : Behavior,
                     IRigidBody,
                     ICollisionBody,
                     IDynamicsEntity,
                     WCollisionMgr::ICollisionHandler,
                     CollisionGeometry::IBoundable,
                     bTNode<RigidBody> {
    struct Primitive : bTNode<Primitive> {
      enum class Flags : std::uint32_t {
        VSWORLD   = 1 << 0,
        VSOBJECTS = 1 << 1,
        VSGROUND  = 1 << 2,
        DISABLED  = 1 << 3,
        ONESIDED  = 1 << 4,
      };

      const Math::Vector4 mOrientation;
      const Math::Vector3 mDimension;
      const char          mShape;
      const Math::Vector3 mOffset;
      const UCrc32        mName;
      Math::Vector3       mPrevPosition;
      Flags               mFlags;
      void*               mMaterial;
    };
    struct PrimList : bTList<RigidBody::Primitive> {
      float         mRadius;
      std::uint32_t mSize;
    };

    struct Mesh : bTNode<Mesh> {
      enum class Flags {
        DISABLED = 1 << 0,
        FREEABLE = 1 << 2,
      };

      Math::Vector4*      mVerts;
      const std::uint16_t mNumVertices;
      Flags               mFlags;
      void*               mMaterial;
      UCrc32              mName;
    };
    struct MeshList : bTList<Mesh> {
      std::uint32_t mSize;
      std::uint32_t mVertCount;
    };

    struct Volatile {
      enum class Status : std::uint32_t {
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
      Status         statusPrev;
      // [South, East, Vertical]
      UMath::Vector3 linearVelocity;
      float          mass;
      // [South, East, Horizontal]
      UMath::Vector3 angularVelocity;
      // OOMass
      float oom;
      // PrincipalInertia
      UMath::Vector3 InertiaTensor;
      Status         status;
      UMath::Vector3 force;
      int8_t         leversInContact;
      int8_t         mode;
      int8_t         index;
      int8_t         __unused2;
      UMath::Vector3 torque;
      float          radius;
      // World transformation matrix
      // [v0] RightVector   (Rotation)
      // [v1] UpVector      (OrientToGround)
      // [v2] ForwardVector [South, East, Vertical, ?]
      // [v3] ?
      UMath::Matrix4 bodyMatrix;

      bool GetStatus(Status status) {
        return (static_cast<std::uint32_t>(this->status) & static_cast<std::uint32_t>(status)) ==
               static_cast<std::uint32_t>(status);
      }
      void SetStatus(Status status) {
        this->status =
            static_cast<Status>(static_cast<std::uint32_t>(this->status) | static_cast<std::uint32_t>(status));
      }
      void RemoveStatus(Status status) {
        this->status =
            static_cast<Status>(static_cast<std::uint32_t>(this->status) ^ static_cast<std::uint32_t>(status));
      }

      static inline Volatile** g_mInstances = reinterpret_cast<Volatile**>(0x9383B0);

      static std::int32_t GetInstancesCount() {
        std::int32_t _amount    = 0;
        auto**       _pInstance = g_mInstances;
        while ((*_pInstance)++) _amount++;

        return _amount;
      }

      static RigidBody::Volatile* GetInstance(std::int32_t idx) {
        auto* _instance = g_mInstances[idx];
        if (_instance) return _instance;

        return nullptr;
      }
    };

    ScratchPtr<Volatile>                          mData;
    BehaviorSpecsPtr<Attrib::Gen::rigidbodyspecs> mSpecs;
    UMath::Matrix4                                mInvWorldTensor;
    UMath::Vector4                                mGroundNormal;
    UMath::Vector3                                mDimension;
    WCollider*                                    mWCollider;
    UMath::Vector3                                mCenterOfGravity;
    const CollisionGeometry::Bounds*              mGeoms;
    RBGrid*                                       mGrid;
    unsigned int                                  mCollisionMask;
    SimableType                                   mSimableType;
    float                                         mDetachForce;
    PrimList                                      mPrimitives;
    MeshList                                      mMeshes;

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

#pragma region overrides
    virtual ISimable*             GetOwner() override;
    virtual bool                  IsSimple() override;
    virtual std::int32_t          GetIndex() override;
    virtual SimableType           GetSimableType() override;
    virtual float                 GetRadius() override;
    virtual float                 GetMass() override;
    virtual float                 GetOOMass() override;
    virtual const UMath::Vector3& GetPosition() override;
    virtual const UMath::Vector3& GetLinearVelocity() override;
    virtual const UMath::Vector3& GetAngularVelocity() override;
    virtual float                 GetSpeed() override;
    virtual float                 GetSpeedXZ() override;
    virtual void                  GetForwardVector(UMath::Vector3& out) override;
    virtual void                  GetRightVector(UMath::Vector3& out) override;
    virtual void                  GetUpVector(UMath::Vector3& out) override;
    virtual void                  GetMatrix4(UMath::Matrix4& out) override;
    virtual const UMath::Vector4& GetOrientation() override;
    virtual void                  GetDimension(UMath::Vector3& out) const override;
    virtual void                  GetDimension(UMath::Vector3& out) override;
    virtual std::uint32_t         GetTriggerFlags() override;
    virtual WCollider*            GetWCollider() override;
    virtual void                  GetPointVelocity(const UMath::Vector3& vec, UMath::Vector3& out) override;
    virtual void                  SetPosition(const UMath::Vector3& newPosition) override;
    virtual void                  SetLinearVelocity(const UMath::Vector3& newLinearVelocity) override;
    virtual void                  SetAngularVelocity(const UMath::Vector3& newAngularVelocity) override;
    virtual void                  SetRadius(float newRadius) override;
    virtual void                  SetMass(float newMass) override;
    virtual void                  SetOrientation(const UMath::Matrix4& newOrientation) override;
    virtual void                  SetOrientation(const UMath::Vector4& newOrientation) override;
    virtual void                  ModifyXPos(float newPosX) override;
    virtual void                  ModifyYPos(float newPosY) override;
    virtual void                  ModifyZPos(float newPosZ) override;
    virtual void                  Resolve(const UMath::Vector3&, const UMath::Vector3&) override;
    virtual void                  ResolveForce(const UMath::Vector3&, const UMath::Vector3&) override;
    virtual void                  ResolveForce(const UMath::Vector3&) override;
    virtual void                  ResolveTorque(const UMath::Vector3&, const UMath::Vector3&) override;
    virtual void                  ResolveTorque(const UMath::Vector3&) override;
    virtual void                  PlaceObject(const UMath::Matrix4&, const UMath::Vector3&) override;
    virtual void                  Accelerate(const UMath::Vector3& distribution, float amount) override;
    virtual void                  ConvertLocalToWorld(UMath::Vector3& out, bool normalize) override;
    virtual void                  ConvertWorldToLocal(UMath::Vector3& out, bool normalize) override;
    virtual void                  Debug() override;
#pragma endregion
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(RigidBody::Primitive::Flags)
  DEFINE_ENUM_FLAG_OPERATORS(RigidBody::Mesh::Flags)
  DEFINE_ENUM_FLAG_OPERATORS(RigidBody::Volatile::Status)
#endif
}  // namespace OpenSpeed::MW05
