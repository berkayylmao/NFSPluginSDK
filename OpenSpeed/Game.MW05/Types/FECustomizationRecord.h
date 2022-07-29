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

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Physics.h>

namespace OpenSpeed::MW05 {
  struct FECustomizationRecord {
    std::int16_t               mInstalledPartIndices[139];
    Physics::Upgrades::Package mInstalledPhysics;
    Physics::Tunings           mTunings[3];
    eCustomTuningType          mActiveTuning;
    std::int32_t               mPreset;
    std::uint8_t               mHandle;

    inline void WriteRideIntoRecord(const RideInfo* rideInfo) {
      reinterpret_cast<void(__thiscall*)(FECustomizationRecord*, const RideInfo*)>(0x56F2F0)(this, rideInfo);
    }

    void operator=(const FECustomizationRecord& rhs) {
      std::copy(std::cbegin(rhs.mInstalledPartIndices), std::cend(rhs.mInstalledPartIndices),
                std::begin(this->mInstalledPartIndices));
      this->mInstalledPhysics = rhs.mInstalledPhysics;
      std::copy(std::cbegin(rhs.mTunings), std::cend(rhs.mTunings), std::begin(this->mTunings));
      this->mActiveTuning = rhs.mActiveTuning;
      this->mPreset       = rhs.mPreset;
      this->mHandle       = rhs.mHandle;
    }

    std::int16_t& operator[](CarSlotId id) noexcept { return mInstalledPartIndices[static_cast<std::uint32_t>(id)]; }
    const std::int16_t& operator[](CarSlotId id) const noexcept {
      return mInstalledPartIndices[static_cast<std::uint32_t>(id)];
    }

    explicit FECustomizationRecord() {
      reinterpret_cast<FECustomizationRecord*(__thiscall*)(FECustomizationRecord*)>(0x581C20)(this);
    }
  };
}  // namespace OpenSpeed::MW05
