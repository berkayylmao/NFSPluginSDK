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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEMARKERMANAGER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEMARKERMANAGER_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EA.h>

namespace NFSPluginSDK::ProStreet {
  struct FEMarkerManager : EA::Memcard::IMemcardSavable {
    enum class BasketType : std::uint32_t { General, Win, Dominate, Cars };
    enum class ePossibleMarker : std::uint32_t {
      None,
      Body,
      Hood,
      Spoiler,
      Rims,
      RoofScoop,
      CustomHud,
      Vinyl,
      Decal,
      Paint,
      GetOutOfJail,
      PinkSlip,
      Cash,
      AddImpoundBox,
      ReduceHeat,
      FreeRepair,
      FreeTotalRepair,
      FreeCar,
      PerformancePart,
      ChallengeCar
    };

    void AddPlayerMarker(ePossibleMarker marker, std::uint32_t param1 = 0, std::uint32_t param2 = 0,
                         BasketType basketType = BasketType::General) {
      reinterpret_cast<void(__thiscall*)(FEMarkerManager*, ePossibleMarker, std::uint32_t, std::uint32_t, BasketType)>(
          0x570970)(this, marker, param1, param2, basketType);
    }

    static FEMarkerManager* Get() {
      static FEMarkerManager** fObj = reinterpret_cast<FEMarkerManager**>(0xAB0EC8);
      return *fObj;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEMARKERMANAGER_H
