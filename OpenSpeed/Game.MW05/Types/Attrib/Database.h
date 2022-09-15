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

#ifndef OPENSPEED_GAME_MW05_TYPES_ATTRIB_DATABASE_H
#define OPENSPEED_GAME_MW05_TYPES_ATTRIB_DATABASE_H
#pragma once

#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05::Attrib {
  struct Database {
    DatabasePrivate& mPrivates;

    virtual ~Database();

    inline Class* GetClass(std::uint32_t key) {
      return reinterpret_cast<Class*(__thiscall*)(Database*, std::uint32_t)>(0x455BC0)(this, key);
    }

    static inline Database** g_mThis = reinterpret_cast<Database**>(0x90DCBC);
    static Database*         Get() {
              if (!g_mThis) return nullptr;
      return *g_mThis;
    }
  };
}  // namespace OpenSpeed::MW05::Attrib

#endif  // OPENSPEED_GAME_MW05_TYPES_ATTRIB_DATABASE_H
