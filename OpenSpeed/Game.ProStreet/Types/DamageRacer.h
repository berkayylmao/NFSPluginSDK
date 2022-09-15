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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_DAMAGERACER_H
#define OPENSPEED_GAME_PROSTREET_TYPES_DAMAGERACER_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DamageVehicle.h>
#include <OpenSpeed/Game.ProStreet/Types/ISpikeable.h>
#include <OpenSpeed/Game.ProStreet/Types/IWheelDamage.h>

namespace OpenSpeed::ProStreet {
  struct DamageRacer : DamageVehicle, ISpikeable, IWheelDamage {
    IChassis*    mChassis;
    float        mBlowOutTimes[4];
    eTireDamage  mTireDamage[4];
    eWheelDamage mWheelDamage[4];

    virtual ~DamageRacer();

#pragma region overrides
    virtual bool             IsLightDamaged(VehicleFX::LightID idx) override;
    virtual DamageZone::Info GetZoneDamage() override;
    virtual void             OnTaskSimulate(float deltaTime) override;
    virtual void             OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void             ResetDamagePrivate() override;
    virtual eTireDamage      GetTireDamage(eTireIdx idx) override;
    virtual std::int32_t     GetNumBlowouts() override;
    virtual void             Puncture(eTireIdx idx) override;
    virtual eWheelDamage     GetWheelDamage(eTireIdx idx) override;
    virtual std::int32_t     GetNumDamagedWheels() override;
    virtual void             DamageWheel(eTireIdx idx) override;
#pragma endregion
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_DAMAGERACER_H
