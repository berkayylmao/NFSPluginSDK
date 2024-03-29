// clang-format off
//
//    BSD 3-Clause License
//    Copyright (c) 2022, Berkay Yigit (berkayylmao) <mail@berkay.link>
//    All rights reserved.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    You should have received a copy of the BSD 3-Clause License along with
//    this program. If not, see <https://opensource.org/licenses/BSD-3-Clause/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_RIGIDBODY_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_RIGIDBODY_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/rigidbodyspecs.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Behavior.h>
#include <NFSPluginSDK/Game.ProStreet/Types/bList.h>
#include <NFSPluginSDK/Game.ProStreet/Types/CollisionGeometry.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ICollisionBody.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IDynamicsEntity.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IRigidBody.h>
#include <NFSPluginSDK/Game.ProStreet/Types/RBGrid.h>
#include <NFSPluginSDK/Game.ProStreet/Types/WCollisionMgr.h>

namespace NFSPluginSDK::ProStreet {
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

      UMath::Vector4            mOrientation;
      UMath::Vector3            mDimension;
      std::uint32_t             mShape;
      UMath::Vector3            mOffset;
      UCrc32                    mName;
      UMath::Vector3            mPrevPosition;
      Flags                     mFlags;
      const Attrib::Collection* mMaterial;
      HCOLPRIM__*               mHandle;
    };
    struct PrimList : bTList<RigidBody::Primitive> {
      eastl::map<HCOLPRIM__*, Primitive*, eastl::less<HCOLPRIM__*>> mMap;
      unsigned char                                                 _mapPad[4];
      float                                                         mRadius;
      std::uint32_t                                                 mSize;
    };

    struct Mesh : bTNode<Mesh> {
      enum class Flags : std::uint16_t {
        DISABLED = 1 << 0,
        FREEABLE = 1 << 2,
      };

      UMath::Vector4*           mVerts;
      const std::uint16_t       mNumVertices;
      Flags                     mFlags;
      const Attrib::Collection* mMaterial;
      UCrc32                    mName;
    };
    struct MeshList : bTList<Mesh> {
      std::uint32_t mSize;
      std::uint32_t mVertCount;
    };

    struct State {
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
      std::int8_t    leversInContact;
      std::int8_t    mode;
      std::int8_t    index;
      std::int8_t    __unused2;
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
      bool GetStatusPrev(Status status) {
        return (static_cast<std::uint32_t>(this->statusPrev) & static_cast<std::uint32_t>(status)) ==
               static_cast<std::uint32_t>(status);
      }

      void SetStatus(Status status) {
        this->status =
            static_cast<Status>(static_cast<std::uint32_t>(this->status) | static_cast<std::uint32_t>(status));
      }
      void SetStatusPrev(Status status) {
        this->status =
            static_cast<Status>(static_cast<std::uint32_t>(this->statusPrev) | static_cast<std::uint32_t>(status));
      }

      void RemoveStatus(Status status) {
        this->status =
            static_cast<Status>(static_cast<std::uint32_t>(this->status) ^ static_cast<std::uint32_t>(status));
      }
      void RemoveStatusPrev(Status status) {
        this->status =
            static_cast<Status>(static_cast<std::uint32_t>(this->statusPrev) ^ static_cast<std::uint32_t>(status));
      }
    };

    ScratchPtr<State>                             mState;
    BehaviorSpecsPtr<Attrib::Gen::rigidbodyspecs> mSpecs;
    UMath::Matrix4                                mInvWorldTensor;
    UMath::Vector4                                mGroundNormal;
    UMath::Vector3                                mDimension;
    WCollider*                                    mWCollider;
    UMath::Vector3                                mCenterOfGravity;
    const CollisionGeometry::Bounds*              mGeoms;
    RBGrid*                                       mGrid;
    std::uint32_t                                 mCollisionMask;
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
  DEFINE_ENUM_FLAG_OPERATORS(RigidBody::State::Status)
#endif
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_RIGIDBODY_H
