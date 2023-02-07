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

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DLCommandObject.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECarRecord.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Physics.h>
#include <NFSPluginSDK/Game.ProStreet/Types/RideInfo.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UserProfile.h>

namespace NFSPluginSDK::ProStreet::DALVehicleCommands {
  struct BlueprintInfo {
    char         name[64];
    bool         active;
    bool         used;
    bool         locked;
    std::uint8_t _padding[0x9];
  };

  struct CarInfo {
    std::uint32_t mCarNameHash;
    std::uint32_t mCarManuLogoHash;
    std::uint32_t mCarLogoHash;
    std::uint32_t mCarCost;
    DriveTrain    mDrivetrain;
    std::uint32_t mHandle;
    RaceMode      mMode;
    float         mDamage;

    explicit CarInfo() = default;
    explicit CarInfo(std::uint32_t carNameHash, std::uint32_t carManuLogoHash, std::uint32_t carLogoHash,
                     std::uint32_t carCost, DriveTrain drivetrain, std::uint32_t handle, RaceMode mode, float damage) :
        mCarNameHash(carNameHash),
        mCarManuLogoHash(carManuLogoHash),
        mCarLogoHash(carLogoHash),
        mCarCost(carCost),
        mDrivetrain(drivetrain),
        mHandle(handle),
        mMode(mode),
        mDamage(damage) {}
  };

  struct CreateCustomizableCar : DLCommandObject {
    std::uint32_t mNewCar;
    std::uint32_t mHandle;
    RaceMode      mRaceMode;

    virtual void Execute() override { reinterpret_cast<void(__thiscall*)(CreateCustomizableCar*)>(0x5633E0)(this); }

    explicit CreateCustomizableCar(std::uint32_t newCar, std::uint32_t handle, RaceMode raceMode) :
        mNewCar(newCar), mHandle(handle), mRaceMode(raceMode) {}
  };

  struct GetBlueprintInfo : DLCommandObject {
    eastl::vector<BlueprintInfo> mVector;
    std::uint32_t                mHandle;

    virtual ~GetBlueprintInfo() {
      reinterpret_cast<DLCommandObject*(__thiscall*)(GetBlueprintInfo*, bool freeMemory)>(0x560160)(this, false);
    }
    virtual void Execute() override { reinterpret_cast<void(__thiscall*)(GetBlueprintInfo*)>(0x56F480)(this); }
  };

  struct GetCustomizableCars : DLCommandObject {
    eastl::vector<DALVehicleCommands::CarInfo> mVector;
    RaceMode                                   mMode;
    FEPlayerCarDBFilterBits                    mFilter;

    virtual ~GetCustomizableCars() {
      // reinterpret_cast<DLCommandObject*(__thiscall*)(GetCustomizableCars*, bool freeMemory)>(0x560120)(this, false);
    }
    virtual void Execute() override {
      // reinterpret_cast<void(__thiscall*)(GetCustomizableCars*)>(0x56F1E0)(this);

      if (auto* profile = UserProfile::Get()) {
        for (const auto& car : profile->mCarStable.mCarTable) {
          if (car.MatchesFilter(FEPlayerCarDBFilterBits::FILTER_LIST_CUSTOMIZABLE) && car.MatchesFilter(mFilter)) {
            if (mMode != RaceMode::Invalid && car.GetMode() != mMode) continue;
            mVector.push_back(CarInfo(car.GetNameHash(), car.GetMenuLogoHash(), car.GetLogoHash(), car.GetCost(),
                                      car.GetDriveTrain(), car.Handle, car.GetMode(), 0.0f));
          }
        }
      }
    }

    explicit GetCustomizableCars(RaceMode                mode   = RaceMode::Invalid,
                                 FEPlayerCarDBFilterBits filter = FEPlayerCarDBFilterBits::FILTER_REGION_MASK |
                                                                  FEPlayerCarDBFilterBits::FILTER_LIST_MASK) :
        mMode(mode), mFilter(filter) {}
  };

  struct GetDownloadedBlueprints : DLCommandObject {
    std::uint32_t       mNumBlueprints;
    BlueprintShareable* mBlueprints;
  };

  // Named 'GetSliderStats' in the RTII.
  struct GetCarStats : DLCommandObject {
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

    // Deletes mRideInfos
    virtual ~GetCarStats() {
      reinterpret_cast<DLCommandObject*(__thiscall*)(GetCarStats*, bool freeMemory)>(0x55DE50)(this, false);
    }
    virtual void Execute() override { reinterpret_cast<void(__thiscall*)(GetCarStats*)>(0x575F30)(this); }
  };

  struct GetStockCars : DLCommandObject {
    eastl::vector<DALVehicleCommands::CarInfo> mVector;

    virtual ~GetStockCars() {
      // reinterpret_cast<DLCommandObject*(__thiscall*)(GetStockCars*, bool freeMemory)>(0x5B5960)(this, false);
    }
    virtual void Execute() override {
      // reinterpret_cast<void(__thiscall*)(GetStockCars*)>(0x56EB30)(this);

      if (auto* profile = UserProfile::Get()) {
        for (const auto& car : profile->mCarStable.mCarTable) {
          if (car.MatchesFilter(FEPlayerCarDBFilterBits::FILTER_LIST_STOCK |
                                FEPlayerCarDBFilterBits::FILTER_REGION_ALL)) {
            mVector.push_back(CarInfo(car.GetNameHash(), car.GetMenuLogoHash(), car.GetLogoHash(), car.GetCost(),
                                      car.GetDriveTrain(), car.Handle, car.GetMode(), 0.0f));
          }
        }
      }
    }
  };

  struct RemoveCustomizableCar : DLCommandObject {
    std::uint32_t mHandle;

    virtual void Execute() override { reinterpret_cast<void(__thiscall*)(RemoveCustomizableCar*)>(0x5636F0)(this); }
  };
}  // namespace NFSPluginSDK::ProStreet::DALVehicleCommands

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALVEHICLECOMMANDS_H
