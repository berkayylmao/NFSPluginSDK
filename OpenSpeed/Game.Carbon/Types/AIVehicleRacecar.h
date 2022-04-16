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
#include <OpenSpeed/Game.Carbon/Types/AIPerpVehicle.h>
#include <OpenSpeed/Game.Carbon/Types/IRacer.h>

namespace OpenSpeed::Carbon {
  struct AIVehicleRacecar : AIPerpVehicle, IRacer {
    float        mSimTimeToNextConsiderSimplePhysics;
    std::uint8_t __unk_AIVehicleRacerCar__[0x8];

    virtual ~AIVehicleRacecar();
#pragma region overrides
    virtual void       Update(float deltaTime) override;
    virtual void       OnDebugDraw() override;
    virtual IVehicle*  GetLeader() override;
    virtual float      GetSkill() override;
    virtual float      GetBaseSkill() override;
    virtual void       PrepareForRace(const RacePreparationInfo& rpi) override;
    virtual void       StartRace(DriverStyle style) override;
    virtual void       QuitRace() override;
    virtual AIWingman* GetWingman() override;
    virtual void       SetWingman(IVehicle* vehicle) override;
    virtual void       BecomeWingman(eWingmanRole role) override;
    virtual bool       GaveHeadStart() override;
#pragma endregion
  };
}  // namespace OpenSpeed::Carbon
