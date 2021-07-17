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
#include <type_traits>  // enable_if_t, is_base_of_v

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
#pragma region overrides
    virtual bool                            OnTask(HSIMTASK__* p, float) override;
    virtual void                            Kill() override;
    virtual void                            DebugObject() override;
    virtual const UMath::Vector3&           GetPosition() override;
    virtual const IModel*                   GetModel() const                                                 = 0;
    virtual IModel*                         GetModel()                                                       = 0;
    virtual ISimable*                       GetSimable()                                                     = 0;
    virtual const ISimable*                 GetSimable() const                                               = 0;
    virtual const UMath::Vector3&           GetPosition()                                                    = 0;
    virtual void                            SetBehaviorOverride(UCrc32, UCrc32)                              = 0;
    virtual void                            RemoveBehaviorOverride(UCrc32)                                   = 0;
    virtual void                            CommitBehaviorOverrides()                                        = 0;
    virtual void                            SetStaging(bool isStaging)                                       = 0;
    virtual bool                            IsStaging()                                                      = 0;
    virtual void                            Launch()                                                         = 0;
    virtual float                           GetPerfectLaunch()                                               = 0;
    virtual void                            SetDriverStyle(DriverStyle newDriverStyle)                       = 0;
    virtual DriverStyle                     GetDriverStyle()                                                 = 0;
    virtual void                            SetPhysicsMode(PhysicsMode newPhysicsMode)                       = 0;
    virtual PhysicsMode                     GetPhysicsMode()                                                 = 0;
    virtual std::int32_t                    GetModelType()                                                   = 0;
    virtual bool                            IsSpooled()                                                      = 0;
    virtual const UCrc32&                   GetVehicleClass()                                                = 0;
    virtual const Attrib::Gen::pvehicle&    GetVehicleAttributes()                                           = 0;
    virtual const char*                     GetVehicleName()                                                 = 0;
    virtual std::uint32_t                   GetVehicleKey()                                                  = 0;
    virtual void                            SetDriverClass(DriverClass newDriverClass)                       = 0;
    virtual DriverClass                     GetDriverClass()                                                 = 0;
    virtual bool                            IsLoading()                                                      = 0;
    virtual float                           GetOffscreenTime()                                               = 0;
    virtual float                           GetOnScreenTime()                                                = 0;
    virtual bool                            SetVehicleOnGround(const UMath::Vector3&, const UMath::Vector3&) = 0;
    virtual void                            ForceStopOn(ForceStopType type)                                  = 0;
    virtual void                            ForceStopOff(ForceStopType type)                                 = 0;
    virtual ForceStopType                   GetForceStop()                                                   = 0;
    virtual bool                            InShock()                                                        = 0;
    virtual bool                            IsDestroyed()                                                    = 0;
    virtual void                            Activate()                                                       = 0;
    virtual void                            Deactivate()                                                     = 0;
    virtual bool                            IsActive()                                                       = 0;
    virtual float                           GetSpeedometer()                                                 = 0;
    virtual float                           GetSpeed()                                                       = 0;
    virtual void                            SetSpeed(float newSpeed)                                         = 0;
    virtual float                           GetAbsoluteSpeed()                                               = 0;
    virtual bool                            IsGlareOn(VehicleFX::LightID fxId)                               = 0;
    virtual void                            GlareOn(VehicleFX::LightID fxId)                                 = 0;
    virtual void                            GlareOff(VehicleFX::LightID fxId)                                = 0;
    virtual bool                            IsCollidingWithSoftBarrier()                                     = 0;
    virtual IVehicleAI*                     GetAIVehiclePtr()                                                = 0;
    virtual float                           GetSlipAngle()                                                   = 0;
    virtual const UMath::Vector3&           GetLocalVelocity()                                               = 0;
    virtual void                            ComputeHeading(UMath::Vector3* out)                              = 0;
    virtual bool                            IsAnimating()                                                    = 0;
    virtual void                            SetAnimating(bool isAnimating)                                   = 0;
    virtual bool                            IsOffWorld()                                                     = 0;
    virtual FECustomizationRecord*          GetCustomizations()                                              = 0;
    virtual FECustomizationRecord::Tunings* GetTunings()                                                     = 0;
    virtual void                            SetTunings(const FECustomizationRecord::Tunings& newTunings)     = 0;
    virtual bool                            GetPerformance(Physics::Info::CorrectedPerformance& out)         = 0;
    virtual void*                           _unkFunc()                                                       = 0;
#pragma endregion

    bool IsValid() { return mObjType != SimableType::Invalid && mDirty == false && this->GetRigidBody(); }

    template <typename T>
    std::enable_if_t<std::is_base_of_v<IVehicleAI, T>, T*> GetAIAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mAI);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<IArticulatedVehicle, T>, T*> GetArticulatedVehicleAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mArticulation);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<IAudible, T>, T*> GetAudibleAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mAudible);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<ICollisionBody, T>, T*> GetCollisionBodyAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mCollisionBody);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<IDamageable, T>, T*> GetDamageableAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mDamage);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<IEngine, T>, T*> GetEngineAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mEngine);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<IInput, T>, T*> GetInputAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mInput);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<IRenderable, T>, T*> GetRenderableAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mRenderable);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<IRigidBody, T>, T*> GetRigidBodyAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(GetRigidBody());
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<ISuspension, T>, T*> GetSuspensionAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mSuspension);
    }
    template <typename T>
    std::enable_if_t<std::is_base_of_v<ITransmission, T>, T*> GetTransmissionAs() {
      if (!IsValid()) return nullptr;
      return static_cast<T*>(mTranny);
    }

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
