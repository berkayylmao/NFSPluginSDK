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
#include <Core/EASTL/EASTL/map.h>

#include <Game.MW05/Types.h>
#include <Game.MW05/Types/Behavior.h>
#include <Game.MW05/Types/IBody.h>
#include <Game.MW05/Types/ISimable.h>

namespace OpenSpeed::MW05 {
  struct PhysicsObject : Sim::Object,
                         ISimable,
                         IBody,
                         IAttachable,
                         UTL::GarbageNode<PhysicsObject>,
                         Behavior::Container {
    struct Mechanics : eastl::map<std::uint32_t, Behavior*, eastl::less<std::uint32_t>> {};
    struct Behaviors : eastl::list<Behavior*> {};

    WWorldPos*       mWPos;
    SimableType      mObjType;
    HSIMABLE__*      mOwner;
    Attrib::Instance mAttributes;
    IRigidBody*      mRigidBody;
    HSIMTASK__*      mSimulateTask;
    Sim::IEntity*    mEntity;
    IPlayer*         mPlayer;
    HSIMSERVICE__*   mBodyService;
    std::uint32_t    mWorldID;
    Mechanics        mMechanics;

    virtual ~PhysicsObject();
    virtual void Reset();
    virtual void OnTaskSimulate(float) = 0;
    virtual void OnBehaviorChange(const UCrc32&);
  };
}  // namespace OpenSpeed::MW05
