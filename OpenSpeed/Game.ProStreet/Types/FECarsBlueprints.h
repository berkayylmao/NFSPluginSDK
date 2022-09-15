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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FECARSBLUEPRINTS_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FECARSBLUEPRINTS_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DALVehicleCommands.h>
#include <OpenSpeed/Game.ProStreet/Types/FECustomizeStatsWidget.h>
#include <OpenSpeed/Game.ProStreet/Types/MenuScreen.h>

namespace OpenSpeed::ProStreet {
  struct FECarsBlueprintsOption {
    eFECarsBlueprintsOptionID OptionID;
    bool                      Enabled;
  };

  struct FECarsBlueprints : MenuScreen {
    std::int32_t                                mNumCarInfos;
    DALVehicleCommands::CarInfo*                mCarInfos;
    DALVehicleCommands::BlueprintInfo           mBPInfos[3];
    DALVehicleCommands::CarInfo                 mCarFilter;
    BluePrintType                               mMode;
    std::int32_t                                mSelectedCarIndex;
    std::int32_t                                mSelectedBPIndex;
    bool                                        mMenuVisible;
    std::int32_t                                mSelectedMenuIndex;
    std::int32_t                                mNumMenuItems;
    std::uint32_t                               mEmptyBlueprintLangHash;
    FECarsBlueprintsOption                      mMenuItems[5];
    FECustomizeStatsWidget                      mStatsWidget;
    DALVehicleCommands::GetDownloadedBlueprints mDownloadedBlueprints;
    DALVehicleCommands::CarInfo                 mDownloadedCarInfo;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FECARSBLUEPRINTS_H
