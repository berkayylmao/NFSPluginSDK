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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_RACEPREPARATIONINFO_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_RACEPREPARATIONINFO_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05 {
  struct RacePreparationInfo {
    enum class Flags : std::uint32_t { NONE, RESET_DAMAGE };

    UMath::Vector3 mPosition;
    float          mSpeed;
    UMath::Vector3 mDirection;
    float          mHeatLevel;
    Flags          mFlags;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_RACEPREPARATIONINFO_H