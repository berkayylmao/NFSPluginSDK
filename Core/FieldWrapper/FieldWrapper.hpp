// clang-format off
//
//    FieldWrapper: A header-only library to make fields/structs reflectable.
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
#include <cstdint>    // integer types
#include <map>        // map
#include <memory>     // make_shared, shared_ptr
#include <stdexcept>  // out_of_range
#include <string>     // string
#include <typeindex>  // type_index
#include <vector>     // vector

#if (defined(FIELDWRAPPER_DEFINE_MEMORYFIELDWRAPPER))
#if (FIELDWRAPPER_DEFINE_MEMORYFIELDWRAPPER > 0)
#define DEFINE_MEMORYFIELDWRAPPER
#include <Core/MemoryEditor/MemoryEditor.hpp>
#endif
#endif

namespace details {
  template <typename T>
  using __MakeRef = T&;
  template <typename T>
  using __MakePtr = T*;
}  // namespace details

class IFieldWrapper {
 protected:
  std::string     _fieldName;
  std::type_index _fieldTypeIndex;
  void*           _fieldPointer;
  void*           _fieldMinimumValue;
  void*           _fieldMaximumValue;

 public:
  IFieldWrapper(const char* szFieldName, std::type_index typeIndex, void* pField)
      : _fieldName(szFieldName),
        _fieldTypeIndex(typeIndex),
        _fieldPointer(pField),
        _fieldMinimumValue(nullptr),
        _fieldMaximumValue(nullptr) {}
  IFieldWrapper(const char* szFieldName, std::type_info& typeInfo, void* pField)
      : IFieldWrapper(szFieldName, std::type_index(typeInfo), pField) {}

  IFieldWrapper(const std::string& fieldName, std::type_index typeIndex, void* pField)
      : IFieldWrapper(fieldName.c_str(), typeIndex, pField) {}
  IFieldWrapper(const std::string& fieldName, std::type_index& typeIndex, void* pField)
      : IFieldWrapper(fieldName.c_str(), typeIndex, pField) {}
  IFieldWrapper(const std::string& fieldName, std::type_info& typeInfo, void* pField)
      : IFieldWrapper(fieldName.c_str(), typeInfo, pField) {}

  ~IFieldWrapper() = default;

  // Not array
  virtual const char* const      GetFieldName() const { return _fieldName.c_str(); }
  virtual const std::string&     GetFieldNameAsString() const { return _fieldName; }
  virtual const std::type_index& GetFieldTypeIndex() const { return _fieldTypeIndex; };
  virtual void* const            GetPointerToField() const { return _fieldPointer; }
  template <typename T>
  T* const GetTypedPointerToField() const {
    return static_cast<T*>(_fieldPointer);
  }
  virtual void* const GetFieldMinimumValue() const { return _fieldMinimumValue; }
  virtual void* const GetFieldMaximumValue() const { return _fieldMaximumValue; }

  // 1D array
  virtual const bool                                        Is1DArray() const { return false; }
  virtual const std::vector<std::shared_ptr<IFieldWrapper>> Get1DArrayItems() const { return {}; }
};

template <typename FieldType>
struct FieldWrapper : public IFieldWrapper {
  constexpr FieldWrapper(const char* szFieldName, FieldType* pField)
      : IFieldWrapper constexpr(szFieldName, typeid(FieldType), pField) {}
  constexpr FieldWrapper(const std::string& fieldName, FieldType* pField)
      : FieldWrapper constexpr(fieldName.c_str(), pField) {}

  constexpr FieldWrapper(const FieldWrapper&) = delete;
  ~FieldWrapper()                             = default;

#pragma region operators
  // Wrapped item casts
  constexpr operator details::__MakeRef<FieldType>() const {
    return *reinterpret_cast<FieldType*>(_fieldPointer);
  }

  // Wrapped item assignments
  constexpr details::__MakeRef<FieldType> operator=(
      const details::__MakeRef<FieldType> _newVal) const {
    return *reinterpret_cast<FieldType*>(_fieldPointer) = _newVal;
  }
  constexpr details::__MakeRef<FieldType> operator=(const FieldType _newVal) const {
    return *this = _newVal;
  }

  // Wrapped item semantics
  constexpr details::__MakePtr<FieldType> operator&() const {
    return reinterpret_cast<FieldType*>(_fieldPointer);
  }
  constexpr details::__MakeRef<FieldType> operator->() const {
    return *reinterpret_cast<FieldType*>(_fieldPointer);
  }
#pragma endregion
};

