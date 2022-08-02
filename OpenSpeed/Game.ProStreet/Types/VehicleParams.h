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
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Game.h>
#include <OpenSpeed/Game.ProStreet/Types/Sim.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Gen/pvehicle.h>

namespace OpenSpeed::ProStreet {
  struct VehicleParams : Sim::Param {
    DriverClass                 mDriverClass;
    Attrib::Gen::pvehicle       mAttributes;
    const UMath::Vector3*       mDirection;
    const UMath::Vector3*       mPosition;
    RideInfo*                   mRideInfo;
    IVehicleCache*              mVehicleCache;
    Physics::Info::Performance* mPerformanceMatch;
    eVehicleParamFlags          mFlags;

    explicit VehicleParams(DriverClass driverClass, const Attrib::Gen::pvehicle& attributes,
                           const UMath::Vector3& direction, const UMath::Vector3& position,
                           RideInfo*          pRideInfo = nullptr,
                           eVehicleParamFlags flags     = eVehicleParamFlags::SnapToGround |
                                                      eVehicleParamFlags::ComputePerformance,
                           IVehicleCache*              pVehicleCache     = nullptr,
                           Physics::Info::Performance* pPerformanceMatch = nullptr) :
        mDriverClass(driverClass),
        mAttributes(attributes),
        mDirection(&direction),
        mPosition(&position),
        mRideInfo(pRideInfo),
        mVehicleCache(pVehicleCache),
        mPerformanceMatch(pPerformanceMatch),
        mFlags(flags) {
      AddTypeName(this);
    }

    static void AddTypeName(VehicleParams* to) { to->mType = Game::stringhash32("VehicleParams"); }
  };
}  // namespace OpenSpeed::ProStreet
