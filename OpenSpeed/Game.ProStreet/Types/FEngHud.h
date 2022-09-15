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
//    but WITHOUT ANY WARRANTY=0; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FENGHUD_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FENGHUD_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/ActionQueue.h>
#include <OpenSpeed/Game.ProStreet/Types/HudElement.h>
#include <OpenSpeed/Game.ProStreet/Types/ICountdown.h>
#include <OpenSpeed/Game.ProStreet/Types/IHud.h>

namespace OpenSpeed::ProStreet {
  struct FEngHud : UTL::COM::Object, IHud, ICountdown {
    ePlayerHudType         mPlayerHudType;
    IPlayer*               mPlayer;
    std::int32_t           mPlayerNumber;
    ActionQueue            mActionQ;
    bool                   mShouldDeleteHUD;
    std::int32_t           mUpdateCount;
    ResourceFile*          mpHudBundleFile;
    const char*            mpPackageName;
    FEObject*              mFEObjSpeedSensitiveGroup;
    FEObject*              mFEObjMainGroup;
    FEObject*              mFEObjRvmGroup;
    HudElement*            mHudElements[24];
    std::uint64_t          mCurrentHudFeatures;
    std::uint64_t          mRaceHudFeatures;
    std::uint64_t          mOptionsHudFeatures;
    std::uint64_t          mGameFlowHudFeatures;
    std::uint64_t          mEventDrivenHudFeatures;
    bool                   mWasInitialized;
    bool                   mCurrentWidescreenSetting;
    Hermes::_h_HHANDLER__* mMsgShowHUD;
    Hermes::_h_HHANDLER__* mMsgHideHUD;
    bool                   mHideAll;
    bool                   mHideHUDTillGo;

    virtual ~FEngHud();
    virtual void           Update(IPlayer*, float) override;
    virtual void           Release() override;
    virtual void           HideAll() override;
    virtual void           FadeAllForSpeedBreaker(bool fade) override;
    virtual void           FadeAll(bool fade) override;
    virtual bool           AreResourcesLoaded() override;
    virtual bool           IsHudVisible() override;
    virtual bool           IsRvmVisible() override;
    virtual void           JoyEnable() override;
    virtual void           JoyDisable() override;
    virtual void           RefreshMiniMapItems() override;
    virtual void           StartNewMode(IPlayer*) override;
    virtual bool           ShouldDeleteHUD() override;
    virtual void           SetShouldDeleteHUD(bool deleteHUD) override;
    virtual float          GetRearViewMirrorAlpha() override;
    virtual void           SetDebugText(int, const char* text) override;
    virtual ePlayerHudType GetHudType() override;
    virtual void           ShowGO() override;
    virtual bool           WasInitialized() override;
    virtual void           BeginCountdown(std::int32_t countdown) override;
    virtual bool           IsActive() override;
    virtual float          GetSecondsBeforeRaceStart() override;

    HudElement* GetHudElement(HudElement::eHudElementIds id) { return mHudElements[static_cast<std::uint32_t>(id)]; }
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FENGHUD_H
