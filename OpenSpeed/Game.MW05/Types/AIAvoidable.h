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
#include <OpenSpeed/Core/EASTL/EASTL/list.h>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Grid.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct AIAvoidable {
    Grid<AIAvoidable>*        mGridNode;
    eastl::list<AIAvoidable*> mNeighbors;
    UTL::COM::IUnknown*       mUnk;

    virtual ~AIAvoidable();
    virtual bool OnUpdateAvoidable(UMath::Vector3& pos, float& sweep) = 0;

    inline const auto& GetAvoidableNeighbors() { return mNeighbors; }
    inline void        SetAvoidableObject(UTL::COM::IUnknown* obj) { mUnk = obj; }
  };
}  // namespace OpenSpeed::MW05
