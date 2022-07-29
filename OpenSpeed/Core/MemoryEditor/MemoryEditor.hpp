// clang-format off
//
//    MemoryEditor: A header-only cross-platform library to edit runtime memory. (C++17)
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
#include <array>
#include <cassert>
#include <cstdint>  // integer types
#include <cstring>  // memcpy
#include <initializer_list>
#include <memory>  // unique_ptr
#include <mutex>   // mutex, scoped_lock
#include <unordered_map>
#include <type_traits>  // enable_if, is_arithmetic
#include <tuple>

#if defined(__linux__) || defined(_LINUX)
#include <sys/mman.h>  // mprotect()
#elif defined(_WIN32)
#include <libloaderapi.h>  // GetModuleHandle()
#include <memoryapi.h>     // VirtualProtect()
#else
#error This operating system is not supported.
#endif

namespace MemoryEditor {
  enum class MakeType : std::uint8_t {
    // 0xE8
    Call,
    // 0xE9
    Jump,
    // 0x90
    NOP,
    // 0xC3
    Return,
    // 0xCC
    DebuggerTrap
  };

  class Editor {
    std::uintptr_t mBase;

    explicit Editor() {
#if defined(__linux__) || defined(_LINUX)
#error Base address cannot be dynamically acquired without hacks on linux systems. Call 'Get(baseAddress)' instead.
#elif defined(_WIN32)
      mBase = reinterpret_cast<std::uintptr_t>(GetModuleHandleW(NULL));
#endif
    }
    explicit Editor(std::uintptr_t base) : mBase(base) {}

   public:
    class DetourInfo {
      bool                                                mHasDetoured;
      std::array<std::uint8_t, sizeof(std::uint32_t) + 1> mOrigBytes;
      std::uintptr_t                                      mAddrFrom;
      std::uintptr_t                                      mAddrDetour;

     public:
      std::uintptr_t GetAddrFrom() const { return mAddrFrom; }
      std::uintptr_t GetAddrDetour() const { return mAddrDetour; }
      bool           GetHasDetoured() const { return mHasDetoured; }

      void Detour(MakeType detourType = MakeType::Jump) {
        if (mHasDetoured) return;

        Editor::Get().Make(detourType, mAddrFrom, mAddrDetour);
        mHasDetoured = true;
      }
      void Restore() {
        if (!mHasDetoured) return;

        auto              m    = Editor::Get().GetRawMemory(mAddrFrom);
        const std::size_t size = sizeof(std::uint32_t) + 1;
        if (auto old = m.Unlock(size)) {
          std::memcpy(reinterpret_cast<void*>(mAddrFrom), mOrigBytes.data(), sizeof(std::uint32_t) + 1);
          m.Lock(size, old);
          mHasDetoured = false;
        }
      }

      // Detours immediately
      explicit DetourInfo(std::uintptr_t addrFrom, std::uintptr_t addrDetour, MakeType detourType) :
          mHasDetoured(false), mAddrFrom(addrFrom), mAddrDetour(addrDetour) {
        auto              m    = Editor::Get().GetRawMemory(mAddrFrom);
        const std::size_t size = sizeof(std::uint32_t) + 1;
        if (auto old = m.Unlock(size)) {
          std::memcpy(mOrigBytes.data(), reinterpret_cast<void*>(mAddrFrom), sizeof(std::uint32_t) + 1);
          m.Lock(size, old);
        }

        Detour(detourType);
      }

      // Detours immediately
      explicit DetourInfo(std::uintptr_t addrFrom, std::uintptr_t addrDetour) :
          DetourInfo(addrFrom, addrDetour, MakeType::Jump) {}
    };
    class RawMemory {
      std::uintptr_t mAddress;

     public:
      /// <summary>
      /// Relocks memory at mAddress.
      /// </summary>
      /// <param name="size">How many bytes were unlocked</param>
      /// <param name="oldProtect">Old memory protect value</param>
      /// <returns>True if successful, false otherwise</returns>
      bool Lock(std::size_t size, std::uint_least32_t oldProtect) const {
#if defined(_WIN32)
        DWORD old;
        return VirtualProtect(reinterpret_cast<LPVOID>(mAddress), size, static_cast<DWORD>(oldProtect), &old);
#else
        return false;
#endif
      }

      /// <summary>
      /// Unlocks memory at mAddress.
      /// </summary>
      /// <param name="size">How many bytes to unlock</param>
      /// <returns>Old memory protect value, NULL if failed</returns>
      std::uint_least32_t Unlock(std::size_t size) const {
#if defined(__linux__) || defined(_LINUX)
        return mprotect(reinterpret_cast<void*>(mAddress), size, PROT_READ | PROT_WRITE | PROT_EXEC) == 0;
#elif defined(_WIN32)
        DWORD old;
        if (VirtualProtect(reinterpret_cast<LPVOID>(mAddress), size, PAGE_EXECUTE_READWRITE, &old)) return old;

        return NULL;
#endif
      }

