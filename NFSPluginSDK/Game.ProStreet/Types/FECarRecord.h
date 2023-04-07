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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARRECORD_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARRECORD_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECustomizationRecord.h>

namespace NFSPluginSDK::ProStreet {
  struct FECarRecord {
    std::uint32_t           Handle;
    std::uint32_t           FEKey;
    std::uint32_t           VehicleKey;
    std::uint32_t           PresetKey;
    FEPlayerCarDBFilterBits FilterBits;
    std::uint8_t            Customization;
    std::uint8_t            CareerHandle;
    std::uint8_t            IsPresetSkin;
    std::uint8_t            Padd;

    bool IsUnlocked() const { return reinterpret_cast<bool(__thiscall*)(const FECarRecord*)>(0x548C00)(this); }
    bool MatchesFilter(FEPlayerCarDBFilterBits filter) const {
      return reinterpret_cast<bool(__thiscall*)(const FECarRecord*, FEPlayerCarDBFilterBits)>(0x533610)(this, filter);
    }

    std::uint32_t GetNameHash() const {
      return reinterpret_cast<std::uint32_t(__thiscall*)(const FECarRecord*)>(0x5611A0)(this);
    }
    std::uint32_t GetMenuLogoHash() const {
      return reinterpret_cast<std::uint32_t(__thiscall*)(const FECarRecord*)>(0x561270)(this);
    }
    std::uint32_t GetLogoHash() const {
      return reinterpret_cast<std::uint32_t(__thiscall*)(const FECarRecord*)>(0x558470)(this);
    }
    DALVehicleCommands::DriveTrain GetDriveTrain() const {
      return reinterpret_cast<DALVehicleCommands::DriveTrain(__thiscall*)(const FECarRecord*)>(0x548C40)(this);
    }
    std::uint32_t GetCost() const {
      return reinterpret_cast<std::uint32_t(__thiscall*)(const FECarRecord*)>(0x5485A0)(this);
    }
    BluePrintType GetMode() const {
      return reinterpret_cast<BluePrintType(__thiscall*)(const FECarRecord*)>(0x548D90)(this);
    }

    FECustomizationRecord* GetCustomizationRecord() const {
      return reinterpret_cast<FECustomizationRecord*(__thiscall*)(const FECarRecord*)>(0x533640)(this);
    }
    VehicleCustomizations* GetVCRecord(BluePrintNumber blueprintIdx) const {
      auto* fecr = GetCustomizationRecord();
      if (!fecr) return nullptr;

      return &fecr->mBluePrints[static_cast<std::size_t>(blueprintIdx)];
    }
    VehicleCustomizations* GetActiveVCRecord() const {
      auto* fecr = GetCustomizationRecord();
      if (!fecr) return nullptr;

      return &fecr->mBluePrints[static_cast<std::size_t>(fecr->mActiveBlueprint)];
    }

    void SetMode(BluePrintType mode) {
      reinterpret_cast<void(__thiscall*)(FECarRecord*, BluePrintType)>(0x5584A0)(this, mode);
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARRECORD_H
