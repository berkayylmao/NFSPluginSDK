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

namespace OpenSpeed::MW05 {
  struct FECarRecord {
    std::uint32_t Handle;
    std::uint32_t FEKey;
    std::uint32_t VehicleKey;
    std::uint32_t FilterBits;
    std::uint8_t  Customization;
    std::uint8_t  CareerHandle;
    std::uint16_t Padd;

    inline std::int32_t GetCost() { return reinterpret_cast<std::int32_t(__thiscall*)(FECarRecord*)>(0x581730)(this); }
    inline const char*  GetManufacturerName() {
      return reinterpret_cast<const char*(__thiscall*)(FECarRecord*)>(0x581790)(this);
    }
    CarType GetType() { return reinterpret_cast<CarType(__thiscall*)(FECarRecord*)>(0x5816B0)(this); }
  };
}  // namespace OpenSpeed::MW05
