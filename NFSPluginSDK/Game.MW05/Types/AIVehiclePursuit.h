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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEPURSUIT_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEPURSUIT_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehiclePid.h>
#include <NFSPluginSDK/Game.MW05/Types/IPursuitAI.h>
#include <NFSPluginSDK/Game.MW05/Types/Timer.h>

namespace NFSPluginSDK::MW05 {
  struct AIVehiclePursuit : AIVehiclePid, IPursuitAI {
    bool           mInPursuit;
    bool           mBreaker;
    bool           mChicken;
    bool           mDamagedByPerp;
    SirenState     mSirenState;
    bool           mSirenInit;
    Timer          mT_siren[3];
    bool           mInFormation;
    bool           mInPosition;
    bool           mWithinEngagementRadius;
    UMath::Vector3 mPursuitOffset;
    UMath::Vector3 mInPositionOffset;
    UCrc32         mInPositionGoal;
    float          mTimeSinceTargetSeen;
    float          mVisibiltyTestTimer;
    UCrc32         mSupportGoal;

    virtual ~AIVehiclePursuit();
    virtual void UpdateSiren(float deltaTime);
#pragma region overrides
    virtual void                  Update(float deltaTime) override;
    virtual void                  ResetInternals() override;
    virtual void                  StartPatrol() override;
    virtual void                  StartRoadBlock() override;
    virtual void                  StartFlee() override;
    virtual void                  SetInPursuit(bool inPursuit) override;
    virtual bool                  GetInPursuit() override;
    virtual void                  StartPursuit(AITarget* target, ISimable* itargetSimable) override;
    virtual void                  DoInPositionGoal() override;
    virtual void                  EndPursuit() override;
    virtual AITarget*             GetPursuitTarget() override;
    virtual bool                  StartSupportGoal() override;
    virtual AITarget*             PursuitRequest() override;
    virtual void                  SetInFormation(bool inFormation) override;
    virtual bool                  GetInFormation() override;
    virtual void                  SetInPosition(bool inPosition) override;
    virtual bool                  GetInPosition() override;
    virtual void                  SetPursuitOffset(const UMath::Vector3& offset) override;
    virtual const UMath::Vector3& GetPursuitOffset() override;
    virtual void                  SetInPositionGoal(const UCrc32& ipg) override;
    virtual const UCrc32&         GetInPositionGoal() override;
    virtual void                  SetInPositionOffset(const UMath::Vector3& offset) override;
    virtual const UMath::Vector3& GetInPositionOffset() override;
    virtual void                  SetBreaker(bool breaker) override;
    virtual bool                  GetBreaker() override;
    virtual void                  SetChicken(bool chicken) override;
    virtual bool                  GetChicken() override;
    virtual void                  SetDamagedByPerp(bool damaged) override;
    virtual bool                  GetDamagedByPerp() override;
    virtual SirenState            GetSirenState() override;
    virtual float                 GetTimeSinceTargetSeen() override;
    virtual void                  ZeroTimeSinceTargetSeen() override;
    virtual bool                  CanSeeTarget(AITarget* target) override;
    virtual const UCrc32&         GetSupportGoal() override;
    virtual void                  SetSupportGoal(UCrc32 sg) override;
    virtual void                  SetWithinEngagementRadius() override;
    virtual bool                  WasWithinEngagementRadius() override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEPURSUIT_H
