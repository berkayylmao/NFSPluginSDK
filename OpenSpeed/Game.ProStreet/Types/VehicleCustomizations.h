// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation either version 3 of the License or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/CarPaintPartRecordPacked.h>
#include <OpenSpeed/Game.ProStreet/Types/PackedDecalLayer.h>
#include <OpenSpeed/Game.ProStreet/Types/PackedVinylLayer.h>

namespace OpenSpeed::ProStreet {
  struct VehicleCustomizations {
    std::int16_t             GUID[0x5];
    std::uint32_t            creatorId;
    std::int8_t              creatorName[0x20];
    std::uint32_t            shareNumber;
    std::int16_t             InstalledParts[0xA5];
    std::uint8_t             customPaintsValid[0xC];
    CarPaintPartRecordPacked customPaints[0xC];
    std::uint8_t             partBaseMaterials[0xC];
    BluePrintType            bluePrintType;
    KitType                  kitType;
    std::uint32_t            kitNum;
    float                    RideHeight;
    float                    RidePitch;
    PackedVinylLayer         VinylLayers[0x14];
    std::int32_t             VinylMirrorBits;
    std::int32_t             NumVinylLayers;
    PackedDecalLayer         DecalLayers[0x14];
    std::int32_t             DecalMirrorBits;
    std::int32_t             NumDecalLayers;
    std::int32_t             LiveryID;
    std::uint8_t             MorphValues[0xB][0x28];
    float                    PhysicsTuning[0x1F];
    std::int32_t             Type;
  };
}  // namespace OpenSpeed::ProStreet
