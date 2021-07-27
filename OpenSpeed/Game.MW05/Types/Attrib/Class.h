// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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

namespace OpenSpeed::MW05::Attrib {
  struct Class {
    std::uint32_t mKey;
    std::uint32_t mRefCount;
    ClassPrivate& mPrivates;

    Definition* GetDefinition(StringKey key) {
      return reinterpret_cast<Definition*(__thiscall*)(Class*, StringKey)>(0x457380)(this, key);
    }
    std::uint32_t GetNumDefinitions() { return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x451660)(this); }
    std::uint32_t GetFirstDefinition() { return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x451670)(this); }
    std::uint32_t GetNextDefinition(StringKey key) {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*, StringKey)>(0x4573C0)(this, key);
    }

    Collection* GetCollection(StringKey key) {
      return reinterpret_cast<Collection*(__thiscall*)(Class*, StringKey)>(0x455960)(this, key);
    }
    std::uint32_t GetNumCollections() { return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x453FC0)(this); }
    std::uint32_t GetFirstCollection() { return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x456B00)(this); }
    std::uint32_t GetNextCollection(StringKey key) {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*, StringKey)>(0x456B20)(this, key);
    }
  };
}  // namespace OpenSpeed::MW05::Attrib
