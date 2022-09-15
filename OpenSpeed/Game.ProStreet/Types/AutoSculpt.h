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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_AUTOSCULPT_H
#define OPENSPEED_GAME_PROSTREET_TYPES_AUTOSCULPT_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/AutoSculptRegion.h>

namespace OpenSpeed::ProStreet {
  struct AutoSculpt {
    enum class RegionID : std::uint32_t {
      RegionFrontBumper,
      RegionRearBumper,
      RegionSkirtLeft,
      RegionSkirtRight,
      RegionRimsFront,
      RegionRimsRear,
      RegionDoorLeft,
      RegionDoorRight,
      RegionDoorRearLeft,
      RegionDoorRearRight,
      RegionFenderFrontLeft,
      RegionFenderFrontRight,
      RegionHoods,
      RegionSpoilers,
      RegionRoofScoops,
      RegionRoofHeight,
      RegionExhaust,
      RegionFrontWindow,
      RegionRearWindow,
      RegionFrontLeftWindow,
      RegionFrontRightWindow,
      RegionRearLeftWindow,
      RegionRearRightWindow,
      RegionLeftDoor,
      RegionRightDoor,
      RegionInterior,
      RegionDoorline,
      RegionDamageFront,
      RegionDamageRear,
      RegionWindTunnelType1,
      RegionWindTunnelType2,
      RegionWindTunnelType3,
      RegionWindTunnelType4,
      RegionWindTunnelType5,
      RegionWindTunnelType6,
      RegionWindTunnelType7,
      RegionWindTunnelType8,
      RegionWindTunnelType9,
      RegionWindTunnelType10,
      RegionRearBumperExtra
    };
    enum class ZoneID : std::uint32_t { Zone0, Zone1, Zone2, Zone3, Zone4, Zone5, Zone6, Zone7, Zone8, Zone9, Zone10 };

    bool             mIsInitialized;
    AutoSculptRegion mRegionList[40];
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_AUTOSCULPT_H
