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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FECUSTOMIZATIONRECORD_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FECUSTOMIZATIONRECORD_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Physics.h>
#include <OpenSpeed/Game.ProStreet/Types/VehicleCustomizations.h>

namespace OpenSpeed::ProStreet {
  struct FEBlueprintStats {
    std::int32_t mNumRaces;
    std::int32_t mNumWins;
    std::int32_t mNumTotaled;
    float        mContent[4];
  };

  template <std::size_t n>
  struct FEBitField {
    char mBitChunks[n];
  };
  struct FEKitInfo {
    KitType       mInstalledType[3];
    std::uint32_t mInstalledKitNum[3];
    std::uint32_t mInventory[4];
  };
  struct FEPaintSV {
    std::int8_t mSaturation;
    std::int8_t mValue;
  };

  struct FECustomizationRecord {
    std::uint16_t         mFirstCarPartRecordIndex;
    std::uint16_t         mFirstVinylRecordIndex;
    VehicleCustomizations mBluePrints[3];
    FEKitInfo             mBodykitInfo;
    FEBlueprintStats      mBlueprintStats[3];
    FEBitField<32>        mPhysicsInventory;
    Physics::Tunings      mTunings[3];
    eCustomTuningType     mActiveTuning;
    std::int32_t          mPreset;
    std::int8_t           mHandle;
    std::int32_t          mType;
    FEPaintSV             mPaint[3][12];
    float                 mPerformanceDetuning[3];
    float                 mRideHeight;
    bool                  mFastVinyl;
    bool                  mBlueprintIsLocked[3];
    BluePrintNumber       mActiveBlueprint;
    bool                  mBlueprintUsed[3];

    VehicleCustomizations* GetActiveBluePrint() { return &mBluePrints[static_cast<std::size_t>(mActiveBlueprint)]; }
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FECUSTOMIZATIONRECORD_H
