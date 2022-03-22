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
#include <OpenSpeed/Game.MW05/Types/AIVehicleRacecar.h>
#include <OpenSpeed/Game.MW05/Types/IHumanAI.h>

namespace OpenSpeed::MW05 {
  struct AIVehicleHuman : AIVehicleRacecar, IHumanAI {
    bool           bAiControl;
    UMath::Vector3 vMomentPosition;
    float          fMomentRadius;
    bool           mWrongWay;

    virtual ~AIVehicleHuman();
#pragma region overrides
    virtual void                  Update(float deltaTime) override;
    virtual float                 GetSkill() override;
    virtual float                 GetCatchupCheat() override;
    virtual void                  ChangeDragLanes(bool left) override;
    virtual bool                  IsPlayerSteering() override;
    virtual bool                  GetAiControl() override;
    virtual void                  SetAiControl(bool ai_control) override;
    virtual void                  SetWorldMoment(const UMath::Vector3& position, float radius) override;
    virtual const UMath::Vector3& GetWorldMomentPosition() override;
    virtual float                 GetWorldMomentRadius() override;
    virtual void                  ClearWorldMoment() override;
    virtual bool                  IsFacingWrongWay() override;
#pragma endregion
  };
}  // namespace OpenSpeed::MW05
