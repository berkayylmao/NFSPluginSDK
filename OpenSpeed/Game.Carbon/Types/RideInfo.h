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

#ifndef OPENSPEED_GAME_CARBON_TYPES_RIDEINFO_H
#define OPENSPEED_GAME_CARBON_TYPES_RIDEINFO_H
#pragma once

#include <OpenSpeed/Game.Carbon/Types.h>

namespace OpenSpeed::Carbon {
  struct RideInfo {
    CarType        Type;
    char           InstanceIndex;
    char           HasDash;
    char           CanBeVertexDamaged;
    char           SkinType;
    CARPART_LOD    mMinLodLevel;
    CARPART_LOD    mMaxLodLevel;
    CARPART_LOD    mMinFELodLevel;
    CARPART_LOD    mMaxFELodLevel;
    CARPART_LOD    mMaxLicenseLodLevel;
    CARPART_LOD    mMinTrafficDiffuseLodLevel;
    CARPART_LOD    mMinShadowLodLevel;
    CARPART_LOD    mMaxShadowLodLevel;
    CARPART_LOD    mMaxTireLodLevel;
    CARPART_LOD    mMaxBrakeLodLevel;
    CARPART_LOD    mMaxSpoilerLodLevel;
    CARPART_LOD    mMaxRoofScoopLodLevel;
    CARPART_LOD    mMinReflectionLodLevel;
    std::uint32_t  mCompositeSkinHash;
    std::uint32_t  mCompositeWheelHash;
    std::uint32_t  mCompositeSpinnerHash;
    CarPart*       mPartsTable[139];
    char           mPartsEnabled[139];
    CarPart*       PreviewPart;
    std::int32_t   mMyCarLoaderHandle;
    CarRenderUsage mMyCarRenderUsage;
    std::uint8_t   mSpecialLODBehavior;
    std::uint8_t   padpadpad[0xBF0];

    inline CarPart* GetPart(CarSlotId slotId) {
      return reinterpret_cast<CarPart*(__thiscall*)(RideInfo*, CarSlotId)>(0x7B06F0)(this, slotId);
    }

    inline void SetRandomPart(CarSlotId slotId, eCareerUpgradeLevels upgradeLevel) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarSlotId, eCareerUpgradeLevels)>(0x7DA970)(this, slotId,
                                                                                                upgradeLevel);
    }
    inline void SetUpgradePart(CarSlotId slotId, eCareerUpgradeLevels upgradeLevel) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarSlotId, eCareerUpgradeLevels)>(0x7DA740)(this, slotId,
                                                                                                upgradeLevel);
    }

    inline void SetRandomPaint() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x7DACA0)(this); }
    inline void SetRandomParts(Attrib::StringKey presetName = NULL) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, Attrib::StringKey)>(0x7E1880)(this, presetName);
    }
    inline void SetStockParts() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x7DA770)(this); }

    inline void Init(CarType type, CarRenderUsage renderUsage) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarType, CarRenderUsage, std::uint32_t, std::uint32_t)>(0x4ABE60)(
          this, type, renderUsage, 0, 0);
    }

    explicit RideInfo(CarType type, CarRenderUsage renderUsage) {
      reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x412350)(this);
      Init(type, renderUsage);
    }
    explicit RideInfo(CarType type) : RideInfo(type, CarRenderUsage::Player) {}
    explicit RideInfo() : RideInfo(CarType::NONE) {}
  };
}  // namespace OpenSpeed::Carbon

#endif  // OPENSPEED_GAME_CARBON_TYPES_RIDEINFO_H
