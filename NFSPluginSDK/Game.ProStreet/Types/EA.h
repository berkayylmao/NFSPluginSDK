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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::EA {
  namespace Localizer::LocalizerManager {
    static const char* const GetPackedString(std::uint32_t labelHash) {
      return reinterpret_cast<const char* const(__cdecl*)(std::uint32_t)>(0x5B8410)(labelHash);
    }
  }  // namespace Localizer::LocalizerManager

  namespace Memcard {
    struct MemcardChunk {
      std::uint32_t ID;
      std::int32_t  Size;
      bool          isNestedChunk;
    };

    struct IMemcardSavable {
      std::uint32_t mNameHash;
      MemcardChunk* mpChunk;
      void*         mpEndOfBuffer;
      void*         mpStartOfBuffer;
      std::uint32_t mSize;

      virtual ~IMemcardSavable();
      virtual void RegisterForSave(const char*, std::int32_t);
      virtual void SaveData(std::int32_t);
      virtual bool LoadData(std::int32_t);
      virtual void DefaultData(std::int32_t);
    };
  }  // namespace Memcard
  namespace Thread {
    struct alignas(8) EAMutexData {
      std::uint8_t mData[32];
      std::int32_t mnLockCount;
      bool         mbIntraProcess;
      void*        mThreadId;
    };

    struct Mutex {
      EAMutexData mMutexData;
    };
  }  // namespace Thread
}  // namespace NFSPluginSDK::ProStreet::EA

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
