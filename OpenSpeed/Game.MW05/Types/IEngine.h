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
  struct IEngine : UTL::COM::IUnknown {
    virtual ~IEngine();
    virtual float GetRPM()                = 0;
    virtual float GetRedline()            = 0;
    virtual float GetMaxRPM()             = 0;
    virtual float GetMinRPM()             = 0;
    virtual float GetPeakTorqueRPM()      = 0;
    virtual void  MatchSpeed(float speed) = 0;
    virtual float GetNOSCapacity()        = 0;
    virtual bool  IsNOSEngaged()          = 0;
    virtual float GetNOSFlowRate()        = 0;
    virtual float GetNOSBoost()           = 0;
    virtual bool  HasNOS()                = 0;
    virtual void  ChargeNOS(float amount) = 0;
    virtual float GetMaxHorsePower()      = 0;
    virtual float GetMinHorsePower()      = 0;
    virtual float GetHorsePower()         = 0;
  };
}  // namespace OpenSpeed::MW05