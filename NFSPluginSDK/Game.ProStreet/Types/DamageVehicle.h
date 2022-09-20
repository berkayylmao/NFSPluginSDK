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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DAMAGEVEHICLE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DAMAGEVEHICLE_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/damagespecs.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DamageZone.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EventSequencer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IDamageable.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IDamageableVehicle.h>
#include <NFSPluginSDK/Game.ProStreet/Types/VehicleBehavior.h>

namespace NFSPluginSDK::ProStreet {
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
    ICollisionBody*                            mCollisionBody;
    IRigidBody*                                mRB;
    IRenderable*                               mRenderable;
    DamageZone::Info                           mZoneDamage;
    UMath::Vector3                             mLastImpactSpeed;
    eastl::list<UCrc32>                        mBrokenParts;
    VehicleFX::LightID                         mLightDamage;
    VehicleFX::LightID                         mLightCracked;
    VehicleFX::WindowID                        mWindowDamage;
    VehicleFX::WindowID                        mWindowCracked;
    float                                      mHitPointsOverride;

    virtual ~DamageVehicle();
    virtual void OnImpact(const UMath::Vector3&, const UMath::Vector3&, float, float, const SimSurface&, ISimable*);
    virtual bool CanDamageVisuals();

#pragma region overrides
    virtual void                OnTaskSimulate(float deltaTime) override;
    virtual void                OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void                Reset() override;
    virtual void                SetInShock(float) override;
    virtual void                SetShockForce(float) override;
    virtual float               InShock() override;
    virtual void                ResetDamagePrivate() override;
    virtual float               GetHealth() override;
    virtual bool                IsDestroyed() override;
    virtual void                Destroy() override;
    virtual DamageZone::Info    GetZoneDamage() override;
    virtual void                OnCollision(const Sim::Collision::Info& cinfo) override;
    virtual bool                IsLightDamaged(VehicleFX::LightID idx) override;
    virtual void                DamageLight(VehicleFX::LightID idx, bool damage) override;
    virtual bool                IsLightCracked(VehicleFX::LightID idx) override;
    virtual void                CrackLight(VehicleFX::LightID idx, bool crack) override;
    virtual bool                IsWindowDamaged(VehicleFX::WindowID idx) override;
    virtual void                DamageWindow(VehicleFX::WindowID idx, bool damage) override;
    virtual bool                IsWindowCracked(VehicleFX::WindowID idx) override;
    virtual void                CrackWindow(VehicleFX::WindowID idx, bool crack) override;
    virtual void                SetHitPointsOverride(float hp) override;
    virtual UTL::COM::IUnknown* GetContextOwner() = 0;
    virtual std::int32_t        GetContextDebugName(char* out, std::uint32_t len) override;
    virtual bool                GetDynamicData(EventSequencer::System* system, void* pOutEventDynamicData) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DAMAGEVEHICLE_H
