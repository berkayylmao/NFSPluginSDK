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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_VINYLSELECTABLEPART_H
#define OPENSPEED_GAME_PROSTREET_TYPES_VINYLSELECTABLEPART_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/ISelectablePart.h>
#include <OpenSpeed/Game.ProStreet/Types/VinylSystem.h>

namespace OpenSpeed::ProStreet {
  struct VinylSelectablePart : ISelectablePart {
    enum class TransformType : std::uint32_t { TranslateX, TranslateY, Rotate, ShearX, ShearY, ScaleX, ScaleY };

    std::int32_t                      mCurrentEditingLayer;
    DBCarPart                         mCurrentPart;
    VinylSystem::VinylTransformPacked mTransform;
    FECust::ColourPartData            mColorData[4];
    bool                              mIsMirrored;
    bool                              mIsEditingLayer;
    bool                              mIsEmptyFromDeletion;
    bool                              mIsDecal;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_VINYLSELECTABLEPART_H
