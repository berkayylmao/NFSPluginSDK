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
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct IPerpetrator : UTL::COM::IUnknown {
    virtual ~IPerpetrator();

    virtual float                           GetHeat();
    virtual void                            SetHeat(float heat);
    virtual Attrib::Gen::pursuitescalation* GetPursuitEscalationAttrib();
    virtual Attrib::Gen::pursuitlevels*     GetPursuitLevelAttrib();
    virtual Attrib::Gen::pursuitsupport*    GetPursuitSupportAttrib();
    virtual void                            AddCostToState(std::int32_t cost);
    virtual std::int32_t                    GetCostToState();
    virtual void                            SetCostToState(std::int32_t costToState);
    virtual bool                            IsRacing();
    virtual bool                            IsBeingPursued();
    virtual bool                            IsHiddenFromCars();
    virtual bool                            IsHiddenFromHelicopters();
    virtual bool                            IsPartiallyHidden(float& howHidden);
    virtual void                            AddToPendingRepPointsFromCopDestruction(std::int32_t amount);
    virtual void                            AddToPendingRepPointsNormal(std::int32_t amount);
    virtual std::int32_t                    GetPendingRepPointsNormal();
    virtual std::int32_t                    GetPendingRepPointsFromCopDestruction();
    virtual void                            ClearPendingRepPoints();
    virtual void                            SetRacerInfo(GRacerInfo* info);
    virtual GRacerInfo*                     GetRacerInfo();
    virtual float                           GetLastTrafficHitTime();
    virtual void                            Set911CallTime(float time);
    virtual float                           Get911CallTime();

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4037E0)(); }
  };
}  // namespace OpenSpeed::MW05
