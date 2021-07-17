// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/GIcon.h>

namespace OpenSpeed::MW05 {
  struct GManager {
    inline auto AllocIcon(GIcon::Type type, const Math::Vector3& initialPosition, const float unk1 = 0.0f,
                          const bool unk2 = true) {
      return reinterpret_cast<GIcon*(__thiscall*)(GManager*, GIcon::Type, const Math::Vector3&, float, bool)>(0x5E9EC0)(
          this, type, initialPosition, unk1, unk2);
    }
    inline void SpawnAllLoadedSectionIcons() { reinterpret_cast<void(__thiscall*)(GManager*)>(0x5EDE20)(this); }
    inline void UnspawnAllIcons() { reinterpret_cast<void(__thiscall*)(GManager*)>(0x5EA010)(this); }

    GManager()  = delete;
    ~GManager() = delete;
    static GManager* Get() { return *reinterpret_cast<GManager**>(0x91E00C); }
  };
}  // namespace OpenSpeed::MW05
