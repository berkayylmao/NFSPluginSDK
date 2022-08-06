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
#include <OpenSpeed/Core/EASTL/EASTL/vector.h>

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DALVehicleCommands.h>
#include <OpenSpeed/Game.ProStreet/Types/FEStateManager.h>

namespace OpenSpeed::ProStreet {
  struct FECarLotStateManager : FEStateManager {
    using eDriveTrainFilter = DALVehicleCommands::DriveTrain;
    enum class eFECarLotState : std::uint32_t {
      CARLOT_MAIN,
      CARLOT_MODE_DIALOG,
      CARLOT_MAXIMUM_CARS_DIALOG,
      CARLOT_NOT_ENOUGH_CASH_DIALOG,
      CARLOT_PURCHASE_DIALOG,
      CARLOT_PURCHASE_MS_POINTS_DIALOG,
      CARLOT_GARAGE,
      STATE_SHOWCASE
    };

    eastl::vector<DALVehicleCommands::CarInfo> mAWDCarList;
    eastl::vector<DALVehicleCommands::CarInfo> mRWDCarList;
    eastl::vector<DALVehicleCommands::CarInfo> mFWDCarList;
    eastl::vector<DALVehicleCommands::CarInfo> mAllCarList;
    eastl::vector<DALVehicleCommands::CarInfo> mCurrentCarList;
    eDriveTrainFilter                          mCurrentDriveTrain;
    std::int32_t                               mCurrentCarIndex;
    std::uint32_t                              mCurrentCarCost;
    std::int32_t                               mPlayerCash;
    bool                                       mUsedCash;
    bool                                       mCurrentCarIsLocked;
    FEObject*                                  mPrevModeButton;

    static inline FECarLotStateManager** spInstance = reinterpret_cast<FECarLotStateManager**>(0xB32B20);
    static FECarLotStateManager*         Get() {
      if (!spInstance) return nullptr;
      return *spInstance;
    }
  };
}  // namespace OpenSpeed::ProStreet
