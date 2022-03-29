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
#include <OpenSpeed/Core/EASTL/EASTL/vector.h>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UTL/_ListSet.h>

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

  template <typename T, std::size_t nT, typename E, std::size_t nE>
  struct ListableSet {
    _ListSet<T, nT, E, nE> mSet;
  };

  namespace COM {
    struct Object {
      struct _IPair {
        struct _Finder {
          const IUnknown* ref;
        };

        void*     handle;
        IUnknown* ref;
      };
      struct _IList : eastl::vector<UTL::COM::Object::_IPair> {
        template <typename T>
        T* Find() {
          return reinterpret_cast<T*(__thiscall*)(_IList*, IHandle*)>(0x5D59F0)(this, T::GetIHandle());
        }
      };

      _IList _mInterfaces;
    };

    struct IUnknown {
      Object* _mCOMObject;

      virtual ~IUnknown();
    };
  }  // namespace COM
}  // namespace OpenSpeed::MW05::UTL
