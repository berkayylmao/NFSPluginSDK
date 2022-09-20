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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEGARAGEMAIN_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEGARAGEMAIN_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FrontEndRenderingCar.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GarageCarLoader.h>
#include <NFSPluginSDK/Game.ProStreet/Types/MenuScreen.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IUnplugErrorAllowable.h>
#include <NFSPluginSDK/Game.ProStreet/Types/TrackPositionMarker.h>

namespace NFSPluginSDK::ProStreet {
  struct FEGarageMain : MenuScreen, IUnplugErrorAllowable {
    enum class eSafehouse : std::uint32_t {
      None,
      Muscle,
      Tuner,
      Exotic,
      CarLotMuscle,
      CarLotTuner,
      CarLotExotic,
      CarLotMazda,
      Main,
      Generic,
      CarClass
    };

    FrontEndRenderingCar* mRenderingCar;
    GarageCarLoader*      mGarageCarLoader;
    std::uint32_t         mCarHandle;
    SelectCarCameraMover* mpCameraMover;
    TrackPositionMarker*  mCarPosition;
    std::int32_t          mCarState;
    char                  mCarPosMarkerId;
    float                 mTimeToMoveCarPos;
    float                 mTimeToStartFEngEnter;
    bool                  mICECamPlaying;
    ActionQueue*          mActionQ[4];
    std::int32_t          HideEntireScreen;
    std::int32_t          ViewID;
    std::uint32_t         mScreenKey;
    std::uint32_t         mCameraKey;
    std::uint32_t         mScreenKeyCamIsSetTo;
    bool                  bUserRotate;
    bool                  bUserZoom;
    bool                  bUserHasRotatedThisScreen;
    float                 mOrbitV;
    float                 mOrbitH;
    float                 mZoom;
    float                 mCarRotateSpeed;
    bool                  mWheelMouseScrolled;
    bool                  mBlackPolyVisible;
    char                  mTrackPositionMarkerName[32];
    bool                  mAutosculptResetHack;

    void SetRideInfo(std::uint32_t carHandle, BluePrintNumber bp) {
      reinterpret_cast<void(__thiscall*)(FEGarageMain*, std::uint32_t, BluePrintNumber)>(0x7E6EF0)(this, carHandle, bp);
    }
    void SetRideInfo(RideInfo* rideInfo, FECustomizationRecord* fecr, BluePrintNumber bp) {
      reinterpret_cast<void(__thiscall*)(FEGarageMain*, RideInfo*, FECustomizationRecord*, BluePrintNumber)>(0x7E6DD0)(
          this, rideInfo, fecr, bp);
    }

    static inline FEGarageMain** spInstance = reinterpret_cast<FEGarageMain**>(0xB32AAC);
    static FEGarageMain*         Get() {
              if (!spInstance) return nullptr;
      return *spInstance;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEGARAGEMAIN_H
