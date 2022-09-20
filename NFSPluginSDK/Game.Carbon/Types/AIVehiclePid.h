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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEPID_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEPID_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicle.h>

namespace NFSPluginSDK::Carbon {
  struct AIVehiclePid : AIVehicle {
    PidError*                         pBodyError;
    PidError*                         pHeadingError;
    PidError*                         pVelocityError;
    AdaptivePIDControllerComplicated* pSteeringController;
    AdaptivePIDControllerSimple*      pThrottleBrakeController;
    float                             mThrottleBrake;
    float                             mPrevDesiredSpeed;
    std::uint8_t                      __unk_AIVehiclePid__[0x1C];

    virtual ~AIVehiclePid();
#pragma region overrides
    virtual void Reset() override;
    virtual void OnSteering(float deltaTime) override;
    virtual void OnGasBrake(float deltaTime) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEPID_H
