// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Core/EASTL/EASTL/vector.h>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/GRuntimeInstance.h>
#include <OpenSpeed/Game.MW05/Types/WTrigger.h>

namespace OpenSpeed::MW05 {
  struct GTrigger : GRuntimeInstance {
    WTrigger                 mWorldTrigger;
    UMath::Vector3           mDirection;
    std::uint32_t            mTriggerEnabled;
    eastl::vector<ISimable*> mSimObjInside;
    CARP::EventList          mEventList;
    CARP::EventStaticData    mEventStaticData;
    std::uint8_t             mTriggerEventData[16];
    EmitterGroup*            mParticleEffect[2];
    GIcon*                   mIcon;
    bool                     mEnabled;
    std::int32_t             mActivationReferences;
  };
}  // namespace OpenSpeed::MW05
