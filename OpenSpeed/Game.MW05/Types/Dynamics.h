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
#include <OpenSpeed/Game.MW05/Types/UMath.h>

namespace OpenSpeed::MW05::Dynamics {
  namespace Collision {
    struct Geometry {
      UMath::Vector4 mPosition;
      UMath::Vector4 mNormal[3];
      UMath::Vector4 mExtent[3];
      UMath::Vector4 mCollision_point;
      UMath::Vector4 mCollision_normal;
      float          mDimension[3];
      std::uint16_t  mShape;
      std::uint16_t  mPenetratesOther;
      UMath::Vector3 mDelta;
      float          mOverlap;
    };
  }  // namespace Collision

  struct IEntity {
    virtual const UMath::Vector3& GetPosition()                                                = 0;
    virtual void                  SetPosition(const UMath::Vector3& newPosition)               = 0;
    virtual const UMath::Vector3& GetAngularVelocity()                                         = 0;
    virtual void                  SetAngularVelocity(const UMath::Vector3& newAngularVelocity) = 0;
    virtual const UMath::Vector3& GetLinearVelocity()                                          = 0;
    virtual void                  SetLinearVelocity(const UMath::Vector3& newLinearVelocity)   = 0;
    virtual const UMath::Matrix4& GetRotation()                                                = 0;
    virtual void                  SetRotation(const UMath::Matrix4& newRotation)               = 0;
    virtual const UMath::Vector4& GetOrientation()                                             = 0;
    virtual void                  SetOrientation(const UMath::Vector4& newOrientation)         = 0;
    virtual const UMath::Vector3& GetPrincipalInertia()                                        = 0;
    virtual float                 GetMass()                                                    = 0;
    virtual const UMath::Vector3& GetCenterOfGravity()                                         = 0;
    virtual bool                  IsImmobile()                                                 = 0;
  };
}  // namespace OpenSpeed::MW05::Dynamics
