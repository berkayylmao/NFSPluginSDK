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

namespace OpenSpeed::Carbon {
  struct FECustomizationRecord {
    std::uint8_t __unk_FECustomizationRecord_1__[0x666];  // unksize

    inline void WriteRideIntoRecord(const RideInfo& rideInfo) {
      reinterpret_cast<void(__thiscall*)(FECustomizationRecord*, const RideInfo&)>(0x4C47F0)(this, rideInfo);
    }
    inline void WriteToGame(Attrib::StringKey collectionKey, VehicleCustomizations* out_VehicleParams) {
      reinterpret_cast<void(__thiscall*)(FECustomizationRecord*, Attrib::StringKey, VehicleCustomizations*)>(0x4BAD10)(
          this, collectionKey, out_VehicleParams);
    }
  };
}  // namespace OpenSpeed::Carbon
