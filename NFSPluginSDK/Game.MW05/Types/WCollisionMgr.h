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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_WCOLLISIONMGR_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_WCOLLISIONMGR_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05::WCollisionMgr {
  struct WorldCollisionInfo {
    UMath::Vector4                 fCollidePt;
    UMath::Vector4                 fNormal;
    float                          fDist;
    bool                           fAnimated;
    bool                           fType;
    std::uint16_t                  fPad;
    void*                          fCInst;
    Dynamics::Collision::Geometry* pWorldGeom;
    Dynamics::Collision::Geometry* pUserGeom;
    UTL::COM::IUnknown*            pUnk;
    unsigned char                  __PADDING__[8];
  };

  struct ICollisionHandler {
    virtual bool OnWCollide(const WCollisionMgr::WorldCollisionInfo&, const UMath::Vector3&, void*) = 0;
  };
}  // namespace NFSPluginSDK::MW05::WCollisionMgr

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_WCOLLISIONMGR_H
