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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARCUSTOMIZEMANAGER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARCUSTOMIZEMANAGER_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/stack.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/pvehicle.h>
#include <NFSPluginSDK/Game.ProStreet/Types/CurrentPartHelper.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECarRecord.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ISelectablePart.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Timer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/VinylCommand.h>

namespace NFSPluginSDK::ProStreet {
  struct CarCustomizeManager {
    CurrentPartHelper                                                mCurrentPartHelper;
    VinylCommandInvoker                                              mVinylInvoker;
    FECarRecord*                                                     TuningCar;
    BluePrintNumber                                                  mBluePrintNumber;
    Attrib::Gen::pvehicle                                            ThePVehicle;
    eastl::stack<ISelectablePart*, eastl::vector<ISelectablePart*> > mPreviewPartStack[4];
    Timer                                                            mPartLoadDelay;
    std::int32_t                                                     mCurrentEditingLayer;
    bool                                                             mDecal;

    static inline CarCustomizeManager* Get() { return reinterpret_cast<CarCustomizeManager*>(0xB32CE0); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARCUSTOMIZEMANAGER_H
