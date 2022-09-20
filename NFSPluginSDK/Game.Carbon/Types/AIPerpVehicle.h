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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_AIPERPVEHICLE_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_AIPERPVEHICLE_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehiclePid.h>
#include <NFSPluginSDK/Game.Carbon/Types/ICause.h>
#include <NFSPluginSDK/Game.Carbon/Types/ICheater.h>
#include <NFSPluginSDK/Game.Carbon/Types/IPerpetrator.h>

namespace NFSPluginSDK::Carbon {
  struct AIPerpVehicle : AIVehiclePid, IPerpetrator, ICause, ICheater {
    float                           mHeat;
    bool                            mHeatChangedInCareer;
    std::int32_t                    mCostToState;
    std::int32_t                    mPendingRepPointsNormal;
    std::int32_t                    mPendingRepPointsFromCopDestruction;
    bool                            mHiddenFromCars;
    bool                            mHiddenFromHelicopters;
    bool                            mWasInRaceEventLastHeatUpdate;
    float                           mHiddenZoneTimer;
    float                           mHiddenZoneLatchTime;
    bool                            mWasInZoneLastUpdate;
    std::int32_t                    mPursuitZoneCheck;
    Attrib::Gen::pursuitlevels*     mPursuitLevelAttrib;
    Attrib::Gen::pursuitsupport*    mPursuitSupportAttrib;
    Attrib::Gen::pursuitescalation* mPursuitEscalationAttrib;
    GRacerInfo*                     pRacerInfo;
    float                           fBaseSkill;
    float                           fGlueSkill;
    PidError*                       pGlueError;
    float                           fGlueTimer;
    float                           fGlueOutput;
    float                           mCheatOverride;
    float                           mLastTrafficHitTime;
    float                           m911CallTimer;

    virtual ~AIPerpVehicle();
#pragma region overrides
    virtual void                            Reset() override;
    virtual void                            OnTaskSimulate(float deltaTime) override;
    virtual void                            OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void                            Update(float deltaTime) override;
    virtual void                            OnClearCausality(float startTime) override;
    virtual float                           GetSkill() override;
    virtual float                           GetBaseSkill() override;
    virtual float                           GetHeat() override;
    virtual void                            SetHeat(float heat) override;
    virtual Attrib::Gen::pursuitescalation* GetPursuitEscalationAttrib() override;
    virtual Attrib::Gen::pursuitlevels*     GetPursuitLevelAttrib() override;
    virtual Attrib::Gen::pursuitsupport*    GetPursuitSupportAttrib() override;
    virtual bool                            GetHeatChangedInCareer() override;
    virtual void                            AddCostToState(std::int32_t cost) override;
    virtual std::int32_t                    GetCostToState() override;
    virtual void                            SetCostToState(std::int32_t costToState) override;
    virtual bool                            IsRacing() override;
    virtual bool                            IsBeingPursued() override;
    virtual bool                            IsHiddenFromCars() override;
    virtual bool                            IsHiddenFromHelicopters() override;
    virtual bool                            IsPartiallyHidden(float& howHidden) override;
    virtual void                            AddToPendingRepPointsFromCopDestruction(std::int32_t amount) override;
    virtual void                            AddToPendingRepPointsNormal(std::int32_t amount) override;
    virtual std::int32_t                    GetPendingRepPointsNormal() override;
    virtual std::int32_t                    GetPendingRepPointsFromCopDestruction() override;
    virtual void                            ClearPendingRepPoints() override;
    virtual void                            SetRacerInfo(GRacerInfo* info) override;
    virtual GRacerInfo*                     GetRacerInfo() override;
    virtual float                           GetLastTrafficHitTime() override;
    virtual void                            Set911CallTime(float time) override;
    virtual float                           Get911CallTime() override;
    virtual void  OnCausedCollision(const Sim::Collision::Info& cInfo, ISimable* from, ISimable* to) override;
    virtual void  OnCausedExplosion(IExplosion* explosion, ISimable* to) override;
    virtual float GetCatchupCheat() override;
    virtual void  SetCatchupCheatOverride(float cheat) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_AIPERPVEHICLE_H