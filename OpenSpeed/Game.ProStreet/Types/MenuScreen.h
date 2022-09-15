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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_MENUSCREEN_H
#define OPENSPEED_GAME_PROSTREET_TYPES_MENUSCREEN_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/ScreenConstructorData.h>

namespace OpenSpeed::ProStreet {
  struct MenuScreen {
    bool                  mPlaySound;
    std::uint32_t         mDirectionForNextSound;
    const char*           mpPackageFilename;
    ScreenConstructorData mConstructData;
    bool                  mIsGarageScreen;

    virtual ~MenuScreen();
    virtual eMenuSoundTriggers NotifySoundMessage(std::uint32_t, eMenuSoundTriggers);
    virtual void               SetInitialOption(std::uint32_t);
    virtual void               SetInitialOptionUsingDescHash(std::uint32_t);
    virtual void               ShowHelpbar(char*);
    virtual void               ShowScreen(bool);
    virtual void               InitInstance();
    virtual void               SetAspectRatio();
    virtual void               __unk_related_to_lan_raceday();
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_MENUSCREEN_H
