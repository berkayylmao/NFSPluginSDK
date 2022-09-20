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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_GRUNTIMEINSTANCE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_GRUNTIMEINSTANCE_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/gameplay.h>

namespace NFSPluginSDK::MW05 {
  struct GRuntimeInstance : Attrib::Gen::gameplay {
    struct ConnectedInstance {
      std::uint32_t     mIndexedKey;
      GRuntimeInstance* mInstance;
    };

    std::uint16_t      mFlags;
    std::uint16_t      mNumConnected;
    ConnectedInstance* mConnected;
    GRuntimeInstance*  mPrev;
    GRuntimeInstance*  mNext;

    inline bool GetDirection(UMath::Vector3& out) {
      return reinterpret_cast<bool(__thiscall*)(GRuntimeInstance*, UMath::Vector3&)>(0x5DACF0)(this, out);
    }
    inline bool GetPosition(UMath::Vector3& out) {
      return reinterpret_cast<bool(__thiscall*)(GRuntimeInstance*, UMath::Vector3&)>(0x5E2970)(this, out);
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_GRUNTIMEINSTANCE_H
