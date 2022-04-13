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
#include <OpenSpeed/Game.Carbon/Types.h>
#include <OpenSpeed/Game.Carbon/Types/Sim.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Gen/pvehicle.h>

namespace OpenSpeed::Carbon {
  struct VehicleParams : Sim::Param {
    DriverClass                 mDriverClass;
    Attrib::Gen::pvehicle       mAttributes;
    const UMath::Vector3*       mDirection;
    const UMath::Vector3*       mPosition;
    VehicleCustomizations*      mCustomization;
    IVehicleCache*              mVehicleCache;
    Physics::Info::Performance* mPerformanceMatch;
    std::uint32_t               abc = 0;
    eVehicleParamFlags          mFlags;
    std::uint32_t               abc2 = 0;

    explicit VehicleParams(DriverClass driverClass, const Attrib::Gen::pvehicle& attributes,
                           const UMath::Vector3& direction, const UMath::Vector3& position,
                           VehicleCustomizations* pCustomizations = nullptr,
                           eVehicleParamFlags     flags           = eVehicleParamFlags::SnapToGround |
                                                      eVehicleParamFlags::CalcPerformance,
                           IVehicleCache*              pVehicleCache     = nullptr,
                           Physics::Info::Performance* pPerformanceMatch = nullptr) :
        mDriverClass(driverClass),
        mAttributes(attributes),
        mDirection(&direction),
        mPosition(&position),
        mCustomization(pCustomizations),
        mVehicleCache(pVehicleCache),
        mPerformanceMatch(pPerformanceMatch),
        mFlags(flags) {
      AddTypeName(this);
    }

    static void AddTypeName(VehicleParams* to) { reinterpret_cast<void(__cdecl*)(VehicleParams*)>(0x404820)(to); }
  };
}  // namespace OpenSpeed::Carbon
