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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ISIMPLEBODY_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ISIMPLEBODY_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct ISimpleBody : UTL::COM::IUnknown {
    enum class BodyFlags : std::uint16_t {
      None                   = 0,
      SkipSRBCollisions      = 1 << 0,
      SkipRBCollisions       = 1 << 1,
      SkipCollisions         = 3,
      ApplyBasicPhysics      = 1 << 2,
      LinearMotion           = 1 << 3,
      OBBCollideWith_RB      = 1 << 6,
      OBBCollideWith_SRB     = 1 << 7,
      CanHitTriggers         = 1 << 8,
      AngularMotion          = 1 << 9,
      SkipSameTypeCollisions = 1 << 14,
      SOBBCollideWith_RB     = 1 << 15,
    };

    virtual ~ISimpleBody();
    virtual void                   ModifyFlags(BodyFlags remove, BodyFlags add) = 0;
    virtual bool                   CanCollideWithSRB()                          = 0;
    virtual bool                   CanCollideWithRB()                           = 0;
    virtual bool                   CanHitTrigger()                              = 0;
    virtual const SimCollisionMap* GetCollisionMap() const                      = 0;
    virtual SimCollisionMap*       GetCollisionMap()                            = 0;
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(ISimpleBody::BodyFlags)
#endif
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ISIMPLEBODY_H
