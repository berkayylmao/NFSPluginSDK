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
    struct _InstanceLayout {
      PVehicle* mInstance;
      bool      mIsEnabled;
    };

    Attrib::Instance         mAttributes;
    std::uint32_t            mClassKey;
    FECustomizationRecord*   mCustomization;
    IInput*                  mInput;
    ICollisionBody*          mCollisionBody;
    ISuspension*             mSuspension;
    IEngine*                 mEngine;
    IDamageable*             mDamage;
    ITransmission*           mTranny;
    IVehicleAI*              mAI;
    IArticulatedVehicle*     mArticulation;
    IRenderable*             mRenderable;
    IAudible*                mAudible;
    EventSequencer::IEngine* mSequencer;
    HSIMTASK__*              mTaskFX;
    UCrc32                   mClass;
    float                    mSpeed;
    float                    mAbsSpeed;
    float                    mSpeedometer;
    float                    mTimeInAir;
    float                    mSlipAngle;
    std::uint32_t            mWheelsOnGround;
    UMath::Vector3           mLocalVel;
    DriverClass              mDriverClass;
    DriverStyle              mDriverStyle;
    VehicleFX::LightID       mGlareState;
    float                    mStartingNOS;
    float                    mBrakeTime;
    IVehicle::ForceStopType  mForceStop;
    PhysicsMode              mPhysicsMode;
    bool                     mAnimating;
    bool                     mStaging;

    virtual ~PVehicle();
    virtual void OnDebugDraw() = 0;

    bool IsValid() { return mObjType != SimableType::Invalid && mDirty == false && this->GetRigidBody(); }

    static inline _InstanceLayout* g_mInstances = reinterpret_cast<_InstanceLayout*>(0x9352B0);

    static PVehicle* Construct(const VehicleParams& vehicleParams) {
      ISimable* pSimable = reinterpret_cast<ISimable*(__cdecl*)(const VehicleParams&, UCrc32)>(0x689820)(
          vehicleParams, vehicleParams.mName);
      return static_cast<PVehicle*>(pSimable);
    }

    static std::int32_t GetInstancesCount() {
      std::int32_t _amount    = 0;
      auto*        _pInstance = g_mInstances;
      while ((_pInstance++)->mInstance) _amount++;

      return _amount;
    }

    static PVehicle* GetInstance(std::int32_t idx) {
      auto* _instance = g_mInstances[idx].mInstance;
      if (_instance && _instance->IsValid()) return _instance;

      return nullptr;
    }

    static PVehicle* GetPlayerInstance() {
      auto* _instance = g_mInstances;
      while (_instance->mInstance) {
        if (_instance->mInstance->IsValid() &&
            (_instance->mInstance->IsPlayer() || _instance->mInstance->IsOwnedByPlayer()))
          return _instance->mInstance;

        _instance++;
      }

      return nullptr;
    }
  };
}  // namespace OpenSpeed::MW05
