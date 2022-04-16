// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.Carbon/Types.h>
#include <OpenSpeed/Game.Carbon/Types/AIGoal.h>
#include <OpenSpeed/Game.Carbon/Types/AIAvoidable.h>
#include <OpenSpeed/Game.Carbon/Types/FloatSpring.h>
#include <OpenSpeed/Game.Carbon/Types/IAvoidable.h>
#include <OpenSpeed/Game.Carbon/Types/IInput.h>
#include <OpenSpeed/Game.Carbon/Types/IVehicleAI.h>
#include <OpenSpeed/Game.Carbon/Types/VehicleBehavior.h>
#include <OpenSpeed/Game.Carbon/Types/WRoadNav.h>
#include <OpenSpeed/Game.Carbon/Types/WRoadNavInfluence.h>

namespace OpenSpeed::Carbon {
  struct AIVehicle : VehicleBehavior, IVehicleAI, IInput, IAvoidable, AIAvoidable {
    struct InputControls {
      float mSteering;
      float mGas;
      float mBrake;
      float mHandBrake;
      float mClutch;
      float mOverSteer;
      bool  mNOS;
      bool  mCruiseControl;
    };

    std::uint32_t           __unk_AIVehicle_1__;
    WRoadNav*               mDriveToNav;
    UMath::Vector3          mDirToNav;
    bool                    mDrivableToNav;
    float                   mDriveableToNavTimer;
    float                   mDriveSpeed;
    UMath::Vector3          mDest;
    float                   mReverseOverrideTimer;
    float                   mReverseOverrideSteer;
    bool                    mReverseOverrideDirection;
    AITarget*               mTarget;
    AITarget*               mPursuitTarget;
    std::int16_t            mDestSegment;
    bool                    mDrivableToTargetPos;
    bool                    mDrivableToPursuitTargetPos;
    bool                    mReversingSpeed;
    bool                    mSteeringBehind;
    UMath::Vector3          mPursuitOffset;
    HSIMTASK__*             mThinkTask;
    float                   mLastSpawnTime;
    bool                    mCanRespawn;
    AIGoal*                 mCurrentGoal;
    float                   mStunTime;
    IPursuit*               mPursuit;
    IRoadBlock*             mRoadBlock;
    UCrc32                  mGoalName;
    bool                    mIsAvoidable;
    float                   mAvoidableRadius;
    DriveFlags              mDriveFlags;
    ICollisionBody*         mCollisionBody;
    ITransmission*          mITransmission;
    ISuspension*            mISuspension;
    IEngine*                mIEngine;
    InputControls           mControls;
    WRoadNav*               mCollNav;
    Attrib::Gen::aivehicle* mAttributes;
    FloatSpring             mDampedAngularVel;
    FloatSpring             mDampedAngle;
    float                   mRoadUpdateTimer;
    float                   mRoadIncrementTimer;
    float                   mSeekAheadTimer;
    UMath::Vector3          mSeekAheadPosition;
    UMath::Vector3          mFarFutureDirection;
    UMath::Vector3          mFarFuturePosition;
    WRoadNav*               mCurrentRoad;
    WRoadNav*               mFutureRoad;
    float                   mAccelData[10];
    float                   mTopSpeed;
    bool                    mSimplePhysicsEnabled;
    float                   mSteerCorrectionPower;
    bool                    mCrashed;
    WRoadNavInfluence       mNavInfluence;

