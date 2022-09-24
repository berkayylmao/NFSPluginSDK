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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_RIDEINFO_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_RIDEINFO_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05 {
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

    inline CarPart* GetPart(CarSlotId slotId) {
      return reinterpret_cast<CarPart*(__thiscall*)(RideInfo*, CarSlotId)>(0x739C70)(this, slotId);
    }

    inline void SetRandomPart(CarSlotId slotId, eCareerUpgradeLevels upgradeLevel) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarSlotId, eCareerUpgradeLevels)>(0x7596E0)(this, slotId,
                                                                                                upgradeLevel);
    }
    inline void SetUpgradePart(CarSlotId slotId, eCareerUpgradeLevels upgradeLevel) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarSlotId, eCareerUpgradeLevels)>(0x759470)(this, slotId,
                                                                                                upgradeLevel);
    }

    inline void SetRandomPaint() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x759800)(this); }
    inline void SetRandomParts() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x75B220)(this); }
    inline void SetStockParts() { reinterpret_cast<void(__thiscall*)(RideInfo*)>(0x7594A0)(this); }

    inline void Init(CarType type, CarRenderUsage renderUsage, std::int32_t _unk1 = 0, std::int32_t _unk2 = 0) {
      reinterpret_cast<void(__thiscall*)(RideInfo*, CarType, CarRenderUsage, std::int32_t, std::int32_t)>(0x739A70)(
          this, type, renderUsage, _unk1, _unk2);
    }

    explicit RideInfo(CarType type, CarRenderUsage renderUsage) { Init(type, renderUsage); }
    explicit RideInfo(CarType type) : RideInfo(type, CarRenderUsage::Player) {}
    explicit RideInfo() : RideInfo(CarType::NONE) {}
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_RIDEINFO_H
