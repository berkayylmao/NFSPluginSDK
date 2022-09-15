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

#ifndef OPENSPEED_GAME_MW05_TYPES_AITARGET_H
#define OPENSPEED_GAME_MW05_TYPES_AITARGET_H
#pragma once

#include <new>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/bNode.h>

namespace OpenSpeed::MW05 {
  struct AITarget : bTNode<AITarget> {
    ISimable*      mOwner;
    UMath::Vector3 mTargetPosition;
    ISimable*      mTargetSimable;
    UMath::Vector3 mTargetDirection;
    bool           mValid;
    UMath::Vector3 mDirTo;
    float          mDistTo;

    virtual ~AITarget();

    inline void Clear() { reinterpret_cast<void(__thiscall*)(AITarget*)>(0x409E60)(this); }
    inline void Acquire(ISimable* target) {
      reinterpret_cast<void(__thiscall*)(AITarget*, ISimable*)>(0x423860)(this, target);
    }
    inline void Register(ISimable* who) {
      reinterpret_cast<void(__thiscall*)(AITarget*, ISimable*)>(0x423750)(this, who);
    }
    inline void TrackInternal(ISimable* who) { reinterpret_cast<void(__thiscall*)(AITarget*)>(0x4180F0)(this); }

    /// <summary>
    /// Creates an AITarget object through game-code.
    /// </summary>
    /// <returns>A volatile pointer to a created <see cref="AITarget"/> object.</returns>
    static AITarget* Construct(ISimable* owner) {
      // A hacky way to create an object that we do not really have a control over
      AITarget* ret = reinterpret_cast<AITarget*>(::operator new(sizeof(AITarget), std::nothrow));
      if (!ret) return nullptr;

      reinterpret_cast<void(__thiscall*)(AITarget*, ISimable*)>(0x418000)(ret, owner);
      return ret;
    }
  };
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_AITARGET_H
