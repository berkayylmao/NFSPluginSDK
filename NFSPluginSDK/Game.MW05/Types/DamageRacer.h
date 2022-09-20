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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGERACER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGERACER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/ISpikeable.h>

namespace NFSPluginSDK::MW05 {
  struct DamageRacer : DamageVehicle, ISpikeable {
    ISuspension* mSuspension;
    union {
      float mBlowOutTimes[4];
      union {
        float mFrontLeftBlowOutTime;
        float mFrontRightBlowOutTime;
        float mRearRightBlowOutTime;
        float mRearLeftBlowOutTime;
      };
    };
    union {
      eTireDamage mDamage[4];
      union {
        eTireDamage mFrontLeftDamage;
        eTireDamage mFrontRightDamage;
        eTireDamage mRearRightDamage;
        eTireDamage mRearLeftDamage;
      };
    };

    virtual ~DamageRacer();

#pragma region overrides
    virtual bool                  CanDamageVisuals() override;
    virtual void                  OnTaskSimulate(float deltaTime) override;
    virtual void                  OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void                  ResetDamage() override;
    virtual Sim::Collision::Info* GetZoneDamage() override;
    virtual void                  OnCollision(const Sim::Collision::Info& cinfo) override;
    virtual bool                  IsLightDamaged(VehicleFX::LightID idx) override;
    virtual eTireDamage           GetTireDamage(eTireIdx idx) override;
    virtual std::int32_t          GetNumBlowouts() override;
    virtual void                  Puncture(eTireIdx idx) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGERACER_H
