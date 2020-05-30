// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Attrib.h>

namespace OpenSpeed::MW05 {
  struct CameraInfo {
    Attrib::Private _Array_STIFFNESS;
    float           STIFFNESS[2];
    Attrib::Private _Array_ANGLE;
    float           ANGLE[2];
    Attrib::Private _Array_LAG;
    float           LAG[2];
    Attrib::Private _Array_FOV;
    float           FOV[2];
    Attrib::Private _Array_HEIGHT;
    float           HEIGHT[2];
    Attrib::Private _Array_LATEOFFSET;
    float           LATEOFFSET[2];
    char*           CollectionName;
    Attrib::Private _Array_TILTING;
    bool            TILTING[2];
    Attrib::Private _Array_SELECTABLE;
    bool            SELECTABLE[2];

    void operator=(const CameraInfo& newCameraInfo) {
      std::memcpy(STIFFNESS, newCameraInfo.STIFFNESS, sizeof(float) * 2);
      std::memcpy(ANGLE, newCameraInfo.ANGLE, sizeof(float) * 2);
      std::memcpy(LAG, newCameraInfo.LAG, sizeof(float) * 2);
      std::memcpy(FOV, newCameraInfo.FOV, sizeof(float) * 2);
      std::memcpy(HEIGHT, newCameraInfo.HEIGHT, sizeof(float) * 2);
      std::memcpy(LATEOFFSET, newCameraInfo.LATEOFFSET, sizeof(float) * 2);
      std::memcpy(TILTING, newCameraInfo.TILTING, sizeof(bool) * 2);
      std::memcpy(SELECTABLE, newCameraInfo.SELECTABLE, sizeof(bool) * 2);
    }
  };
}  // namespace OpenSpeed::MW05
