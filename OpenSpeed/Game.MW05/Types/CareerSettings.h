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
#include <OpenSpeed/Game.MW05/Types/SMSMessage.h>

namespace OpenSpeed::MW05 {
  struct CareerSettings {
    std::uint32_t CurrentCar;
    std::uint32_t SpecialFlags;
    std::uint8_t  CurrentBin;
    std::int32_t  CurrentCash;
    std::int16_t  AdaptiveDifficulty;
    SMSMessage    SMSMessages[150];
    std::uint16_t SMSSortOrder;
    char          CaseFileName[16];

    inline const char*   GetCaseFileName() { return CaseFileName; }
    inline void          AwardCash(std::int32_t amount) { CurrentCash += amount; }
    inline std::int32_t  GetCash() { return CurrentCash; }
    inline std::uint8_t  GetCurrentBin() { return CurrentBin; }
    inline void          SetCurrentBin(std::uint8_t bin) { CurrentBin = bin; }
    inline std::uint32_t GetCurrentCar() { return CurrentCar; }
    inline std::uint32_t SetCurrentCar(std::uint32_t handle) { CurrentCar = handle; }
  };
}  // namespace OpenSpeed::MW05