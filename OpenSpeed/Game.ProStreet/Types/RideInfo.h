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
#include <OpenSpeed/Game.ProStreet/Types/AutoSculpt.h>
#include <OpenSpeed/Game.ProStreet/Types/DBCarPart.h>
#include <OpenSpeed/Game.ProStreet/Types/CarPaintPart.h>
#include <OpenSpeed/Game.ProStreet/Types/DecalLayerPartInfo.h>
#include <OpenSpeed/Game.ProStreet/Types/Physics.h>
#include <OpenSpeed/Game.ProStreet/Types/VinylLayerPartInfo.h>

namespace OpenSpeed::ProStreet {
  struct RideInfo {
    CarType                   Type;
    std::int8_t               InstanceIndex;
    bool                      Initialized;
    bool                      ForceLowRez;
    bool                      loadedFE;
    CARPART_LOD               mMinLodLevel;
    CARPART_LOD               mMaxLodLevel;
    CARPART_LOD               mMinFELodLevel;
    CARPART_LOD               mMaxFELodLevel;
    CARPART_LOD               mMaxLicenseLodLevel;
    CARPART_LOD               mMinTrafficDiffuseLodLevel;
    CARPART_LOD               mMinShadowLodLevel;
    CARPART_LOD               mMaxShadowLodLevel;
    CARPART_LOD               mMaxExhaustLodLevel;
    CARPART_LOD               mMaxTireLodLevel;
    CARPART_LOD               mMaxBrakeLodLevel;
    CARPART_LOD               mMaxSpoilerLodLevel;
    CARPART_LOD               mMaxRoofScoopLodLevel;
    CARPART_LOD               mMaxSeatLodLevel;
    CARPART_LOD               mMinReflectionLodLevel;
    CARPART_LOD               mMaxInteriorLodLevel;
    CARPART_LOD               mMinInteriorLodLevel;
    std::uint8_t              mCompositeSkinHash;
    std::uint8_t              mCompositeWheelHash[2];
    DBCarPart                 mPartsTable[165];
    char                      mPartsEnabled[165];
    DBCarPart*                PreviewPart;
    bool                      autosculptLoad;
    CarPaintPart              mCustomPaints[12];
    bool                      mCustomPaintValid[12];
    eLightMaterial*           partLightMaterials[19];
    std::int32_t              mMyCarLoaderHandle;
    CarRenderUsage            mMyCarRenderUsage;
    char                      mSpecialLODBehavior;
    float                     mRideHeight;
    VinylLayerPartInfo        mVinylLayers[20];
    DecalLayerPartInfo        mDecalLayers[20];
    std::uint32_t             mVinylMirrorBits;
    std::uint64_t             mDecalMirrorBits;
    std::uint16_t             mNumVinylLayers;
    std::uint16_t             mNumDecalLayers;
    std::uint16_t             mVinylEditLayer;
    std::uint16_t             mDecalEditLayer;
    bool                      mEditingVinyl;
    bool                      mEditingDecal;
    std::uint16_t             mFastVinyl;
    AutoSculpt                mAutoSculpt;
    IAttachmentSystem*        mAttachmentSystem;
    bool                      mNeedCreateSkins;
    KitType                   kitTypeInstalled;
    std::uint32_t             kitNumInstalled;
    BluePrintType             bluePrintType;
    Physics::Upgrades::Tuning PhysicsTuning[31];

    inline void SetStockParts() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x78A2B0)(this); }

    inline void Init(CarType type, CarRenderUsage renderUsage) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarType, CarRenderUsage, std::uint32_t, std::uint32_t,
                                         std::uint32_t, std::uint32_t)>(0x789E10)(this, type, renderUsage, 0, 0, 0, 0);
    }

    explicit RideInfo(CarType type, CarRenderUsage renderUsage) {
      reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x78E2B0)(this);
      Init(type, renderUsage);
    }
    explicit RideInfo(CarType type) : RideInfo(type, CarRenderUsage::Player) {}
    explicit RideInfo() : RideInfo(CarType::NONE) {}

    ~RideInfo() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x785130)(this); }
  };
}  // namespace OpenSpeed::ProStreet
