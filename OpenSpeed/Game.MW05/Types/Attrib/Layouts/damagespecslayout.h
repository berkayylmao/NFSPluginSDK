// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05::Attrib::Layouts {
  struct damagespecslayout {
    struct DamageScaleRecord {
      float VisualScale;
      float HitPointScale;
    };

    DamageScaleRecord DZ_LFRONT;
    DamageScaleRecord DZ_FRONT;
    DamageScaleRecord DZ_BOTTOM;
    DamageScaleRecord DZ_LEFT;
    DamageScaleRecord DZ_RREAR;
    DamageScaleRecord DZ_LREAR;
    DamageScaleRecord DZ_RIGHT;
    DamageScaleRecord DZ_REAR;
    DamageScaleRecord DZ_TOP;
    DamageScaleRecord DZ_RFRONT;
    float             SHOCK_TIME;
    float             HP_THRESHOLD;
    float             SUPPRESS_DIST;
    float             SHOCK_FORCE;
    float             FORCE;
    float             HIT_POINTS;
  };
}  // namespace OpenSpeed::MW05::Attrib::Layouts
