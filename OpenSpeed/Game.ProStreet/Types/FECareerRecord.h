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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_FECAREERRECORD_H
#define OPENSPEED_GAME_PROSTREET_TYPES_FECAREERRECORD_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/FEImpoundData.h>
#include <OpenSpeed/Game.ProStreet/Types/FEInfractionsData.h>

namespace OpenSpeed::ProStreet {
  struct FECareerRecord {
    std::uint8_t      mHandle;
    FEImpoundData     mTheImpoundData;
    float             mVehicleHeat;
    bool              mHasNeverBeenInHub;
    std::uint32_t     mBounty;
    std::uint16_t     mNumEvadedPursuits;
    std::uint16_t     mNumBustedPursuits;
    float             mDamageLevel;
    std::int32_t      mDamageCost;
    FEInfractionsData mUnservedInfractions;
    FEInfractionsData mServedInfractions;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_FECAREERRECORD_H
