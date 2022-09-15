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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_IVEHICLECACHE_H
#define OPENSPEED_GAME_PROSTREET_TYPES_IVEHICLECACHE_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/UTL.h>

namespace OpenSpeed::ProStreet {
  struct IVehicleCache : UTL::COM::IUnknown {
    virtual ~IVehicleCache();
    virtual const char*         GetCacheName()                                                                   = 0;
    virtual eVehicleCacheResult OnQueryVehicleCache(const IVehicle* removethis, const IVehicleCache* whosasking) = 0;
    virtual void                OnRemovedVehicleCache(IVehicle* ivehicle)                                        = 0;
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_IVEHICLECACHE_H