template <typename ArrayItemType, size_t ArrayItemCount>
struct ArrayFieldWrapper : public IFieldWrapper {
  ArrayFieldWrapper(const char*                                       szFieldName,
                    details::__MakePtr<ArrayItemType[ArrayItemCount]> pField)
      : IFieldWrapper(szFieldName, typeid(ArrayItemType[ArrayItemCount]), pField) {}
  ArrayFieldWrapper(const std::string&                                fieldName,
                    details::__MakePtr<ArrayItemType[ArrayItemCount]> pField)
      : ArrayFieldWrapper(fieldName.c_str(), pField) {}

  ArrayFieldWrapper(const ArrayFieldWrapper&) = delete;
  ~ArrayFieldWrapper()                        = default;

#pragma region operators
  // Wrapped item casts
  operator details::__MakeRef<ArrayItemType[ArrayItemCount]>() {
    return *reinterpret_cast<details::__MakePtr<ArrayItemType[ArrayItemCount]>>(_fieldPointer);
  }

  // Wrapped item assignments
  details::__MakeRef<ArrayItemType[ArrayItemCount]> operator=(
      details::__MakeRef<ArrayItemType[ArrayItemCount]> newVal) {
    return *this = newVal;
  }
  details::__MakeRef<ArrayItemType[ArrayItemCount]> operator=(
      details::__MakePtr<ArrayItemType> newVal) {
    memcpy_s(_fieldPointer, sizeof(ArrayItemType) * ArrayItemCount, newVal,
             sizeof(ArrayItemType) * ArrayItemCount);
    return *this;
  }
  details::__MakeRef<ArrayItemType[ArrayItemCount]> operator=(
      const details::__MakePtr<const ArrayItemType> newVal) {
    return *this = const_cast<details::__MakePtr<ArrayItemType>>(newVal);
  }

  // Wrapped item semantics
  details::__MakePtr<ArrayItemType[ArrayItemCount]> operator&() {
    return reinterpret_cast<details::__MakePtr<ArrayItemType[ArrayItemCount]>>(_fieldPointer);
  }
  details::__MakeRef<ArrayItemType[ArrayItemCount]> operator->() {
    return *reinterpret_cast<details::__MakePtr<ArrayItemType[ArrayItemCount]>>(_fieldPointer);
  }
  details::__MakeRef<ArrayItemType> operator[](size_t index) {
    return (
        *reinterpret_cast<details::__MakePtr<ArrayItemType[ArrayItemCount]>>(_fieldPointer))[index];
  }
#pragma endregion

  virtual const bool Is1DArray() const override { return true; }
  virtual const std::vector<std::shared_ptr<IFieldWrapper>> Get1DArrayItems() const override {
    std::vector<std::shared_ptr<IFieldWrapper>> vRet;

    size_t itemSize  = sizeof(ArrayItemType);
    size_t arraySize = itemSize * ArrayItemCount;
    size_t itemCount = arraySize / itemSize;

    for (size_t i = 0; i < itemCount; i++) {
      const std::string subFieldName = _fieldName + "[" + std::to_string(i) + "]";
      vRet.push_back(std::make_shared<FieldWrapper<ArrayItemType>>(
          subFieldName.c_str(),
          &(*reinterpret_cast<details::__MakePtr<ArrayItemType[ArrayItemCount]>>(
              _fieldPointer))[i]));
    }
    return vRet;
  }
};

#if defined(DEFINE_MEMORYFIELDWRAPPER)
template <typename FieldType>
class MemoryFieldWrapper {
 private:
  std::string                   _fieldName;
  details::__MakePtr<FieldType> _fieldPointer;
  std::uintptr_t                _fieldRawAddress;
  FieldType                     _fieldDefVal, _fieldMinVal, _fieldMaxVal;

