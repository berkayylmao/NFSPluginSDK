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
#include <OpenSpeed/Core/MemoryEditor.hpp>

#include <OpenSpeed/Game.Carbon/Types.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/HashMap.h>

namespace OpenSpeed::Carbon::Attrib {
  struct Collection {
    HashMap       mTable;
    Collection*   mParent;
    Class*        mClass;
    void*         mLayout;
    std::uint32_t mRefCount;
    std::uint32_t mKey;
    Vault*        mSource;
    const char**  mNamePtr;

    template <typename T>
    inline T* GetData(StringKey fieldKey, std::int32_t idx = 0) {
      return reinterpret_cast<T*(__thiscall*)(Collection*, StringKey, std::int32_t)>(0x463480)(this, fieldKey, idx);
    }
    template <typename T>
    inline T* GetData(const char* fieldName, std::int32_t idx = 0) {
      return GetData<T>(StringToKey(fieldName), idx);
    }

    template <typename T>
    inline T* GetLayout() {
      return reinterpret_cast<T*>(mLayout);
    }

    template <typename T>
    inline bool TrySetData(StringKey fieldKey, T value, std::int32_t idx = 0) {
      auto* p = GetData<T>(fieldKey, idx);
      if (p) MemoryEditor::Get().GetRawMemory(p).SetValue(value);
      return p != nullptr;
    }
    template <typename T>
    inline bool TrySetData(const char* fieldName, T value, std::int32_t idx = 0) {
      return TrySetData(StringToKey(fieldName), value, idx);
    }
  };
}  // namespace OpenSpeed::Carbon::Attrib
