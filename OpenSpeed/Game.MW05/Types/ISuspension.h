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
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct ISuspension : UTL::COM::IUnknown {
    virtual ~ISuspension();
    virtual float                 GetWheelTraction(std::uint32_t idx)                              = 0;
    virtual std::uint32_t         GetNumWheels()                                                   = 0;
    virtual const UMath::Vector3& GetWheelPos(std::uint32_t idx)                                   = 0;
    virtual const UMath::Vector3& GetWheelLocalPos(std::uint32_t idx)                              = 0;
    virtual UMath::Vector3        GetWheelCenterPos(std::uint32_t idx)                             = 0;
    virtual float                 GetWheelLoad(std::uint32_t idx)                                  = 0;
    virtual void                  ApplyVehicleEntryForces(bool, const UMath::Vector3&, bool)       = 0;
    virtual const float           GetWheelRoadHeight(std::uint32_t idx)                            = 0;
    virtual bool                  IsWheelOnGround(std::uint32_t idx)                               = 0;
    virtual float                 GetCompression(std::uint32_t)                                    = 0;
    virtual float                 GuessCompression(std::uint32_t, float)                           = 0;
    virtual float                 GetWheelSlip(std::uint32_t idx)                                  = 0;
    virtual float                 GetToleratedSlip(std::uint32_t)                                  = 0;
    virtual float                 GetWheelSkid(std::uint32_t idx)                                  = 0;
    virtual float                 GetWheelSlipAngle(std::uint32_t idx)                             = 0;
    virtual const UMath::Vector4& GetWheelRoadNormal(std::uint32_t idx)                            = 0;
    virtual const SimSurface&     GetWheelRoadSurface(std::uint32_t idx)                           = 0;
    virtual const UMath::Vector3& GetWheelVelocity(std::uint32_t idx)                              = 0;
    virtual std::uint32_t         GetNumWheelsOnGround()                                           = 0;
    virtual float                 GetWheelAngularVelocity(std::int32_t idx)                        = 0;
    virtual void                  SetWheelAngularVelocity(std::int32_t idx, float angularVelocity) = 0;
    virtual float                 GetWheelSteer(std::uint32_t idx)                                 = 0;
    virtual float                 CalculateUndersteerFactor()                                      = 0;
    virtual float                 CalculateOversteerFactor()                                       = 0;
    virtual float                 GetRideHeight(std::uint32_t)                                     = 0;
    virtual float                 GetWheelRadius(std::uint32_t idx)                                = 0;
    virtual float                 GetMaxSteering()                                                 = 0;
    virtual void                  MatchSpeed(float speed)                                          = 0;
    virtual float                 GetRenderMotion()                                                = 0;

    static IHandle* GetHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x404040)(); }
  }
}  // namespace OpenSpeed::MW05