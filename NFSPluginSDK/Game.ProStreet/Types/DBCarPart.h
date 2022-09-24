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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DBCARPART_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DBCARPART_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Game.h>
#include <NFSPluginSDK/Game.ProStreet/Types/CarPartAttribute.h>

namespace NFSPluginSDK::ProStreet {
  struct DBCarPart {
    bool                mIsValid;
    std::uint8_t        mCarTypeNameHashIndex;
    std::uint16_t       mAttributeTableOffset;
    Attrib::Collection* mPartAttributes;
    std::uint16_t       mKitNum;
    std::uint16_t       mMaterialFlags;
    char                _pad;

    CarPartAttribute* GetAttribute() {
      return reinterpret_cast<CarPartAttribute*(__thiscall*)(DBCarPart*, std::uint32_t, std::uint32_t)>(0x754CD0)(
          this, Game::bStringHash("PARTID_UPGRADE_GROUP"), 0);
    }
    std::uint32_t GetCarTypeNameHash() {
      static MemoryFieldWrapper<std::uint32_t*> sCarPartTypeNameHashTable{0xAEB774, nullptr};
      return sCarPartTypeNameHashTable[mCarTypeNameHashIndex];
    }
    std::uint32_t GetGroupNumber() { return reinterpret_cast<std::int32_t(__thiscall*)(DBCarPart*)>(0x76AB50)(this); }
    std::uint32_t GetPartID() { return reinterpret_cast<std::int32_t(__thiscall*)(DBCarPart*)>(0x76AB20)(this); }
    std::uint32_t GetUpgradeLevel() {
      if (auto* attribute = GetAttribute()) return attribute->muParam >> 5;
      return 0;
    }

    DBCarPart() = default;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DBCARPART_H
