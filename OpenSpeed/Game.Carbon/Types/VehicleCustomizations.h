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

#ifndef OPENSPEED_GAME_CARBON_TYPES_VEHICLECUSTOMIZATIONS_H
#define OPENSPEED_GAME_CARBON_TYPES_VEHICLECUSTOMIZATIONS_H
#pragma once

#include <OpenSpeed/Game.Carbon/Types.h>

namespace OpenSpeed::Carbon {
  struct VehicleCustomizations {
    std::uint8_t __unk_VehicleCustomizations_1__[0x42C];

    inline void ReadFrom(const Attrib::Gen::pvehicle& attributes) {
      reinterpret_cast<void(__thiscall*)(VehicleCustomizations*, const Attrib::Gen::pvehicle&)>(0x7B2FF0)(this,
                                                                                                          attributes);
    }
    inline void ReadFrom(const RideInfo& rideInfo) {
      reinterpret_cast<void(__thiscall*)(VehicleCustomizations*, const RideInfo&)>(0x7C4040)(this, rideInfo);
    }

    explicit VehicleCustomizations() {
      reinterpret_cast<VehicleCustomizations*(__thiscall*)(VehicleCustomizations*)>(0x4AC790)(this);
    }
  };
}  // namespace OpenSpeed::Carbon

#endif  // OPENSPEED_GAME_CARBON_TYPES_VEHICLECUSTOMIZATIONS_H
