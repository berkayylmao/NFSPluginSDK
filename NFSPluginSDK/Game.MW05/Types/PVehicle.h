// clang-format off
//
//    BSD 3-Clause License
//    Copyright (c) 2022, Berkay Yigit (berkayylmao) <mail@berkay.link>
//    All rights reserved.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    You should have received a copy of the BSD 3-Clause License along with
//    this program. If not, see <https://opensource.org/licenses/BSD-3-Clause/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_PVEHICLE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_PVEHICLE_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/bList.h>
#include <NFSPluginSDK/Game.MW05/Types/IAttributeable.h>
#include <NFSPluginSDK/Game.MW05/Types/IExplodeable.h>
#include <NFSPluginSDK/Game.MW05/Types/IVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/PhysicsObject.h>
#include <NFSPluginSDK/Game.MW05/Types/VehicleParams.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/pvehicle.h>

namespace NFSPluginSDK::MW05 {
  struct PVehicle : PhysicsObject, IVehicle, EventSequencer::IContext, IExplodeable, IAttributeable, bTNode<PVehicle> {
    struct _InstanceLayout {
      PVehicle* mInstance;
      bool      mIsEnabled;
    };

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
    virtual FECustomizationRecord*       GetCustomizations() override;
    virtual Physics::Tunings*            GetTunings() override;
    virtual void                         SetTunings(const Physics::Tunings& tunings) override;
    virtual bool                         GetPerformance(Physics::Info::CorrectedPerformance& to) override;
    virtual void*                        _unkFunc() override;
#pragma endregion

    static inline _InstanceLayout* g_mInstances = reinterpret_cast<_InstanceLayout*>(0x9352B0);

    static inline PVehicle* Construct(const VehicleParams& vehicleParams) {
      ISimable* pSimable =
          reinterpret_cast<ISimable*(__cdecl*)(VehicleParams, UCrc32)>(0x689820)(vehicleParams, vehicleParams.mName);
      return static_cast<PVehicle*>(pSimable);
    }

    static inline std::int32_t GetInstancesCount() {
      std::int32_t _amount    = 0;
      auto*        _pInstance = g_mInstances;
      while ((_pInstance++)->mInstance) _amount++;

      return _amount;
    }

    static inline PVehicle* GetInstance(std::int32_t idx) {
      auto* _instance = g_mInstances[idx].mInstance;
      if (_instance) return _instance;

      return nullptr;
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_PVEHICLE_H
