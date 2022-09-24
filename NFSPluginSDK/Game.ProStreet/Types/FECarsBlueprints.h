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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARSBLUEPRINTS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARSBLUEPRINTS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DALVehicleCommands.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECustomizeStatsWidget.h>
#include <NFSPluginSDK/Game.ProStreet/Types/MenuScreen.h>

namespace NFSPluginSDK::ProStreet {
  struct FECarsBlueprintsOption {
    eFECarsBlueprintsOptionID OptionID;
    bool                      Enabled;
  };

  struct FECarsBlueprints : MenuScreen {
    std::int32_t                                mNumCarInfos;
    DALVehicleCommands::CarInfo*                mCarInfos;
    DALVehicleCommands::BlueprintInfo           mBPInfos[3];
    DALVehicleCommands::CarInfo                 mCarFilter;
    BluePrintType                               mMode;
    std::int32_t                                mSelectedCarIndex;
    std::int32_t                                mSelectedBPIndex;
    bool                                        mMenuVisible;
    std::int32_t                                mSelectedMenuIndex;
    std::int32_t                                mNumMenuItems;
    std::uint32_t                               mEmptyBlueprintLangHash;
    FECarsBlueprintsOption                      mMenuItems[5];
    FECustomizeStatsWidget                      mStatsWidget;
    DALVehicleCommands::GetDownloadedBlueprints mDownloadedBlueprints;
    DALVehicleCommands::CarInfo                 mDownloadedCarInfo;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARSBLUEPRINTS_H
