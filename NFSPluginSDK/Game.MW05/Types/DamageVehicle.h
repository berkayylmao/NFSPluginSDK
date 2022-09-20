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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGEVEHICLE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGEVEHICLE_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/slist.h>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/damagespecs.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageZone.h>
#include <NFSPluginSDK/Game.MW05/Types/EventSequencer.h>
#include <NFSPluginSDK/Game.MW05/Types/IDamageable.h>
#include <NFSPluginSDK/Game.MW05/Types/IDamageableVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/VehicleBehavior.h>

namespace NFSPluginSDK::MW05 {
  struct DamageVehicle : VehicleBehavior,
                         IDamageable,
                         Sim::Collision::IListener,
                         IDamageableVehicle,
                         EventSequencer::IContext {
    float                                      mShockTimer;
    int                                        fTempInvincibilityTimer;
    BehaviorSpecsPtr<Attrib::Gen::damagespecs> mSpecs;
    float                                      mOffScreenTimer;
    float                                      mDamageTotal;
    ICollisionBody*                            mIRBComplex;
    IRigidBody*                                mRB;
    IRenderable*                               mRenderable;
    DamageZone::Info                           mZoneDamage;
    UMath::Vector3                             mLastImpactSpeed;
    eastl::slist<UCrc32>                       mBrokenParts;
    VehicleFX::LightID                         mLightDamage;

    virtual ~DamageVehicle();
    virtual void OnImpact(const UMath::Vector3&, const UMath::Vector3&, float, float, const SimSurface&, ISimable*);
    virtual bool CanDamageVisuals();

#pragma region overrides
    virtual void                  Reset() override;
    virtual void                  OnTaskSimulate(float deltaTime) override;
    virtual void                  OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void                  SetInShock(float) override;
    virtual void                  SetShockForce(float) override;
    virtual float                 InShock() override;
    virtual void                  ResetDamage() override;
    virtual float                 GetHealth() override;
    virtual bool                  IsDestroyed() override;
    virtual void                  Destroy() override;
    virtual Sim::Collision::Info* GetZoneDamage() override;
    virtual void                  OnCollision(const Sim::Collision::Info& cinfo) override;
    virtual bool                  IsLightDamaged(VehicleFX::LightID idx) override;
    virtual void                  DamageLight(VehicleFX::LightID idx, bool damage) override;
    virtual bool                  SetDynamicData(void* System, void* pOutEventDynamicData) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGEVEHICLE_H
