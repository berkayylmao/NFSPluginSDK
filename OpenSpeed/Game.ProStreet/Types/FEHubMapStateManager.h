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
#include <OpenSpeed/Game.ProStreet/Types/FEAnimMenuStateData.h>
#include <OpenSpeed/Game.ProStreet/Types/FEStateManager.h>

namespace OpenSpeed::ProStreet {
  struct FEHubMapStateManager : FEStateManager<> {
    std::uint32_t           mActiveHubKey;
    eastl::list<FEMapTier*> mTierList;
    FEMapHub*               mLastHubEntered;
    FEAnimMenuStateData*    mpStateData;
    std::uint32_t           mLastTreeState;
    bool                    mIsSplitScreenHub;
    std::int32_t            mIndexOfRaceDayToBeDeleted;
    char                    mMovieNameToPlay[64];
    bool                    mCrownAnimationPlayed;
    bool                    mNeedToFireIceCamDone;
    bool                    mWaitingOnDiskError;

    static FEHubMapStateManager* Get() {
      static auto** spInstance = reinterpret_cast<FEHubMapStateManager**>(0xB32BE0);
      if (!spInstance) return nullptr;

      return *spInstance;
    }
  };
}  // namespace OpenSpeed::ProStreet
