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
#include <OpenSpeed/Game.MW05/Types/UMath.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct IRigidBody : UTL::COM::IUnknown {
    virtual ~IRigidBody();
    virtual ISimable*             GetOwner()                                                       = 0;
    virtual bool                  IsSimple()                                                       = 0;
    virtual std::int32_t          GetIndex()                                                       = 0;
    virtual SimableType           GetSimableType()                                                 = 0;
    virtual float                 GetRadius()                                                      = 0;
    virtual float                 GetMass()                                                        = 0;
    virtual float                 GetOOMass()                                                      = 0;
    virtual const UMath::Vector3& GetPosition()                                                    = 0;
    virtual const UMath::Vector3& GetLinearVelocity()                                              = 0;
    virtual const UMath::Vector3& GetAngularVelocity()                                             = 0;
    virtual float                 GetSpeed()                                                       = 0;
    virtual float                 GetSpeedXZ()                                                     = 0;
    virtual void                  GetForwardVector(UMath::Vector3& out)                            = 0;
    virtual void                  GetRightVector(UMath::Vector3& out)                              = 0;
    virtual void                  GetUpVector(UMath::Vector3& out)                                 = 0;
    virtual void                  GetMatrix4(UMath::Matrix4& out)                                  = 0;
    virtual const UMath::Vector4& GetOrientation()                                                 = 0;
    virtual void                  GetDimension(UMath::Vector3& out) const                          = 0;
    virtual void                  GetDimension(UMath::Vector3& out)                                = 0;
    virtual std::uint32_t         GetTriggerFlags()                                                = 0;
    virtual WCollider*            GetWCollider()                                                   = 0;
    virtual void                  GetPointVelocity(const UMath::Vector3& vec, UMath::Vector3& out) = 0;
    virtual void                  SetPosition(const UMath::Vector3& newPosition)                   = 0;
    virtual void                  SetLinearVelocity(const UMath::Vector3& newLinearVelocity)       = 0;
    virtual void                  SetAngularVelocity(const UMath::Vector3& newAngularVelocity)     = 0;
    virtual void                  SetRadius(float newRadius)                                       = 0;
    virtual void                  SetMass(float newMass)                                           = 0;
    virtual void                  SetOrientation(const UMath::Matrix4& newOrientation)             = 0;
    virtual void                  SetOrientation(const UMath::Vector4& newOrientation)             = 0;
    virtual void                  ModifyXPos(float newPosX)                                        = 0;
    virtual void                  ModifyYPos(float newPosY)                                        = 0;
    virtual void                  ModifyZPos(float newPosZ)                                        = 0;
    virtual void                  Resolve(const UMath::Vector3&, const UMath::Vector3&)            = 0;
    virtual void                  ResolveForce(const UMath::Vector3&, const UMath::Vector3&)       = 0;
    virtual void                  ResolveForce(const UMath::Vector3&)                              = 0;
    virtual void                  ResolveTorque(const UMath::Vector3&, const UMath::Vector3&)      = 0;
    virtual void                  ResolveTorque(const UMath::Vector3&)                             = 0;
    virtual void                  PlaceObject(const UMath::Matrix4&, const UMath::Vector3&)        = 0;
    virtual void                  Accelerate(const UMath::Vector3& distribution, float amount)     = 0;
    virtual void                  ConvertLocalToWorld(UMath::Vector3& out, bool normalize)         = 0;
    virtual void                  ConvertWorldToLocal(UMath::Vector3& out, bool normalize)         = 0;
    virtual void                  Debug()                                                          = 0;
  };
}  // namespace OpenSpeed::MW05
