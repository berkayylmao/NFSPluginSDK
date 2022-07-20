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
#include <algorithm>    // copy
#include <cstdint>      // integer types
#include <iterator>     // begin, end
#include <type_traits>  // enable_if_t, is_base_of_v
#if defined(_WIN32)
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

#include <OpenSpeed/Game.ProStreet/Types/Math.h>
#include <OpenSpeed/Game.ProStreet/Types/UMath.h>

namespace OpenSpeed::ProStreet {
#pragma region Forward declarations
  namespace Attrib {
    using StringKey = std::uint32_t;

    struct ChunkBlock;
    struct Class;
    struct ClassPrivate;
    struct Collection;
    struct Database;
    struct DatabasePrivate;
    struct DataBlock;
    struct Definition;
    struct DependencyNode;
    struct ExportManager;
    struct ExportNode;
    struct ExportPolicyPair;
    struct HashMap;
    struct Instance;
    struct Node;
    struct PointerNode;
    struct Private;
    struct RefSpec;
    struct Vault;

    namespace Gen {
      struct aivehicle;
      struct camerainfo;
      struct chopperspecs;
      struct collisionreactions;
      struct gameplay;
      struct presetride;
      struct pursuitescalation;
      struct pursuitlevels;
      struct pursuitsupport;
      struct pvehicle;
      struct rigidbodyspecs;
      struct simsurface;
      struct timeofdaylighting;
      struct trafficpattern;
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

  namespace DamageZone {
    struct Info;
  }

  namespace Dynamics {
    namespace Collision {
      struct Geometry;
      struct Moment;
      struct Plane;
    }  // namespace Collision

    struct IEntity;
  }  // namespace Dynamics

  namespace Physics {
    enum class ePerformanceType : std::uint32_t {
      SimpleTime_0_to_100MPH,
      SimpleTime_0_to_60MPH,
      SimpleTime_70_to_150MPH,
      SimpleTime_100_to_0MPH,
      SimpleTime_60_to_0MPH,
      SimpleDistance_60_to_0MPH,
      SimpleDistance_100_to_0MPH,
      SimpleTimeQuarterMile,
      SimpleSpeedQuarterMileMPH,
      SimpleTime60Feet,
      SimpleTopspeed,
      SimpleMax_gs_30MPH,
      SimpleMax_gs_60MPH,
      SimpleMax_gs_100MPH,
      SimpleTimeCorner_200m_40m_300m,
      SimpleDownforce,
      SimpleDrag,
      SimpleFrontToe30MPH,
      SimpleFrontToe60MPH,
      SimpleFrontToe100MPH,
      SimpleCaster,
      SimpleFrontWeightBias,
      SimpleBbrake,
      SimpleSteeringAlignmentTorque,
      SimpleAeroCG,
      SimpleRollCenter,
      SimpleSpringStiffness,
      SimpleSwaybarStiffness,
      SimpleShockDigression,
      SimpleShockValving,
      SimpleHorsePower,
      SimpleHorsePowerRPM,
      SimplePeakTorque,
      SimplePeakTorqueRPM,
      SimpleWeight,
      SimpleWeightToPowerRatio,
      ComplexGrip,
      ComplexDrift,
      ComplexDrag,
      ComplexWheelie,
      ComplexSpeedChallenge,
      ComplexPower,
      ComplexTraction,
      ComplexAero,
      ComplexHandling,
      ComplexControl,
      ComplexStability,
    };

    struct Tunings;

    namespace Info {
      struct CorrectedPerformance;
      struct Performance;
    }  // namespace Info

    namespace Upgrades {
      enum class Type : std::uint32_t { Tires, Brakes, Chassis, Transmission, Engine, Induction, NOS };
      struct Package;
      struct Part;
      struct Tuning;
    }  // namespace Upgrades
  }    // namespace Physics

  namespace Sim {
    namespace Collision {
      enum class CollisionType : std::uint32_t { None, Object, World, Ground };

      struct Info;
      struct IListener;
    }  // namespace Collision

    struct Activity;
    struct Entity;
    struct IActivity;
    struct IEntity;
    struct IServiceable;
    struct ITaskable;
    struct Object;
    struct Packet;
    struct Param;
  }  // namespace Sim

  namespace UTL {
    template <typename T, std::size_t nT, typename E, std::size_t nE>
    struct _ListSet;
    template <typename T, std::size_t nT>
    struct _Storage;
    template <typename T, std::size_t nT, std::size_t N = 16>
    struct FixedVector;
    template <typename T>
    struct GarbageNode;
    template <typename T, std::size_t nT>
    struct List;
    template <typename T, std::size_t nT, typename E, std::size_t nE>
    struct ListableSet;
    template <typename T, std::size_t N = 16>
    struct Vector;

