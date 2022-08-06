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
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/bNode.h>
#include <OpenSpeed/Game.ProStreet/Types/RideInfo.h>

namespace OpenSpeed::ProStreet {
  struct FrontEndRenderingCar : bTNode<FrontEndRenderingCar> {
    RideInfo               mRideInfo;
    CarRenderInfo*         RenderInfo;
    std::int32_t           ViewID;
    float                  Height;
    /* +0x21F0 */ bVector3 Position;
    bMatrix4               BodyMatrix;
    bMatrix4               TireMatrices[4];
    bMatrix4               BrakeMatrices[4];
    /* +0x2440 */ eModel*  OverrideModel;
    std::int32_t           Visible;
    std::int32_t           nPasses;
    std::int32_t           Reflection;
    std::int32_t           LightsOn;
    std::int32_t           CopLightsOn;
  };
}  // namespace OpenSpeed::ProStreet
