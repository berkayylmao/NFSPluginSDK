// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types/UCrc32.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct ICollisionBody : UTL::COM::IUnknown {
    virtual ~ICollisionBody();
    virtual const UMath::Vector3& GetPosition()                                                = 0;
    virtual const UMath::Vector3& GetLinearVelocity()                                          = 0;
    virtual const UMath::Vector3& GetAngularVelocity()                                         = 0;
    virtual void                  GetDimension(UMath::Vector3& to)                             = 0;
    virtual void                  Damp(float amount)                                           = 0;
    virtual void                  SetAnimating(bool isAnimating)                               = 0;
    virtual bool                  IsModeling()                                                 = 0;
    virtual void                  DisableModeling()                                            = 0;
    virtual void                  EnableModeling()                                             = 0;
    virtual bool                  IsTriggering()                                               = 0;
    virtual void                  DisableTriggering()                                          = 0;
    virtual void                  EnableTriggering()                                           = 0;
    virtual bool                  IsSleeping()                                                 = 0;
    virtual void                  SetCenterOfGravity(const UMath::Vector3& newCenterOfGravity) = 0;
    virtual const UMath::Vector3& GetCenterOfGravity()                                         = 0;
    virtual bool                  HasHadCollision()                                            = 0;
    virtual bool                  HasHadWorldCollision()                                       = 0;
    virtual bool                  HasHadObjectCollision()                                      = 0;
    virtual void                  EnableCollisionGeometries(UCrc32 crc, bool isEnabled)        = 0;
    virtual bool                  DistributeMass()                                             = 0;
    virtual const UMath::Vector3& GetWorldMomentScale()                                        = 0;
    virtual const UMath::Vector3& GetGroundMomentScale()                                       = 0;
    virtual bool                  IsAttachedToWorld()                                          = 0;
    virtual void                  AttachedToWorld(bool, float)                                 = 0;
    virtual bool                  IsAnchored()                                                 = 0;
    virtual void                  SetAnchored(bool isAnchored)                                 = 0;
    virtual void                  SetInertiaTensor(const UMath::Vector3& newInertiaTensor)     = 0;
    virtual const UMath::Vector3& GetInertiaTensor()                                           = 0;
    virtual float                 GetOrientToGround()                                          = 0;
    virtual bool                  IsInGroundContact()                                          = 0;
    virtual std::int32_t          GetNumContactPoints()                                        = 0;
    virtual const UMath::Vector4& GetGroundNormal()                                            = 0;
    virtual void                  SetForce(const UMath::Vector3& newForce)                     = 0;
    virtual void                  SetTorque(const UMath::Vector3& newTorque)                   = 0;
    virtual const UMath::Vector3& GetForce()                                                   = 0;
    virtual const UMath::Vector3& GetTorque()                                                  = 0;
    virtual float                 GetGravity()                                                 = 0;
    virtual const UMath::Vector3& GetForwardVector()                                           = 0;
    virtual const UMath::Vector3& GetRightVector()                                             = 0;
    virtual const UMath::Vector3& GetUpVector()                                                = 0;
    virtual const UMath::Matrix4& GetMatrix4()                                                 = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4039C0)(); }
  };
}  // namespace OpenSpeed::MW05
