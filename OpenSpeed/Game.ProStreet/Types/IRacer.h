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
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct IRacer : UTL::COM::IUnknown {
    virtual ~IRacer();
    virtual void       PrepareForRace(const RacePreparationInfo& rpi) = 0;
    virtual void       StartRace(DriverStyle style)                   = 0;
    virtual void       QuitRace()                                     = 0;
    virtual AIWingman* GetWingman()                                   = 0;
    virtual void       SetWingman(IVehicle* vehicle)                  = 0;
    virtual void       BecomeWingman(eWingmanRole role)               = 0;
    virtual bool       GaveHeadStart()                                = 0;
  };
}  // namespace OpenSpeed::ProStreet
