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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_CAMERAINFOLAYOUT_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_CAMERAINFOLAYOUT_H
#pragma once

#include <iterator>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Private.h>

namespace NFSPluginSDK::MW05::Attrib::Layouts {
  struct camerainfolayout {
    Private     _Array_STIFFNESS;
    float       STIFFNESS[2];
    Private     _Array_ANGLE;
    float       ANGLE[2];
    Private     _Array_LAG;
    float       LAG[2];
    Private     _Array_FOV;
    float       FOV[2];
    Private     _Array_HEIGHT;
    float       HEIGHT[2];
    Private     _Array_LATEOFFSET;
    float       LATEOFFSET[2];
    const char* CollectionName;
    Private     _Array_TILTING;
    bool        TILTING[2];
    Private     _Array_SELECTABLE;
    bool        SELECTABLE[2];

    void operator=(const camerainfolayout& rhs) {
      std::copy(std::cbegin(rhs.STIFFNESS), std::cend(rhs.STIFFNESS), std::begin(this->STIFFNESS));
      std::copy(std::cbegin(rhs.ANGLE), std::cend(rhs.ANGLE), std::begin(this->ANGLE));
      std::copy(std::cbegin(rhs.LAG), std::cend(rhs.LAG), std::begin(this->LAG));
      std::copy(std::cbegin(rhs.FOV), std::cend(rhs.FOV), std::begin(this->FOV));
      std::copy(std::cbegin(rhs.HEIGHT), std::cend(rhs.HEIGHT), std::begin(this->HEIGHT));
      std::copy(std::cbegin(rhs.LATEOFFSET), std::cend(rhs.LATEOFFSET), std::begin(this->LATEOFFSET));
      std::copy(std::cbegin(rhs.TILTING), std::cend(rhs.TILTING), std::begin(this->TILTING));
      std::copy(std::cbegin(rhs.SELECTABLE), std::cend(rhs.SELECTABLE), std::begin(this->SELECTABLE));
    }
  };
}  // namespace NFSPluginSDK::MW05::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_CAMERAINFOLAYOUT_H
