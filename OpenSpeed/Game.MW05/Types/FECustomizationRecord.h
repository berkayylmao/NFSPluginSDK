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

namespace OpenSpeed::MW05 {
  struct FECustomizationRecord {
    enum class eCustomTuningType : std::int32_t { CTT_SETTING_1 = 0, CTT_SETTING_2 = 1, CTT_SETTING_3 = 2 };

    // Performance upgrades
    struct Package {
      enum class JunkmanParts : std::uint32_t {
        Tire        = 1 << 0,
        Brakes      = 1 << 1,
        Drivetrain  = 1 << 2,
        Transmisson = 1 << 3,
        Engine      = 1 << 4,
        Turbo       = 1 << 5,
        Nitrous     = 1 << 6
      };

      std::uint32_t mTires;
      std::uint32_t mBrakes;
      std::uint32_t mDrivetrain;
      std::uint32_t mTransmission;
      std::uint32_t mEngine;
      std::uint32_t mTurbo;
      std::uint32_t mNitro;
      JunkmanParts  mJunkman;
    };

    // Performance tunings
    struct Tunings {
      enum class Path {
        STEERING     = 0,
        HANDLING     = 1,
        BRAKES       = 2,
        RIDEHEIGHT   = 3,
        AERODYNAMICS = 4,
        NOS          = 5,
        INDUCTION    = 6
      };

      static inline const float g_GameDisplayMultiplier = 5.0f;

      float mSteering;
      float mHandling;
      float mBrakes;
      float mRideHeight;
      float mAerodynamics;
      float mNOS;
      float mInduction;

      explicit Tunings() :
          mSteering(0.0f),
          mHandling(0.0f),
          mBrakes(0.0f),
          mRideHeight(0.0f),
          mAerodynamics(0.0f),
          mNOS(0.0f),
          mInduction(0.0f) {}
    };

    unsigned char     __stuff1[0x2E];
    std::uint16_t     bodykit;
    std::uint16_t     brakepadsFront;
    std::uint16_t     windowFrontLeft;
    std::uint16_t     windowFrontRight;
    std::uint16_t     windowWindshield;
    std::uint16_t     interior;
    std::uint16_t     leftTaillight;
    std::uint16_t     windowLeftTaillight;
    std::uint16_t     leftHeadlight;
    std::uint16_t     windowLeftHeadlight;
    unsigned char     __stuff2[0x02];
    std::uint16_t     brakepadsRear;
    std::uint16_t     windowRearLeft;
    std::uint16_t     windowRearRight;
    std::uint16_t     windowRearWindow;
    std::uint16_t     rightTaillight;
    std::uint16_t     windowRightTaillight;
    std::uint16_t     rightHeadlight;
    std::uint16_t     windowRightHeadlight;
    unsigned char     __stuff3[0x02];
    std::uint16_t     driverModel;
    std::uint16_t     spoiler;
    unsigned char     __stuff4[0x22];
    std::uint16_t     roofscoop;
    std::uint16_t     hood;
    unsigned char     __FFBytes1[0x4];
    std::uint16_t     rims;
    unsigned char     __FFBytes2[0x4];
    unsigned char     __stuff5[0xE];
    std::uint16_t     paint;
    std::uint16_t     vinyl;
    std::uint16_t     colourRims;
    unsigned char     __stuff6[0x8];
    std::uint16_t     decalWindshield;
    unsigned char     __stuff7[0xE];
    std::uint16_t     decalRearWindow;
    unsigned char     __stuff8[0xE];
    std::uint16_t     decalLeftDoorSlot1;
    std::uint16_t     decalLeftDoorSlot2;
    std::uint16_t     decalLeftDoorSlot3;
    std::uint16_t     decalLeftDoorSlot4;
    std::uint16_t     decalLeftDoorSlot5;
    std::uint16_t     decalLeftDoorSlot6;
    std::uint16_t     decalLeftDoorNumberLeftHalf;
    std::uint16_t     decalLeftDoorNumberRightHalf;
    std::uint16_t     decalRightDoorSlot1;
    std::uint16_t     decalRightDoorSlot2;
    std::uint16_t     decalRightDoorSlot3;
    std::uint16_t     decalRightDoorSlot4;
    std::uint16_t     decalRightDoorSlot5;
    std::uint16_t     decalRightDoorSlot6;
    std::uint16_t     decalRightDoorNumberLeftHalf;
    std::uint16_t     decalRightDoorNumberRightHalf;
    std::uint16_t     decalLeftQuarterPanel;
    unsigned char     __stuff9[0xE];
    std::uint16_t     decalRightQuarterPanel;
    unsigned char     __stuff10[0xE];
    std::uint16_t     colourWindow;
    std::uint16_t     gaugeType;
    std::uint16_t     gaugeFaceColour;
    std::uint16_t     gaugeNeedleColour;
    std::uint16_t     gaugeLetteringColour;
    unsigned char     __stuff11[0x8];
    Package           mPackage;
    Tunings           mTunings[3];
    eCustomTuningType mActiveTuning;
    std::int32_t      mPreset;
    std::uint8_t      mHandle;
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(FECustomizationRecord::Package::JunkmanParts)
#endif
}  // namespace OpenSpeed::MW05
