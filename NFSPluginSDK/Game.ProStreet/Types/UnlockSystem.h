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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_UNLOCKSYSTEM_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_UNLOCKSYSTEM_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EA.h>

namespace NFSPluginSDK::ProStreet {
  struct UnlockSystem : EA::Memcard::IMemcardSavable {
    enum class eCategoryUnlockable : std::uint32_t {
      Vinyls,
      Paint,
      RimPaint,
      RideHeight,
    };
    enum class ePaintUnlockableLevel : std::uint32_t { Gloss, Metal, Pearl, Matte, Chrome, Iridescent, Candy };
    enum class eUnlockFilters : std::uint32_t { QuickRace = 1 << 0, Career = 1 << 1, Online = 1 << 2 };

    struct Unlockable {
      std::uint32_t mId;
      bool          mIsNew;
    };

    Unlockable*   mUnlockedUnlockables;
    std::uint32_t mUnlockableCount;
    std::uint32_t mUnlockedCarCount;
    std::uint32_t mUnlockedVisualCount;
    std::uint32_t mUnlockedPerfCount;

    static UnlockSystem* Get(std::size_t idx = 0) {
      static auto** spInstance = reinterpret_cast<UnlockSystem**>(0xAB0EC4);
      if (!spInstance) return nullptr;

      return *spInstance;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_UNLOCKSYSTEM_H
