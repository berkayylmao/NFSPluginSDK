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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEPLAYERCARDB_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEPLAYERCARDB_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECareerRecord.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECarPartRecord.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECarRecord.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECustomizationRecord.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEInfractionsData.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FELinkedPool.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEVinylRecord.h>

namespace NFSPluginSDK::ProStreet {
  struct FEPlayerCarDB {
    std::array<FECarRecord, 410>          mCarTable;
    std::array<FECustomizationRecord, 80> mCustomizations;
    std::array<FECareerRecord, 80>        mCareerRecords;
    unsigned char                         __pad[0x122C8];
    std::uint32_t                         mLastAwardedKingCarHistoryCarHandle;
    BluePrintType                         mLastAwardedKingCarHistoryCarMode;
    std::int8_t                           mInitializingCarStable;

    FECarRecord* GetCarRecordByHandle(std::uint32_t handle) {
      return reinterpret_cast<FECarRecord*(__thiscall*)(FEPlayerCarDB*, std::uint32_t)>(0x5332F0)(this, handle);
    }
    FECarRecord* GetCarByIndex(std::uint32_t idx) {
      return reinterpret_cast<FECarRecord*(__thiscall*)(FEPlayerCarDB*, std::uint32_t)>(0x5333B0)(this, idx);
    }
    FECarRecord* GetPresetCarRecord(std::uint32_t presetKey) {
      return reinterpret_cast<FECarRecord*(__thiscall*)(FEPlayerCarDB*, std::uint32_t)>(0x533370)(this, presetKey);
    }

    /*
     * __pad is undefined. The Wii debug build lists the following entries but they don't seem to line up correctly.
     *
     * FELinkedPool<FECarPartRecord, std::uint16_t, std::uint16_t, 9500> CarParts;
     * FELinkedPool<FEVinylRecord, std::uint16_t, std::uint16_t, 700>    Vinyls;
     * std::uint32_t                                                     SoldHistoryBounty;
     * std::uint16_t                                                     SoldHistoryNumEvadedPursuits;
     * std::uint16_t                                                     SoldHistoryNumBustedPursuits;
     * FEInfractionsData                                                 SoldHistoryUnservedInfractions;
     * FEInfractionsData                                                 SoldHistoryServedInfractions;
     */
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEPLAYERCARDB_H
