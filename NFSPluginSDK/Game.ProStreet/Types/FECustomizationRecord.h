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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZATIONRECORD_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZATIONRECORD_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Physics.h>
#include <NFSPluginSDK/Game.ProStreet/Types/VehicleCustomizations.h>

namespace NFSPluginSDK::ProStreet {
  struct FEBlueprintStats {
    std::int32_t mNumRaces;
    std::int32_t mNumWins;
    std::int32_t mNumTotaled;
    float        mContent[4];
  };

  template <std::size_t n>
  struct FEBitField {
    char mBitChunks[n];
  };
  struct FEKitInfo {
    KitType       mInstalledType[3];
    std::uint32_t mInstalledKitNum[3];
    std::uint32_t mInventory[4];
  };
  struct FEPaintSV {
    std::int8_t mSaturation;
    std::int8_t mValue;
  };

  struct FECustomizationRecord {
    std::uint16_t         mFirstCarPartRecordIndex;
    std::uint16_t         mFirstVinylRecordIndex;
    VehicleCustomizations mBluePrints[3];
    FEKitInfo             mBodykitInfo;
    FEBlueprintStats      mBlueprintStats[3];
    Physics::Tunings      mTunings[3];
    eCustomTuningType     mActiveTuning;
    std::int32_t          mPreset;
    std::uint8_t          mHandle;
    std::int32_t          mType;
    FEPaintSV             mPaint[3][12];
    float                 mPerformanceDetuning[3];
    bool                  mFastVinyl;
    bool                  mBlueprintIsLocked[3];
    BluePrintNumber       mActiveBlueprint;
    bool                  mBlueprintUsed[3];
    eOnlineBlueprintType  mOnlineType[3];
    std::uint8_t          mBlueprintTier[3];

    VehicleCustomizations* GetActiveBluePrint() { return &mBluePrints[static_cast<std::size_t>(mActiveBlueprint)]; }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZATIONRECORD_H
