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
#ifndef NFSPLUGINSDK_CORE_MEMORYEDITOR_H
#define NFSPLUGINSDK_CORE_MEMORYEDITOR_H

#include <algorithm>  // copy
#include <array>
#include <cstdint>   // integer types
#include <cstring>   // memcpy
#include <memory>    // unique_ptr
#include <iterator>  // begin, end
#include <unordered_map>

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
    // 0xFF25
    JumpAbsolute,
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
      mBase = reinterpret_cast<std::uintptr_t>(::GetModuleHandleA(NULL));
#endif
    }
    explicit Editor(std::uintptr_t base) : mBase(base) {}

   public:
    class DetourInfo {
      std::uintptr_t              mAddrFrom;
      std::uintptr_t              mAddrDetour;
      std::array<std::uint8_t, 5> mOrigBytes;
      bool                        mHasDetoured;

     public:
      bool IsValid() const {
        return !std::all_of(mOrigBytes.cbegin(), mOrigBytes.cend(), [](std::uint8_t b) { return b == 0; }) &&
               mAddrDetour;
      }
      bool           GetHasDetoured() const { return mHasDetoured; }
      std::uintptr_t GetAddrFrom() const { return mAddrFrom; }
      std::uintptr_t GetAddrDetour() const { return mAddrDetour; }

      void Detour(MakeType detourType = MakeType::Jump) {
        if (mHasDetoured || !mAddrFrom) return;

        Editor::Get().Make(detourType, mAddrFrom, mAddrDetour);
        mHasDetoured = true;
      }
      void Restore() {
        if (!mHasDetoured || !mAddrFrom) return;

        auto m = Editor::Get().GetRawMemory(mAddrFrom);
        if (auto old = m.Unlock(5)) {
          std::memcpy(reinterpret_cast<void*>(mAddrFrom), mOrigBytes.data(), 5);
          m.Lock(5, old);
          mHasDetoured = false;
        }
      }

      explicit DetourInfo(std::uintptr_t addrFrom, std::uintptr_t addrDetour) :
          mAddrFrom(addrFrom), mAddrDetour(addrDetour), mOrigBytes({0}), mHasDetoured(false) {
        auto m = Editor::Get().GetRawMemory(mAddrFrom);
        if (auto old = m.Unlock(5)) {
          std::memcpy(mOrigBytes.data(), reinterpret_cast<void*>(mAddrFrom), 5);
          m.Lock(5, old);
        }
      }
      explicit DetourInfo() : DetourInfo(0, 0) {}
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
        return ::VirtualProtect(reinterpret_cast<LPVOID>(mAddress), size, static_cast<DWORD>(oldProtect), &old);
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
        if (::VirtualProtect(reinterpret_cast<LPVOID>(mAddress), size, PAGE_EXECUTE_READWRITE, &old)) return old;

        return NULL;
#endif
      }

      template <typename T>
      T GetValue() const {
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

      RawMemory operator-(std::uintptr_t offset) {
        auto ret = *this;
        ret.mAddress -= offset;
        return ret;
      }
      RawMemory operator+(std::uintptr_t offset) {
        auto ret = *this;
        ret.mAddress += offset;
        return ret;
      }

      RawMemory& operator--() {
        mAddress--;
        return *this;
      }
      RawMemory& operator++() {
        mAddress++;
        return *this;
      }

      RawMemory operator--(std::int32_t) {
        auto ret = *this;
        --(*this);
        return ret;
      }
      RawMemory operator++(std::int32_t) {
        auto ret = *this;
        ++(*this);
        return ret;
      }

      explicit RawMemory(std::uintptr_t address) : mAddress(address) {}
    };

    inline std::uintptr_t AbsRVA(std::uintptr_t rva) const { return mBase + rva; }
    inline std::uintptr_t CalcRelativeDistance(std::uintptr_t from, std::uintptr_t to) const { return to - from - 5; }

    [[nodiscard]] inline DetourInfo GetDetour(std::uintptr_t from, std::uintptr_t to) const {
      return DetourInfo(from, to);
    }
    [[nodiscard]] inline RawMemory GetRawMemory(std::uintptr_t address) const { return RawMemory(address); }
    // Does not dereference pointer, only casts ptr to a uinptr_t
    [[nodiscard]] inline RawMemory GetRawMemory(void* ptr) const {
      return RawMemory(reinterpret_cast<std::uintptr_t>(ptr));
    }

    void Make(MakeType type, std::uintptr_t from, std::uintptr_t to) const {
      std::int32_t size = (type == MakeType::JumpAbsolute)
                              ? 6
                              : (((type == MakeType::Call) || (type == MakeType::Jump)) ? 5 : to - from);
      if (size < 0) return;

      auto mem = std::make_unique<std::uint8_t[]>(size);

      switch (type) {
        case MakeType::Call: {
          mem[0]                                     = 0xE8;
          *reinterpret_cast<std::uint32_t*>(&mem[1]) = CalcRelativeDistance(from, to);
        } break;
        case MakeType::Jump: {
          mem[0]                                     = 0xE9;
          *reinterpret_cast<std::uint32_t*>(&mem[1]) = CalcRelativeDistance(from, to);
        } break;
        case MakeType::JumpAbsolute: {
          *reinterpret_cast<std::uint16_t*>(&mem[0]) = 0x25FF;
          *reinterpret_cast<std::uint32_t*>(&mem[2]) = to;
        } break;
        case MakeType::NOP:
          std::memset(mem.get(), 0x90, size);
          break;
        case MakeType::DebuggerTrap:
          std::memset(mem.get(), 0xCC, size);
          break;
        case MakeType::Return:
          std::memset(mem.get(), 0xC3, size);
          break;
        default:
          return;
      }

      auto rw = GetRawMemory(from);
      if (auto old = rw.Unlock(size)) {
        std::copy(mem.get(), mem.get() + size, reinterpret_cast<std::uint8_t*>(from));
        rw.Lock(size, old);
      }
    }

    bool ValidateMemory(std::uintptr_t address) const {
#if defined(_WIN32)
      MEMORY_BASIC_INFORMATION mbi = {0};
      if (!::VirtualQuery(reinterpret_cast<LPCVOID>(address), &mbi, sizeof(mbi))) return false;
      if (mbi.Protect & (PAGE_GUARD | PAGE_NOACCESS)) return false;
#endif

      // VC++ Magic Numbers //

      auto rw = GetRawMemory(address);
      if (auto old = rw.Unlock(sizeof(std::uint32_t))) {
        auto val = rw.GetValue<std::uint32_t>();
        if (val == 0x00008123) return false;
        if (val == 0xABABABAB) return false;
        if (val == 0xBAADF00D) return false;
        if (val == 0xCCCCCCCC) return false;
        if (val == 0xCDCDCDCD) return false;
        if (val == 0xDDDDDDDD) return false;
        if (val == 0xFDFDFDFD) return false;
        if (val == 0xFEEEFEEE) return false;

        rw.Lock(sizeof(std::uint32_t), old);
      }

      return true;
    }
    // Checks both the pointer itself and the pointed data (if not NULL)
    template <typename T>
    bool ValidateMemory(T* ptr) const {
      if (!ptr) return false;

      bool ret = ValidateMemory(reinterpret_cast<std::uintptr_t>(ptr));
      if (*reinterpret_cast<std::uintptr_t*>(ptr) == 0) return ret;

      ret |= ValidateMemory(*reinterpret_cast<std::uintptr_t*>(ptr));
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

#endif