 public:
  constexpr MemoryFieldWrapper(const char* szFieldName, details::__MakePtr<FieldType> pField,
                               FieldType fieldDefaultValue, FieldType fieldMinimumValue,
                               FieldType fieldMaximumValue)
      : _fieldName(szFieldName),
        _fieldPointer(pField),
        _fieldRawAddress(reinterpret_cast<std::uintptr_t>(pField)),
        _fieldDefVal(fieldDefaultValue),
        _fieldMinVal(fieldMinimumValue),
        _fieldMaxVal(fieldMaximumValue) {}
  constexpr MemoryFieldWrapper(const char* szFieldName, void* pField, FieldType fieldDefaultValue,
                               FieldType fieldMinimumValue, FieldType fieldMaximumValue)
      : MemoryFieldWrapper(szFieldName, reinterpret_cast<details::__MakePtr<FieldType>>(pField),
                           fieldDefaultValue, fieldMinimumValue, fieldMaximumValue) {}
  constexpr MemoryFieldWrapper(const char* szFieldName, std::uintptr_t fieldAddress,
                               FieldType fieldDefaultValue,
                               FieldType fieldMinimumValue = FieldType(),
                               FieldType fieldMaximumValue = FieldType())
      : MemoryFieldWrapper(szFieldName,
                           reinterpret_cast<details::__MakePtr<FieldType>>(fieldAddress),
                           fieldDefaultValue, fieldMinimumValue, fieldMaximumValue) {}
  ~MemoryFieldWrapper() = default;

  virtual const std::string&            GetFieldName() const { return _fieldName; }
  virtual const char* const             GetFieldNameAsCString() const { return _fieldName.c_str(); }
  virtual details::__MakeRef<FieldType> GetField() const { return *_fieldPointer; }
  virtual details::__MakePtr<FieldType> const GetFieldPointer() const { return _fieldPointer; }
  virtual details::__MakeRef<const FieldType> GetFieldDefaultValue() const { return _fieldDefVal; }
  virtual details::__MakeRef<const FieldType> GetFieldMinimumValue() const { return _fieldMinVal; }
  virtual details::__MakeRef<const FieldType> GetFieldMaximumValue() const { return _fieldMaxVal; }

#pragma region operators
  // Wrapped item casts
  operator details::__MakeRef<FieldType>() const {
    return *reinterpret_cast<details::__MakePtr<FieldType>>(_fieldPointer);
  }

  // Wrapped item assignments
  details::__MakeRef<FieldType> operator=(const FieldType _newVal) const {
    if constexpr (typeid(FieldType) != typeid(bool)) {
      if (_newVal < GetFieldMinimumValue() || _newVal > GetFieldMaximumValue())
        return *_fieldPointer;
    }

    MemoryEditor::Get().UnlockMemory(_fieldRawAddress, sizeof(FieldType));
    *_fieldPointer = _newVal;
    MemoryEditor::Get().LockMemory(_fieldRawAddress);
    return *_fieldPointer;
  }

  // Wrapped item semantics
  constexpr details::__MakePtr<FieldType> operator&() const { return _fieldPointer; }
  details::__MakeRef<FieldType>           operator->() const { return *_fieldPointer; }
#pragma endregion
};
#endif

namespace details {
  static inline std::map<uintptr_t, std::shared_ptr<IFieldWrapper>> _mWrappedFields;
}  // namespace details

template <size_t LayoutSizeInBytes>
struct LayoutWrapper {
  const std::vector<std::shared_ptr<IFieldWrapper>> GetWrappedFields() {
    std::vector<std::shared_ptr<IFieldWrapper>> vRet;

    uintptr_t addrStart = reinterpret_cast<uintptr_t>(this);
    uintptr_t addrEnd   = addrStart + static_cast<uintptr_t>(LayoutSizeInBytes);

    for (uintptr_t i = addrStart; i < addrEnd; i++) {
      auto wrappedField = details::_mWrappedFields.find(i);
      if (wrappedField != std::end(details::_mWrappedFields)) {
        vRet.push_back(wrappedField->second);
      }
    }
    return vRet;
  }

  void operator()() {}
};

struct FieldWrapperManager {
  FieldWrapperManager()                           = delete;
  FieldWrapperManager(const FieldWrapperManager&) = delete;
  ~FieldWrapperManager()                          = delete;

  // Not array
  template <typename FieldType>
  static std::shared_ptr<IFieldWrapper> WrapField(const char*      szFieldName,
                                                  FieldType* const pField) {
    return details::_mWrappedFields[reinterpret_cast<uintptr_t>(pField)] =
               std::make_shared<FieldWrapper<FieldType>>(szFieldName, pField);
  }
  template <typename FieldType>
  static std::shared_ptr<IFieldWrapper> WrapField(const std::string& fieldName,
                                                  FieldType* const   pField) {
    return details::_mWrappedFields[reinterpret_cast<uintptr_t>(pField)] =
               std::make_shared<FieldWrapper<FieldType>>(fieldName, pField);
  }

