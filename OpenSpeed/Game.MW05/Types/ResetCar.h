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
#include <OpenSpeed/Game.MW05/Types/BehaviorParams.h>
#include <OpenSpeed/Game.MW05/Types/IRBVehicle.h>
#include <OpenSpeed/Game.MW05/Types/IResetable.h>
#include <OpenSpeed/Game.MW05/Types/VehicleBehavior.h>
#include <OpenSpeed/Game.MW05/Types/WRoadNav.h>

namespace OpenSpeed::MW05 {
  struct ResetCar : VehicleBehavior, IResetable {
    enum class Flags : std::uint32_t { None, FindRoad };
    struct ResetCookie {
      UMath::Vector3 position;
      Flags          flags;
      UMath::Vector3 direction;
      float          time;
    };

    float                                 mFlippedOver;
    WRoadNav::CookieTrail<ResetCookie, 4> mCookies;
    ICollisionBody*                       mCollisionBody;
    ISuspension*                          mSuspension;
    IRBVehicle*                           mVehicleBody;
    HSIMTASK__*                           mCheckTask;

    virtual ~ResetCar();
#pragma region overrides
    virtual void Reset() override;
    virtual void OnBehaviorChange(const UCrc32& mechanic) override;
    virtual bool HasResetPosition() override;
    virtual bool ResetVehicle(bool findRoad) override;
    virtual void SetResetPosition(const UMath::Vector3& position, const UMath::Vector3& direction) override;
    virtual void ClearResetPosition() override;
#pragma endregion

    static IResetable* Construct(const BehaviorParams& params) {
      IResetable* p = reinterpret_cast<IResetable*(__cdecl*)(BehaviorParams)>(0x689820)(params);
      return static_cast<ResetCar*>(p);
    }
  };
}  // namespace OpenSpeed::MW05
