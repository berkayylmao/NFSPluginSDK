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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARLOTSTATEMANAGER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARLOTSTATEMANAGER_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DALVehicleCommands.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEStateManager.h>

namespace NFSPluginSDK::ProStreet {
  struct FECarLotStateManager : FEStateManager<> {
    using eDriveTrainFilter = DALVehicleCommands::DriveTrain;
    enum class eFECarLotState : std::uint32_t {
      CARLOT_MAIN,
      CARLOT_MODE_DIALOG,
      CARLOT_MAXIMUM_CARS_DIALOG,
      CARLOT_NOT_ENOUGH_CASH_DIALOG,
      CARLOT_PURCHASE_DIALOG,
      CARLOT_PURCHASE_MS_POINTS_DIALOG,
      CARLOT_GARAGE,
      STATE_SHOWCASE
    };

    eastl::vector<DALVehicleCommands::CarInfo> mAWDCarList;
    eastl::vector<DALVehicleCommands::CarInfo> mRWDCarList;
    eastl::vector<DALVehicleCommands::CarInfo> mFWDCarList;
    eastl::vector<DALVehicleCommands::CarInfo> mAllCarList;
    eastl::vector<DALVehicleCommands::CarInfo> mCurrentCarList;
    eDriveTrainFilter                          mCurrentDriveTrain;
    std::int32_t                               mCurrentCarIndex;
    std::uint32_t                              mCurrentCarCost;
    std::int32_t                               mPlayerCash;
    bool                                       mUsedCash;
    bool                                       mCurrentCarIsLocked;
    FEObject*                                  mPrevModeButton;

    static FECarLotStateManager* Get() {
      static auto** spInstance = reinterpret_cast<FECarLotStateManager**>(0xB32B20);
      if (!spInstance) return nullptr;

      return *spInstance;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECARLOTSTATEMANAGER_H
