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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEHUMAN_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEHUMAN_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleRacecar.h>
#include <NFSPluginSDK/Game.Carbon/Types/IHumanAI.h>
#include <NFSPluginSDK/Game.Carbon/Types/IInputPlayer.h>

namespace NFSPluginSDK::Carbon {
  struct AIVehicleHuman : AIVehicleRacecar, IHumanAI, IInputPlayer {
    bool           bAiControl;
    UMath::Vector3 vMomentPosition;
    float          fMomentRadius;
    bool           mWrongWay;
    ActionQueue*   mActionQ;
    float          mSteerRight;
    float          mSteerLeft;
    float          mOverSteer;
    bool           mOverSteering;
    float          mOverSteerRight;
    float          mOverSteerLeft;
    float          mGasButton;
    float          mBrakeButton;
    float          mClutchButton;
    float          mClutchKickButton;
    float          mLookBackButton;
    float          mPullBackButton;
    float          mCameraRotInput;
    float          mWingmanButton;
    bool           mGasInputUsedSinceStart;
    bool           mGaveHeadStart;
    bool           mIOBlocked;
    bool           mEnableDampening;

    virtual ~AIVehicleHuman();
#pragma region overrides
    virtual void                  Reset() override;
    virtual void                  OnTaskSimulate(float deltaTime) override;
    virtual bool                  IsLookBackButtonPressed() override;
    virtual bool                  IsPullBackButtonPressed() override;
    virtual bool                  IsWingmanActivationButtonPressed() override;
    virtual bool                  IsAutomaticShift() override;
    virtual float                 GetCatchupCheat() override;
    virtual void                  StartRace(DriverStyle style) override;
    virtual bool                  GaveHeadStart() override;
    virtual bool                  IsPlayerSteering() override;
    virtual bool                  GetAiControl() override;
    virtual void                  SetAiControl(bool aiControl) override;
    virtual void                  SetWorldMoment(const UMath::Vector3& position, float radius) override;
    virtual const UMath::Vector3& GetWorldMomentPosition() override;
    virtual float                 GetWorldMomentRadius() override;
    virtual void                  ClearWorldMoment() override;
    virtual bool                  IsFacingWrongWay() override;
    virtual void                  BlockInput(bool block) override;
    virtual bool                  IsBlocked() override;
    virtual void                  FetchInput() override;
    virtual void                  ClearInput() override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEHUMAN_H
