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
#include <Game.MW05/Types.h>

namespace OpenSpeed::MW05 {
  struct FECustomizationRecord {
    enum class JunkmanParts : std::uint32_t {
      Tire        = 1 << 0,
      Brakes      = 1 << 1,
      Drivetrain  = 1 << 2,
      Transmisson = 1 << 3,
      Engine      = 1 << 4,
      Turbo       = 1 << 5,
      Nitrous     = 1 << 6
    };

    std::uint8_t  damage1[0x6];
    unsigned char __stuff1[0x2C];
    std::uint16_t bodykit;
    std::uint16_t brakepadsFront;
    std::uint16_t windowFrontLeft;
    std::uint16_t windowFrontRight;
    std::uint16_t windowWindshield;
    std::uint16_t interior;
    std::uint16_t leftTaillight;
    std::uint16_t windowLeftTaillight;
    std::uint16_t leftHeadlight;
    std::uint16_t windowLeftHeadlight;
    unsigned char __stuff2[0x02];
    std::uint16_t brakepadsRear;
    std::uint16_t windowRearLeft;
    std::uint16_t windowRearRight;
    std::uint16_t windowRearWindow;
    std::uint16_t rightTaillight;
    std::uint16_t windowRightTaillight;
    std::uint16_t rightHeadlight;
    std::uint16_t windowRightHeadlight;
    unsigned char __stuff3[0x02];
    std::uint16_t driverModel;
    std::uint16_t spoiler;
    unsigned char __stuff4[0x22];
    std::uint16_t roofscoop;
    std::uint16_t hood;
    unsigned char __FFBytes1[0x4];
    std::uint16_t rims;
    unsigned char __FFBytes2[0x4];
    unsigned char __stuff5[0xE];
    std::uint16_t paint;
    std::uint16_t vinyl;
    std::uint16_t colourRims;
    unsigned char __stuff6[0x8];
    std::uint16_t decalWindshield;
    unsigned char __stuff7[0xE];
    std::uint16_t decalRearWindow;
    unsigned char __stuff8[0xE];
    std::uint16_t decalLeftDoorSlot1;
    std::uint16_t decalLeftDoorSlot2;
    std::uint16_t decalLeftDoorSlot3;
    std::uint16_t decalLeftDoorSlot4;
    std::uint16_t decalLeftDoorSlot5;
    std::uint16_t decalLeftDoorSlot6;
    std::uint16_t decalLeftDoorNumberLeftHalf;
    std::uint16_t decalLeftDoorNumberRightHalf;
    std::uint16_t decalRightDoorSlot1;
    std::uint16_t decalRightDoorSlot2;
    std::uint16_t decalRightDoorSlot3;
    std::uint16_t decalRightDoorSlot4;
    std::uint16_t decalRightDoorSlot5;
    std::uint16_t decalRightDoorSlot6;
    std::uint16_t decalRightDoorNumberLeftHalf;
    std::uint16_t decalRightDoorNumberRightHalf;
    std::uint16_t decalLeftQuarterPanel;
    unsigned char __stuff9[0xE];
    std::uint16_t decalRightQuarterPanel;
    unsigned char __stuff10[0xE];
    std::uint16_t colourWindow;
    std::uint16_t gaugeType;
    std::uint16_t gaugeFaceColour;
    std::uint16_t gaugeNeedleColour;
    std::uint16_t gaugeLetteringColour;
    unsigned char __stuff11[0x8];
    std::uint32_t perfTires;
    std::uint32_t perfBrakes;
    std::uint32_t perfDrivetrain;
    std::uint32_t perfTransmission;
    std::uint32_t perfEngine;
    std::uint32_t perfTurbo;
    std::uint32_t perfNitro;
    JunkmanParts  perfJunkman;
    unsigned char __stuff12[0x5C];
    std::uint8_t  slotId;
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(FECustomizationRecord::JunkmanParts)
#endif
}  // namespace OpenSpeed::MW05
