// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05 {
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

    CarPart* GetPart(CarSlotId slotId) {
      reinterpret_cast<CarPart*(__thiscall*)(RideInfo*, CarSlotId)>(0x739C70)(this, slotId);
    }

    void SetRandomPart(CarSlotId slotId, eCareerUpgradeLevels upgradeLevel) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarSlotId, eCareerUpgradeLevels)>(0x7596E0)(this, slotId,
                                                                                                upgradeLevel);
    }
    void SetUpgradePart(CarSlotId slotId, eCareerUpgradeLevels upgradeLevel) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarSlotId, eCareerUpgradeLevels)>(0x759470)(this, slotId,
                                                                                                upgradeLevel);
    }

    void SetRandomPaint() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x759800)(this); }
    void SetRandomParts() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x75B220)(this); }
    void SetStockParts() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x7594A0)(this); }

    void Init(CarType type, CarRenderUsage renderUsage, std::int32_t _unk1 = 0, std::int32_t _unk2 = 0) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarType, CarRenderUsage, std::int32_t, std::int32_t)>(0x739A70)(
          this, type, renderUsage, _unk1, _unk2);
    }

    explicit RideInfo(CarType type, CarRenderUsage renderUsage) { Init(type, renderUsage); }
    explicit RideInfo(CarType type) : RideInfo(type, CarRenderUsage::Player) {}
    explicit RideInfo() : RideInfo(CarType::NONE) {}
  };
}  // namespace OpenSpeed::MW05
