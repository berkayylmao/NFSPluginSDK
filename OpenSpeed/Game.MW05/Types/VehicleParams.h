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

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Sim.h>

namespace OpenSpeed::MW05 {
  struct VehicleParams : Sim::Param {
    DriverClass                 mDriverClass;
    std::uint32_t               mVehicleKey;
    const UMath::Vector3*       mDirection;
    const UMath::Vector3*       mPosition;
    FECustomizationRecord*      mCustomization;
    IVehicleCache*              mVehicleCache;
    Physics::Info::Performance* mPerformanceMatch;
    eVehicleParamFlags          mFlags;

    explicit VehicleParams(DriverClass driverClass, std::uint32_t vehicleKey, const UMath::Vector3& direction,
                           const UMath::Vector3& position, FECustomizationRecord* pFECR = nullptr,
                           eVehicleParamFlags flags = eVehicleParamFlags::SnapToGround |
                                                      eVehicleParamFlags::CalcPerformance,
                           IVehicleCache*              pVehicleCache     = nullptr,
                           Physics::Info::Performance* pPerformanceMatch = nullptr) :
        Sim::Param(0x0A6B47FAC),
        mDriverClass(driverClass),
        mVehicleKey(vehicleKey),
        mDirection(&direction),
        mPosition(&position),
        mCustomization(pFECR),
        mVehicleCache(pVehicleCache),
        mPerformanceMatch(pPerformanceMatch),
        mFlags(flags) {
      AddTypeName(this);
    }

    static void AddTypeName(VehicleParams* to) { reinterpret_cast<void(__cdecl*)(VehicleParams*)>(0x4040F0)(to); }
  };
}  // namespace OpenSpeed::MW05
