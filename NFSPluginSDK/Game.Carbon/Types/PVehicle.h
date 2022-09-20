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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_PVEHICLE_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_PVEHICLE_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/bList.h>
#include <NFSPluginSDK/Game.Carbon/Types/IAttributeable.h>
#include <NFSPluginSDK/Game.Carbon/Types/IExplodeable.h>
#include <NFSPluginSDK/Game.Carbon/Types/IVehicle.h>
#include <NFSPluginSDK/Game.Carbon/Types/PhysicsObject.h>
#include <NFSPluginSDK/Game.Carbon/Types/VehicleParams.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Gen/pvehicle.h>

namespace NFSPluginSDK::Carbon {
  struct PVehicle : PhysicsObject, IVehicle, EventSequencer::IContext, IExplodeable, IAttributeable, bTNode<PVehicle> {
    Attrib::Gen::pvehicle    mAttributes;
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
    IDamagePhysics*          mDamagePhysics;
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
    virtual void OnDebugDraw();
#pragma region overrides
    virtual bool                         OnTask(HSIMTASK__* p, float) override;
    virtual void                         Kill() override;
    virtual void                         DebugObject() override;
    virtual const IModel*                GetModel() const override;
    virtual IModel*                      GetModel() override;
    virtual ISimable*                    GetSimable() override;
    virtual const ISimable*              GetSimable() const override;
    virtual const UMath::Vector3&        GetPosition() override;
    virtual void                         SetBehaviorOverride(UCrc32, UCrc32) override;
    virtual void                         RemoveBehaviorOverride(UCrc32) override;
    virtual void                         CommitBehaviorOverrides() override;
    virtual void                         SetStaging(bool isStaging) override;
    virtual bool                         IsStaging() override;
    virtual void                         Launch() override;
    virtual float                        GetPerfectLaunch() override;
    virtual void                         SetDriverStyle(DriverStyle newDriverStyle) override;
    virtual DriverStyle                  GetDriverStyle() override;
    virtual void                         SetPhysicsMode(PhysicsMode newPhysicsMode) override;
    virtual PhysicsMode                  GetPhysicsMode() override;
    virtual std::int32_t                 GetModelType() override;
    virtual bool                         IsSpooled() override;
    virtual const UCrc32&                GetVehicleClass() override;
    virtual const Attrib::Gen::pvehicle& GetVehicleAttributes() override;
    virtual const char*                  GetVehicleName() override;
    virtual std::uint32_t                GetVehicleKey() override;
    virtual void                         SetDriverClass(DriverClass newDriverClass) override;
    virtual DriverClass                  GetDriverClass() override;
    virtual bool                         IsLoading() override;
    virtual float                        GetOffScreenTime() override;
    virtual float                        GetOnScreenTime() override;
    virtual bool                         SetVehicleOnGround(const UMath::Vector3&, const UMath::Vector3&) override;
    virtual void                         ForceStopOn(ForceStopType type) override;
    virtual void                         ForceStopOff(ForceStopType type) override;
    virtual ForceStopType                GetForceStop() override;
    virtual bool                         InShock() override;
    virtual bool                         IsDestroyed() override;
    virtual void                         Activate() override;
    virtual void                         Deactivate() override;
    virtual bool                         IsActive() override;
    virtual float                        GetSpeedometer() override;
    virtual float                        GetSpeed() override;
    virtual void                         SetSpeed(float newSpeed) override;
    virtual float                        GetAbsoluteSpeed() override;
    virtual bool                         IsGlareOn(VehicleFX::LightID fxId) override;
    virtual void                         GlareOn(VehicleFX::LightID fxId) override;
    virtual void                         GlareOff(VehicleFX::LightID fxId) override;
    virtual bool                         IsCollidingWithSoftBarrier() override;
    virtual IVehicleAI*                  GetAIVehiclePtr() override;
    virtual float                        GetSlipAngle() override;
    virtual const UMath::Vector3&        GetLocalVelocity() override;
    virtual void                         ComputeHeading(UMath::Vector3* out) override;
    virtual bool                         IsAnimating() override;
    virtual void                         SetAnimating(bool isAnimating) override;
    virtual bool                         IsOffWorld() override;
    virtual VehicleCustomizations*       GetCustomizations() override;
    virtual Physics::Tunings*            GetTunings() override;
    virtual void                         SetTunings(const Physics::Tunings& tunings) override;
    virtual bool                         GetPerformance(Physics::Info::CorrectedPerformance& to) override;
    virtual UTL::COM::IUnknown*          GetContextOwner() override;
    virtual bool        GetDynamicData(EventSequencer::System* system, void* pOutEventDynamicData) override;
    virtual const char* GetContextDebugName() override;
#pragma endregion

    static inline bTNode<PVehicle>** g_mInstances = reinterpret_cast<bTNode<PVehicle>**>(0xA9E728);

    static PVehicle* Construct(VehicleParams vehicleParams) {
      ISimable* simable =
          reinterpret_cast<ISimable*(__cdecl*)(UCrc32, VehicleParams*)>(0x6DAA80)(vehicleParams.mType, &vehicleParams);
      if (simable) return static_cast<PVehicle*>(simable);
      return nullptr;
    }

    static std::int32_t GetInstancesCount() {
      std::int32_t amount = 0;

      auto** pInstance = PVehicle::g_mInstances;
      if (!pInstance) return amount;

      auto* instance = *pInstance;
      while (instance != reinterpret_cast<bTNode<PVehicle>*>(pInstance)) {
        amount++;
        instance = instance->GetNext();
      }
      return amount;
    }

    static PVehicle* GetInstance(std::int32_t idx) {
      auto** pInstance = PVehicle::g_mInstances;
      if (!pInstance) return nullptr;

      std::int32_t cur_idx  = 0;
      auto*        instance = *pInstance;
      while (instance != reinterpret_cast<bTNode<PVehicle>*>(pInstance)) {
        if (cur_idx == idx) return static_cast<PVehicle*>(instance);

        cur_idx++;
        instance = instance->GetNext();
      }
      return nullptr;
    }
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_PVEHICLE_H
