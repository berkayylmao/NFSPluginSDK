// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <mail@berkay.link>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Core/EASTL/EASTL/vector.h>

#include <memory>  // unique_ptr
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DLCommandObject.h>

namespace OpenSpeed::ProStreet::DALVehicleCommands {
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
}  // namespace OpenSpeed::ProStreet::DALVehicleCommands
