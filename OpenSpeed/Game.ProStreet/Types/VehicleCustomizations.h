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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_VEHICLECUSTOMIZATIONS_H
#define OPENSPEED_GAME_PROSTREET_TYPES_VEHICLECUSTOMIZATIONS_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/CarPaintPartRecordPacked.h>
#include <OpenSpeed/Game.ProStreet/Types/DBCarPart.h>
#include <OpenSpeed/Game.ProStreet/Types/PackedDecalLayer.h>
#include <OpenSpeed/Game.ProStreet/Types/PackedVinylLayer.h>

namespace OpenSpeed::ProStreet {
  struct VehicleCustomizations {
    std::int16_t mGUID[5];
    alignas(4) std::uint32_t mCreatorId;
    char          mCreatorName[32];
    std::uint32_t mShareNumber;
    std::int16_t  mInstalledParts[165];
    std::int8_t   mCustomPaintsValid[12];
    alignas(4) CarPaintPartRecordPacked mCustomPaints[12];
    std::int8_t      mPartBaseMaterials[12];
    BluePrintType    mBluePrintType;
    KitType          mKitType;
    std::uint32_t    mKitNum;
    float            mRideHeight;
    float            mRidePitch;
    PackedVinylLayer mVinylLayers[20];
    std::int32_t     mVinylMirrorBits;
    std::int32_t     mNumVinylLayers;
    PackedDecalLayer mDecalLayers[20];
    std::int32_t     mDecalMirrorBits;
    std::int32_t     mNumDecalLayers;
    std::int32_t     mLiveryID;
    std::int8_t      mMorphValues[40][11];
    float            mPhysicsTuning[31];
    std::int32_t     mType;

    bool GetInstalledPart(CarSlotId slotId, CarType carType, DBCarPart* out) {
      return reinterpret_cast<bool(__thiscall*)(VehicleCustomizations*, CarSlotId, CarType, DBCarPart*)>(0x782F70)(
          this, slotId, carType, out);
    }
    std::int16_t& GetInstalledPart(CarSlotId slotId) noexcept {
      return mInstalledParts[static_cast<std::size_t>(slotId)];
    }
    const std::int16_t& GetInstalledPart(CarSlotId slotId) const noexcept {
      return mInstalledParts[static_cast<std::size_t>(slotId)];
    }
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_VEHICLECUSTOMIZATIONS_H
