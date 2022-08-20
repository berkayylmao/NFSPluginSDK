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
#include <OpenSpeed/Game.ProStreet/Types/DriftLapReport.h>

namespace OpenSpeed::ProStreet {
  struct DriftScoreReport {
    std::uint32_t                                                         totalPoints;
    DriftChainInfo*                                                       bestDriftInDuration;
    DriftChainInfo*                                                       bestDriftInLength;
    DriftChainInfo*                                                       bestDriftInScore;
    std::uint32_t                                                         averageDriftScore;
    float                                                                 averageDriftLength;
    float                                                                 averageDriftDuration;
    std::uint32_t                                                         numberOfSpinOuts;
    std::uint32_t                                                         numberOfWallsHit;
    std::uint32_t                                                         numberOfDriftChains;
    std::uint32_t                                                         externalPoints;
    eastl::map<std::uint32_t, DriftLapReport, eastl::less<std::uint32_t>> driftLapReports;
    unsigned char                                                         _pad1[4];
  };
}  // namespace OpenSpeed::ProStreet
