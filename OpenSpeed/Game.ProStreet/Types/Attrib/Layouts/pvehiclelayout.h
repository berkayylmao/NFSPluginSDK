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
#include <OpenSpeed/Game.ProStreet/Types/Attrib/RefSpec.h>

namespace OpenSpeed::ProStreet::Attrib::Layouts {
  struct pvehiclelayout {
    Attrib::StringKey            MODEL;
    Attrib::RefSpec              frontend;
    const char*                  DefaultPresetRide;
    const char*                  CollectionName;
    std::int32_t                 transmission_upgrades;
    std::int32_t                 tires_upgrades;
    bool                         RandomOpponent;
    std::int32_t /*GRace::Tier*/ RacingTier;
    std::int32_t                 nos_upgrades;
    bool                         isRateable;
    std::int32_t                 induction_upgrades;
    std::int32_t                 engine_upgrades;
    std::int32_t                 chassis_upgrades;
    std::int32_t                 brakes_upgrades;
  };
}  // namespace OpenSpeed::ProStreet::Attrib::Layouts
