// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UMath.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct IPlayer : UTL::COM::IUnknown {
    virtual ISimable*             GetSimable()                                   = 0;
    virtual bool                  IsLocal()                                      = 0;
    virtual const UMath::Vector3& GetPosition()                                  = 0;
    virtual bool                  SetPosition(const UMath::Vector3& newPosition) = 0;
    virtual PlayerSettings*       GetSettings()                                  = 0;
    virtual void                  SetSettings(std::int32_t)                      = 0;
    virtual std::int32_t          GetSettingsIndex()                             = 0;
    virtual IHud*                 GetHud()                                       = 0;
    virtual void                  SetHud(ePlayerHudType newHudType)              = 0;
    virtual void                  SetRenderPort(int32_t)                         = 0;
    virtual std::int32_t          GetRenderPort()                                = 0;
    virtual void                  SetControllerPort(std::int32_t)                = 0;
    virtual std::int32_t          GetControllerPort()                            = 0;
    virtual IFeedback*            GetFFB()                                       = 0;
    virtual ISteeringWheel*       GetSteeringDevice()                            = 0;
    virtual bool                  InGameBreaker()                                = 0;
    virtual bool                  CanRechargeNOS()                               = 0;
    virtual void                  ResetGameBreaker(bool fill)                    = 0;
    virtual void                  ChargeGameBreaker(float amount)                = 0;
    virtual bool                  ToggleGameBreaker()                            = 0;

    static inline UTL::ListableSet<IPlayer, 8, ePlayerList, 3>* g_mLists =
        reinterpret_cast<UTL::ListableSet<IPlayer, 8, ePlayerList, 3>*>(0x92D87C);

    static IPlayer* GetPlayer() {
      if (IPlayer* player = *g_mLists->mSet[ePlayerList::All].mBegin) return player;
      return nullptr;
    }
  };
}  // namespace OpenSpeed::MW05
