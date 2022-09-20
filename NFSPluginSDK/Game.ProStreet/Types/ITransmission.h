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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ITRANSMISSION_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ITRANSMISSION_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct ITransmission : UTL::COM::IUnknown {
    enum class ClutchState : std::uint32_t { Engaged, Disengaged, Upshift, Downshift };
    enum class GearID : std::uint32_t { Reverse, Neutral, First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth };
    enum class ShiftPotential : std::uint32_t {
      None,
      Down,
      Up,
      Good,
      Perfect,
      Miss,
    };
    enum class ShiftStatus : std::uint32_t {
      None,
      Normal,
      Good,
      Perfect,
      Missed,
    };

    virtual ~ITransmission();
    virtual GearID                GetGear()                                               = 0;
    virtual GearID                GetTopGear()                                            = 0;
    virtual bool                  Shift(GearID gear)                                      = 0;
    virtual bool                  IsClutchEngaged()                                       = 0;
    virtual bool                  IsGearChanging()                                        = 0;
    virtual bool                  IsReversing()                                           = 0;
    virtual float                 GetSpeedometer()                                        = 0;
    virtual float                 GetMaxSpeedometer()                                     = 0;
    virtual float                 GetDriveTorqueAtEngine()                                = 0;
    virtual float                 GetDriveTorque()                                        = 0;
    virtual float                 GetEngineBrakingTorque()                                = 0;
    virtual float                 GetShiftPoint(GearID from, GearID to)                   = 0;
    virtual ShiftStatus           GetShiftStatus()                                        = 0;
    virtual ShiftPotential        GetShiftPotential()                                     = 0;
    virtual bool                  DoClutchKick(float amount)                              = 0;
    virtual float                 GetTorqueSplit()                                        = 0;
    virtual float                 GetTotalShiftTime()                                     = 0;
    virtual ClutchState           GetClutchState()                                        = 0;
    virtual float                 GetTimeUntilTransition()                                = 0;
    virtual float                 GetClutchPosition()                                     = 0;
    virtual float                 GetClutchGrind()                                        = 0;
    virtual void                  SetTransmissionOverride(eTransmissionOverride override) = 0;
    virtual eTransmissionOverride GetTransmissionOverride()                               = 0;
    virtual float                 GetPerfectLaunchError()                                 = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x404010)(); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ITRANSMISSION_H
