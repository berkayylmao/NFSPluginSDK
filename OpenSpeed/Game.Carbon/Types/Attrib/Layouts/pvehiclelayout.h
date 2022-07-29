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
#include <OpenSpeed/Game.Carbon/Types.h>

namespace OpenSpeed::Carbon::Attrib::Layouts {
  struct pvehiclelayout {
    enum class CarType : std::uint32_t {
      McLaren     = 1 << 0,
      Porsche     = 1 << 1,
      FordGT      = 1 << 2,
      Viper       = 1 << 3,
      AstonMartin = 1 << 4,
      Corvette    = 1 << 5,
      BMW         = 1 << 6,
      Mercedes    = 1 << 7,
      Audi        = 1 << 8,
      Mitsubishi  = 1 << 9,
      Mustang     = 1 << 10,
      Lotus       = 1 << 11,
      Subaru      = 1 << 12,
      Camaro      = 1 << 13,
      GTO         = 1 << 14,
      Nissan      = 1 << 15,
      Mazda       = 1 << 16,
      Renault     = 1 << 17,
      Lexus       = 1 << 18,
      Mini        = 1 << 19,
      Volkswagen  = 1 << 20,
      SUV         = 1 << 21,
      Pickup      = 1 << 22,
      Pagani      = 1 << 23,
      Lamborghini = 1 << 24,
      Chrysler    = 1 << 25,
      Opel        = 1 << 26,
      Sedan       = 1 << 27,
      SportsCar   = 1 << 28,
      Supra       = 1 << 29,
      Cadillac    = 1 << 30
    };

    UMath::Vector4 TENSOR_SCALE;
    StringKey      MODEL;
    const char*    DefaultPresetRide;
    const char*    CollectionName;
    std::int32_t   engine_upgrades;
    std::int32_t   transmission_upgrades;
    std::int32_t   nos_upgrades;
    std::int32_t   brakes_upgrades;
    float          MASS;
    std::int32_t   tires_upgrades;
    CarType        VerbalType;
    std::int32_t   induction_upgrades;
    std::int32_t   chassis_upgrades;
    std::uint8_t   HornType;
    std::uint8_t   TrafficEngType;
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(pvehiclelayout::CarType)
#endif
}  // namespace OpenSpeed::Carbon::Attrib::Layouts
