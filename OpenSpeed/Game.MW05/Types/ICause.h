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
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
  struct ICause : UTL::COM::IUnknown {
    std::uint32_t _mHandle;  // from UTL::Instanceable<HCAUSE__ *, ICause, n>

    virtual ~ICause();
    virtual void OnCausedCollision(const Sim::Collision::Info& cInfo, ISimable* from, ISimable* to) = 0;
    virtual void OnCausedExplosion(IExplosion* explosion, ISimable* to)                             = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x405020)(); }
  };
}  // namespace OpenSpeed::MW05
