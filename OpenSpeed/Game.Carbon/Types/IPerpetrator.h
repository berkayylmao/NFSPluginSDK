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
#include <OpenSpeed/Game.Carbon/Types.h>
#include <OpenSpeed/Game.Carbon/Types/UTL.h>

namespace OpenSpeed::Carbon {
  struct IPerpetrator : UTL::COM::IUnknown {
    virtual ~IPerpetrator();
    virtual float                           GetHeat()                                                    = 0;
    virtual void                            SetHeat(float heat)                                          = 0;
    virtual Attrib::Gen::pursuitescalation* GetPursuitEscalationAttrib()                                 = 0;
    virtual Attrib::Gen::pursuitlevels*     GetPursuitLevelAttrib()                                      = 0;
    virtual Attrib::Gen::pursuitsupport*    GetPursuitSupportAttrib()                                    = 0;
    virtual bool                            GetHeatChangedInCareer()                                     = 0;
    virtual void                            AddCostToState(std::int32_t cost)                            = 0;
    virtual std::int32_t                    GetCostToState()                                             = 0;
    virtual void                            SetCostToState(std::int32_t costToState)                     = 0;
    virtual bool                            IsRacing()                                                   = 0;
    virtual bool                            IsBeingPursued()                                             = 0;
    virtual bool                            IsHiddenFromCars()                                           = 0;
    virtual bool                            IsHiddenFromHelicopters()                                    = 0;
    virtual bool                            IsPartiallyHidden(float& howHidden)                          = 0;
    virtual void                            AddToPendingRepPointsFromCopDestruction(std::int32_t amount) = 0;
    virtual void                            AddToPendingRepPointsNormal(std::int32_t amount)             = 0;
    virtual std::int32_t                    GetPendingRepPointsNormal()                                  = 0;
    virtual std::int32_t                    GetPendingRepPointsFromCopDestruction()                      = 0;
    virtual void                            ClearPendingRepPoints()                                      = 0;
    virtual void                            SetRacerInfo(GRacerInfo* info)                               = 0;
    virtual GRacerInfo*                     GetRacerInfo()                                               = 0;
    virtual float                           GetLastTrafficHitTime()                                      = 0;
    virtual void                            Set911CallTime(float time)                                   = 0;
    virtual float                           Get911CallTime()                                             = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4061D0)(); }
  };
}  // namespace OpenSpeed::Carbon
