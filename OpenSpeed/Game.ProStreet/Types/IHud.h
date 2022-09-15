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

#pragma once
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/IPlayer.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct IHud : UTL::COM::IUnknown {
    virtual ~IHud();
    virtual void           Update(IPlayer*, float)             = 0;
    virtual void           Release()                           = 0;
    virtual void           HideAll()                           = 0;
    virtual void           FadeAllForSpeedBreaker(bool fade)   = 0;
    virtual void           FadeAll(bool fade)                  = 0;
    virtual bool           AreResourcesLoaded()                = 0;
    virtual bool           IsHudVisible()                      = 0;
    virtual bool           IsRvmVisible()                      = 0;
    virtual void           JoyEnable()                         = 0;
    virtual void           JoyDisable()                        = 0;
    virtual void           RefreshMiniMapItems()               = 0;
    virtual void           StartNewMode(IPlayer*)              = 0;
    virtual bool           ShouldDeleteHUD()                   = 0;
    virtual void           SetShouldDeleteHUD(bool deleteHUD)  = 0;
    virtual float          GetRearViewMirrorAlpha()            = 0;
    virtual void           SetDebugText(int, const char* text) = 0;
    virtual ePlayerHudType GetHudType()                        = 0;
    virtual void           ShowGO()                            = 0;
    virtual bool           WasInitialized()                    = 0;
  };
}  // namespace OpenSpeed::ProStreet
