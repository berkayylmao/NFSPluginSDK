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

#ifndef OPENSPEED_GAME_MW05_TYPES_GROUNDSUPPORTREQUEST_H
#define OPENSPEED_GAME_MW05_TYPES_GROUNDSUPPORTREQUEST_H
#pragma once

#include <OpenSpeed/Core/EASTL/EASTL/list.h>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct GroundSupportRequest {
    enum Status : std::uint32_t { NotActive, Pending, Active };

    const HeavySupport*      mHeavySupport;
    const LeaderSupport*     mLeaderSupport;
    UTL::List<IVehicle*, 10> mIVehicleList;
    eastl::list<char*>       mVehicleGoals;
    float                    mSupportTimer;
    Status                   mSupportRequestStatus;
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_GROUNDSUPPORTREQUEST_H
