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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FEINFRACTIONSDATA_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FEINFRACTIONSDATA_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>

namespace OpenSpeed::ProStreet {
  struct FEInfractionsData {
    std::uint16_t Speeding;
    std::uint16_t Racing;
    std::uint16_t Reckless;
    std::uint16_t Assault;
    std::uint16_t HitAndRun;
    std::uint16_t Damage;
    std::uint16_t Resist;
    std::uint16_t OffRoad;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FEINFRACTIONSDATA_H
