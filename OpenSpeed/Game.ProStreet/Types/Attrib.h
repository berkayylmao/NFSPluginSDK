// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Class.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Collection.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Database.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Definition.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/HashMap.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Instance.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Private.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/RefSpec.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/RGBA.h>

namespace OpenSpeed::ProStreet::Attrib {
  static inline StringKey StringToKey(const char* name) {
    return reinterpret_cast<StringKey(__cdecl*)(const char*)>(0x52B8D0)(name);
  }
}  // namespace OpenSpeed::ProStreet::Attrib
