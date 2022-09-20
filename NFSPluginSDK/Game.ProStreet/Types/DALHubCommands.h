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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALHUBCOMMANDS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALHUBCOMMANDS_H
#pragma once

#include <memory>  // unique_ptr
#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DLCommandObject.h>

namespace NFSPluginSDK::ProStreet::DALHubCommands {
  struct GetScoresAndConditions : DLCommandObject {
    std::int32_t mScorePlayer1;
    std::int32_t mScorePlayer2;
    std::int32_t mWinCondition;
    std::int32_t mDominateCondition;

    virtual ~GetScoresAndConditions();
    virtual void Execute() override;

    static std::unique_ptr<GetScoresAndConditions> Construct() {
      auto dummy  = std::make_unique<uint8_t[]>(sizeof(GetScoresAndConditions));
      auto ret    = std::unique_ptr<GetScoresAndConditions>{reinterpret_cast<GetScoresAndConditions*>(dummy.release())};
      ret->mState = DLCommandObject::CommandState::WaitingToExecute;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x96FC04;
      return ret;
    }
  };
}  // namespace NFSPluginSDK::ProStreet::DALHubCommands

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALHUBCOMMANDS_H
