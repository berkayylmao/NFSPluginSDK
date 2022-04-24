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
#include <OpenSpeed/Game.MW05/Types/UTL/List.h>

namespace OpenSpeed::MW05::UTL {
  template <typename T, std::size_t nT, typename E, std::size_t nE>
  struct _ListSet {
    List<T, nT> _buckets[nE];

    List<T, nT>&       operator[](std::size_t index) noexcept { return _buckets[index]; }
    const List<T, nT>& operator[](std::size_t index) const noexcept { return _buckets[index]; }
    List<T, nT>&       operator[](E index) noexcept { return _buckets[static_cast<std::size_t>(index)]; }
    const List<T, nT>& operator[](E index) const noexcept { return _buckets[static_cast<std::size_t>(index)]; }
  };
}  // namespace OpenSpeed::MW05::UTL
