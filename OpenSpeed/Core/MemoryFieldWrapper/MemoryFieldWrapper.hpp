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
#include <cstdint>      // integer types
#include <map>          // map
#include <memory>       // make_shared, shared_ptr
#include <stdexcept>    // out_of_range
#include <string>       // string
#include <type_traits>  // is_arithmetic, is_enum
#include <typeindex>    // type_index
#include <vector>       // vector
// MemoryEditor
#include <OpenSpeed/Core/MemoryEditor/MemoryEditor.hpp>

namespace details {
  template <typename T>
  using __MakeRef = T&;
  template <typename T>
  using __MakePtr = T*;
}  // namespace details

template <typename FieldType>
class MemoryFieldWrapper {
 private:
  details::__MakePtr<FieldType> const mFieldPtr;
  const FieldType                     mFieldDefVal;
  const FieldType                     mFieldMinVal;
  const FieldType                     mFieldMaxVal;

  MemoryFieldWrapper(const MemoryFieldWrapper&) = delete;
  MemoryFieldWrapper(MemoryFieldWrapper&&)      = delete;

 public:
  constexpr MemoryFieldWrapper(details::__MakePtr<FieldType> const volatile fieldPtr,
                               details::__MakeRef<const FieldType> fieldDefaultValue,
                               details::__MakeRef<const FieldType> fieldMinimumValue = FieldType(),
                               details::__MakeRef<const FieldType> fieldMaximumValue = FieldType()) :
      mFieldPtr(fieldPtr),
      mFieldDefVal(fieldDefaultValue),
      mFieldMinVal(fieldMinimumValue),
      mFieldMaxVal(fieldMaximumValue) {}
  constexpr MemoryFieldWrapper(std::uintptr_t fieldAddress, details::__MakeRef<const FieldType> fieldDefaultValue,
                               details::__MakeRef<const FieldType> fieldMinimumValue = FieldType(),
                               details::__MakeRef<const FieldType> fieldMaximumValue = FieldType()) :
      MemoryFieldWrapper(reinterpret_cast<details::__MakePtr<FieldType>>(fieldAddress), fieldDefaultValue,
                         fieldMinimumValue, fieldMaximumValue) {}

  details::__MakeRef<FieldType>       GetField() const { return *mFieldPtr; }
  details::__MakePtr<FieldType> const GetFieldPointer() const { return mFieldPtr; }
  details::__MakeRef<const FieldType> GetFieldDefaultValue() const { return mFieldDefVal; }
  details::__MakeRef<const FieldType> GetFieldMinimumValue() const { return mFieldMinVal; }
  details::__MakeRef<const FieldType> GetFieldMaximumValue() const { return mFieldMaxVal; }

#pragma region operators
  // Wrapped item casts
  inline operator details::__MakeRef<FieldType>() const {
    return *reinterpret_cast<details::__MakePtr<FieldType>>(mFieldPtr);
  }

  // Wrapped item assignments
  details::__MakeRef<FieldType> operator=(details::__MakeRef<const FieldType> _newVal) const {
    if constexpr (std::is_arithmetic_v<FieldType>())
      if constexpr (_newVal <= GetFieldMinimumValue() || _newVal >= GetFieldMaximumValue()) return *mFieldPtr;

    MemoryEditor::Get().UnlockMemory(reinterpret_cast<std::uintptr_t>(mFieldPtr), sizeof(FieldType));
    *mFieldPtr = _newVal;
    MemoryEditor::Get().LockMemory(reinterpret_cast<std::uintptr_t>(mFieldPtr));
    return *mFieldPtr;
  }

  // Wrapped item semantics
  inline details::__MakePtr<FieldType> operator&() const { return mFieldPtr; }
  inline details::__MakeRef<FieldType> operator->() const { return *mFieldPtr; }
#pragma endregion
};
