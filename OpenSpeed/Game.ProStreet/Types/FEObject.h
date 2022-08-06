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
#include <OpenSpeed/Game.ProStreet/Types/FEMinList.h>
#include <OpenSpeed/Game.ProStreet/Types/FERenderObject.h>
#include <OpenSpeed/Game.ProStreet/Types/FEScript.h>

namespace OpenSpeed::ProStreet {
  struct FEObject : FEMinNode {
    std::uint32_t   GUID;
    std::uint32_t   NameHash;
    char*           pName;
    FEObjType       Type;
    std::uint32_t   Flags;
    std::uint16_t   RenderContext;
    std::uint16_t   ResourceIndex;
    std::uint32_t   Handle;
    std::uint32_t   UserParam;
    char*           pData;
    std::uint32_t   DataSize;
    FEMinList       Responses;
    FEMinList       Scripts;
    FEScript*       pCurrentScript;
    FERenderObject* Cached;
  };
}  // namespace OpenSpeed::ProStreet
