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
#include <cstdint>  // integer types
#include <cstring>  // memcpy
#if defined(_WIN32)
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

namespace OpenSpeed::MW05 {
  struct ActionRef;
  struct AIAvoidable;
  struct AISplinePath;
  struct AITarget;
  struct AIVehicle;
  struct Attachments;
  template <class T>
  struct AttributeStructPtr;
  struct AudioSettings;
  struct Behavior;
  template <class T>
  struct BehaviorSpecsPtr;
  struct bList;
  template <class T>
  struct bTList;
  struct bNode;
  template <class T>
  struct bTNode;
  struct CareerPursuitScores;
  struct CareerSettings;
  struct cFinishedRaceStats;
  struct cFrontEndDatabase;
  struct CostToStateScores;
  struct EventSequencer;
  struct FECareerRecord;
  struct FECarRecord;
  struct FECustomizationRecord;
  struct FEImpoundData;
  struct FEInfractionsData;
  struct FEKeyboardSettings;
  struct FEPlayerCarDB;
  struct FinishedRaceStatsEntry;
  struct GameplaySettings;
  struct GIcon;
  struct GManager;
  template <class T>
  struct Grid;
  struct HACTIVITY__;
  struct HCAUSE__;
  struct HighScoresDatabase;
  struct HSIMABLE__;
  struct HSIMPROFILE__;
  struct HSIMSERVICE__;
  struct HSIMTASK__;
  struct IActivity;
  struct IArticulatedVehicle;
  struct IAttachable;
  struct IAttributeable;
  struct IAudible;
  struct IBody;
  struct ICollisionBody;
  struct IDamageable;
  struct IDamagePhysics;
  struct IDynamicsEntity;
  struct IEngine;
  struct IExplodeable;
  struct IExplosion;
  struct IFeedback;
  struct IHud;
  struct IInput;
  struct IInputPlayer;
  struct IModel;
  struct InputControls;
  struct InputPlayer;
  struct IPlayer;
  struct IPursuit;
  struct IRBVehicle;
  struct IRenderable;
  struct IRigidBody;
  struct IRoadBlock;
  struct ISimable;
  struct ISteeringWheel;
  struct ISuspension;
  struct ITransmission;
  struct IVehicle;
  struct IVehicleAI;
  struct IVehicleCache;
  struct JukeboxEntry;
  struct LocalPlayer;
  struct OptionsSettings;
  struct PhysicsObject;
  struct PInput;
  struct PlayerSettings;
  struct PursuitScore;
  struct PVehicle;
  struct RaceSettings;
  struct RaceTypeHighScores;
  struct RBTractor;
  struct RBVehicle;
  struct RideInfo;
  struct RigidBody;
  template <class T>
  struct ScratchPtr;
  struct SimSurface;
  struct TimeOfDay;
  struct Timer;
  struct TopEvadedPursuitDetail;
  struct TrackHighScore;
  struct UCrc32;
  struct UserProfile;
  struct VehicleParams;
  struct VideoSettings;
  struct WCollider;
  struct WorldModel;
  struct WRoadNav;
  struct WWorldPos;

  namespace Attrib {
    using StringKey = std::uint32_t;

    struct Class;
    struct ClassPrivate;
    struct Collection;
    struct Database;
    struct DatabasePrivate;
    struct Definition;
    struct HashMap;
    struct Instance;
    struct Node;
    struct Private;
    struct RefSpec;
    struct Vault;

    namespace Gen {
      struct aivehicle;
      struct camerainfo;
      struct collisionreactions;
      struct presetride;
      struct pvehicle;
      struct rigidbodyspecs;
      struct simsurface;
      struct timeofdaylighting;
    }  // namespace Gen
  }    // namespace Attrib

  namespace CollisionGeometry {
    struct _V3c;
    struct _Q4c;
    struct BoundsHeader;
    struct Bounds;
    struct Collection;
    struct PCloudHeader;
    struct IBoundable;
  }  // namespace CollisionGeometry

  namespace Dynamics {
    namespace Collision {
      struct Geometry;
      struct Moment;
      struct Plane;
    }  // namespace Collision

    struct IEntity;
  }  // namespace Dynamics

  namespace Physics {
    struct Tunings;

    namespace Info {
      struct CorrectedPerformance;
      struct Performance;
    }  // namespace Info

    namespace Upgrades {
      enum class Type : std::uint32_t { Tires, Brakes, Chassis, Transmission, Engine, Induction, NOS };
      struct Package;
    }  // namespace Upgrades
  }    // namespace Physics

  namespace Math {
    struct Vector2;
    struct Vector3;
    struct Vector4;
    struct Matrix4;
  }  // namespace Math

  namespace Sim {
    namespace Collision {
      struct Info;
      struct IListener;
    }  // namespace Collision

    struct Attachments;
    struct Entity;
    struct IEntity;
    struct IServiceable;
    struct ITaskable;
    struct Object;
    struct Packet;
    struct Param;
  }  // namespace Sim

  namespace UMath {
    struct Vector2;
    struct Vector3;
    struct Vector4;
    struct Matrix4;
  }  // namespace UMath

