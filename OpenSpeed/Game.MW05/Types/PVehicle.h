// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/bList.h>
#include <OpenSpeed/Game.MW05/Types/IAttributeable.h>
#include <OpenSpeed/Game.MW05/Types/IExplodeable.h>
#include <OpenSpeed/Game.MW05/Types/IVehicle.h>
#include <OpenSpeed/Game.MW05/Types/PhysicsObject.h>
#include <OpenSpeed/Game.MW05/Types/VehicleParams.h>

namespace OpenSpeed::MW05 {
  struct PVehicle : PhysicsObject, IVehicle, EventSequencer::IContext, IExplodeable, IAttributeable, bTNode<PVehicle*> {
    static inline bTList<PVehicle>* g_mInstances = reinterpret_cast<bTList<PVehicle>*>(0x9352B0);

    // Probably not all correct, TODO:FIX
    Attrib::Gen::pvehicle    mAttributes;
    VehicleCustomizations*   mCustomization;
    IInput*                  mInput;
    ICollisionBody*          mCollisionBody;
    IChassis*                mChassis;
    IEngine*                 mEngine;
    IDamageable*             mDamage;
    ITransmission*           mTranny;
    IVehicleAI*              mAI;
    IArticulatedVehicle*     mArticulation;
    IRenderable*             mRenderable;
    IAudible*                mAudible;
    IDamagePhysics*          mDamagePhysics;
    EventSequencer::IEngine* mSequencer;
    HSIMTASK__*              mTaskFX;
    UCrc32                   mClass;

    float          mSpeed;
    float          mAbsSpeed;
    float          mSpeedometer;
    float          mTimeInAir;
    float          mSlipAngle;
    float          mDraftZoneModifier;
    std::uint32_t  mWheelsOnGround;
    UMath::Vector3 mLocalVel;

    DriverClass             mDriverClass;
    DriverStyle             mDriverStyle;
    bool                    mDriverStyleInitted;
    VehicleFX::LightID      mGlareState;
    float                   mStartingNOS;
    float                   mBrakeTime;
    IVehicle::ForceStopType mForceStop;
    PhysicsMode             mPhysicsMode;
    bool                    mAnimating;
    bool                    mStaging;
    bool                    mDragStaging;
    bool                    mShouldUseDragStagingCamera;

    virtual ~PVehicle();
    virtual void OnDebugDraw() = 0;

    static PVehicle* Construct(const VehicleParams& vehicleParams) {
      ISimable* pSimable = reinterpret_cast<ISimable*(__cdecl*)(const VehicleParams&, UCrc32)>(0x689820)(
          vehicleParams, vehicleParams.hash);
      return dynamic_cast<PVehicle*>(pSimable);
    }
  };
}  // namespace OpenSpeed::MW05
