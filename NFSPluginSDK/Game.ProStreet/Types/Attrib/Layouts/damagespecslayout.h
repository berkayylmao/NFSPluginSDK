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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_DAMAGESPECSLAYOUT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_DAMAGESPECSLAYOUT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::Attrib::Layouts {
  struct damagespecslayout {
    struct DamageScaleRecord {
      float VisualScale;
      float HitPointScale;
    };

    DamageScaleRecord DZ_TOP;
    DamageScaleRecord DZ_RREAR;
    DamageScaleRecord DZ_RIGHT;
    DamageScaleRecord DZ_RFRONT;
    DamageScaleRecord DZ_REAR;
    DamageScaleRecord DZ_LREAR;
    DamageScaleRecord DZ_LFRONT;
    DamageScaleRecord DZ_LEFT;
    DamageScaleRecord DZ_FRONT;
    DamageScaleRecord DZ_BOTTOM;
    float             SUPPRESS_DIST;
    float             SHOCK_TIME;
    float             SHOCK_FORCE;
    float             HP_THRESHOLD;
    float             HIT_POINTS;
    float             FORCE;
  };
}  // namespace NFSPluginSDK::ProStreet::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_DAMAGESPECSLAYOUT_H
