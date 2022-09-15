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
#include <OpenSpeed/Game.ProStreet/Types/ActionQueue.h>
#include <OpenSpeed/Game.ProStreet/Types/FEGroup.h>
#include <OpenSpeed/Game.ProStreet/Types/FEMapHubPopupWindow.h>
#include <OpenSpeed/Game.ProStreet/Types/FEMapTier.h>
#include <OpenSpeed/Game.ProStreet/Types/MenuScreen.h>

namespace OpenSpeed::ProStreet {
  struct FEMapScreen : MenuScreen {
    enum class ZoomState : std::uint8_t { Tier, NonSelect, Hub, All };

    eastl::list<FEMapTier*>*                                  mTierList;
    FEMapHub*                                                 mSelectedHub;
    eastl::ListIterator<FEMapTier*, FEMapTier**, FEMapTier*&> mSelectedTierIter;
    ActionQueue*                                              mActionQ;
    bVector2                                                  mActionQDirection;
    float                                                     mSelectionWait;
    FEGroup* const                                            mTagGroup;
    FEMapStreamer*                                            mMapStreamer;
    FEMapHubPopupWindow*                                      mPopWindow;
    FEMapHubPopupWindow::eDirection                           mPopupEventDir;
    FEObject* const                                           mPopupBacking;
    ZoomState                                                 mZoomState;
    bVector2                                                  mLastZoom;
    FEHubAnimController*                                      mHubAnimController;
    bool                                                      mScreenEntered;
    bool                                                      mCameraMoving;
    std::uint32_t                                             mTierPanGroupHash;

    static FEMapScreen* Get() {
      static auto** spInstance = reinterpret_cast<FEMapScreen**>(0xB32BC4);
      if (!spInstance) return nullptr;

      return *spInstance;
    }
  };
}  // namespace OpenSpeed::ProStreet