      template <typename T>
      const T GetValue() const {
        T ret{};

        auto old = Unlock(sizeof(T));
        if (!old) return ret;

        ret = *reinterpret_cast<T*>(mAddress);
        Lock(sizeof(T), old);
        return ret;
      }
      template <typename T>
      bool SetValue(const T& value) const {
        auto old = Unlock(sizeof(T));
        if (!old) return false;

        *reinterpret_cast<T*>(mAddress) = value;
        Lock(sizeof(T), old);
        return true;
      }

      explicit RawMemory(std::uintptr_t address) : mAddress(address) {}
    };

    [[nodiscard]] inline RawMemory GetRawMemory(std::uintptr_t address) const { return RawMemory(address); }

    inline std::uintptr_t AbsRVA(std::uintptr_t rva) const { return mBase + rva; }
    inline std::uintptr_t CalculateRelativeDistance(std::uintptr_t from, std::uintptr_t to) const {
      return to - from - sizeof(std::uintptr_t) - 1;
    }
    bool ValidateMemoryIsInitialized(std::uintptr_t address) const {
#if defined(_WIN32)
      // Check if page is accessible
      {
        MEMORY_BASIC_INFORMATION mbi;
        ZeroMemory(&mbi, sizeof(MEMORY_BASIC_INFORMATION));
        if (!::VirtualQuery(reinterpret_cast<LPCVOID>(address), &mbi, sizeof(mbi))) return false;
        // Ensure r/w/x
        if (!(mbi.Protect & (PAGE_READONLY | PAGE_READWRITE | PAGE_WRITECOPY | PAGE_EXECUTE_READ |
                             PAGE_EXECUTE_READWRITE | PAGE_EXECUTE_WRITECOPY)))
          return false;
        // Ensure no guard or no access
        if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) return false;
      }
#endif

      // VC++ Magic Numbers //

      auto m = GetRawMemory(address);

      // Guard bytes after allocated heap memory
      if (m.GetValue<std::uint32_t>() == 0xABABABAB) return false;
      // Uninitialized stack memory
      if (m.GetValue<std::uint32_t>() == 0xCCCCCCCC) return false;
      // Uninitialized heap memory
      if (m.GetValue<std::uint32_t>() == 0xCDCDCDCD) return false;
      // Guard bytes before & after allocated heap memory
      if (m.GetValue<std::uint32_t>() == 0xFDFDFDFD) return false;
      // Freed memory
      if (m.GetValue<std::uint32_t>() == 0xFEEEFEEE) return false;

      return true;
    }

    std::unique_ptr<DetourInfo> Detour(std::uintptr_t from, std::uintptr_t to, MakeType type = MakeType::Jump) const {
      return std::make_unique<DetourInfo>(from, to, type);
    }
    void Make(MakeType type, std::uintptr_t from, std::uintptr_t to) const {
      std::uint8_t* arr = reinterpret_cast<std::uint8_t*>(from);
      auto          m   = GetRawMemory(from);

      std::uint8_t val = 0x00;
      switch (type) {
        case MakeType::Call:
          auto size = sizeof(std::uint32_t) + 1;
          if (auto old = m.Unlock(size)) {
            arr[0]                                     = 0xE8;
            *reinterpret_cast<std::uint32_t*>(&arr[1]) = CalculateRelativeDistance(from, to);
            m.Lock(size, old);
          }
          break;
        case MakeType::Jump:
          auto size = sizeof(std::uint32_t) + 1;
          if (auto old = m.Unlock(size)) {
            arr[0]                                     = 0xE9;
            *reinterpret_cast<std::uint32_t*>(&arr[1]) = CalculateRelativeDistance(from, to);
            m.Lock(size, old);
          }
          break;
        case MakeType::NOP:
          val = 0x90;
          break;
        case MakeType::DebuggerTrap:
          val = 0xCC;
          break;
        case MakeType::Return:
          val = 0xC3;
          break;
      }

      if (val != 0x00 && (to - from) > 0) {
        auto size = to - from;
        if (auto old = m.Unlock(size)) {
          std::memset(reinterpret_cast<void*>(from), val, size);
          m.Lock(size, old);
        }
      }
    }

    template <typename PointedType>
    PointedType* ReadPointer(std::uintptr_t base, std::initializer_list<std::uintptr_t> offsets) const {
      PointedType* ret = nullptr;
      if (!base || !ValidateMemoryIsInitialized(base) || !GetRawMemory(base).GetValue<std::uintptr_t>()) {
        return ret;
      }

      std::uintptr_t last = *reinterpret_cast<std::uintptr_t*>(base);

      for (const auto& off : offsets) {
        auto            m = GetRawMemory(last + off);
        std::uintptr_t* p = m.GetValue<std::uintptr_t*>();
        if (!p || !ValidateMemoryIsInitialized(*p)) {
          ret = nullptr;
          break;
        }
        ret = reinterpret_cast<PointedType*>(*p);
      }
      return ret;
    }

    static inline const Editor& Get() {
      static Editor memory;
      return memory;
    }
    static inline const Editor& Get(std::uintptr_t base) {
      static Editor memory(base);
      return memory;
    }
  };

  static inline const Editor& Get() { return Editor::Get(); }
  static inline const Editor& Get(std::uintptr_t base) { return Editor::Get(base); }
}  // namespace MemoryEditor