  // 1D array
  template <typename ArrayItemType, size_t ArrayItemCount>
  static std::shared_ptr<IFieldWrapper> WrapField(
      const char* szFieldName, details::__MakePtr<ArrayItemType[ArrayItemCount]> const pField) {
    return details::_mWrappedFields[reinterpret_cast<uintptr_t>(pField)] =
               std::make_shared<ArrayFieldWrapper<ArrayItemType, ArrayItemCount>>(szFieldName,
                                                                                  pField);
  }
  template <typename ArrayItemType, size_t ArrayItemCount>
  static std::shared_ptr<IFieldWrapper> WrapField(
      const std::string&                                      fieldName,
      details::__MakePtr<ArrayItemType[ArrayItemCount]> const pField) {
    return details::_mWrappedFields[reinterpret_cast<uintptr_t>(pField)] =
               std::make_shared<ArrayFieldWrapper<ArrayItemType, ArrayItemCount>>(fieldName,
                                                                                  pField);
  }

  static std::shared_ptr<IFieldWrapper> AddWrappedField(const IFieldWrapper& Field) {
    return details::_mWrappedFields[reinterpret_cast<uintptr_t>(Field.GetPointerToField())] =
               std::make_shared<IFieldWrapper>(Field);
  }
  static std::shared_ptr<IFieldWrapper> GetWrappedFieldAt(const uintptr_t& MemoryAddress) {
    try {
      auto wrappedField = details::_mWrappedFields.at(MemoryAddress);
      return wrappedField;
    } catch (const std::out_of_range&) {
      return nullptr;
    }
  }
};

template <typename FieldType>
class WrapField {
  FieldType _var;

 public:
  WrapField(const char* szFieldName) {
    FieldWrapperManager::WrapField<FieldType>(szFieldName, &_var);
  }
  WrapField(const std::string& fieldName) {
    FieldWrapperManager::WrapField<FieldType>(fieldName.c_str(), &_var);
  }

  const size_t          GetSize() const { return sizeof(FieldType); }
  const std::type_info& GetTypeId() const { return typeid(_var); }

  explicit operator details::__MakeRef<FieldType>() { return _var; }

  details::__MakeRef<FieldType> operator=(const details::__MakeRef<FieldType> _newVal) {
    return _var = _newVal;
  }

  details::__MakePtr<FieldType> operator&() { return &_var; }
  details::__MakeRef<FieldType> operator->() { return _var; }
};

template <typename ArrayItemType, size_t ArrayItemCount>
class WrapArrayField {
  ArrayItemType _var[ArrayItemCount];

 public:
  WrapArrayField(const char* szFieldName) {
    FieldWrapperManager::WrapField<ArrayItemType, ArrayItemCount>(szFieldName, &_var);
  }
  WrapArrayField(const std::string& fieldName) {
    FieldWrapperManager::WrapField<ArrayItemType, ArrayItemCount>(fieldName.c_str(), &_var);
  }

  const size_t          GetArrayItemSize() const { return sizeof(ArrayItemType); }
  const size_t          GetArrayItemCount() const { return ArrayItemCount; }
  const std::type_info& GetArrayItemTypeId() const { return typeid(ArrayItemType); }
  const size_t          GetArraySize() const { return GetArrayItemCount() * GetArrayItemSize(); }
  const std::type_info& GetArrayTypeId() const { return typeid(_var); }
  const std::type_index GetArrayTypeIndex() const { return std::type_index(GetArrayTypeId()); }

  explicit operator details::__MakeRef<ArrayItemType[ArrayItemCount]>() { return _var; }

  details::__MakeRef<ArrayItemType[ArrayItemCount]> operator=(
      details::__MakeRef<ArrayItemType[ArrayItemCount]> newVal) {
    return _var = newVal;
  }
  details::__MakeRef<ArrayItemType[ArrayItemCount]> operator=(
      details::__MakePtr<ArrayItemType> newVal) {
    memcpy_s(_var, GetArraySize(), newVal, GetArraySize());
    return _var;
  }
  details::__MakeRef<ArrayItemType[ArrayItemCount]> operator=(
      const details::__MakePtr<const ArrayItemType> newVal) {
    return *this = const_cast<details::__MakePtr<ArrayItemType>>(newVal);
  }

  details::__MakePtr<ArrayItemType[ArrayItemCount]> operator&() { return &_var; }
  details::__MakeRef<ArrayItemType[ArrayItemCount]> operator->() { return _var; }
  details::__MakeRef<ArrayItemType>                 operator[](size_t index) { return _var[index]; }
};
