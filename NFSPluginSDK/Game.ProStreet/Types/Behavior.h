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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_BEHAVIOR_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_BEHAVIOR_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Sim.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UCrc32.h>

namespace NFSPluginSDK::ProStreet {
  struct Behavior : Sim::Object {
    struct Container {
      struct Elements : eastl::list<Behavior*> {};

      Elements _mElements;
    };

    bool           mPaused;
    PhysicsObject* mOwner;
    ISimable*      mIOwner;
    UCrc32         mMechanic;
    UCrc32         mSignature;
    std::int32_t   mPriority;
    HSIMPROFILE__* mProfile;

    virtual ~Behavior();
    virtual void         Reset() = 0;
    virtual std::int32_t GetPriority();
    virtual void         OnOwnerAttached(IAttachable* pOther);
    virtual void         OnOwnerDetached(IAttachable* pOther);
    virtual void         OnTaskSimulate(float deltaTime);
    virtual void         OnBehaviorChange(const UCrc32& mechanic);
    virtual void         OnPause();
    virtual void         OnUnPause();
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_BEHAVIOR_H
