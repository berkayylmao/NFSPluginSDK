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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZEPARTLIST_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZEPARTLIST_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ArrayScrollerMenu.h>
#include <NFSPluginSDK/Game.ProStreet/Types/AutoSculpt.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DALVehicleCommands.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECustomizeCarStatsWidget.h>
#include <NFSPluginSDK/Game.ProStreet/Types/RideInfo.h>

namespace NFSPluginSDK::ProStreet {
  struct FECustomizePartList : ArrayScrollerMenu {
    /* FeGarageMain* */ std::uint32_t* mGarage;
    bool                               mIsAutosculpt;
    AutoSculpt::RegionID               mResetRegion;
    DALVehicleCommands::RaceMode       mMode;
    FECustomizeCarStatsWidget          mStatsWidget;
    DALVehicleCommands::GetCarStats*   mCarStatsBefore;
    RideInfo*                          mRideInfoBefore;

    static FECustomizePartList* Get() {
      static auto** spInstance = reinterpret_cast<FECustomizePartList**>(0xB32ADC);
      if (!spInstance) return nullptr;

      return *spInstance;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECUSTOMIZEPARTLIST_H
