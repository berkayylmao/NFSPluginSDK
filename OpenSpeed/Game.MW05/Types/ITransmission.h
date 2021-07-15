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
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct ITransmission : UTL::COM::IUnknown {
    enum class GearID {
      Reverse = 0,
      Neutral = 1,
      First   = 2,
      Second  = 3,
      Third   = 4,
      Fourth  = 5,
      Fifth   = 6,
      Sixth   = 7,
      Seventh = 8,
      Eighth  = 9
    };
    enum class ShiftPotential {
      None    = 0,
      Down    = 1,
      Up      = 2,
      Good    = 3,
      Perfect = 4,
      Miss    = 5,
    };
    enum class ShiftStatus {
      None    = 0,
      Normal  = 1,
      Good    = 2,
      Perfect = 3,
      Missed  = 4,
    };

    virtual ~ITransmission();
    virtual GearID         GetGear()                             = 0;
    virtual GearID         GetTopGear()                          = 0;
    virtual bool           Shift(GearID gear)                    = 0;
    virtual bool           IsGearChanging()                      = 0;
    virtual bool           IsReversing()                         = 0;
    virtual float          GetSpeedometer()                      = 0;
    virtual float          GetMaxSpeedometer()                   = 0;
    virtual float          GetDriveTorque()                      = 0;
    virtual float          GetOptimalShiftRange(GearID gear)     = 0;
    virtual float          GetShiftPoint(GearID from, GearID to) = 0;
    virtual ShiftStatus    GetShiftStatus()                      = 0;
    virtual ShiftPotential GetShiftPotential()                   = 0;
  };
}  // namespace OpenSpeed::MW05
