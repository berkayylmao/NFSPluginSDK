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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_FEPLAYERCARDB_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_FEPLAYERCARDB_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/FECareerRecord.h>
#include <NFSPluginSDK/Game.MW05/Types/FECarRecord.h>
#include <NFSPluginSDK/Game.MW05/Types/FECustomizationRecord.h>
#include <NFSPluginSDK/Game.MW05/Types/FEInfractionsData.h>

namespace NFSPluginSDK::MW05 {
  struct FEPlayerCarDB {
    FECarRecord           CarTable[200];
    FECustomizationRecord Customizations[75];
    FECareerRecord        CareerRecords[25];
    std::uint32_t         SoldHistoryBounty;
    std::uint16_t         SoldHistoryNumEvadedPursuits;
    std::uint16_t         SoldHistoryNumBustedPursuits;
    FEInfractionsData     SoldHistoryUnservedInfractions;
    FEInfractionsData     SoldHistoryServedInfractions;

    inline void AwardBonusCars() { reinterpret_cast<void(__thiscall*)(FEPlayerCarDB*)>(0x56F0C0)(this); }
    inline void AwardRivalCar(Attrib::StringKey carKey) {
      reinterpret_cast<void(__thiscall*)(FEPlayerCarDB*, Attrib::StringKey)>(0x5A41E0)(this, carKey);
    }
    inline FECarRecord* GetCarByIndex(std::uint32_t index) {
      return reinterpret_cast<FECarRecord*(__thiscall*)(FEPlayerCarDB*, std::uint32_t)>(0x56ECF0)(this, index);
    }
    inline FECarRecord* GetCarRecordByHandle(std::uint32_t handle) {
      return reinterpret_cast<FECarRecord*(__thiscall*)(FEPlayerCarDB*, std::uint32_t)>(0x56ECC0)(this, handle);
    }
    inline FECareerRecord* GetCareerRecordByHandle(std::uint8_t handle) {
      return reinterpret_cast<FECareerRecord*(__thiscall*)(FEPlayerCarDB*, std::uint8_t)>(0x56F120)(this, handle);
    }
    inline FECustomizationRecord* GetCustomizationRecordByHandle(std::uint8_t handle) {
      return reinterpret_cast<FECustomizationRecord*(__thiscall*)(FEPlayerCarDB*, std::uint8_t)>(0x56F100)(this,
                                                                                                           handle);
    }
    inline std::size_t GetNumCars() {
      return reinterpret_cast<std::size_t(__thiscall*)(FEPlayerCarDB*)>(0x5812C0)(this);
    }
    inline std::size_t GetNumCareerCars() {
      return reinterpret_cast<std::size_t(__thiscall*)(FEPlayerCarDB*)>(0x5810E0)(this);
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_FEPLAYERCARDB_H
