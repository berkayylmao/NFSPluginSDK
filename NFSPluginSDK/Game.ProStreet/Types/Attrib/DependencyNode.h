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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_DEPENDENCYNODE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_DEPENDENCYNODE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/ChunkBlock.h>

namespace NFSPluginSDK::ProStreet::Attrib {
  struct DependencyNode : ChunkBlock {
    std::uint32_t mCount;
  };
}  // namespace NFSPluginSDK::ProStreet::Attrib

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_DEPENDENCYNODE_H
