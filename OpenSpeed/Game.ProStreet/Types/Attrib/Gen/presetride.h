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
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Instance.h>

namespace OpenSpeed::ProStreet::Attrib::Gen {
  struct presetride : Instance {
    static presetride TryGetInstance(std::uint32_t key) {
      presetride instance;
      reinterpret_cast<presetride*(__thiscall*)(presetride&, std::uint32_t, bool)>(0x4D4120)(instance, key, false);

      return instance;
    }
    static presetride TryGetInstance(const char* name) { return TryGetInstance(StringToKey(name)); }
  };
}  // namespace OpenSpeed::ProStreet::Attrib::Gen
