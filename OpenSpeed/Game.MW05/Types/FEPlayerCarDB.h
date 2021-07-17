// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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
#include <OpenSpeed/Game.MW05/Types/FECareerRecord.h>
#include <OpenSpeed/Game.MW05/Types/FECarRecord.h>
#include <OpenSpeed/Game.MW05/Types/FECustomizationRecord.h>
#include <OpenSpeed/Game.MW05/Types/FEInfractionsData.h>

namespace OpenSpeed::MW05 {
  struct FEPlayerCarDB {
    FECarRecord           CarTable[200];
    FECustomizationRecord Customizations[75];
    FECareerRecord        CareerRecords[25];
    std::uint32_t         SoldHistoryBounty;
    std::uint16_t         SoldHistoryNumEvadedPursuits;
    std::uint16_t         SoldHistoryNumBustedPursuits;
    FEInfractionsData     SoldHistoryUnservedInfractions;
    FEInfractionsData     SoldHistoryServedInfractions;
  };
}  // namespace OpenSpeed::MW05