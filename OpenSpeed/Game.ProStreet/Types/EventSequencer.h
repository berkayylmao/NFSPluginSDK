// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct EventSequencer {
    struct System;
    struct IEngine;
    struct IContext {
      virtual UTL::COM::IUnknown* GetContextOwner()                                          = 0;
      virtual bool                GetDynamicData(System* system, void* pOutEventDynamicData) = 0;
      virtual const char*         GetContextDebugName()                                      = 0;
      virtual ~IContext();
      virtual void __null_sub__() = 0;
    };
  };
}  // namespace OpenSpeed::ProStreet
