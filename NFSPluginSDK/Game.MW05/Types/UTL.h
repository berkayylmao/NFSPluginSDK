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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_UTL_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_UTL_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL/FixedVector.h>

namespace NFSPluginSDK::MW05::UTL {
  template <typename T, std::size_t nT>
  struct GarbageNode {
    struct Collector {
      struct _Node {
        T*           myptr;
        std::int32_t refcount;
      };
      UTL::FixedVector<GarbageNode<T, nT>::Collector::_Node, nT> _mDirty;
      UTL::FixedVector<GarbageNode<T, nT>::Collector::_Node, nT> _mClean;
      std::uint32_t                                              _mCount;
    };

    bool mDirty;
  };

  template <typename HandleType, typename T, std::size_t nMaxInstances>
  struct Instanceable {
    HandleType _mHandle;
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
}  // namespace NFSPluginSDK::MW05::UTL

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_UTL_H
