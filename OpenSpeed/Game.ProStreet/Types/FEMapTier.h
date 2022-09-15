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
#include <OpenSpeed/Core/EASTL/EASTL/list.h>

#include <OpenSpeed/Game.ProStreet/Types.h>

namespace OpenSpeed::ProStreet {
  struct FEMapTier {
    std::uint32_t          mTierKey;
    std::uint32_t          mFirstHub;
    eastl::list<FEMapHub*> mHubList;
    char                   mTierId;
    bool                   mIsShowDown;
    bool                   mIsElite;
    std::uint32_t          mHubWonCount;
    std::uint32_t          mHubDominateCount;
    std::uint32_t          mHubRecordCount;
    std::uint32_t          mPrevHubWonCount;
    std::uint32_t          mPrevHubDominateCount;
    std::uint32_t          mPrevHubRecordCount;
    std::uint32_t          mHubReqWonCount;
    std::uint32_t          mHubReqDominateCount;
    std::uint32_t          mHubReqRecordCount;
    std::uint32_t          mTierTrackRecordReq;
  };
}  // namespace OpenSpeed::ProStreet
