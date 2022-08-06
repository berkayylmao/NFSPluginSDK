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
#include <OpenSpeed/Game.ProStreet/Types/FEObject.h>
#include <OpenSpeed/Game.ProStreet/Types/FEWideString.h>

namespace OpenSpeed::ProStreet {
  struct FEString : FEObject {
    char*         pLabelName;
    std::uint32_t LabelHash;
    FEWideString  string;
    std::uint32_t Format;
    std::int32_t  Leading;
    std::uint32_t MaxWidth;
  };
}  // namespace OpenSpeed::ProStreet
