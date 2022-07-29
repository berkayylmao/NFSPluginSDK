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

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/AIVehicle.h>
#include <OpenSpeed/Game.MW05/Types/ITrafficAI.h>

namespace OpenSpeed::MW05 {
  struct AIVehicleTraffic : AIVehicle, ITrafficAI {
    virtual ~AIVehicleTraffic();
#pragma region overrides
    virtual void Update(float deltaTime) override;
    virtual void StartDriving(float speed) override;
#pragma endregion
  };
}  // namespace OpenSpeed::MW05
