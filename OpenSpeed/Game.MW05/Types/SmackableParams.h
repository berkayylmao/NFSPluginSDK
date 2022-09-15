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

#ifndef OPENSPEED_GAME_MW05_TYPES_SMACKABLEPARAMS_H
#define OPENSPEED_GAME_MW05_TYPES_SMACKABLEPARAMS_H
#pragma once

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Sim.h>

namespace OpenSpeed::MW05 {
  struct SmackableParams : Sim::Param {
    UMath::Matrix4 fMatrix;
    bool           fVirginSpawn;
    IModel*        fScenery;
    bool           fSimplePhysics;

    explicit SmackableParams(const UMath::Matrix4& matrix, bool isVirginSpawn = true, IModel* scenery = nullptr,
                             bool isSimplePhysics = true) :
        Sim::Param(0x0A6B47FAC),
        fMatrix(matrix),
        fVirginSpawn(isVirginSpawn),
        fScenery(scenery),
        fSimplePhysics(isSimplePhysics) {
      AddTypeName(this);
    }

    static void AddTypeName(SmackableParams* to) { reinterpret_cast<void(__cdecl*)(SmackableParams*)>(0x620FF0)(to); }
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_SMACKABLEPARAMS_H
