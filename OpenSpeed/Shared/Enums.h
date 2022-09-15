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
#ifndef OPENSPEED_SHARED_ENUMS_H
#define OPENSPEED_SHARED_ENUMS_H

#include <cstdint>
#ifdef _WIN32
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

namespace OpenSpeed {
  enum class CARPART_LOD : std::uint32_t { A, B, C, D, E, OFF = UINT32_MAX };
  enum class CarRenderUsage : std::uint32_t {
    Player,
    RemotePlayer,
    AIRacer,
    AICop,
    AITraffic,
    AIHeli,
    NISCar,
    Ghost,
    Invalid
  };
  enum class CarUsageType : std::uint32_t { Racing, Cop, Traffic, Wheels, Universal };
  enum class CopDensity : std::uint8_t { Off, Light, Medium, Heavy };
  enum class Difficulty : std::uint8_t { Easy, Medium, Hard };
  enum class eCustomTuningType : std::uint32_t { Setting1, Setting2, Setting3 };
  enum class eGPSState : std::uint32_t { Down, Searching, Tracking };
  enum class eHandlingMode : std::uint8_t { Classic, Extreme };
  enum class eInvulnerability : std::uint32_t {
    None,
    FromManualReset,
    FromReset,
    FromControlSwitch,
    FromPhysicsSwitch
  };
  enum class eLaneSelection : std::uint32_t { CenterLane, CurrentLane, ValidLane };
  enum class eLaneType : std::uint32_t { Racing, Traffic, Drag, Cop, CopReckless, Reset, StartingGrid, Any };
  enum class eNavType : std::uint32_t { None, Traffic, Direction, Path };
  enum class ePathType : std::uint32_t { Cop, None, Racer, GPS, Player, Chopper, RaceRoute };
  enum class ePlayerHudType : std::uint32_t { None, Standard, Drag, Split1, Split2, DragSplit1, DragSplit2 };
  enum class ePrecullerMode : std::uint8_t { Off, On, Blinking, HighSpeed };
  enum class eTireDamage : std::uint8_t { None, Punctured, Blown };
  enum class eTireIdx : std::uint32_t { FrontLeft, FrontRight, RearLeft, RearRight };
  enum class TractionControlStates : std::uint8_t { Off, Level1, Level2, Level3, Level4, ThrottleControl };
  enum class eTrafficDensity : std::uint8_t { Off, Low, Medium, High };
  enum class eVehicleCacheResult : std::uint32_t { Want, DontCare };
  enum class eWorldMapZoomLevels : std::uint8_t { All, Level1, Level2, Level4 };
  enum class FEObjFlags : std::uint32_t {
    MouseObject           = 0x20000,
    SaveStaticTracks      = 0x40000,
    DontNavigate          = 0x80000,
    UsesLibraryObject     = 0x100000,
    CodeSuppliedResource  = 0x200000,
    DirtyCode             = 0x400000,
    DirtyColor            = 0x800000,
    DirtyTransform        = 0x1000000,
    Dirty                 = 0x2000000,
    IgnoreButton          = 0x4000000,
    ObjectLocked          = 0x8000000,
    IsButton              = 0x10000000,
    PerspectiveProjection = 0x20000000,
    AffectAllScripts      = 0x40000000,
    HideInEdit            = 0x80000000,
    Hidden                = 0x00000001
  };
  enum class FEObjType : std::uint32_t {
    None,
    Image,
    String,
    Model,
    List,
    Group,
    CodeList,
    Movie,
    Effect,
    ColoredImage,
    AnimImage,
    SimpleImage,
    MultiImage,
    UserMin = 256
  };
  enum class FEPlayerCarDBFilterBits : std::uint32_t {
    FILTER_LIST_STOCK        = 0x1,
    FILTER_LIST_CUSTOMIZABLE = 0x2,
    FILTER_LIST_SHARED       = 0x4,
    FILTER_LIST_BONUS        = 0x8,
    FILTER_LIST_PRESET       = 0x10,
    FILTER_LIST_DEBUG        = 0x20,
    FILTER_PINKSLIP          = 0x40,
    FILTER_LIST_MASK         = 0xFFFF,
    FILTER_REGION_AMERICA    = 0x10000,
    FILTER_REGION_EUROPE     = 0x20000,
    FILTER_REGION_JAPAN      = 0x40000,
    FILTER_REGION_DEBUG      = 0x80000,
    FILTER_REGION_ALL        = 0xF0000,
    FILTER_REGION_MASK       = 0xFFFF0000
  };
  enum class FEStringFormatting : std::uint32_t {
    JustifyHorizontalCenter,
    JustifyHorizontalRight,
    JustifyVerticalCenter,
    JustifyVerticalBottom,
    WordWrap
  };
  enum class GameFlowState : std::uint32_t {
    None,
    LoadingFrontEnd,
    UnloadingFrontEnd,
    InFrontEnd,
    LoadingRegion,
    LoadingTrack,
    Racing,
    UnloadingTrack,
    UnloadingRegion,
    ExitDemoDisc
  };
  enum class PhysicsMode : std::uint32_t { Inactive, Simulated, Emulated };
  enum class ScrapeSurfaces : std::uint32_t { None, Concrete, Metal, Rubber };
  enum class SimableType : std::uint32_t {
    Invalid,
    Vehicle,
    Smackable,
    Explosion,
    Human,
    Weapon,
    Newton,
    Sentry,
    Fragment
  };
  enum class SirenState : std::uint32_t { Wail, Yelp, Scream, Die, Off = UINT32_MAX };
  enum class SpeedUnitType : std::uint8_t { MPH, KPH, MPS };

