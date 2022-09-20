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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEPARAMETERS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEPARAMETERS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/gameplay.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GRaceIndexData.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GVault.h>

namespace NFSPluginSDK::ProStreet {
  struct GRaceParameters {
    enum class ScoreUnitType : std::uint32_t { None, Time, Speed, Points };

    GRaceIndexData*        mIndex;
    Attrib::Gen::gameplay* mRaceRecord;
    GVault*                mParentVault;
    GVault*                mChildVault;
    GVault*                mTrackVault;
    GVault*                mRegionVault;

    virtual void GetCheckpointPosition(std::uint32_t, UMath::Vector3&);
    virtual void GetCheckpointDirection(std::uint32_t, UMath::Vector3&);
    virtual ~GRaceParameters();

    std::int8_t    GetNumLaps() { return reinterpret_cast<std::int8_t(__thiscall*)(GRaceParameters*)>(0x657CF0)(this); }
    GRace::Variant GetRaceVariant() {
      if (!mIndex) return GRace::Variant::Invalid;

      return reinterpret_cast<GRace::Variant(__cdecl*)(GRace::Type)>(0x657E10)(mIndex->mRaceType);
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEPARAMETERS_H
