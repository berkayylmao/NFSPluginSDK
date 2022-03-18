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
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/AIAvoidable.h>
#include <OpenSpeed/Game.MW05/Types/FloatSpring.h>
#include <OpenSpeed/Game.MW05/Types/IVehicleAI.h>
#include <OpenSpeed/Game.MW05/Types/VehicleBehavior.h>
#include <OpenSpeed/Game.MW05/Types/WRoadNav.h>

namespace OpenSpeed::MW05 {
  struct AIVehicle : VehicleBehavior, IVehicleAI, AIAvoidable {
    WRoadNav*               mDriveToNav;
    UMath::Vector3          mDirToNav;
    bool                    mDrivableToNav;
    float                   mDriveSpeed;
    UMath::Vector3          mDest;
    float                   mReverseOverrideTimer;
    float                   mReverseOverrideSteer;
    bool                    mReverseOverrideDirection;
    AITarget*               mTarget;
    short                   mDestSegment;
    bool                    mDrivableToTargetPos;
    bool                    mReversingSpeed;
    bool                    mSteeringBehind;
    HSIMTASK__*             mThinkTask;
    float                   mLastSpawnTime;
    bool                    mCanRespawn;
    AIGoal*                 mCurrentGoal;
    IPursuit*               mPursuit;
    IRoadBlock*             mRoadBlock;
    UCrc32                  mGoalName;
    float                   mAvoidableRadius;
    unsigned int            mDriveFlags;
    ICollisionBody*         mCollisionBody;
    ITransmission*          mITransmission;
    ISuspension*            mISuspension;
    IEngine*                mIEngine;
    IInput*                 mIInput;
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
    short                   mLastFutureSegment;
    short                   mLastFutureNodeInd;
    WRoadNav                mCurrentRoad;
    WRoadNav                mFutureRoad;
    float                   mAccelData[10];
    float                   mTopSpeed;

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
    virtual const eastl::list<AIAvoidable*>& GetAvoidableList() override;
    virtual void                             SetAvoidableRadius(float radius) override;
    virtual float                            GetTopSpeed() override;
    virtual float                            GetAcceleration(float at) override;
    virtual void                             GetWorldAvoidanceInfo(float dT, UMath::Vector3& leftCollNormal,
                                                                   UMath::Vector3& rightCollNormal) override;
    virtual void                          GetCollNav(const UMath::Vector3& forwardVector, float predictTime) override;
    virtual float                         GetLastSpawnTime() override;
    virtual void                          SetSpawned() override;
    virtual void                          UnSpawn() override;
    virtual void                          CanRespawn(bool respawnAvailable) override;
    virtual const Attrib::Gen::aivehicle& GetAttributes() override;
    virtual void                          EnableSimplePhysics() override;
    virtual void                          DisableSimplePhysics() override;
    virtual IPursuit*                     GetPursuit() override;
    virtual IRoadBlock*                   GetRoadBlock() override;
    virtual const UMath::Vector3&         GetSeekAheadPosition() override;
    virtual const UMath::Vector3&         GetFarFuturePosition() override;
    virtual const UMath::Vector3&         GetFarFutureDirection() override;
    virtual WRoadNav*                     GetCurrentRoad() override;
    virtual WRoadNav*                     GetFutureRoad() override;
    virtual bool                          IsCurrentGoal(const UCrc32& name) override;
    virtual UCrc32&                       GetGoalName() override;
    virtual bool                          IsCurrentAction(const UCrc32& name) override;
    virtual UCrc32                        GetActionName() override;
    virtual float                         GetSkill() override;
    virtual float                         GetShortcutSkill() override;
    virtual float                         GetPercentRaceComplete() override;
    virtual void                          Reset() override;
    virtual std::int32_t                  GetPriority() override;
    virtual void                          OnOwnerAttached(IAttachable* pOther) override;
    virtual void                          OnOwnerDetached(IAttachable* pOther) override;
    virtual void                          OnTaskSimulate(float deltaTime) override;
    virtual void                          OnBehaviorChange(const UCrc32& mechanic) override;
#pragma endregion

    inline AIGoal*        GetGoal() { return mCurrentGoal; }
    inline void           UpdateSpawnTimer(float spawnTime) { mLastSpawnTime = spawnTime; }
    inline ITransmission* GetTransmission() { return mITransmission; }
    inline ISuspension*   GetSuspension() { return mISuspension; }
    inline IEngine*       GetEngine() { return mIEngine; }
    inline IInput*        GetInput() { return mIInput; }
  };
}  // namespace OpenSpeed::MW05
