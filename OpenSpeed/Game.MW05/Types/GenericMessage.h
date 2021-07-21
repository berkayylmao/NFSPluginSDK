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
#include <OpenSpeed/Game.MW05/Types/HudElement.h>
#include <OpenSpeed/Game.MW05/Types/IGenericMessage.h>

namespace OpenSpeed::MW05 {
  struct GenericMessage : HudElement, IGenericMessage {
    FEObject*     mpMessageFirstLine;
    FEObject*     mpMessageSecondLine;
    FEObject*     mpIcon;
    Priority      mPriority;
    std::uint32_t mNumFramesPlayed;
    char          mStringBuffer[64];
    std::uint32_t mFengHash;
    bool          mPlayOneFrame;

    virtual ~GenericMessage();
    virtual void     RequestGenericMessage(char const* text, bool, std::uint32_t, std::uint32_t, std::uint32_t,
                                           Priority    priority) override;
    virtual void     RequestGenericMessageZoomOut(std::uint32_t) override;
    virtual bool     IsGenericMessageShowing() override;
    virtual Priority GetCurrentGenericMessagePriority() override;
  };
}  // namespace OpenSpeed::MW05
