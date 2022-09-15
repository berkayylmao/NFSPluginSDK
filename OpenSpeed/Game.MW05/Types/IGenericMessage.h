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

#ifndef OPENSPEED_GAME_MW05_TYPES_IGENERICMESSAGE_H
#define OPENSPEED_GAME_MW05_TYPES_IGENERICMESSAGE_H
#pragma once

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct IGenericMessage : UTL::COM::IUnknown {
    enum class FEngTypes : std::uint32_t {
      None,
      Type1 = 0x8AB83EDB,  // [White Text] Fades out towards bottom of the screen
      Type2 = 0x9D73BC15,  // [White Text] Fades out towards player camera
      Type3 = 0x5230FAF6,  // [Red Text] Fades out towards top of the screen
      Type4 = 0xA19BB14C,  // [Green Text] Fades out towards bottom of the screen
      Type5 = 0x821E6378   // [Green/White Text] Flashes and is kept alive
    };
    enum class IconDisplayTypes : std::uint32_t {
      HideIcon,
      ShowIcon = 0x609F6B15,  // [Flashing background] Fades out towards bottom of the screen
    };
    enum class Priority : std::uint32_t { Priority5, Priority4, Priority3, Priority2, Priority1 };

    virtual ~IGenericMessage();
    virtual void     RequestGenericMessage(char const* text, bool playOneFrame, Attrib::StringKey fengHash,
                                           std::uint32_t iconHash, Attrib::StringKey iconDisplayKey, Priority priority) = 0;
    virtual void     RequestGenericMessageZoomOut(std::uint32_t) = 0;
    virtual bool     IsGenericMessageShowing()                   = 0;
    virtual Priority GetCurrentGenericMessagePriority()          = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x5650B0)(); }
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_IGENERICMESSAGE_H
