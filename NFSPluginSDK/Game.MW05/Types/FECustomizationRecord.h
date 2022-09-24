// clang-format off
//
//    BSD 3-Clause License
//    Copyright (c) 2022, Berkay Yigit (berkayylmao) <mail@berkay.link>
//    All rights reserved.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    You should have received a copy of the BSD 3-Clause License along with
//    this program. If not, see <https://opensource.org/licenses/BSD-3-Clause/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_FECUSTOMIZATIONRECORD_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_FECUSTOMIZATIONRECORD_H
#pragma once

#include <algorithm>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Physics.h>

namespace NFSPluginSDK::MW05 {
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
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_FECUSTOMIZATIONRECORD_H
