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

#pragma once
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/AllocationHeader.h>
#include <OpenSpeed/Game.ProStreet/Types/bList.h>
#include <OpenSpeed/Game.ProStreet/Types/bMutex.h>
#include <OpenSpeed/Game.ProStreet/Types/FreeBlock.h>

namespace OpenSpeed::ProStreet {
  struct MemoryPool {
    const char*              pDebugName;
    bTList<FreeBlock>        FreeBlockList;
    bTList<AllocationHeader> AllocationHeaderList;
    std::int32_t             InitialAddress;
    std::int32_t             InitialSize;
    std::int32_t             NumAllocations;
    std::int32_t             TotalNumAllocations;
    std::int32_t             PoolSize;
    std::int32_t             AmountAllocated;
    std::int32_t             MostAmountAllocated;
    std::int32_t             AmountFree;
    std::int32_t             LeastAmountFree;
    bool                     DebugFillEnabled;
    bool                     DebugTracingEnabled;
    bMutex                   Mutex;
  };
}  // namespace OpenSpeed::ProStreet
