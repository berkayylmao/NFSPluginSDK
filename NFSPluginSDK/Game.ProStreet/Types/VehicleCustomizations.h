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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_VEHICLECUSTOMIZATIONS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_VEHICLECUSTOMIZATIONS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/presetride.h>
#include <NFSPluginSDK/Game.ProStreet/Types/CarPaintPartRecordPacked.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DBCarPart.h>
#include <NFSPluginSDK/Game.ProStreet/Types/PackedDecalLayer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/PackedVinylLayer.h>

namespace NFSPluginSDK::ProStreet {
  struct VehicleCustomizations {
    std::int16_t mGUID[5];
    alignas(4) std::uint32_t mCreatorId;
    char                        mCreatorName[32];
    std::uint32_t               mShareNumber;
    std::int16_t                mInstalledParts[165];
    std::array<std::int8_t, 12> mCustomPaintsValid;
    alignas(4) std::array<CarPaintPartRecordPacked, 12> mCustomPaints;
    std::int8_t      mPartBaseMaterials[12];
    BluePrintType    mBluePrintType;
    KitType          mKitType;
    std::uint32_t    mKitNum;
    float            mRideHeight;
    PackedVinylLayer mVinylLayers[20];
    std::int32_t     mVinylMirrorBits;
    std::int32_t     mNumVinylLayers;
    PackedDecalLayer mDecalLayers[20];
    std::int32_t     mDecalMirrorBits;
    std::int32_t     mNumDecalLayers;
    std::int32_t     mLiveryID;
    std::int8_t      mMorphValues[41][11];
    float            mPhysicsTuning[32];
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

    void ReadFrom(const Attrib::Gen::presetride& preset) {
      reinterpret_cast<void(__thiscall*)(VehicleCustomizations*, const Attrib::Gen::presetride&)>(0x785EE0)(this,
                                                                                                            preset);
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_VEHICLECUSTOMIZATIONS_H
