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

#pragma once
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DLCommandObject.h>

namespace OpenSpeed::ProStreet {
  struct DALInterface {
    enum class InterfaceType : std::uint32_t {
      Template,
      Racer,
      Vehicle,
      Event,
      LangHash,
      Options,
      Career,
      FEVehicle,
      PauseStates,
      Player,
      Pursuit,
      Statistics,
      Online,
      Challenge,
      Hub,
      Async,
      Rewards,
      RaceDay,
      Opponent,
      Memcard,
      MemcardTasks,
      StatsMetrics
    };

    InterfaceType mInterfaceIndex;

    virtual ~DALInterface();
    virtual bool IsInterfaceValid(const int, const int, const int, const int);
    virtual bool GetFloat(const int, float*, const int, const int, const int);
    virtual bool SetFloat(const int, const float, const int, const int, const int);
    virtual bool IncrementFloat(const int, const float, const int, const int, const int);
    virtual bool DecrementFloat(const int, const float, const int, const int, const int);
    virtual bool GetInt(const int, int*, const int, const int, const int);
    virtual bool SetInt(const int, const int, const int, const int, const int);
    virtual bool IncrementInt(const int, const int, const int, const int, const int);
    virtual bool DecrementInt(const int, const int, const int, const int, const int);
    virtual bool GetString(const int, char*, const int, const int, const int, const int);
    virtual bool SetString(const int, const char*, const int, const int, const int, const int);
    virtual bool GetDefaultInt(const int, int*, const int, const int, const int);
    virtual bool GetDefaultFloat(const int, float*, const int, const int, const int);
    virtual void HandleCommand(DLCommandObject*);
    virtual void CancelCommand(DLCommandObject*);
  };
}  // namespace OpenSpeed::ProStreet
