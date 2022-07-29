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

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>
#include <OpenSpeed/Game.MW05/Types/InputControls.h>

namespace OpenSpeed::MW05 {
  struct IInput : UTL::COM::IUnknown {
    virtual ~IInput();
    virtual void           ClearInput()                             = 0;
    virtual InputControls& GetControls()                            = 0;
    virtual float          GetControlHandBrake()                    = 0;
    virtual float          GetControlActionButton()                 = 0;
    virtual void           SetControlSteering(float amount)         = 0;
    virtual void           SetControlGas(float amount)              = 0;
    virtual void           SetControlBrake(float amount)            = 0;
    virtual void           SetControlNOS(bool isPressed)            = 0;
    virtual void           SetControlHandBrake(float amount)        = 0;
    virtual void           SetControlActionButton(bool isPressed)   = 0;
    virtual void           SetControlSteeringVertical(float amount) = 0;
    virtual void           SetControlBanking(float amount)          = 0;
    virtual float          GetControlBanking()                      = 0;
    virtual bool           IsLookBackButtonPressed()                = 0;
    virtual bool           IsPullBackButtonPressed()                = 0;
    virtual bool           IsAutomaticShift()                       = 0;
  };
}  // namespace OpenSpeed::MW05
