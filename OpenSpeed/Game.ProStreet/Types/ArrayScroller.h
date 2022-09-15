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
#include <OpenSpeed/Game.ProStreet/Types/bList.h>
#include <OpenSpeed/Game.ProStreet/Types/ArrayDatum.h>
#include <OpenSpeed/Game.ProStreet/Types/ArraySlot.h>
#include <OpenSpeed/Game.ProStreet/Types/FEScrollBar.h>

namespace OpenSpeed::ProStreet {
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
}  // namespace OpenSpeed::ProStreet
