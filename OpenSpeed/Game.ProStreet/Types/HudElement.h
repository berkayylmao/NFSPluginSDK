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
#include <OpenSpeed/Game.ProStreet/Types/FEObject.h>

namespace OpenSpeed::ProStreet {
  struct HudElement {
    enum class eHudElementIds : std::uint32_t {
      kTachometer,
      kRaceOver,
      kLeaderboard,
      kLeaderboard4Up,
      kSplitTime,
      kWrongWay,
      kFullScreenFade,
      kSectorDisplay,
      k321Go,
      kNitrous,
      kBoostGauge,
      kMinimap,
      kGenericMessage,
      kTimeExtension,
      kRaceInformation,
      kDriftScores,
      kRevolutionWheel,
      kFadeToBlack,
      kGameplayDebug,
      kPositionIndicator,
      kDragStats,
      kTurnIndicator,
      kDragStagingMeter,
      kLapTime
    };

    enum class eHudEvent : std::uint32_t { kDoLeaderBoardPopup };

    bPList<FEObject> mObjects;
    const char*      mpPackageName;
    bool             mIsVisible;

    virtual ~HudElement();
    virtual void        Update(IPlayer*);
    virtual void        StartNewMode(IPlayer*, std::int32_t);
    virtual void        Refresh();
    virtual void        OnEvent(eHudEvent event);
    virtual const char* GetDebugName();
  };
}  // namespace OpenSpeed::ProStreet
