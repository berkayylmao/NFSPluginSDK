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

namespace OpenSpeed::MW05::CARP {
  struct EventList {
    std::uint32_t fNumEvents;
    std::uint32_t fPad[3];
  };

  struct EventStaticData {
    std::uint32_t fEventID;
    std::uint32_t fEventSize;
    std::uint32_t fDataOffset;
    std::uint32_t fPad;
  };

  struct Trigger {
    UMath::Vector4 fMatRow0Width;
    TriggerTypes   fType : 4;
    std::uint32_t  fShape : 4;
    TriggerFlags   fFlags : 24;
    float          fHeight;
    EventList*     fEvents;
    std::uint16_t  fIterStamp;
    std::uint16_t  fFingerprint;
    UMath::Vector4 fMatRow2Length;
    UMath::Vector4 fPosRadius;
  };
}  // namespace OpenSpeed::MW05::CARP
