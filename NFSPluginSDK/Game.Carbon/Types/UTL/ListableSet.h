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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_UTL_LISTABLESET_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_UTL_LISTABLESET_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL/FixedVector.h>

namespace NFSPluginSDK::Carbon::UTL {
  template <typename T, std::size_t nT, typename E, std::size_t nE>
  struct ListableSet {
    struct List : FixedVector<T*, nT> {};
    struct _ListSet {
      List _buckets[nE];

      List&       operator[](std::size_t index) noexcept { return _buckets[index]; }
      const List& operator[](std::size_t index) const noexcept { return _buckets[index]; }
      List&       operator[](E index) noexcept { return _buckets[static_cast<std::size_t>(index)]; }
      const List& operator[](E index) const noexcept { return _buckets[static_cast<std::size_t>(index)]; }
    };
  };
}  // namespace NFSPluginSDK::Carbon::UTL

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_UTL_LISTABLESET_H
