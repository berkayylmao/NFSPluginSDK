// clang-format off
//
//    MemoryEditor: A header-only cross-platform library to edit runtime memory. (C++11)
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
#include <array>          // array
#include <cstdint>        // integer types
#include <mutex>          // mutex, scoped_lock
#include <unordered_map>  // unordered_map
#include <type_traits>    // enable_if, is_arithmetic

#if defined(__linux__) || defined(_LINUX)
#include <sys/mman.h>  // mprotect()
#elif defined(_WIN32)
#include <intrin.h>     // __readfsdword()
#include <memoryapi.h>  // VirtualProtect()
#include <winternl.h>   // PEB
#else
#error This operating system is not supported.
#endif

namespace MemoryEditor {
  enum class MakeType : std::uint8_t { Call, Jump, Detour, NOP, Return, DebuggerTrap };

  class Editor {
    struct MemoryAccessInfo {
#if defined(_WIN32)
      DWORD oldMemoryAccess = NULL;
#endif
      std::uintmax_t size = NULL;

      constexpr MemoryAccessInfo() = default;
      constexpr MemoryAccessInfo(std::uintmax_t infoSize) : size(infoSize) {}
    };

    std::size_t                                                  _baseAddress;
    mutable std::mutex                                           _mutex;
    mutable std::unordered_map<std::uintptr_t, MemoryAccessInfo> _mapAccessInfo;

    inline std::uint32_t CalcDistance(const std::uintptr_t from, const std::uintptr_t to) const {
      return to - from - sizeof(std::uint32_t) - 1;
    }

   public:
    inline std::uintptr_t AbsRVA(const std::uintptr_t rva) const { return _baseAddress + rva; }

    void LockMemory(const std::uintptr_t address) const {
      // Old memory access page is stored only in Windows.
#ifdef _WIN32
      std::scoped_lock _lock(_mutex);

      MemoryAccessInfo& info = _mapAccessInfo[address];
      VirtualProtect(reinterpret_cast<LPVOID>(address), info.size, info.oldMemoryAccess,
                     &info.oldMemoryAccess);
#endif
      _mapAccessInfo.erase(address);
    }
    void UnlockMemory(const std::uintptr_t address, const std::size_t size) const {
      std::scoped_lock _lock(_mutex);

      MemoryAccessInfo info(size);

#if defined(__linux__) || defined(_LINUX)
      mprotect(reinterpret_cast<void*>(address), size, PROT_READ | PROT_WRITE | PROT_EXEC);
#elif defined(_WIN32)
      VirtualProtect(reinterpret_cast<LPVOID>(address), size, PAGE_EXECUTE_READWRITE,
                     &info.oldMemoryAccess);
#endif
      _mapAccessInfo[address] = info;
    }

    template <typename PointedType, typename... Offsets>
    std::enable_if_t<std::is_same<Offsets..., std::int32_t>::value, PointedType*> ReadPointer(
        const std::uintptr_t base, Offsets&&... offsets) const {
      PointedType* ret = nullptr;
      UnlockMemory(base, sizeof(std::uintptr_t));
      if (!base || !*reinterpret_cast<PointedType*>(base)) {
        LockMemory(base);
        return ret;
      }

      std::uintptr_t _base =
          reinterpret_cast<std::uintptr_t>(*reinterpret_cast<PointedType*>(base));
      LockMemory(base);

      constexpr std::array<std::int32_t, sizeof...(Offsets)> arrOffsets{Offsets...};
      for (const auto& off : arrOffsets) {
        LockMemory(_base);
        constexpr std::uintptr_t offBase = _base + off;
        constexpr PointedType*   p       = reinterpret_cast<PointedType*>(offBase);
        UnlockMemory(offBase, sizeof(std::uintptr_t));
        if (!p || !*p) {
          LockMemory(offBase);
          ret = nullptr;
          break;
        }
        _base = reinterpret_cast<std::uintptr_t>(*p);
        ret   = reinterpret_cast<PointedType*>(_base);
      }
      return ret;
    }

    void Make(const MakeType type, const std::uintptr_t from, const std::uintptr_t to) const {
      std::uint8_t* arr = reinterpret_cast<std::uint8_t*>(from);

      std::uint8_t b = 0x00;
      switch (type) {
        case MakeType::Call:
          UnlockMemory(from, sizeof(std::uint32_t) + 1);
          arr[0]                                     = 0xE8;
          *reinterpret_cast<std::uint32_t*>(&arr[1]) = CalcDistance(from, to);
        case MakeType::Jump:
          UnlockMemory(from, sizeof(std::uint32_t) + 1);
          arr[0]                                     = 0xE9;
          *reinterpret_cast<std::uint32_t*>(&arr[1]) = CalcDistance(from, to);
        case MakeType::Detour:
          // detour here
          break;
        case MakeType::NOP:
          b = 0x90;
          break;
        case MakeType::DebuggerTrap:
          b = 0xCC;
          break;
        case MakeType::Return:
          b = 0xC3;
          break;
      }

      if (b != 0x00 && (to - from) < 0) {
        const std::uintptr_t dist = to - from;
        UnlockMemory(from, dist);
        for (std::uintptr_t i = from; i < dist; i++) *reinterpret_cast<std::uint8_t*>(i) = b;
      }
      LockMemory(from);
    }

    Editor() {
#ifdef __linux__ || defined(_LINUX)
#error Base address cannot be dynamically acquired without hacks on linux systems. Call 'ctor(baseAddress)' or 'Get(baseAddress)' instead.
#elif _WIN32
      _baseAddress = reinterpret_cast<std::uintptr_t>(
          reinterpret_cast<PPEB>(__readfsdword(0x30))->Reserved3[1]);
#endif
    }
    Editor(std::uintptr_t baseAddress) : _baseAddress(baseAddress) {}

    static inline Editor& Get(std::uintptr_t baseAddress) {
      static Editor memory(baseAddress);
      return memory;
    }
    static inline Editor& Get() {
      static Editor memory;
      return memory;
    }
  };

  static inline Editor& Get() { return Editor::Get(); }
}  // namespace MemoryEditor
