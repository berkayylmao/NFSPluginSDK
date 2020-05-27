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
#include <Game.MW05/Types/Sim.h>

namespace OpenSpeed::MW05 {
  struct VehicleParams : Sim::Param {
    DriverClass                         mDriverClass;
    Attrib::Gen::pvehicle               mVehicleAttrib;
    UMath::Vector3*                     mDirection;
    UMath::Vector3*                     mPosition;
    FECustomizationRecord*              mFECR;
    IVehicleCache*                      mVehicleCache;
    Physics::Info::PerformanceMatching* mPerformanceMatch;
    VehicleCreateFlags                  mCreateFlags;

    static void TypeName(VehicleParams* pVehicleParams) {
      reinterpret_cast<void(__cdecl*)(VehicleParams*)>(0x4040F0)(pVehicleParams);
    }

    VehicleParams(IVehicleCache* pVehicleCache, DriverClass driverClass,
                  const Attrib::Gen::pvehicle& vehicleAttrib, const UMath::Vector3& direction,
                  const UMath::Vector3& position, VehicleCreateFlags createFlags,
                  FECustomizationRecord*              pFECR,
                  Physics::Info::PerformanceMatching* pPerformanceMatch)
        : Sim::Param(0x0A6B47FAC),
          mVehicleCache(pVehicleCache),
          mDriverClass(driverClass),
          mVehicleAttrib(vehicleAttrib),
          mDirection(const_cast<UMath::Vector3*>(&direction)),
          mPosition(const_cast<UMath::Vector3*>(&position)),
          mCreateFlags(createFlags),
          mFECR(pFECR),
          mPerformanceMatch(pPerformanceMatch) {
      TypeName(this);
    }
    VehicleParams(IVehicleCache* pVehicleCache, DriverClass driverClass,
                  const std::uint32_t vehicleHash, const UMath::Vector3& direction,
                  const UMath::Vector3& position, VehicleCreateFlags createFlags,
                  FECustomizationRecord*              pFECR,
                  Physics::Info::PerformanceMatching* pPerformanceMatch)
        : Sim::Param(0x0A6B47FAC),
          mVehicleCache(pVehicleCache),
          mDriverClass(driverClass),
          mVehicleAttrib(vehicleHash),
          mDirection(const_cast<UMath::Vector3*>(&direction)),
          mPosition(const_cast<UMath::Vector3*>(&position)),
          mCreateFlags(createFlags),
          mFECR(pFECR),
          mPerformanceMatch(pPerformanceMatch) {
      TypeName(this);
    }
  };
}  // namespace OpenSpeed::MW05
