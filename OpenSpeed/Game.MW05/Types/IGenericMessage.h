// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct IGenericMessage : UTL::COM::IUnknown {
    enum class Priority : std::uint32_t { Priority5, Priority4, Priority3, Priority2, Priority1 };

    virtual ~IGenericMessage();
    virtual void     RequestGenericMessage(char const* text, bool, std::uint32_t, std::uint32_t, std::uint32_t,
                                           Priority    priority)    = 0;
    virtual void     RequestGenericMessageZoomOut(std::uint32_t) = 0;
    virtual bool     IsGenericMessageShowing()                   = 0;
    virtual Priority GetCurrentGenericMessagePriority()          = 0;

    static IHandle* GetHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x5650B0)(); }
  };
}  // namespace OpenSpeed::MW05
