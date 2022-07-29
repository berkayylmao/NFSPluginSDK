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

#pragma once
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/bList.h>
#include <OpenSpeed/Game.ProStreet/Types/ICollisionBody.h>
#include <OpenSpeed/Game.ProStreet/Types/IAttributeable.h>
#include <OpenSpeed/Game.ProStreet/Types/IExplodeable.h>
#include <OpenSpeed/Game.ProStreet/Types/IVehicle.h>
#include <OpenSpeed/Game.ProStreet/Types/Physics.h>
#include <OpenSpeed/Game.ProStreet/Types/PhysicsObject.h>
#include <OpenSpeed/Game.ProStreet/Types/VehicleParams.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Gen/pvehicle.h>

namespace OpenSpeed::ProStreet {
  struct PVehicle : PhysicsObject, IVehicle, EventSequencer::IContext, IExplodeable, IAttributeable, bTNode<PVehicle*> {
    struct LaunchState {
      float mTime;
      float mAmount;
    };
    struct Resource {
      enum class Flags : std::uint32_t {
        None             = 0,
        Valid            = 1 << 0,
        Spool            = 1 << 1,
        NeedsCompositing = 1 << 2,
        LowRez           = 1 << 3
      };

      std::int32_t  mType;
      std::uint32_t mCost;
      Flags         mFlags;
    };

