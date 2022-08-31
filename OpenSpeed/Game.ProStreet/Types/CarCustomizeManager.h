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
#include <OpenSpeed/Core/EASTL/EASTL/stack.h>
#include <OpenSpeed/Core/EASTL/EASTL/vector.h>

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Gen/pvehicle.h>
#include <OpenSpeed/Game.ProStreet/Types/CurrentPartHelper.h>
#include <OpenSpeed/Game.ProStreet/Types/FECarRecord.h>
#include <OpenSpeed/Game.ProStreet/Types/ISelectablePart.h>
#include <OpenSpeed/Game.ProStreet/Types/Timer.h>
#include <OpenSpeed/Game.ProStreet/Types/VinylCommand.h>

namespace OpenSpeed::ProStreet {
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
}  // namespace OpenSpeed::ProStreet