    namespace COM {
      struct IUnknown;
      struct Object;
    }  // namespace COM
  }    // namespace UTL

  namespace VinylSystem {
    struct VinylTransformPacked;
  }

  namespace WRoadNav {
    enum class eLaneType : std::uint32_t { Racing, Traffic, Drag, Cop, CopReckless, Reset, StartingGrid, Any };
    enum class eNavType : std::uint32_t { None, Traffic, Direction, Path };
    enum class ePathType : std::uint32_t { Cop, None, Racer, GPS, Player, Chopper, RaceRoute };
  }  // namespace WRoadNav

  struct ActionData;
  struct ActionRef;
  struct ActionQueue;
  struct AdaptivePIDControllerComplicated;
  struct AdaptivePIDControllerSimple;
  struct AIAction;
  struct AIAvoidable;
  struct AICopManager;
  struct AIGoal;
  struct AIPerpVehicle;
  struct AIPursuit;
  struct AIRoadBlock;
  struct AISpawnManager;
  struct AISplinePath;
  struct AITarget;
  struct AIVehicle;
  struct AIVehicleCopCar;
  struct AIVehicleEmpty;
  struct AIVehicleGhost;
  struct AIVehicleHuman;
  struct AIVehiclePursuit;
  struct AIVehicleRacecar;
  struct AIVehicleTraffic;
  struct AIWingman;
  struct Attachments;
  struct AttributeSet;
  struct AttribVaultPackImage;
  struct AudioSettings;
  struct AutoSculpt;
  struct AutoSculptRegion;
  struct Behavior;
  struct BehaviorParams;
  struct bFile;
  struct bList;
  template <typename T>
  struct bPList;
  struct bPNode;
  template <typename T>
  struct bTList;
  struct bNode;
  template <typename T>
  struct bTNode;
  struct CareerPursuitScores;
  struct CareerSettings;
  struct CarPaintPart;
  struct CarPaintPartRecord;
  struct CarPaintPartRecordPacked;
  struct CarPart;
  struct cFinishedRaceStats;
  struct cFrontEndDatabase;
  struct Context;
  struct CostToStateScores;
  struct DamageCopCar;
  struct DamageDragster;
  struct DamageHeli;
  struct DamageRacer;
  struct DamageVehicle;
  struct DBCarPart;
  struct DecalLayerPartInfo;
  struct EmitterGroup;
  struct eLightMaterial;
  struct eModel;
  struct EventSequencer;
  struct FECareerRecord;
  struct FECarRecord;
  struct FECustomizationRecord;
  struct FEImpoundData;
  struct FEInfractionsData;
  struct FEKeyboardSettings;
  struct FEngHud;
  struct FEObject;
  struct FEPlayerCarDB;
  struct FinishedRaceStatsEntry;
  struct FloatSpring;
  struct GameplaySettings;
  struct GCharacter;
  struct GenericMessage;
  struct GEventTimer;
  struct GIcon;
  struct GIOpponent;
  struct GManager;
  struct GMilestone;
  struct GRaceBin;
  struct GRaceIndexData;
  struct GRaceParameters;
  struct GRacerInfo;
  template <typename T>
  struct Grid;
  struct LeaderSupport;
  struct HeavySupport;
  struct GroundSupportRequest;
  struct GRuntimeInstance;
  struct GSpeedTrap;
  struct GTimer;
  struct GTrigger;
  struct GVault;
  struct HACTIVITY__;
  struct HCAUSE__;
  struct HCOLPRIM__;
  struct HighScoresDatabase;
  struct HMODEL__;
  struct HSIMABLE__;
  struct HSIMPROFILE__;
  struct HSIMSERVICE__;
  struct HSIMTASK__;
  struct HudElement;
  struct IAIHelicopter;
  struct IArticulatedVehicle;
  struct IAttachable;
  struct IAttachmentSystem;
  struct IAttributeable;
  struct IAudible;
  struct IBody;
  struct ICause;
  struct IChassis;
  struct ICheater;
  struct ICollisionBody;
  struct ICopMgr;
  struct IDamageable;
  struct IDamageableVehicle;
  struct IDamagePhysics;
  struct IDisposable;
  struct IDynamicsEntity;
  struct IEngine;
  struct IExplodeable;
  struct IExplosion;
  struct IFeedback;
  struct IGarbageCollector;
  struct IGenericMessage;
  struct IHandle;
  struct IHud;
  struct IInput;
  struct IInputPlayer;
  struct IModel;
  struct InputControls;
  struct InputMapping;
  struct InputPlayer;
  struct IPerpetrator;
  struct IPlayer;
  struct IRacer;
  struct IPursuit;
  struct IPursuitAI;
  struct IRBVehicle;
  struct IRenderable;
  struct IResetable;
  struct IRigidBody;
  struct IRoadBlock;
  struct ISimable;
  struct ISimpleBody;
  struct ISimpleChopper;
  struct ISpikeable;
  struct ISteeringWheel;
  struct ISuspension;
  struct ITrafficAI;
  struct ITransmission;
  struct IVehicle;
  struct IVehicleAI;
  struct IVehicleCache;
  struct JukeboxEntry;
  struct LocalPlayer;
  struct MilestoneTypeInfo;
  struct ObjectStateBlockHeader;
  struct OptionsSettings;
  struct PackedDecalLayer;
  struct PackedVinylColor;
  struct PackedVinylLayer;
  struct PhysicsObject;
  struct PidError;
  struct PInput;
  struct PlayerSettings;
  struct PursuitFormation;
  struct PursuitScore;
  struct PVehicle;
  struct RacePreparationInfo;
  struct RaceSettings;
  struct RaceTypeHighScores;
  struct RBTractor;
  struct RBVehicle;
  struct RideInfo;
  struct RigidBody;
  struct SimpleChopper;
  struct SimCollisionMap;
  struct SimSurface;
  struct Smackable;
  struct SmackableParams;
  struct TimeOfDay;
  struct Timer;
  struct TopEvadedPursuitDetail;
  struct TrackHighScore;
  template <typename T, std::size_t N>
  struct UCircularQueue;
  struct UCrc32;
  struct UserProfile;
  struct VehicleBehavior;
  struct VehicleCustomizations;
  struct VehicleParams;
  struct VideoSettings;
  struct VinylColorPartInfo;
  struct VinylLayerPartInfo;
  struct WCollider;
  struct WorldModel;
  struct WRoadNavInfluence;
  struct WTrigger;
  struct WWorldPos;

#pragma endregion

#pragma region Enums

