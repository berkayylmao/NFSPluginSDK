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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_RIDEINFO_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_RIDEINFO_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/AutoSculpt.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DBCarPart.h>
#include <NFSPluginSDK/Game.ProStreet/Types/CarPaintPart.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DecalLayerPartInfo.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Physics.h>
#include <NFSPluginSDK/Game.ProStreet/Types/VinylLayerPartInfo.h>

namespace NFSPluginSDK::ProStreet {
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
    std::uint32_t             mCompositeSkinHash;
    std::uint32_t             mCompositeWheelHash[2];
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
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_RIDEINFO_H
