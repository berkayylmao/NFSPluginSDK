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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_GEN_PRESETRIDE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_GEN_PRESETRIDE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Instance.h>

namespace NFSPluginSDK::ProStreet::Attrib::Gen {
  struct presetride : Instance {
    static presetride TryGetInstance(std::uint32_t key) {
      presetride instance;
      reinterpret_cast<presetride*(__thiscall*)(presetride&, std::uint32_t, bool)>(0x4D4120)(instance, key, false);

      return instance;
    }
    static presetride TryGetInstance(const char* name) { return TryGetInstance(StringToKey(name)); }
  };
}  // namespace NFSPluginSDK::ProStreet::Attrib::Gen

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_GEN_PRESETRIDE_H
