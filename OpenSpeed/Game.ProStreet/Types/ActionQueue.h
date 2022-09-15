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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_ACTIONQUEUE_H
#define OPENSPEED_GAME_PROSTREET_TYPES_ACTIONQUEUE_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Gen/controller.h>
#include <OpenSpeed/Game.ProStreet/Types/ActionData.h>
#include <OpenSpeed/Game.ProStreet/Types/InputMapping.h>
#include <OpenSpeed/Game.ProStreet/Types/Timer.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL/CircularQueue.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL/Listable.h>

namespace OpenSpeed::ProStreet {
  struct ActionQueue : UTL::Listable<ActionQueue, 32>, UTL::Instanceable<HACTIONQUEUE__*, ActionQueue, 32> {
    enum class eState : std::uint32_t { Disabled, Enabled };

    UTL::CircularQueue<ActionData, 50> fQueue;
    std::int32_t                       mPort;
    eState                             mState;
    InputMapping*                      mMappings;
    Attrib::Gen::controller            mAttributes;
    const char*                        mQueueName;
    std::int32_t                       mUniqueID;
    bool                               mConnected;
    bool                               mRequired;
    Timer                              mActionTime;
    Timer                              mActivationTime;
    bool                               mDebouncing;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_ACTIONQUEUE_H
