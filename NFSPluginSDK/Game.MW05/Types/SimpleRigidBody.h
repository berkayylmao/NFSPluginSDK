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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLERIGIDBODY_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLERIGIDBODY_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Behavior.h>
#include <NFSPluginSDK/Game.MW05/Types/bList.h>
#include <NFSPluginSDK/Game.MW05/Types/IRigidBody.h>
#include <NFSPluginSDK/Game.MW05/Types/ISimpleBody.h>

namespace NFSPluginSDK::MW05 {
  struct SimpleRigidBody : Behavior, IRigidBody, ISimpleBody, bTNode<SimpleRigidBody> {
    struct Volatile {
      UMath::Vector4 orientation;
      UMath::Vector3 position;
      std::uint8_t   __unused;
      std::int8_t    index;
      BodyFlags      flags;
      // [South, East, Vertical]
      UMath::Vector3 linearVelocity;
      float          radius;
      // [South, East, Horizontal]
      UMath::Vector3 angularVelocity;
      float          mass;
      UMath::Matrix4 bodyMatrix;

      bool GetFlag(BodyFlags flag) {
        return (static_cast<std::uint32_t>(this->flags) & static_cast<std::uint32_t>(flag)) ==
               static_cast<std::uint32_t>(flag);
      }
      void SetFlag(BodyFlags flag) {
        this->flags =
            static_cast<BodyFlags>(static_cast<std::uint32_t>(this->flags) | static_cast<std::uint32_t>(flag));
      }
      void RemoveStatus(BodyFlags flag) {
        this->flags =
            static_cast<BodyFlags>(static_cast<std::uint32_t>(this->flags) ^ static_cast<std::uint32_t>(flag));
      }

      static inline Volatile** g_mInstances = reinterpret_cast<Volatile**>(0x9384B0);

      static std::int32_t GetInstancesCount() {
        std::int32_t _amount    = 0;
        auto**       _pInstance = g_mInstances;
        while ((*_pInstance)++) _amount++;

        return _amount;
      }

      static Volatile* GetInstance(std::int32_t idx) {
        auto* _instance = g_mInstances[idx];
        if (_instance) return _instance;

        return nullptr;
      }
    };

    ScratchPtr<Volatile> mData;

    virtual ~SimpleRigidBody();
    virtual void OnDebugDraw();
    virtual bool HasHadCollision();
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
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLERIGIDBODY_H
