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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLECHOPPER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLECHOPPER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/chopperspecs.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/pvehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/ISimpleChopper.h>
#include <NFSPluginSDK/Game.MW05/Types/ITransmission.h>
#include <NFSPluginSDK/Game.MW05/Types/VehicleBehavior.h>

namespace NFSPluginSDK::MW05 {
  struct SimpleChopper : VehicleBehavior, ISimpleChopper {
    UMath::Vector3                              mLastBodyOffset;
    UMath::Vector3                              mLastAngVelocity;
    UMath::Vector3                              mLastAccelVector;
    UMath::Vector3                              mDesiredVelocity;
    UMath::Vector3                              mPreviousVelocity;
    UMath::Vector3                              mDesiredFacingVector;
    BehaviorSpecsPtr<Attrib::Gen::chopperspecs> mChopperSpecs;
    BehaviorSpecsPtr<Attrib::Gen::pvehicle>     mVehicleSpecs;
    bool                                        mMaxDecelFlag;
    IRigidBody*                                 mIRigidBody;
    ICollisionBody*                             mIRBComplex;
    IDamageable*                                mIDamage;

    virtual ~SimpleChopper();
    virtual float GetPower();
    virtual float GetRPM();
    virtual float GetMaxRPM();
    virtual float GetRedline();
    virtual float GetMinRPM();
    virtual float GetMinGearRPM(ITransmission::GearID gearId);
    virtual void  MatchSpeed(float speed);
    virtual float GetNOSCapacity();
    virtual bool  IsNOSEngaged();
    virtual bool  HasNOS();
#pragma region overrides
    virtual void Reset() override;
    virtual void OnTaskSimulate(float deltaTime) override;
    virtual void OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void SetDesiredVelocity(const UMath::Vector3& velocity) override;
    virtual void GetDesiredVelocity(UMath::Vector3& out) override;
    virtual void MaxDeceleration(bool limit) override;
    virtual void SetDesiredFacingVector(const UMath::Vector3& vector) override;
    virtual void GetDesiredFacingVector(UMath::Vector3& out) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLECHOPPER_H
