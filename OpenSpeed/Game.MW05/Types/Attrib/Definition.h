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

#ifndef OPENSPEED_GAME_MW05_TYPES_ATTRIB_DEFINITION_H
#define OPENSPEED_GAME_MW05_TYPES_ATTRIB_DEFINITION_H
#pragma once

#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05::Attrib {
  struct Definition {
    enum class Flags : std::uint8_t {
      Array           = 1 << 0,
      InLayout        = 1 << 1,
      IsBound         = 1 << 2,
      IsNotSearchable = 1 << 3,
    };

    std::uint32_t mKey;
    std::uint32_t mType;
    std::uint16_t mOffset;
    std::uint16_t mSize;
    std::uint16_t mMaxCount;
    Flags         mFlags;
    std::uint8_t  mAlignment;
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(Definition::Flags)
#endif
}  // namespace OpenSpeed::MW05::Attrib

#endif  // OPENSPEED_GAME_MW05_TYPES_ATTRIB_DEFINITION_H
