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
#include <Game.MW05/Types.h>

namespace OpenSpeed::MW05::UTL {
  template <typename T>
  struct GarbageNode {
    struct Collector {
      std::int8_t __unk[0x4];
    };

    union {
      bool      mDirty;
      Collector mCollector;
    };
  };

  namespace COM {
    struct Object {
      std::int8_t mInterfaces[0x18];
    };

    struct IUnknown {
      Object* _mCOMObject;

      virtual ~IUnknown();
    };
  }  // namespace COM
}  // namespace OpenSpeed::MW05::UTL
