// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <cstdint>  // integer types
#include <cstring>  // strstr

namespace OpenSpeed {
  enum class SpeedGame { NotSupported, U2, MW05, Carbon };
  struct SpeedGameInformation {
    const char* szWindowName;
    void*       pDirect3D9;
    void**      ppD3DDevice;

    SpeedGameInformation() : szWindowName(nullptr), pDirect3D9(nullptr), ppD3DDevice(nullptr) {}
    SpeedGameInformation(const char* szWindowName, void* pDirect3D9, void** ppD3DDevice)
        : szWindowName(szWindowName), pDirect3D9(pDirect3D9), ppD3DDevice(ppD3DDevice) {}
    SpeedGameInformation(std::uintptr_t szWindowName, std::uintptr_t pDirect3D9,
                         std::uintptr_t ppD3DDevice)
        : szWindowName(reinterpret_cast<const char*>(szWindowName)),
          pDirect3D9(reinterpret_cast<void*>(pDirect3D9)),
          ppD3DDevice(reinterpret_cast<void**>(ppD3DDevice)) {}
  };

  SpeedGame GetCurrentSpeedGame() {
    if (std::strstr(reinterpret_cast<const char*>(0x789694), "Need for Speed Undergound 2"))
      return SpeedGame::U2;
    if (std::strstr(reinterpret_cast<const char*>(0x8AF684), "Need For Speed Most Wanted"))
      return SpeedGame::MW05;
    if (std::strstr(reinterpret_cast<const char*>(0x9E9E94), "Need For Speed Carbon"))
      return SpeedGame::Carbon;

    return SpeedGame::NotSupported;
  }
  SpeedGameInformation GetInformationOfCurrentSpeedGame() {
    switch (GetCurrentSpeedGame()) {
      case SpeedGame::U2:
        return {0x0, 0x870970, 0x0};
      case SpeedGame::MW05:
        return {0x8B0050, 0x0, 0x982BDC};
      case SpeedGame::Carbon:
        return {0x9E3648, 0x0, 0xAB0ABC};
    }
    return {};
  }
}  // namespace OpenSpeed