  enum class BluePrintNumber : std::uint32_t { BluePrint1, BluePrint2, BluePrint3 };
  enum class BluePrintType : std::uint32_t { Grip, Drift, Drag, SpeedChallenge };
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
  enum class CarSlotId : std::uint32_t {
    Invalid = UINT32_MAX,
    BadgingBumperSetFront,
    BadgingBumperSetRear,
    BadgingFenderFrontLeft,
    BadgingFenderFrontRight,
    BadgingFenderRearLeft,
    BadgingFenderRearRight,
    BadgingTrunk,
    Base,
    Body,
    BodyDoorline,
    BrakeCaliperFront,
    BrakeCaliperRear,
    BrakeRotorFront,
    BrakeRotorRear,
    BrakelightGlassLeft,
    BrakelightGlassRight,
    BrakelightLeft,
    BrakelightRight,
    BumperFront,
    BumperFrontExtra,
    BumperRear,
    BumperRearExtra,
    DamageBody,
    DamageBrakelightLeft,
    DamageBrakelightRight,
    DamageBumperFront,
    DamageBumperRear,
    DamageDoorLeft,
    DamageDoorRearLeft,
    DamageDoorRearRight,
    DamageDoorRight,
    DamageFenderFrontLeft,
    DamageFenderFrontRight,
    DamageHeadlightLeft,
    DamageHeadlightRight,
    DamageHood,
    DamageSidemirrorLeft,
    DamageSidemirrorRight,
    DamageTrunk,
    DamageWidebody,
    DamageWidebodyBumperFront,
    DamageWidebodyBumperRear,
    DamageWidebodyDoorLeft,
    DamageWidebodyDoorRearLeft,
    DamageWidebodyDoorRearRight,
    DamageWidebodyDoorRight,
    DamageWidebodyFenderFrontLeft,
    DamageWidebodyFenderFrontRight,
    DamageWindowFront,
    DamageWindowFrontLeft,
    DamageWindowFrontRight,
    DamageWindowRear,
    DamageWindowRearLeft,
    DamageWindowRearRight,
    Damage0Front,
    Damage0FrontLeft,
    Damage0FrontRight,
    Damage0Rear,
    Damage0RearLeft,
    Damage0RearRight,
    DecalFrontWindow,
    DecalRearWindow,
    DoorLeft,
    DoorRearLeft,
    DoorRearRight,
    DoorRight,
    DoorhandleFrontLeft,
    DoorhandleFrontRight,
    DoorhandleRearLeft,
    DoorhandleRearRight,
    Driver,
    Engine,
    Exhaust,
    FenderFrontLeft,
    FenderFrontRight,
    HeadlightGlassLeft,
    HeadlightGlassRight,
    HeadlightLeft,
    HeadlightRight,
    Hood,
    Interior,
    LicensePlate,
    RollCage,
    Roof,
    RoofInside,
    RoofScoop,
    SeatLeft,
    SeatRight,
    SideMirrorLeft,
    SideMirrorRight,
    SkirtLeft,
    SkirtRight,
    Spoiler,
    SteeringWheel,
    Trunk,
    UniversalSpoilerBase,
    WheelFront,
    WheelRear,
    WindowFront,
    WindowFrontLeft,
    WindowFrontRight,
    WindowRear,
    WindowRearLeft,
    WindowRearRight,
    WindtunnelType1,
    WindtunnelType10,
    WindtunnelType2,
    WindtunnelType3,
    WindtunnelType4,
    WindtunnelType5,
    WindtunnelType6,
    WindtunnelType7,
    WindtunnelType8,
    WindtunnelType9,
    BodyPaint,
    BodyPaintGroup,
    BodyPaintSwatch,
    BumperFrontPaint,
    BumperFrontPaintGroup,
    BumperFrontPaintSwatch,
    BumperRearPaint,
    BumperRearPaintGroup,
    BumperRearPaintSwatch,
    Chassis,
    DrivetrainPackage,
    EnginePackage,
    ForcedInductionPackage,
    HoodPaint,
    HoodPaintGroup,
    HoodPaintSwatch,
    Livery,
    NitrousPackage,
    RollcagePaint,
    RollcagePaintGroup,
    RollcagePaintSwatch,
    RoofScoopPaint,
    RoofScoopPaintGroup,
    RoofScoopPaintSwatch,
    SideMirrorPaint,
    SideMirrorPaintGroup,
    SideMirrorPaintSwatch,
    SkirtPaint,
    SkirtPaintGroup,
    SkirtPaintSwatch,
    SpoilerPaint,
    SpoilerPaintGroup,
    SpoilerPaintSwatch,
    SuspensionPackage,
    TireFront,
    TirePackage,
    TireRear,
    VectorVinyl,
    VinylPaint,
    WheelPaint,
    WheelPaintGroup,
    WheelPaintSwatch,
    WheelSpokeFrontPaint,
    WheelSpokeFrontPaintGroup,
    WheelSpokeFrontPaintSwatch,
    WheelSpokeRearPaint,
    WheelSpokeRearPaintGroup,
    WheelSpokeRearPaintSwatch,
    WindowTint,
    WindowTintGroup,
    WindowTintSwatch
  };
  enum class CarType : std::uint32_t {
    CCX,
    FOCUSST,
    S3,
    SL65,
    DBR9,
    DB9,
    NISSAN_350Z,
    BMWM3,
    RX7,
    PORSCHE_997GT3RS,
    VEYRON,
    CHEVELLE,
    LANCEREVO9,
    PORSCHE_997GT2,
    S2000,
    NSX,
    SKYLINER35,
    CAMARON,
    CAYMANS,
    MURCIELAGO640,
    S4,
    MUSTANGSHLBYO,
    MUSTANGSHLBYN,
    PORSCHE_997TT,
    ELISE,
    CHALLENGER71,
    CORVETTE,
    MCLARENF1,
    GTRPROTO,
    IS350,
    CTSV,
    CHARGER69,
    RX8,
    GTO,
    G35,
    MUSTANGGT,
    DELTA,
    SILVIA,
    LANCEREVOX,
    INTEGRATYPER,
    CORVETTEZ06,
    SKYLINE,
    MAZDASPEED3,
    SOLSTICEGXP,
    BMWM3E92,
    SUPRA,
    CAMARO,
    GTO65,
    BMWMZ4,
    GALLARDOS,
    COSWORTH,
    CIVICSI,
    COROLLA,
    R8PROD,
    PORSCHE_997GT3,
    RSX,
    TTN,
    IMPREZAWRXSTI,
    FORDGT,
    COBALTSS,
    ZONDA,
    ROADRUNNER,
    INTEGRALS,
    CIVICHB,
    CARRERAGT,
    CORVETTE67,
    GTI,
    NISSAN_240SX,
    MUSTANG03,
    R32,
    LEONCUPRA,
    RS4,
    ECLIPSE,
    VIPER,
    CUDA,
    CHALLENGERN,
    NISSAN_370ZN,
    FERRARI_458ITALIA,
    FERRARI_488GTB,
    FERRARI_599GTO,
    FERRARI_812SF,
    CIVICSI86,
    CIVICTYPER15,
    ENZO,
    F12BERLINETTA,
    F50,
    IMPREZAGV,
    JZX90,
    LAFERRARI,
    NSX17,
    NSXR92,
    R35NFS,
    SKYLINER31,
    SKYLINER33,
    SUPRA92,
    XJ220,
    NONE = UINT32_MAX
  };
  enum class DriverAidType : std::uint32_t {
    TractionControl,
    AntiBrakeLock,
    StabilityManagement,
    DriftSteeringAssist,
    DriftGlueToRoad,
    DriftDynamicBrake,
    DriftSpeedControl,
    RacelineAssist,
    BrakingAssist
  };
  enum class DriverAssistLevel : std::uint32_t { Family, Racer, King };
  enum class DriverClass : std::uint32_t { Human, Traffic, Cop, Racer, None, NIS, Remote, RemoteRacer, Ghost, Hub };
  enum class DriverStyle : std::uint32_t { Racing, Drag, Drift, HighSpeed, Traffic, None = UINT32_MAX };
  enum class KitType : std::int32_t {
    Base,
    Stock,
    Autosculpt,
    Widebody,
  };
  enum class eCustomTuningType : std::uint32_t { Setting1, Setting2, Setting3 };
  enum class eLaneSelection : std::uint32_t { CenterLane, CurrentLane, ValidLane };
  enum class ePlayerHudType : std::uint32_t { None, Standard, Drag, Split1, Split2, DragSplit1, DragSplit2 };
  enum class eTrafficDensity : std::uint8_t { Off, Low, Medium, High };
  enum class eTransmissionOverride : std::uint32_t { None, Manual, ManualClutch, Automatic };
  enum class eVehicleCacheResult : std::uint32_t { Want, DontCare };
  enum class eVehicleParamFlags : std::uint32_t {
    None,
    SpoolResources     = 1 << 0,
    SnapToGround       = 1 << 1,
    RemoveNOS          = 1 << 2,
    ComputePerformance = 1 << 3,
    ForceNOS           = 1 << 4,
    LowRez             = 1 << 5,
    Critical           = 1 << 6,
    PhysicsOnly        = 1 << 7
  };
  enum class eWingmanRole : std::uint32_t { Unknown, Leader, Blocky, Pathy, Speedy };
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

