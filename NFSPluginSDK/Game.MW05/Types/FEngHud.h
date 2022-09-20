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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_FENGHUD_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_FENGHUD_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/ActionQueue.h>
#include <NFSPluginSDK/Game.MW05/Types/IHud.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct FEngHud : UTL::COM::Object, IHud {
    std::uint64_t  CurrentHudFeatures;
    ePlayerHudType mPlayerHudType;
    const char*    pPackageName;
    IPlayer*       pPlayer;
    std::int32_t   PlayerNumber;
    ActionQueue    mActionQ;
    bool           mInPursuit;
    bool           mHasTurbo;
    HudElement*    pSpeedometer;
    HudElement*    pTachometer;
    HudElement*    pTachometerDrag;
    HudElement*    pShiftUpdater;
    HudElement*    pCostToState;
    HudElement*    pReputation;
    HudElement*    pHeatMeter;
    HudElement*    pTurboMeter;
    HudElement*    pEngineTemp;
    HudElement*    pNitrous;
    HudElement*    pSpeedBreakerMeter;
    HudElement*    pRaceOverMessage;
    HudElement*    pGenericMessage;
    HudElement*    pAutoSaveIcon;
    HudElement*    pRaceInformation;
    HudElement*    pLeaderBoard;
    HudElement*    pPursuitBoard;
    HudElement*    pMilestoneBoard;
    HudElement*    pBustedMeter;
    HudElement*    pTimeExtension;
    HudElement*    pWrongWIndi;
    HudElement*    pOnlineSupport;
    HudElement*    p321Go;
    HudElement*    pRadarDetector;
    HudElement*    pMinimap;
    HudElement*    pGetAwayMeter;
    HudElement*    pMenuZoneTrigger;
    HudElement*    pInfractions;
    bool           mCurrentWidescreenSetting;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_FENGHUD_H
