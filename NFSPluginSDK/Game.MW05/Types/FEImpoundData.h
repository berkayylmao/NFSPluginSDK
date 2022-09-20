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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_FEIMPOUNDDATA_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_FEIMPOUNDDATA_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05 {
  struct FEImpoundData {
    std::uint8_t    MaxBusted;
    std::int8_t     TimesBusted;
    eImpoundReasons ImpoundedState;
    std::uint8_t    DaysBeforeRelease;
    std::int8_t     EvadeCount;
    std::int8_t     Pad1;
    std::int16_t    Pad2;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_FEIMPOUNDDATA_H
