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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_GRACESTATUS_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_GRACESTATUS_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/GRacerInfo.h>
#include <NFSPluginSDK/Game.Carbon/Types/IVehicleCache.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL.h>

namespace NFSPluginSDK::Carbon {
  struct GRaceStatus : UTL::COM::Object, IVehicleCache {
    enum class PlayMode : std::uint32_t { Roaming, Racing };

    GRacerInfo   mRacerInfo[20];
    std::uint8_t __unk_GRaceStatus_1__[0x23A0];
    std::int32_t mRacerCount;
    std::uint8_t __unk_GRaceStatus_2__[0x20];
    PlayMode     mPlayMode;

    void DisableBarriers() { reinterpret_cast<void(__thiscall*)(GRaceStatus*)>(0x63DE50)(this); }

    static inline GRaceStatus** g_mThis = reinterpret_cast<GRaceStatus**>(0xA98284);
    static GRaceStatus*         Get() {
              if (!g_mThis) return nullptr;
      return *g_mThis;
    }
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_GRACESTATUS_H