    virtual ~AIVehicle();
    virtual void Update(float deltaTime);
    virtual void OnCollision(Sim::Collision::Info const& cInfo);
    virtual void OnDebugDraw();
    virtual void OnClearCausality(float startTime);
    virtual void OnReverse(float deltaTime);
    virtual void OnSteering(float deltaTime);
    virtual void OnGasBrake(float deltaTime);
    virtual void OnDriving(float deltaTime);
    virtual void ResetInternals();
    virtual void IsTetheredToTarget(UTL::COM::IUnknown* object);
#pragma region overrides
    virtual bool                  OnTask(HSIMTASK__* hTask, float deltaTime) override;
    virtual void                  Reset() override;
    virtual std::int32_t          GetPriority() override;
    virtual void                  OnOwnerAttached(IAttachable* pOther) override;
    virtual void                  OnOwnerDetached(IAttachable* pOther) override;
    virtual void                  OnTaskSimulate(float deltaTime) override;
    virtual void                  OnBehaviorChange(const UCrc32& mechanic) override;
    virtual ISimable*             GetSimable() override;
    virtual IVehicle*             GetVehicle() override;
    virtual AISplinePath*         GetSplinePath() override;
    virtual void                  SetReverseOverride(float time) override;
    virtual bool                  GetReverseOverride() override;
    virtual DriveFlags            GetDriveFlags() override;
    virtual void                  ClearDriveFlags() override;
    virtual void                  DoReverse() override;
    virtual void                  DoSteering() override;
    virtual void                  DoGasBrake() override;
    virtual void                  DoDriving(DriveFlags flags) override;
    virtual void                  DoNOS() override;
    virtual bool                  GetNOSAllowed() override;
    virtual float                 GetDriveSpeed() override;
    virtual void                  SetDriveSpeed(float driveSpeed) override;
    virtual void                  SetDriveTarget(const UMath::Vector3& destination) override;
    virtual float                 GetLookAhead() override;
    virtual const UMath::Vector3& GetDriveTarget() override;
    virtual WRoadNav*             GetDriveToNav() override;
    virtual bool                  GetDrivableToDriveToNav() override;
    virtual void                  ResetDriveToNav(eLaneSelection laneSelection) override;
    virtual void                  ResetVehicleToRoadNav(WRoadNav* otherNav) override;
    virtual void                  ResetVehicleToRoadNav(std::int16_t segInd, char laneInd, float timeStep) override;
    virtual void  ResetVehicleToRoadPos(const UMath::Vector3& position, const UMath::Vector3& forwardVector) override;
    virtual float GetPathDistanceRemaining() override;
    virtual AITarget*                        GetTarget() override;
    virtual bool                             GetDrivableToTargetPos() override;
    virtual bool                             GetDrivableToPursuitTargetPos() override;
    virtual AITarget*                        GetPursuitTarget() override;
    virtual const eastl::list<AIAvoidable*>& GetAvoidableList() override;
    virtual void                             SetAvoidableRadius(float radius) override;
    virtual float                            GetTopSpeed() override;
    virtual float                            GetAcceleration(float at) override;
    virtual void                             GetWorldAvoidanceInfo(float dT, UMath::Vector3& leftCollNormal,
                                                                   UMath::Vector3& rightCollNormal) override;
    virtual bool                             HasWorldCollision(const UMath::Vector3&) override;
    virtual float                            GetLastSpawnTime() override;
    virtual void                             SetSpawned() override;
    virtual void                             UnSpawn() override;
    virtual bool                             CanRespawn(bool setRespawnAvailable) override;
    virtual const Attrib::Gen::aivehicle&    GetAttributes() override;
    virtual void                             EnableSimplePhysics() override;
    virtual bool                             IsSimplePhysicsActive() override;
    virtual void                             DisableSimplePhysics() override;
    virtual IPursuit*                        GetPursuit() override;
    virtual AIPursuit*                       AttachPursuit(AIPursuit*) override;
    virtual AIRoadBlock*                     AttachRoadBlock(AIRoadBlock*) override;
    virtual UMath::Vector3&                  GetPursuitOffset() override;
    virtual IRoadBlock*                      GetRoadBlock() override;
    virtual IVehicle*                        GetLeader() override;
    virtual AIWingman*                       GetWingman() override;
    virtual float                            GetStunTime() override;
    virtual void                             SetStunTime(float stunTime) override;
    virtual const UMath::Vector3&            GetSeekAheadPosition() override;
    virtual const UMath::Vector3&            GetFarFuturePosition() override;
    virtual const UMath::Vector3&            GetFarFutureDirection() override;
    virtual WRoadNav*                        GetCurrentRoad() override;
    virtual WRoadNav*                        GetFutureRoad() override;
    virtual bool                             IsCurrentGoal(const UCrc32& goal) override;
    virtual UCrc32&                          GetGoalName() override;
    virtual void                             SetGoal(const UCrc32& goal) override;
    virtual bool                             IsGoalAccomplished() override;
    virtual void                             ResetVehicleCollisionReactions() override;
    virtual bool                             IsCurrentAction(const UCrc32& action) override;
    virtual UCrc32                           GetActionName() override;
    virtual float                            GetSkill() override;
    virtual float                            GetBaseSkill() override;
    virtual float                            GetShortcutSkill() override;
    virtual float                            GetPercentRaceComplete() override;
    virtual bool                             IsCrashed() override;
    virtual void                             SetCrashed(bool crashed) override;
    virtual bool                             IsOnHighway() override;
    virtual WRoadNavInfluence&               GetNavInfluence() override;
    virtual bool                             IsWingman(ISimable* target) override;
    virtual bool                             IsCrewMate(ISimable* target) override;
    virtual bool                             IsCopVehicle() override;
    virtual bool                             OnUpdateAvoidable(UMath::Vector3& pos, float& sweep) override;
#pragma endregion

    inline void ClearGoal() {
      if (mCurrentGoal) mCurrentGoal->~AIGoal();
      mCurrentGoal = nullptr;
      mGoalName    = NULL;
    }

    inline AIGoal*        GetGoal() { return mCurrentGoal; }
    inline ITransmission* GetTransmission() { return mITransmission; }
    inline ISuspension*   GetSuspension() { return mISuspension; }
    inline IEngine*       GetEngine() { return mIEngine; }
    inline InputControls& GetInputControls() { return mControls; }

    inline void UpdateSpawnTimer(float spawnTime) { mLastSpawnTime = spawnTime; }
  };
}  // namespace OpenSpeed::Carbon
