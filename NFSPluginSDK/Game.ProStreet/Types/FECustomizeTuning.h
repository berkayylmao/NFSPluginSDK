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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZETUNING_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZETUNING_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ArrayWidgetMenu.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DALVehicleCommands.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECustomizeCarStatsWidget.h>
#include <NFSPluginSDK/Game.ProStreet/Types/RideInfo.h>
#include <NFSPluginSDK/Game.ProStreet/Types/TuningSelectablePart.h>

namespace NFSPluginSDK::ProStreet {
  struct FECustomizeTuning : ArrayWidgetMenu {
    TuningSelectablePart*               mTuningPart;
    RideInfo                            mRideInfo;
    DALVehicleCommands::GetSliderStats* mSliderStats;
    std::uint32_t                       mPVehicleKey;
    DALVehicleCommands::RaceMode        mMode;
    FECustomizeCarStatsWidget           mStatsWidget;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZETUNING_H
