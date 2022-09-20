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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GVAULT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GVAULT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/LoggingAttribAllocator.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Vault.h>

namespace NFSPluginSDK::ProStreet {
  struct GVault {
    Attrib::Vault*                  mVault;
    const char*                     mVaultName;
    std::uint32_t                   mFlags;
    void*                           mBinResidentData;
    std::uint32_t                   mBinOffset;
    std::uint32_t                   mBinSize;
    std::uint32_t                   mVltOffset;
    std::uint32_t                   mVltSize;
    Attrib::LoggingAttribAllocator* mAttribAllocator;
    std::uint32_t                   mAttribObjSize;
    std::uint32_t                   mAttribAllocChecksum;
    void*                           mAttribTransientData;
    std::uint32_t                   mGameObjSize;
    std::uint32_t                   mGameObjCount;
    std::uint32_t                   mCollectionCount;
    GObjectBlock*                   mGameObjBlock;
    void*                           mGameObjData;
    std::uint32_t                   mAssetID;
    std::uint32_t                   mLoadTime;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GVAULT_H