  namespace UTL {
    template <typename T, std::uint32_t nT, typename E, std::uint32_t nE>
    struct _ListSet;
    template <typename T, std::uint32_t nT>
    struct _Storage;
    template <typename T, std::uint32_t nT, std::uint32_t N = 16>
    struct FixedVector;
    template <typename T>
    struct GarbageNode;
    template <typename T, std::uint32_t nT>
    struct List;
    template <typename T, std::uint32_t nT, typename E, std::uint32_t nE>
    struct ListableSet;
    template <typename T, std::uint32_t N = 16>
    struct Vector;

    namespace COM {
      struct IUnknown;
      struct Object;
    }  // namespace COM
  }    // namespace UTL

  namespace WCollisionMgr {
    struct WorldCollisionInfo;
  }  // namespace WCollisionMgr

  enum class CarSlotId : std::uint32_t {
    Base,
    DamageModel_FrontWindow,
    DamageModel_Body,
    DamageModel_CopLights,
    DamageModel_CopSpoiler,
    DamageModel_FrontWheel,
    DamageModel_LeftBrakelight,
    DamageModel_RightBrakelight,
    DamageModel_LeftHeadlight,
    DamageModel_RightHeadlight,
    DamageModel_Hood,
    DamageModel_Bushguard,
    DamageModel_FrontBumper,
    DamageModel_RightDoor,
    DamageModel_RightRearDoor,
    DamageModel_Trunk,
    DamageModel_RearBumper,
    DamageModel_RearKeftWindow,
    DamageModel_FrontLeftWindow,
    DamageModel_FrontRightWindow,
    DamageModel_RearRightWindow,
    DamageModel_LeftDoor,
    DamageModel_LeftRearDoor,
    Body,
    FrontBrake,
    FrontLeftWindow,
    FrontRightWindow,
    FrontWindow,
    Interior,
    LeftBrakelight,
    LeftBrakelightGlass,
    LeftHeadlight,
    LeftHeadlightGlass,
    LeftSideMirror,
    RearBrake,
    RearLeftWindow,
    RearRightWindow,
    RearWindow,
    RightBrakelight,
    RightBrakelightGlass,
    RightHeadlight,
    RightHeadlightGlass,
    RightSideMirror,
    Driver,
    Spoiler,
    UniversalSpoilerBase,
    DamagePlayerModel_Front,
    DamagePlayerModel_FrontLeft,
    DamagePlayerModel_FrontRight,
    DamagePlayerModel_Rear,
    DamagePlayerModel_RearLeft,
    DamagePlayerModel_RearRight,
    Attachment0,
    Attachment1,
    Attachment2,
    Attachment3,
    Attachment4,
    Attachment5,
    Attachment6,
    Attachment7,
    Attachment8,
    Attachment9,
    RoofScoop,
    Hood,
    Headlight,
    Brakelight,
    FrontWheel,
    RearWheel,
    Spinner,
    LicensePlate,
    DecalModel_FrontWindow,
    DecalModel_RearWindow,
    DecalModel_LeftDoor,
    DecalModel_RightDoor,
    DecalModel_LeftQuarter,
    DecalModel_RightQuarter,
    BasePaint,
    VinylLayer,
    PaintRim,
    VinylColour0,
    VinylColour1,
    VinylColour2,
    VinylColour3,
    DecalTexture_FrontWindow0,
    DecalTexture_FrontWindow1,
    DecalTexture_FrontWindow2,
    DecalTexture_FrontWindow3,
    DecalTexture_FrontWindow4,
    DecalTexture_FrontWindow5,
    DecalTexture_FrontWindow6,
    DecalTexture_FrontWindow7,
    DecalTexture_RearWindow0,
    DecalTexture_RearWindow1,
    DecalTexture_RearWindow2,
    DecalTexture_RearWindow3,
    DecalTexture_RearWindow4,
    DecalTexture_RearWindow5,
    DecalTexture_RearWindow6,
    DecalTexture_RearWindow7,
    DecalTexture_LeftDoor0,
    DecalTexture_LeftDoor1,
    DecalTexture_LeftDoor2,
    DecalTexture_LeftDoor3,
    DecalTexture_LeftDoor4,
    DecalTexture_LeftDoor5,
    DecalTexture_LeftDoor_LeftNumber,
    DecalTexture_LeftDoor6,
    DecalTexture_LeftDoor_RightNumber,
    DecalTexture_LeftDoor7,
    DecalTexture_RightDoor0,
    DecalTexture_RightDoor1,
    DecalTexture_RightDoor2,
    DecalTexture_RightDoor3,
    DecalTexture_RightDoor4,
    DecalTexture_RightDoor5,
    DecalTexture_RightDoor_LeftNumber,
    DecalTexture_RightDoor6,
    DecalTexture_RightDoor_RightNumber,
    DecalTexture_RightDoor7,
    DecalTexture_LeftQuarter0,
    DecalTexture_LeftQuarter1,
    DecalTexture_LeftQuarter2,
    DecalTexture_LeftQuarter3,
    DecalTexture_LeftQuarter4,
    DecalTexture_LeftQuarter5,
    DecalTexture_LeftQuarter6,
    DecalTexture_LeftQuarter7,
    DecalTexture_RightQuarter_tex0,
    DecalTexture_RightQuarter_tex1,
    DecalTexture_RightQuarter_tex2,
    DecalTexture_RightQuarter_tex3,
    DecalTexture_RightQuarter_tex4,
    DecalTexture_RightQuarter_tex5,
    DecalTexture_RightQuarter_tex6,
    DecalTexture_RightQuarter_tex7,
    WindowTint,
    CustomHud,
    HudBackingColour,
    HudNeedleColour,
    HudCharacterColour,
    CV,
    WheelManufacturer,
    Misc
  };
  enum class DriverClass : std::uint32_t { Human, Traffic, Cop, Racer, None, NIS, Remote };
  enum class DriverStyle : std::uint32_t { Racing, Drag };
  enum class eCareerUpgradeLevels : std::uint32_t {
    LevelStock,
    Level1,
    Level2,
    Level3,
    LevelUnique,
    LevelUnspecified = UINT_MAX,
  };
  enum class eControllerConfig : std::uint32_t { MinConfig, Config1, Config2, Config3, Config4, MaxConfig, Config5 };
  enum class eCustomTuningType : std::uint32_t { Setting1, Setting2, Setting3 };
  enum class eFEGameModes : std::uint32_t {
    None,
    Career         = 1 << 0,
    Challenge      = 1 << 1,
    QuickRace      = 1 << 2,
    Online         = 1 << 3,
    Options        = 1 << 4,
    Customize      = 1 << 5,
    Lan            = 1 << 6,
    ProfileManager = 1 << 7,
    CareerManager  = 1 << 8,
    RapSheet       = 1 << 9,
    ModeSelect     = 1 << 10,
    Trailers       = 1 << 11,
    CarLot         = 1 << 15,
    Safehouse      = 1 << 16,
    PostRival      = 1 << 17,
    BeatGame       = 1 << 18
  };
  enum class eImpoundReasons : std::int8_t { None, BustedByCross, StrikeLimitReached, InsufficientFunds, Released };
  enum class eInvulnerability : std::uint32_t {
    None,
    FromManualReset,
    FromReset,
    FromControlSwitch,
    FromPhysicsSwitch
  };
  enum class eLaneSelection {
    CenterLane,
    CurrentLane,
    ValidLane,
  };
  enum class eLoadSaveGame : std::uint32_t { Load, Save };
  enum class eOptionsCategory : std::uint32_t {
    Audio,
    Video,
    PCAdvancedDisplay,
    Gameplay,
    Player,
    Controls,
    EATrax,
    Trailers,
    Credits,
    Online
  };
  enum class ePlayerHudType : std::uint32_t { None, Standard, Drag, Split1, Split2, DragSplit1, DragSplit2 };
  enum class ePlayerList : std::uint32_t { All, Local, Remote };
  enum class ePlayerSettingsCameras : std::uint32_t { Bumper, Hood, Default, Close, Far, SuperFar, Drift, Pursuit };
  enum class ePostRaceOptions : std::uint32_t { NextRace, Quit, RestartRace, RestartEvent };
  enum class eVehicleCacheResult : std::uint32_t { Want, DontCare };
  enum class eVehicleParamFlags : std::uint32_t {
    Spooled         = 1 << 0,
    SnapToGround    = 1 << 1,
    NosRemoved      = 1 << 2,
    CalcPerformance = 1 << 3,
    NosAdded        = 1 << 4
  };
  enum class eVehicleList : std::uint32_t {
    All,
    Players,
    AI,
    AIRacers,
    AICops,
    AITraffic,
    Racers,
    Remote,
    Inactive,
    Trailers
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
  enum class JunkmanParts : std::uint32_t {
    Tires       = 1 << 0,
    Brakes      = 1 << 1,
    Drivetrain  = 1 << 2,
    Transmisson = 1 << 3,
    Engine      = 1 << 4,
    Turbo       = 1 << 5,
    Nitrous     = 1 << 6,
    All         = static_cast<std::uint32_t>(Tires) | static_cast<std::uint32_t>(Brakes) |
          static_cast<std::uint32_t>(Drivetrain) | static_cast<std::uint32_t>(Transmisson) |
          static_cast<std::uint32_t>(Engine) | static_cast<std::uint32_t>(Turbo) | static_cast<std::uint32_t>(Nitrous)
  };
  enum class PhysicsMode : std::uint32_t { Inactive, Simulated, Emulated };
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
  enum class SpeedUnitType : std::uint8_t { MPH, KMH, MPS };

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
  }

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
  }  // namespace VehicleFX

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(eFEGameModes)
  DEFINE_ENUM_FLAG_OPERATORS(eVehicleParamFlags)
  DEFINE_ENUM_FLAG_OPERATORS(CollisionGeometry::BoundFlags)
  DEFINE_ENUM_FLAG_OPERATORS(JunkmanParts)
  DEFINE_ENUM_FLAG_OPERATORS(VehicleFX::LightID)
#endif
}  // namespace OpenSpeed::MW05
