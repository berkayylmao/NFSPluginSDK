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

#ifndef NFSPLUGINSDK_H
#define NFSPLUGINSDK_H
#pragma once

#include <cstdint>  // integer types
#include <cstring>  // strstr

namespace NFSPluginSDK {
  enum class Game { NotSupported, U2, MW05, Carbon, ProStreet };
  struct GameInformation {
    /// <summary>
    /// Game type.
    /// </summary>
    Game mGame;
    /// <summary>
    /// Pointer to game's window name, const.
    /// </summary>
    const char* mSzWindowName;
    /// <summary>
    /// Pointer to game's window handle.
    /// </summary>
    void** mPHwnd;
    /// <summary>
    /// Pointer to game's Direct3D device.
    /// <para><em>NOTE: For ProStreet, this is a pointer to the pointer of the device.</em></para>
    /// </summary>
    void** mPD3DDevice;
    /// <summary>
    /// Pointer to game's DirectInput8 device.
    /// </summary>
    void** mPDI8Device;

    GameInformation() :
        mGame(Game::NotSupported),
        mSzWindowName(nullptr),
        mPHwnd(nullptr),
        mPD3DDevice(nullptr),
        mPDI8Device(nullptr) {}
    GameInformation(Game game, const char* szWindowName, void** hWnd, void** pD3DDevice, void** pDI8Device) :
        mGame(game), mSzWindowName(szWindowName), mPHwnd(hWnd), mPD3DDevice(pD3DDevice), mPDI8Device(pDI8Device) {}
    GameInformation(Game game, std::uintptr_t szWindowName, std::uintptr_t addrHWND, std::uintptr_t addrPD3DDevice,
                    std::uintptr_t addrPDI8Device) :
        mGame(game),
        mSzWindowName(reinterpret_cast<const char*>(szWindowName)),
        mPHwnd(reinterpret_cast<void**>(addrHWND)),
        mPD3DDevice(reinterpret_cast<void**>(addrPD3DDevice)),
        mPDI8Device(reinterpret_cast<void**>(addrPDI8Device)) {}
  };

  static inline Game GetCurrentGame() {
    if (std::strstr(reinterpret_cast<const char*>(0x789694), "Need for Speed Underground 2")) return Game::U2;
    if (std::strstr(reinterpret_cast<const char*>(0x8AF684), "Need For Speed Most Wanted")) return Game::MW05;
    if (std::strstr(reinterpret_cast<const char*>(0x9E9E94), "Need For Speed Carbon")) return Game::Carbon;
    if (std::strstr(reinterpret_cast<const char*>(0x98E9A0), "ProStreetGame")) return Game::ProStreet;

    return Game::NotSupported;
  }
  static inline GameInformation GetInformationOfCurrentGame() {
    switch (GetCurrentGame()) {
      case Game::U2:
        return GameInformation(Game::U2, 0x78E8F4, 0x870990, 0, 0);
      case Game::MW05:
        return GameInformation(Game::MW05, 0x8B0050, 0x982BF4, 0x982BDC, 0x982D14);
      case Game::Carbon:
        return GameInformation(Game::Carbon, 0x9E3648, 0xAB0AD8, 0xAB0ABC, 0xB1F5CC);
      case Game::ProStreet:
        return GameInformation(Game::ProStreet, 0x98D84C, 0xAC6ED8, 0xAC6ED4, 0xACDCAC);
    }
    return GameInformation();
  }
}  // namespace NFSPluginSDK

#endif  // NFSPLUGINSDK_H
