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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_DALMANAGER_H
#define OPENSPEED_GAME_PROSTREET_TYPES_DALMANAGER_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DALInterface.h>

namespace OpenSpeed::ProStreet {
  struct DALManager : DALInterface {
    DALInterface* mInterfaces[22];
    bool          mInited;

    virtual ~DALManager();
    virtual void HandleCommand(DLCommandObject*, const std::int32_t unk1 = -1);
    virtual void CancelCommand(DLCommandObject*, const std::int32_t unk1 = -1);

    static DALManager* Get() { return reinterpret_cast<DALManager*>(0xA50AD0); }
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_DALMANAGER_H
