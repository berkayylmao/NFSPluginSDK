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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ARRAYSCROLLER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ARRAYSCROLLER_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/bList.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ArrayDatum.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ArraySlot.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEScrollBar.h>

namespace NFSPluginSDK::ProStreet {
  struct ArrayScroller {
    bool               mShouldPlaySound;
    bTList<ArraySlot>  mSlots;
    bTList<ArrayDatum> mData;
    ArrayDatum*        mCurrentDatum;
    std::int32_t       mStartDatum;
    std::int32_t       mEndDatum;
    std::int32_t       mWidth;
    std::int32_t       mHeight;
    std::uint32_t      mDescLabel;
    FEPackage*         mPkg;
    FEScrollBar        mScrollBar;
    bool               mBSelectableArray;
    ArrayScripts       mScripts;
    std::uint32_t      mMouseDownMsg;
    bool               mInClickToSelectMode;
    bool               mSingleScroll;
    bool               mCodeCenter;
    bool               mHwrap;
    FEObject*          mCursor;

    virtual ~ArrayScroller();
    virtual void NotificationMessage(std::uint32_t, FEObject*, std::uint32_t, std::uint32_t);
    virtual void RefreshHeader();
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ARRAYSCROLLER_H
