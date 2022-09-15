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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_IPLAYER_H
#define OPENSPEED_GAME_PROSTREET_TYPES_IPLAYER_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct IPlayer : UTL::COM::IUnknown {
    virtual ~IPlayer();
    virtual ISimable*             GetSimable()                                = 0;
    virtual bool                  IsLocal()                                   = 0;
    virtual const UMath::Vector3& GetPosition()                               = 0;
    virtual bool                  SetPosition(const UMath::Vector3& position) = 0;
    virtual PlayerSettings*       GetSettings()                               = 0;
    virtual void                  SetSettings(std::int32_t)                   = 0;
    virtual std::int32_t          GetSettingsIndex()                          = 0;
    virtual IHud*                 GetHud()                                    = 0;
    virtual void                  ResetHudType()                              = 0;
    virtual void                  ReleaseHud()                                = 0;
    virtual void                  SetRenderPort(std::int32_t)                 = 0;
    virtual std::int32_t          GetRenderPort()                             = 0;
    virtual void                  SetControllerPort(std::int32_t)             = 0;
    virtual std::int32_t          GetControllerPort()                         = 0;
    virtual IFeedback*            GetFFB()                                    = 0;
    virtual ISteeringWheel*       GetSteeringDevice()                         = 0;
    virtual bool                  InGameBreaker()                             = 0;
    virtual bool                  CanRechargeNOS()                            = 0;
    virtual void                  ResetGameBreaker(bool fill)                 = 0;
    virtual void                  ChargeGameBreaker(float amount)             = 0;
    virtual float                 GetGameBreakerCharge()                      = 0;
    virtual bool                  ToggleGameBreaker()                         = 0;
    virtual float                 GetNOSModifier()                            = 0;
    virtual void                  SetNOSModifier(float amount)                = 0;
    virtual void                  SetGameBreakerModifier(float amount)        = 0;
    virtual void                  SetEncounterMessage(std::int32_t)           = 0;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_IPLAYER_H
