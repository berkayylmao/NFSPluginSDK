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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_IDAMAGEABLEVEHICLE_H
#define OPENSPEED_GAME_PROSTREET_TYPES_IDAMAGEABLEVEHICLE_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct IDamageableVehicle : UTL::COM::IUnknown {
    virtual ~IDamageableVehicle();
    virtual bool IsLightDamaged(VehicleFX::LightID idx)             = 0;
    virtual void DamageLight(VehicleFX::LightID idx, bool damage)   = 0;
    virtual bool IsLightCracked(VehicleFX::LightID idx)             = 0;
    virtual void CrackLight(VehicleFX::LightID idx, bool crack)     = 0;
    virtual bool IsWindowDamaged(VehicleFX::WindowID idx)           = 0;
    virtual void DamageWindow(VehicleFX::WindowID idx, bool damage) = 0;
    virtual bool IsWindowCracked(VehicleFX::WindowID idx)           = 0;
    virtual void CrackWindow(VehicleFX::WindowID idx, bool crack)   = 0;
    virtual void SetHitPointsOverride(float hp)                     = 0;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_IDAMAGEABLEVEHICLE_H