  namespace CollisionGeometry {
    enum class BoundFlags : std::uint32_t {
      Disabled            = 1 << 0,
      PrimVsWorld         = 1 << 1,
      PrimVsObjects       = 1 << 2,
      PrimVsGround        = 1 << 3,
      MeshVsGround        = 1 << 4,
      Internal            = 1 << 5,
      Box                 = 1 << 6,
      Sphere              = 1 << 7,
      ConstraintConical   = 1 << 8,
      ConstraintPrismatic = 1 << 9,
      JointFemale         = 1 << 10,
      JointMale           = 1 << 11,
      MalePost            = 1 << 12,
      JointInvert         = 1 << 13,
      PrimVsOwnParts      = 1 << 14
    };
  }

  namespace VehicleFX {
    enum class ID : std::uint32_t {
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
  DEFINE_ENUM_FLAG_OPERATORS(eVehicleParamFlags)
  DEFINE_ENUM_FLAG_OPERATORS(CollisionGeometry::BoundFlags)
  DEFINE_ENUM_FLAG_OPERATORS(VehicleFX::ID)
#endif

#pragma endregion

#pragma region Default types

  template <typename T, typename = std::enable_if_t<std::is_base_of_v<Attrib::Instance, T>>>
  class AttributeStructPtr : T {
    Attrib::Instance* _getAsAttribInstance() { return reinterpret_cast<Attrib::Instance*>(this); }

    template <typename T>
    friend struct BehaviorSpecsPtr;
  };
  template <typename T>
  struct BehaviorSpecsPtr : AttributeStructPtr<T> {
    T& operator*() { return *AttributeStructPtr<T>::_getAsAttribInstance(); }
    T* operator->() { return AttributeStructPtr<T>::_getAsAttribInstance(); }
  };

  template <typename T>
  struct ScratchPtr {
    T** mRef;

    T& operator*() { return **mRef; }
    T* operator->() { return *mRef; }
    T* operator&() { return *mRef; }
  };

#pragma endregion

}  // namespace OpenSpeed::ProStreet
