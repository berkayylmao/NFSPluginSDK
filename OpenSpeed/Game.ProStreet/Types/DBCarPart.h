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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_DBCARPART_H
#define OPENSPEED_GAME_PROSTREET_TYPES_DBCARPART_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Game.h>
#include <OpenSpeed/Game.ProStreet/Types/CarPartAttribute.h>

namespace OpenSpeed::ProStreet {
  struct DBCarPart {
    bool                mIsValid;
    std::uint8_t        mCarTypeNameHashIndex;
    std::uint16_t       mAttributeTableOffset;
    Attrib::Collection* mPartAttributes;
    std::uint16_t       mKitNum;
    std::uint16_t       mMaterialFlags;
    char                _pad;

    CarPartAttribute* GetAttribute() {
      return reinterpret_cast<CarPartAttribute*(__thiscall*)(DBCarPart*, std::uint32_t, std::uint32_t)>(0x754CD0)(
          this, Game::bStringHash("PARTID_UPGRADE_GROUP"), 0);
    }
    std::uint32_t GetCarTypeNameHash() {
      static MemoryFieldWrapper<std::uint32_t*> sCarPartTypeNameHashTable{0xAEB774, nullptr};
      return sCarPartTypeNameHashTable[mCarTypeNameHashIndex];
    }
    std::uint32_t GetGroupNumber() { return reinterpret_cast<std::int32_t(__thiscall*)(DBCarPart*)>(0x76AB50)(this); }
    std::uint32_t GetPartID() { return reinterpret_cast<std::int32_t(__thiscall*)(DBCarPart*)>(0x76AB20)(this); }
    std::uint32_t GetUpgradeLevel() {
      if (auto* attribute = GetAttribute()) return attribute->muParam >> 5;
      return 0;
    }

    DBCarPart() = default;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_DBCARPART_H