  namespace CollisionGeometry {
    enum class BoundFlags : std::uint32_t {
      Disabled             = 1 << 0,
      PrimVsWorld          = 1 << 1,
      PrimVsObjects        = 1 << 2,
      PrimVsGround         = 1 << 3,
      MeshVsGround         = 1 << 4,
      Internal             = 1 << 5,
      Box                  = 1 << 6,
      Sphere               = 1 << 7,
      Constraint_Conical   = 1 << 8,
      Constraint_Prismatic = 1 << 9,
      Joint_Female         = 1 << 10,
      Joint_Male           = 1 << 11,
      Male_Post            = 1 << 12,
      Joint_Invert         = 1 << 13
    };
#ifdef _WIN32
    DEFINE_ENUM_FLAG_OPERATORS(BoundFlags)
#endif
  }  // namespace CollisionGeometry
  namespace VehicleFX {
    enum class LightID : std::uint32_t {
      None,
      LeftHead         = 1 << 0,
      RightHead        = 1 << 1,
      CenterHead       = 1 << 2,
      LeftBrake        = 1 << 3,
      RightBrake       = 1 << 4,
      CenterBrake      = 1 << 5,
      LeftReverse      = 1 << 6,
      RightReverse     = 1 << 7,
      LeftRearSignal   = 1 << 8,
      RightRearSignal  = 1 << 9,
      LeftFrontSignal  = 1 << 10,
      RightFrontSignal = 1 << 11,
      CopRed           = 1 << 12,
      CopBlue          = 1 << 13,
      CopWhite         = 1 << 14,
      Headlights       = (std::uint32_t)LeftHead | (std::uint32_t)RightHead | (std::uint32_t)CenterHead,
      Brakelights      = (std::uint32_t)LeftBrake | (std::uint32_t)RightBrake | (std::uint32_t)CenterBrake,
      RunningLights    = (std::uint32_t)Headlights | (std::uint32_t)Brakelights,
      Reverse          = (std::uint32_t)LeftReverse | (std::uint32_t)RightReverse,
      LeftSignal       = (std::uint32_t)LeftFrontSignal | (std::uint32_t)LeftRearSignal,
      RightSignal      = (std::uint32_t)RightFrontSignal | (std::uint32_t)RightRearSignal,
      Cop              = (std::uint32_t)CopRed | (std::uint32_t)CopBlue | (std::uint32_t)CopWhite
    };
    enum class WindowID : std::uint32_t {
      None,
      Front      = 1 << 0,
      FrontLeft  = 1 << 1,
      RearLeft   = 1 << 2,
      FrontRight = 1 << 3,
      RearRight  = 1 << 4,
      Rear       = 1 << 5
    };

#ifdef _WIN32
    DEFINE_ENUM_FLAG_OPERATORS(LightID)
    DEFINE_ENUM_FLAG_OPERATORS(WindowID)
#endif
  }  // namespace VehicleFX

#ifdef _WIN32
  DEFINE_ENUM_FLAG_OPERATORS(FEObjFlags)
  DEFINE_ENUM_FLAG_OPERATORS(FEPlayerCarDBFilterBits)
#endif
}  // namespace OpenSpeed

#endif // OPENSPEED_SHARED_ENUMS_H
