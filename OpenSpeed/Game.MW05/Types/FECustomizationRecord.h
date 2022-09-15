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

#ifndef OPENSPEED_GAME_MW05_TYPES_FECUSTOMIZATIONRECORD_H
#define OPENSPEED_GAME_MW05_TYPES_FECUSTOMIZATIONRECORD_H
#pragma once

#include <algorithm>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Physics.h>

namespace OpenSpeed::MW05 {
  struct FECustomizationRecord {
    std::int16_t               mInstalledParts[139];
    Physics::Upgrades::Package mInstalledPhysics;
    Physics::Tunings           mTunings[3];
    eCustomTuningType          mActiveTuning;
    std::int32_t               mPreset;
    std::uint8_t               mHandle;

    std::int16_t& GetInstalledPart(CarSlotId slotId) noexcept {
      return mInstalledParts[static_cast<std::size_t>(slotId)];
    }
    const std::int16_t& GetInstalledPart(CarSlotId slotId) const noexcept {
      return mInstalledParts[static_cast<std::size_t>(slotId)];
    }

    void WriteRideIntoRecord(const RideInfo* rideInfo) {
      reinterpret_cast<void(__thiscall*)(FECustomizationRecord*, const RideInfo*)>(0x56F2F0)(this, rideInfo);
    }

    void operator=(const FECustomizationRecord& rhs) {
      std::copy(std::cbegin(rhs.mInstalledParts), std::cend(rhs.mInstalledParts), std::begin(mInstalledParts));
      mInstalledPhysics = rhs.mInstalledPhysics;
      std::copy(std::cbegin(rhs.mTunings), std::cend(rhs.mTunings), std::begin(mTunings));
      mActiveTuning = rhs.mActiveTuning;
      mPreset       = rhs.mPreset;
      mHandle       = rhs.mHandle;
    }

    explicit FECustomizationRecord() {
      reinterpret_cast<FECustomizationRecord*(__thiscall*)(FECustomizationRecord*)>(0x581C20)(this);
    }
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_FECUSTOMIZATIONRECORD_H
