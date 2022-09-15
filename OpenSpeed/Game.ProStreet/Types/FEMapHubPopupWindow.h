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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FEMAPHUBPOPUPWINDOW_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FEMAPHUBPOPUPWINDOW_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/FEGroup.h>
#include <OpenSpeed/Game.ProStreet/Types/Timer.h>

namespace OpenSpeed::ProStreet {
  struct FEMapHubPopupWindow {
    enum class eMode : std::uint8_t { HiddenView, PreviewView, DetailedView };
    enum class eDirection : std::uint8_t { None, Left, Right, Up, Down };

    const char* const mPkgName;
    FEGroup* const    mPopupWindow;
    FEGroup* const    mPositionGroup;
    FEGroup* const    mRaceDayInfo;
    FEGroup* const    mEventDetails;
    FEImage* const    mInfoPanelArrow;
    FEMapHub*         mCurrentHub;
    Timer             mTimer;
    const float       mWindowDelayTime;
    eMode             mWindowMode;
    std::int8_t       mCurrEventIndex;
    bool              mEnterRaceDaySelected;
    std::uint32_t     mLoadingPreview;
    std::uint32_t     mLoadedPreview;
    std::uint32_t     mDesiredLoadingPreview;
    std::int32_t      mIsWidescreen;
    bool              mIsSoundTemplatePushed;
    // DALOnlineStats::GetHubTopFriendCommand* mpTopFriendScore;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FEMAPHUBPOPUPWINDOW_H
