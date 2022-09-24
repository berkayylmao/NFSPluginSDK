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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALVEHICLECOMMANDS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALVEHICLECOMMANDS_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <memory>  // unique_ptr
#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DLCommandObject.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Physics.h>
#include <NFSPluginSDK/Game.ProStreet/Types/RideInfo.h>

namespace NFSPluginSDK::ProStreet::DALVehicleCommands {
  struct BlueprintInfo {
    char         name[64];
    bool         active;
    bool         used;
    bool         locked;
    std::uint8_t _padding[0x9];
  };

  struct CarInfo {
    std::uint32_t carNameHash;
    std::uint32_t carManuLogoHash;
    std::uint32_t carLogoHash;
    std::uint32_t carCost;
    DriveTrain    drivetrain;
    std::uint32_t handle;
    RaceMode      mode;
    float         damage;
  };

  struct CreateCustomizableCar : DLCommandObject {
    std::uint32_t mNewCar;
    std::uint32_t mHandle;
    RaceMode      mMode;

    virtual ~CreateCustomizableCar();
    virtual void Execute() override;

    static std::unique_ptr<CreateCustomizableCar> Construct(std::uint32_t newCar, std::uint32_t handle, RaceMode mode) {
      auto dummy   = std::make_unique<uint8_t[]>(sizeof(CreateCustomizableCar));
      auto ret     = std::unique_ptr<CreateCustomizableCar>{reinterpret_cast<CreateCustomizableCar*>(dummy.release())};
      ret->mState  = DLCommandObject::CommandState::WaitingToExecute;
      ret->mNewCar = newCar;
      ret->mHandle = handle;
      ret->mMode   = mode;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x96F4B0;
      return ret;
    }
  };

  struct GetBlueprintInfo : DLCommandObject {
    eastl::vector<BlueprintInfo> mVector;
    std::uint32_t                mHandle;

    virtual ~GetBlueprintInfo();
    virtual void Execute() override;

    static std::unique_ptr<GetBlueprintInfo> Construct() {
      auto dummy  = std::make_unique<uint8_t[]>(sizeof(GetBlueprintInfo));
      auto ret    = std::unique_ptr<GetBlueprintInfo>{reinterpret_cast<GetBlueprintInfo*>(dummy.release())};
      ret->mState = DLCommandObject::CommandState::WaitingToExecute;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x56F480;
      return ret;
    }
  };

  struct GetCustomizableCars : DLCommandObject {
    eastl::vector<DALVehicleCommands::CarInfo> mVector;
    RaceMode                                   mMode;
    FEPlayerCarDBFilterBits                    mFilter;

    virtual ~GetCustomizableCars();
    virtual void Execute() override;

    static std::unique_ptr<GetCustomizableCars> Construct(RaceMode mode, FEPlayerCarDBFilterBits filter) {
      auto dummy   = std::make_unique<uint8_t[]>(sizeof(GetCustomizableCars));
      auto ret     = std::unique_ptr<GetCustomizableCars>{reinterpret_cast<GetCustomizableCars*>(dummy.release())};
      ret->mState  = DLCommandObject::CommandState::WaitingToExecute;
      ret->mMode   = mode;
      ret->mFilter = filter;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x9708D8;
      return ret;
    }
  };

  struct GetDownloadedBlueprints : DLCommandObject {
    std::uint32_t       mNumBlueprints;
    BlueprintShareable* mBlueprints;

    virtual ~GetDownloadedBlueprints();
    virtual void Execute() override;
  };

  struct GetSliderStats : DLCommandObject {
    std::int32_t                        Levels[3];
    float                               Values[3];
    std::uint32_t                       Hashes[3];
    RideInfo*                           mRideInfo;
    bool                                mCreatedRideInfo;
    std::uint32_t                       mVehicleKey;
    BluePrintType                       mBluePrintType;
    Physics::Info::CorrectedPerformance mCorrectedPerformanceUntuned;
    Physics::Info::Performance          mEstimatedPerformanceUntuned;
    RaceMode                            mMode;

    virtual ~GetSliderStats();
    virtual void Execute() override;
  };

  struct GetStockCars : DLCommandObject {
    eastl::vector<DALVehicleCommands::CarInfo> mVector;

    virtual ~GetStockCars();
    virtual void Execute() override;

    static std::unique_ptr<GetStockCars> Construct() {
      auto dummy  = std::make_unique<uint8_t[]>(sizeof(GetStockCars));
      auto ret    = std::unique_ptr<GetStockCars>{reinterpret_cast<GetStockCars*>(dummy.release())};
      ret->mState = DLCommandObject::CommandState::WaitingToExecute;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x9A163C;
      return ret;
    }
  };

  struct RemoveCustomizableCar : DLCommandObject {
    std::uint32_t mHandle;

    virtual ~RemoveCustomizableCar();
    virtual void Execute() override;

    static std::unique_ptr<RemoveCustomizableCar> Construct() {
      auto dummy  = std::make_unique<uint8_t[]>(sizeof(RemoveCustomizableCar));
      auto ret    = std::unique_ptr<RemoveCustomizableCar>{reinterpret_cast<RemoveCustomizableCar*>(dummy.release())};
      ret->mState = DLCommandObject::CommandState::WaitingToExecute;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x99E870;
      return ret;
    }
  };
}  // namespace NFSPluginSDK::ProStreet::DALVehicleCommands

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALVEHICLECOMMANDS_H
