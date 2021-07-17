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
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/IVehicleCache.h>

namespace OpenSpeed::MW05 {
  struct DebugVehicleSelection : IVehicleCache {
    unsigned char _pad1[0x10];
    std::int32_t  mSelectionIndex;
    unsigned char _pad2[0x4];
    const char**  mSelectionList;
    unsigned char _pad3[0x8];
    const char*   mCollisionObject;
    const char*   mCollisionSurface;

    virtual ~DebugVehicleSelection();

    void ChangePlayerVehicle(std::int32_t selectionIndex) {
      mSelectionIndex        = selectionIndex;
      *g_ChangePlayerVehicle = true;
    }

    static inline DebugVehicleSelection** g_mThis               = reinterpret_cast<DebugVehicleSelection**>(0x9B08F8);
    static inline bool*                   g_ChangePlayerVehicle = reinterpret_cast<bool*>(0x9B08FD);

    static DebugVehicleSelection* Get() {
      if (!g_mThis) return nullptr;
      return *g_mThis;
    }
  };
}  // namespace OpenSpeed::MW05
