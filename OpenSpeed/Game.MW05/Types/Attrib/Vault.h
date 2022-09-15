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

#ifndef OPENSPEED_GAME_MW05_TYPES_ATTRIB_VAULT_H
#define OPENSPEED_GAME_MW05_TYPES_ATTRIB_VAULT_H
#pragma once

#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05::Attrib {
  struct Vault {
    std::uint32_t   mRefCount;
    ExportManager&  mExportMgr;
    DependencyNode* mDependencies;
    DataBlock*      mDepData;
    std::uint32_t*  mDepIDs;
    std::uint32_t   mNumDependencies;
    std::uint32_t   mResolvedCount;
    PointerNode*    mPointers;
    std::uint8_t*   mTransientData;
    ChunkBlock*     mStrings;
    ExportNode*     mExports;
    DataBlock*      mExportData;
    std::uint32_t*  mExportIDs;
    std::uint32_t   mNumExports;
    bool            mInited;
    bool            mDeinited;
  };
}  // namespace OpenSpeed::MW05::Attrib

#endif  // OPENSPEED_GAME_MW05_TYPES_ATTRIB_VAULT_H
