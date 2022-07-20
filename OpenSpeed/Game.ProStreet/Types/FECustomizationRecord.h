// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Physics.h>
#include <OpenSpeed/Game.ProStreet/Types/VehicleCustomizations.h>

namespace OpenSpeed::ProStreet {
  struct FEBlueprintStats {
    std::int32_t NumRaces;
    std::int32_t NumWins;
    std::int32_t NumTotaled;
    float        Content[4];
  };

  template <std::size_t n>
  struct FEBitField {
    char mBitChunks[n];
  };
  struct FEKitInfo {
    KitType       installedType[3];
    std::uint32_t installedKitNum[3];
    std::uint32_t inventory[4];
  };
  struct FEPaintSV {
    std::int8_t saturation;
    std::int8_t value;
  };

  struct FECustomizationRecord {
    std::uint16_t         FirstCarPartRecordIndex;
    std::uint16_t         FirstVinylRecordIndex;
    VehicleCustomizations mBluePrint[3];
    FEKitInfo             mBodykitInfo;
    FEBlueprintStats      mBlueprintStats[3];
    FEBitField<32>        PhysicsInventory;
    Physics::Tunings      Tunings[3];
    eCustomTuningType     ActiveTuning;
    std::int32_t          Preset;
    std::int8_t           Handle;
    std::int32_t          mType;
    FEPaintSV             mPaint[3][12];
    float                 mPerformanceDetuning[3];
    float                 mRideHeight;
    bool                  mFastVinyl;
    bool                  mBlueprintIsLocked[3];
    BluePrintNumber       mActiveBlueprint;
    bool                  mBlueprintUsed[3];

    inline void WriteRideIntoRecord(const RideInfo& rideInfo) {
      reinterpret_cast<void(__thiscall*)(FECustomizationRecord*, const RideInfo&)>(0x4C47F0)(this, rideInfo);
    }
    inline void WriteToGame(Attrib::StringKey collectionKey, VehicleCustomizations* out_VehicleParams) {
      reinterpret_cast<void(__thiscall*)(FECustomizationRecord*, Attrib::StringKey, VehicleCustomizations*)>(0x4BAD10)(
          this, collectionKey, out_VehicleParams);
    }
  };
}  // namespace OpenSpeed::ProStreet
