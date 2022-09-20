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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHELICOPTER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHELICOPTER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehiclePursuit.h>
#include <NFSPluginSDK/Game.MW05/Types/IAIHelicopter.h>
#include <NFSPluginSDK/Game.MW05/Types/HeliSheetCoordinate.h>

namespace NFSPluginSDK::MW05 {
  struct AIVehicleHelicopter : AIVehiclePursuit, IAIHelicopter {
    UMath::Vector3      mDestinationVelocity;
    UMath::Vector3      mLookAtPosition;
    UMath::Vector3      mLastPlaceHeliSawPerp;
    float               mHeight;
    bool                mStrafeToDest;
    bool                mPerpHiddenFromMe;
    float               mHeliFuelTimeRemaining;
    float               mShadowScale;
    float               mDustStormIntensity;
    HeliSheetCoordinate mHeliSheetCoord;
    HeliSheetCoordinate mSecondaryHeliSheetCoord;
    HeliSheetCoordinate mThirdHeliSheetCoord;
    ISimpleChopper*     mISimpleChopper;

    virtual ~AIVehicleHelicopter();
    virtual const HeliSheetCoordinate& GetHeliSheetCoord();
#pragma region overrides
    virtual void           Update(float deltaTime) override;
    virtual void           OnDriving(float deltaTime) override;
    virtual bool           CanSeeTarget(AITarget* target) override;
    virtual float          GetDesiredHeightOverDest() override;
    virtual void           SetDesiredHeightOverDest(float height) override;
    virtual void           SetLookAtPosition(UMath::Vector3 pos) override;
    virtual UMath::Vector3 GetLookAtPosition() override;
    virtual void           SetDestinationVelocity(const UMath::Vector3& velocity) override;
    virtual void           SteerToNav(WRoadNav* road_nav, float height, float speed, bool bStopAtDest) override;
    virtual bool           StartPathToPoint(UMath::Vector3& point) override;
    virtual bool           StrafeToDestIsSet() override;
    virtual void           SetStrafeToDest(bool strafe) override;
    virtual bool           FilterHeliAltitude(UMath::Vector3& point) override;
    virtual void           RestrictPointToRoadNet(UMath::Vector3& seekPosition) override;
    virtual void           SetFuelFull() override;
    virtual float          GetFuelTimeRemaining() override;
    virtual void           SetShadowScale(float scale) override;
    virtual float          GetShadowScale() override;
    virtual void           SetDustStormIntensity(float intensity) override;
    virtual float          GetDustStormIntensity() override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHELICOPTER_H
