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

namespace OpenSpeed::ProStreet::Attrib {
  struct Class {
    std::uint32_t         mKey;
    Attrib::ClassPrivate* mPrivates;

    inline Collection* GetCollection(StringKey key) {
      return reinterpret_cast<Collection*(__thiscall*)(Class*, StringKey)>(0x52C820)(this, key);
    }
    inline std::uint32_t GetNumCollections() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x52B520)(this);
    }
    inline std::uint32_t GetFirstCollection() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x402BC0)(this);
    }
    inline std::uint32_t GetNextCollection(StringKey key) {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*, StringKey)>(0x4F4390)(this, key);
    }
  };
}  // namespace OpenSpeed::ProStreet::Attrib
