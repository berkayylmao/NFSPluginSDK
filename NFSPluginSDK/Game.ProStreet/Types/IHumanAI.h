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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_IHUMANAI_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_IHUMANAI_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct IHumanAI : UTL::COM::IUnknown {
    virtual ~IHumanAI();
    virtual bool                  IsPlayerSteering()                                           = 0;
    virtual bool                  GetAiControl()                                               = 0;
    virtual void                  SetAiControl(bool aiControl)                                 = 0;
    virtual void                  SetWorldMoment(const UMath::Vector3& position, float radius) = 0;
    virtual const UMath::Vector3& GetWorldMomentPosition()                                     = 0;
    virtual float                 GetWorldMomentRadius()                                       = 0;
    virtual void                  ClearWorldMoment()                                           = 0;
    virtual bool                  IsFacingWrongWay()                                           = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4087C0)(); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_IHUMANAI_H
