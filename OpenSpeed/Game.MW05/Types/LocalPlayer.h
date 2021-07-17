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
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/IPlayer.h>
#include <OpenSpeed/Game.MW05/Types/Sim.h>

namespace OpenSpeed::MW05 {
  struct LocalPlayer : Sim::Entity, IPlayer, Sim::Collision::IListener {
    IFeedback*      mFFB;
    ISteeringWheel* mWheelDevice;
    std::int32_t    mRenderPort;
    std::int32_t    mControllerPort;
    std::int32_t    mSettingIndex;
    const char*     mName;
    std::uint32_t   mNeighbourhoodHash;
    IHud*           mHud;
    HSIMTASK__*     mHudTask;
    IActivity*      mSpeech;
    bool            mInGameBreaker;
    float           mGameBreakerCharge;
    HACTIVITY__*    mLastPursuit;

    virtual ~LocalPlayer();
#pragma region overrides
    virtual ISimable*             GetSimable() override;
    virtual bool                  IsLocal() override;
    virtual const UMath::Vector3& GetPosition() override;
    virtual bool                  SetPosition(const UMath::Vector3& newPosition) override;
    virtual PlayerSettings*       GetSettings() override;
    virtual void                  SetSettings(std::int32_t) override;
    virtual std::int32_t          GetSettingsIndex() override;
    virtual IHud*                 GetHud() override;
    virtual void                  SetHud(ePlayerHudType newHudType) override;
    virtual void                  SetRenderPort(int32_t) override;
    virtual std::int32_t          GetRenderPort() override;
    virtual void                  SetControllerPort(std::int32_t) override;
    virtual std::int32_t          GetControllerPort() override;
    virtual IFeedback*            GetFFB() override;
    virtual ISteeringWheel*       GetSteeringDevice() override;
    virtual bool                  InGameBreaker() override;
    virtual bool                  CanRechargeNOS() override;
    virtual void                  ResetGameBreaker(bool fill) override;
    virtual void                  ChargeGameBreaker(float amount) override;
    virtual bool                  ToggleGameBreaker() override;
    virtual bool                  SetPosition(const UMath::Vector3& newPosition) override;
    virtual void                  OnAttached(IAttachable* pOther) override;
    virtual void                  OnDetached(IAttachable* pOther) override;
    virtual void                  OnCollision(const Sim::Collision::Info& cinfo) override;
#pragma endregion
  };
}  // namespace OpenSpeed::MW05