    Attrib::Gen::pvehicle               mAttributes;
    VehicleCustomizations*              mCustomization;
    IInput*                             mInput;
    ICollisionBody*                     mCollisionBody;
    IChassis*                           mChassis;
    IEngine*                            mEngine;
    IDamageable*                        mDamage;
    ITransmission*                      mTranny;
    IVehicleAI*                         mAI;
    IArticulatedVehicle*                mArticulation;
    IRenderable*                        mRenderable;
    IAudible*                           mAudible;
    IDamagePhysics*                     mDamagePhysics;
    EventSequencer::IEngine*            mSequencer;
    HSIMTASK__*                         mTaskFX;
    UCrc32                              mClass;
    float                               mSpeed;
    float                               mAbsSpeed;
    float                               mSpeedometer;
    float                               mTimeInAir;
    float                               mSlipAngle;
    float                               mDraftZoneModifier;
    std::uint32_t                       mWheelsOnGround;
    UMath::Vector3                      mLocalVel;
    DriverClass                         mDriverClass;
    DriverStyle                         mDriverStyle;
    bool                                mDriverStyleInitted;
    VehicleFX::ID                       mGlareState;
    float                               mStartingNOS;
    float                               mBrakeTime;
    IVehicle::ForceStopType             mForceStop;
    PhysicsMode                         mPhysicsMode;
    bool                                mAnimating;
    bool                                mStaging;
    bool                                mDragStaging;
    bool                                mShouldUseDragStagingCamera;
    LaunchState                         mPerfectLaunch;
    eastl::list<UCrc32>                 mBehaviorOverrides;
    bool                                mOverrideDirty;
    CollisionGeometry::Bounds*          mBounds;
    bool                                mIsModeling;
    float                               mOffScreenTime;
    float                               mOnScreenTime;
    bool                                mOffWorld;
    bool                                mHasDyno;
    Resource                            mResources;
    Physics::Info::CorrectedPerformance mPerformance;
    bool                                mPerformanceValid;
    const char*                         mCacheName;
    IAttachmentSystem*                  mAttachmentSystem;
    bool                                mPhysicsOnly;
    HSIMTASK__*                         mAttachmentSystemUpdate;
    /// <summary>
    /// Array members align with enum DriverAidType item indices.
    /// </summary>
    std::int32_t      mSavedDriverAidLevel[9];
    DriverAssistLevel mPreviousDriverAssistLevel;
    std::int32_t      mPreviousPlayerTCSSetting;
    std::int32_t      mPreviousPlayerABSSetting;
    std::int32_t      mPreviousPlayerESCSetting;

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
    virtual void                         ReleaseBehaviorAudio() override;
    virtual void                         SetStaging(bool isStaging) override;
    virtual bool                         IsStaging() override;
    virtual void                         SetDragStaging(bool isDragStaging) override;
    virtual bool                         IsDragStaging() override;
    virtual void                         SetUseDragStagingCamera(bool useDragStatingCamera) override;
    virtual bool                         ShouldUseDragStagingCamera() override;
    virtual void                         Launch() override;
    virtual float                        GetPerfectLaunch() override;
    virtual void                         SetDriverStyle(DriverStyle newDriverStyle) override;
    virtual DriverStyle                  GetDriverStyle() override;
    virtual void                         SetPhysicsMode(PhysicsMode newPhysicsMode) override;
    virtual PhysicsMode                  GetPhysicsMode() override;
    virtual void                         SetDraftZoneModifier(float modifier) override;
    virtual float                        GetDraftZoneModifier() override;
    virtual std::int32_t                 GetModelType() override;
    virtual bool                         IsSpooled() override;
    virtual bool                         IsLowRez() override;
    virtual const UCrc32&                GetVehicleClass() override;
    virtual const Attrib::Gen::pvehicle& GetVehicleAttributes() override;
    virtual const char*                  GetVehicleName() override;
    virtual Attrib::StringKey            GetVehicleKey() override;
    virtual Attrib::StringKey            GetStockVehicleKey() override;
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
    virtual void                         SetVelocity(float x, float y, float z) override;
    virtual float                        GetAbsoluteSpeed() override;
    virtual bool                         IsGlareOn(VehicleFX::ID fxId) override;
    virtual void                         GlareOn(VehicleFX::ID fxId) override;
    virtual void                         GlareOff(VehicleFX::ID fxId) override;
    virtual bool                         IsCollidingWithSoftBarrier() override;
    virtual IVehicleAI*                  GetAIVehiclePtr() override;
    virtual float                        GetSlipAngle() override;
    virtual const UMath::Vector3&        GetLocalVelocity() override;
    virtual void                         ComputeHeading(UMath::Vector3* out) override;
    virtual bool                         IsAnimating() override;
    virtual void                         SetAnimating(bool isAnimating) override;
    virtual bool                         IsOffWorld() override;
    virtual VehicleCustomizations*       GetCustomizations() override;
    virtual void                         SetCustomizations(VehicleCustomizations* customizations) override;
    virtual Physics::Tunings*            GetTunings() override;
    virtual void                         SetTunings(const Physics::Tunings& tunings) override;
    virtual bool                         GetPerformance(Physics::Info::CorrectedPerformance& to) override;
    virtual const char*                  GetCacheName() override;
    virtual bool                GetDynamicData(EventSequencer::System* system, void* pOutEventDynamicData) override;
    virtual bool                IsDriverAidOn(DriverAidType) override;
    virtual void                SetDriverAidLevel(DriverAidType, int, bool) override;
    virtual int                 GetDriverAidLevel(DriverAidType) override;
    virtual int                 GetDriverAidMaxLevel(DriverAidType) override;
    virtual void                RestoreDriverAidLevels_All() override;
    virtual void                RestoreDriverAidLevel(DriverAidType) override;
    virtual ISimable*           SpawnPart(UCrc32, UCrc32, UCrc32) override;
    virtual void                HidePart(UCrc32) override;
    virtual void                ResetPart(UCrc32) override;
    virtual UTL::COM::IUnknown* GetContextOwner() override;
    virtual const char*         GetContextDebugName() override;
#pragma endregion

    static inline bTNode<PVehicle*>** g_mInstances = reinterpret_cast<bTNode<PVehicle*>**>(0xA6AE40);

    static PVehicle* Construct(VehicleParams vehicleParams) {
      ISimable* simable =
          reinterpret_cast<ISimable*(__cdecl*)(UCrc32, VehicleParams*)>(0x72FBC0)(vehicleParams.mType, &vehicleParams);
      if (simable) return static_cast<PVehicle*>(simable);
      return nullptr;
    }

    static std::int32_t GetInstancesCount() {
      std::int32_t amount = 0;

      auto** pInstance = PVehicle::g_mInstances;
      if (!pInstance) return amount;

      auto* instance = *pInstance;
      while (instance != reinterpret_cast<bTNode<PVehicle*>*>(pInstance)) {
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
      while (instance != reinterpret_cast<bTNode<PVehicle*>*>(pInstance)) {
        if (cur_idx == idx) return static_cast<PVehicle*>(instance);

        cur_idx++;
        instance = instance->GetNext();
      }
      return nullptr;
    }
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(PVehicle::Resource::Flags)
#endif
}  // namespace OpenSpeed::ProStreet
