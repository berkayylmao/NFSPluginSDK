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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FESTRING_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FESTRING_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/FEObject.h>
#include <OpenSpeed/Game.ProStreet/Types/FEWideString.h>

namespace OpenSpeed::ProStreet {
  struct FEString : FEObject {
    char*              pLabelName;
    std::uint32_t      LabelHash;
    FEWideString       string;
    FEStringFormatting Format;
    std::int32_t       Leading;
    std::uint32_t      MaxWidth;

    template <typename... Arguments>
    static void Printf(const char* fngName, std::uint32_t objectHash, const char* format, Arguments... args) {
      reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t, const char*, Arguments...)>(0x5CE4F0)(
          fngName, objectHash, format, args...);
    }
    static void SetLanguageHash(const char* fngName, std::uint32_t objectHash, std::uint32_t languageHash) {
      reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t, std::uint32_t)>(0x5BE5F0)(fngName, objectHash,
                                                                                            languageHash);
    }
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FESTRING_H
