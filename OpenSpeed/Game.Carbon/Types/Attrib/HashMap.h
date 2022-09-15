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

#ifndef OPENSPEED_GAME_CARBON_TYPES_ATTRIB_HASHMAP_H
#define OPENSPEED_GAME_CARBON_TYPES_ATTRIB_HASHMAP_H
#pragma once

#include <OpenSpeed/Game.Carbon/Types.h>

namespace OpenSpeed::Carbon::Attrib {
  struct HashMap {
    Node*         mTable;
    std::uint32_t mTableSize;
    std::uint32_t mNumEntries;
    std::uint16_t mWorstCollision;
    std::uint16_t mKeyShift;
  };
}  // namespace OpenSpeed::Carbon::Attrib

#endif  // OPENSPEED_GAME_CARBON_TYPES_ATTRIB_HASHMAP_H
