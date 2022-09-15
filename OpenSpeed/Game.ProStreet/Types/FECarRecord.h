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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FECARRECORD_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FECARRECORD_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/FECustomizationRecord.h>

namespace OpenSpeed::ProStreet {
  struct FECarRecord {
    std::uint32_t           Handle;
    std::uint32_t           FEKey;
    std::uint32_t           VehicleKey;
    std::uint32_t           PresetKey;
    FEPlayerCarDBFilterBits FilterBits;
    std::uint8_t            Customization;
    std::uint8_t            CareerHandle;
    std::uint8_t            IsPresetSkin;
    std::uint8_t            Padd;

    bool IsUnlocked() { return reinterpret_cast<bool(__thiscall*)(FECarRecord*)>(0x548C00)(this); }

    DALVehicleCommands::DriveTrain GetDriveTrain() {
      return reinterpret_cast<DALVehicleCommands::DriveTrain(__thiscall*)(FECarRecord*)>(0x548C40)(this);
    }
    FECustomizationRecord* GetCustomizationRecord() {
      return reinterpret_cast<FECustomizationRecord*(__thiscall*)(FECarRecord*)>(0x533640)(this);
    }
    VehicleCustomizations* GetVCRecord(BluePrintNumber blueprintIdx) {
      auto* fecr = GetCustomizationRecord();
      if (!fecr) return nullptr;

      return &fecr->mBluePrints[static_cast<std::size_t>(blueprintIdx)];
    }
    VehicleCustomizations* GetActiveVCRecord() {
      auto* fecr = GetCustomizationRecord();
      if (!fecr) return nullptr;

      return &fecr->mBluePrints[static_cast<std::size_t>(fecr->mActiveBlueprint)];
    }
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FECARRECORD_H
