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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARPARTATTRIBUTE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARPARTATTRIBUTE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/ProStreet.h>

namespace NFSPluginSDK::ProStreet {
  struct CarPartAttribute {
    std::uint32_t mNameHash;
    union {
      float         mfParam;
      std::int32_t  miParam;
      std::uint32_t muParam;
    };
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARPARTATTRIBUTE_H
