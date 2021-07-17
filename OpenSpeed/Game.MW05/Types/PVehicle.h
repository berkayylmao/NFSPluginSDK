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
    virtual const IModel*                   GetModel() const override;
    virtual IModel*                         GetModel() override;
    virtual ISimable*                       GetSimable() override;
    virtual const ISimable*                 GetSimable() const override;
    virtual const UMath::Vector3&           GetPosition() override;
    virtual void                            SetBehaviorOverride(UCrc32, UCrc32) override;
    virtual void                            RemoveBehaviorOverride(UCrc32) override;
    virtual void                            CommitBehaviorOverrides() override;
    virtual void                            SetStaging(bool isStaging) override;
    virtual bool                            IsStaging() override;
    virtual void                            Launch() override;
    virtual float                           GetPerfectLaunch() override;
    virtual void                            SetDriverStyle(DriverStyle newDriverStyle) override;
    virtual DriverStyle                     GetDriverStyle() override;
    virtual void                            SetPhysicsMode(PhysicsMode newPhysicsMode) override;
    virtual PhysicsMode                     GetPhysicsMode() override;
    virtual std::int32_t                    GetModelType() override;
    virtual bool                            IsSpooled() override;
    virtual const UCrc32&                   GetVehicleClass() override;
    virtual const Attrib::Gen::pvehicle&    GetVehicleAttributes() override;
    virtual const char*                     GetVehicleName() override;
    virtual std::uint32_t                   GetVehicleKey() override;
    virtual void                            SetDriverClass(DriverClass newDriverClass) override;
    virtual DriverClass                     GetDriverClass() override;
    virtual bool                            IsLoading() override;
    virtual float                           GetOffscreenTime() override;
    virtual float                           GetOnScreenTime() override;
    virtual bool                            SetVehicleOnGround(const UMath::Vector3&, const UMath::Vector3&) override;
    virtual void                            ForceStopOn(ForceStopType type) override;
    virtual void                            ForceStopOff(ForceStopType type) override;
    virtual ForceStopType                   GetForceStop() override;
    virtual bool                            InShock() override;
    virtual bool                            IsDestroyed() override;
    virtual void                            Activate() override;
    virtual void                            Deactivate() override;
    virtual bool                            IsActive() override;
    virtual float                           GetSpeedometer() override;
    virtual float                           GetSpeed() override;
    virtual void                            SetSpeed(float newSpeed) override;
    virtual float                           GetAbsoluteSpeed() override;
    virtual bool                            IsGlareOn(VehicleFX::LightID fxId) override;
    virtual void                            GlareOn(VehicleFX::LightID fxId) override;
    virtual void                            GlareOff(VehicleFX::LightID fxId) override;
    virtual bool                            IsCollidingWithSoftBarrier() override;
    virtual IVehicleAI*                     GetAIVehiclePtr() override;
    virtual float                           GetSlipAngle() override;
    virtual const UMath::Vector3&           GetLocalVelocity() override;
    virtual void                            ComputeHeading(UMath::Vector3* out) override;
    virtual bool                            IsAnimating() override;
    virtual void                            SetAnimating(bool isAnimating) override;
    virtual bool                            IsOffWorld() override;
    virtual FECustomizationRecord*          GetCustomizations() override;
    virtual FECustomizationRecord::Tunings* GetTunings() override;
    virtual void                            SetTunings(const FECustomizationRecord::Tunings& newTunings) override;
    virtual bool                            GetPerformance(Physics::Info::CorrectedPerformance& out) override;
    virtual void*                           _unkFunc() override;
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
