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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_ICAUSE_H
#define OPENSPEED_GAME_PROSTREET_TYPES_ICAUSE_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct ICause : UTL::COM::IUnknown {
    std::uint32_t _mHandle;  // from UTL::Instanceable<HCAUSE__ *, ICause, n>

    virtual ~ICause();
    virtual void OnCausedCollision(const Sim::Collision::Info& cInfo, ISimable* from, ISimable* to) = 0;
    virtual void OnCausedExplosion(IExplosion* explosion, ISimable* to)                             = 0;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_ICAUSE_H
