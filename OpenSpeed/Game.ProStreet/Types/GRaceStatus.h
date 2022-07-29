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
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/GRacerInfo.h>
#include <OpenSpeed/Game.ProStreet/Types/IVehicleCache.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct GRaceStatus : UTL::COM::Object, IVehicleCache {
    enum class PlayMode : std::uint32_t { Roaming, Racing };

    GRacerInfo   mRacerInfo[8];
    GRacerInfo*  mLazyRacerInfo[8];
    std::int32_t mRacerCount;
    // unk

    static inline GRaceStatus** g_mThis = reinterpret_cast<GRaceStatus**>(0xAB9D7C);
    static GRaceStatus*         Get() {
      if (!g_mThis) return nullptr;
      return *g_mThis;
    }
  };
}  // namespace OpenSpeed::ProStreet
