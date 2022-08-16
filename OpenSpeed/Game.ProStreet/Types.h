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
#include <cstdint>      // integer types
#include <type_traits>  // enable_if_t, is_base_of_v
#if defined(_WIN32)
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

#include <OpenSpeed/Shared/AllShared.h>

namespace OpenSpeed::ProStreet {
#pragma region Forward declarations
  namespace Attrib {
    struct StringKey {
      std::uint32_t mHash32;
      const char*   mString;

      StringKey(std::uint32_t hash, const char* str) : mHash32(hash), mString(str) {}
      StringKey() : StringKey(0, nullptr) {}
    };

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

    static inline std::uint32_t StringToKey(const char* name) {
      return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x52B8D0)(name);
    }

    static inline Collection* FindCollection(std::uint32_t classKey, std::uint32_t collectionKey) {
      return reinterpret_cast<Collection*(__cdecl*)(std::uint32_t, std::uint32_t)>(0x52CD40)(classKey, collectionKey);
    }
    static inline Collection* FindCollection(const char* className, std::uint32_t collectionKey) {
      return FindCollection(StringToKey(className), collectionKey);
    }
    static inline Collection* FindCollection(const char* className, const char* collectionName) {
      return FindCollection(StringToKey(className), StringToKey(collectionName));
    }
  }  // namespace Attrib

  namespace CollisionGeometry {
    struct _V3c;
    struct _Q4c;
    struct BoundsHeader;
    struct Bounds;
    struct Collection;
    struct PCloudHeader;
    struct IBoundable;
  }  // namespace CollisionGeometry

  namespace DALVehicleCommands {
    enum class RaceMode : std::uint32_t { Grip, Drift, Drag, Speed };
    enum class DriveTrain : std::uint32_t { FWD, RWD, AWD };
    struct CreateCustomizableCar;
  }  // namespace DALVehicleCommands

  namespace DamageZone {
    enum class ID : std::uint32_t { Front, Rear, Left, Right, LeftFront, RightFront, LeftRear, RightRear, Top, Bottom };
    struct Info;
  }  // namespace DamageZone

  namespace Dynamics {
    namespace Collision {
      struct Geometry;
      struct Moment;
      struct Plane;
    }  // namespace Collision

    struct IEntity;
  }  // namespace Dynamics

  namespace Math {
    using Vector2 = OpenSpeed::Vector2;
    using Vector3 = OpenSpeed::Vector3;
    using Vector4 = OpenSpeed::Vector4;
    using Matrix4 = OpenSpeed::Matrix4;

  }  // namespace Math
  namespace UMath {
    using Vector2 = OpenSpeed::UVector2;
    using Vector3 = OpenSpeed::UVector3;
    using Vector4 = OpenSpeed::UVector4;
    using Matrix4 = OpenSpeed::UMatrix4;
  }  // namespace UMath

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
    template <typename T, std::size_t nT, std::size_t VectorCapacity = 16>
    struct FixedVector;
    template <typename T, std::size_t nT>
    struct GarbageNode;
    template <typename T, std::size_t nT>
    struct Listable;
    template <typename T, std::size_t nT, typename E, std::size_t nE>
    struct ListableSet;
    template <typename T, std::size_t N>
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
  struct BlueprintShareable;
  template <typename T>
  struct bPList;
  struct bPNode;
  template <typename T>
  struct bTList;
  struct bNode;
  template <typename T>
  struct bTNode;
  using bVector2    = Math::Vector2;
  using bVector3    = Math::Vector3;
  using bVector4    = Math::Vector4;
  using bQuaternion = Math::Vector4;
  using bMatrix4    = Math::Matrix4;
  struct CareerPursuitScores;
  struct CareerSettings;
  struct CarPaintPart;
  struct CarPaintPartRecord;
  struct CarPaintPartRecordPacked;
  struct CarPart;
  struct CarRenderInfo;
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
  struct DLCommandObject;
  struct EmitterGroup;
  struct eLightMaterial;
  struct eModel;
  struct eSolid;
  struct eReplacementTextures;
  struct EventSequencer;
  struct FECareerRecord;
  struct FECarRecord;
  struct FECustomizationRecord;
  struct FEImpoundData;
  struct FEInfractionsData;
  struct FEKeyboardSettings;
  struct FEngHud;
  struct FEObject;
  struct FEPackage;
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
  using Jukebox = UTL::FixedVector<JukeboxEntry, 40, 16>;
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
  struct SelectCarCameraMover;
  struct SimpleChopper;
  struct SimCollisionMap;
  struct SimSurface;
  struct Smackable;
  struct SmackableParams;
  struct TextureInfo;
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
  enum class DriverClass : std::uint32_t { Human, Traffic, Cop, Racer, None, NIS, Remote, RemoteRacer, Ghost, Hub };
  enum class DriverStyle : std::uint32_t { Racing, Drag, Drift, HighSpeed, Traffic, None = UINT32_MAX };
  enum class eControllerConfig : std::uint8_t { Config1, Config2, MouseWheel };
  enum class eDecalType : std::uint32_t {
    SkidConcrete,
    SkidDirt,
    SkidGrass,
    SkidSand,
    ScrapeMetal,
    ScrapePlastic,
    ScrapeWood,
    ScrapeConcrete,
    None = UINT32_MAX
  };
  enum class eDriverAssistLevel : std::uint8_t { Family, Racer, King };
  enum class eFECarsBlueprintsOptionID : std::uint32_t {
    Customize,
    Summary,
    Delete,
    Reset,
    SetActive,
    ApplyToCar,
    PurchaseCar
  };
  enum class eHandlingMode : std::uint8_t { Classic, Extreme };
  enum class eMenuSoundTriggers : std::uint32_t {
    NONE                             = UINT32_MAX,
    COMMON_UP                        = 0x0,
    COMMON_DOWN                      = 0x1,
    COMMON_SELECT                    = 0x2,
    COMMON_BACK                      = 0x3,
    COMMON_LEFT_AND_RIGHT            = 0x4,
    COMMON_WRONG                     = 0x5,
    COMMON_TRIGGER_LEFT              = 0x6,
    COMMON_TRIGGER_RIGHT             = 0x7,
    COMMON_DLGBOX_APPEAR             = 0x8,
    COMMON_DLGBOX_DISAPPEAR          = 0x9,
    COMMON_DLGBOX_DOWN               = 0xA,
    COMMON_DLGBOX_LEFT               = 0xB,
    COMMON_DLGBOX_RIGHT              = 0xC,
    COMMON_DLGBOX_UP                 = 0xD,
    ENTER_TRIGGER                    = 0x18,
    COMMON_ExpandingTree_Left_BASIC  = 0x1F,
    COMMON_ExpandingTree_Left_P0     = 0x20,
    COMMON_ExpandingTree_Left_P1     = 0x21,
    COMMON_ExpandingTree_Left_P2     = 0x22,
    COMMON_ExpandingTree_Left_P3     = 0x23,
    COMMON_ExpandingTree_Left_P4     = 0x24,
    COMMON_ExpandingTree_Left_P5     = 0x25,
    COMMON_ExpandingTree_Left_P6     = 0x26,
    COMMON_ExpandingTree_Left_P7     = 0x27,
    COMMON_ExpandingTree_Left_P8     = 0x28,
    COMMON_ExpandingTree_Left_P9     = 0x29,
    COMMON_ExpandingTree_Right_BASIC = 0x2A,
    COMMON_ExpandingTree_Right_P0    = 0x2B,
    COMMON_ExpandingTree_Right_P1    = 0x2C,
    COMMON_ExpandingTree_Right_P2    = 0x2D,
    COMMON_ExpandingTree_Right_P3    = 0x2E,
    COMMON_ExpandingTree_Right_P4    = 0x2F,
    COMMON_ExpandingTree_Right_P5    = 0x30,
    COMMON_ExpandingTree_Right_P6    = 0x31,
    COMMON_ExpandingTree_Right_P7    = 0x32,
    COMMON_ExpandingTree_Right_P8    = 0x33,
    COMMON_ExpandingTree_Right_P9    = 0x34,
    COMMON_e3_Transition             = 0x49,
    COMMON_e3_Move_Left              = 0x4A,
    COMMON_LIGHT_TREE_TICK           = 0x4C,
    COMMON_LIGHT_TREE_GO             = 0x4D,
    COMMON_OPTION_SLIDER_TICK        = 0x4E,
    HUD_RACE_COMPLETE_IN             = 0x4F,
    HUD_COUNTDOWN                    = 0x50,
    HUD_COUNTDOWN_GO                 = 0x53,
    HUD_MATCHUP_TEXT_IN              = 0x54,
    HUD_MATCHUP_TEXT_OUT             = 0x55,
    HUD_STUTTER_TEXT_OVERLAY_IN      = 0x56,
    HUD_STUTTER_TEXT_OVERLAY_OUT     = 0x57,
    HUD_BURNOUT_RATING_IN            = 0x58,
    HUD_BURNOUT_RATING_OUT           = 0x59,
    HUD_DRAG_COUNTDOWN               = 0x5C,
    HUD_DRAG_COUNTDOWN_GO            = 0x5D,
    COMMON_CHYRON_IN                 = 0x5E,
    COMMON_CHYRON_OUT                = 0x5F,
    COMMON_CHYRON_NOTIFICATION       = 0x60,
    HUD_COUNTDOWN_1                  = 0x61,
    HUD_COUNTDOWN_2                  = 0x62,
    HUD_COUNTDOWN_3                  = 0x63,
    COMMON_MUSIC_CHYRON_IN           = 0x64,
    COMMON_MUSIC_CHYRON_OUT          = 0x65,
    COMMON_LARGE_MENU_IN             = 0x66,
    COMMON_LARGE_MENU_OUT            = 0x67,
    COMMON_PAUSE_MENU_IN             = 0x68,
    COMMON_PAUSE_MENU_OUT            = 0x69,
    COMMON_YOU_WON                   = 0x6A,
    COMMON_MAX_NUM                   = 0xC7,
    MAIN_UP_AND_DOWN                 = 0xC8,
    MAIN_LEFT_AND_RIGHT              = 0xC9,
    MAIN_SCROLL_LEFT                 = 0xCA,
    MAIN_SCROLL_RIGHT                = 0xCB,
    MAIN_SELECT                      = 0xCC,
    MAIN_BACK                        = 0xCD,
    MAIN_WRONG                       = 0xCF,
    MAIN_TRANSITION_IN               = 0xD0,
    MAIN_TRANSITION_OUT              = 0xD1,
    MAIN_DLGBOX_IN                   = 0xD2,
    MAIN_DLGBOX_OUT                  = 0xD3,
    UGNEW_KBTYPE                     = 0xE0,
    UGNEW_ENTER                      = 0xE1,
    UGNEW_DELETE                     = 0xE2,
    MAIN_END_OF_LIST                 = 0xE4,
    MAIN_KBCURSOR_UPDOWN             = 0xE6,
    MAIN_KBCURSOR_LEFTRIGHT          = 0xE7,
    MAIN_TRANSITION_ANIMATION_1      = 0xE8,
    MAIN_TRANSITION_ANIMATION_2      = 0xE9,
    MAIN_TRANSITION_ANIMATION_3      = 0xEA,
    MAIN_TRANSITION_ANIMATION_4      = 0xEB,
    MAIN_TRANSITION_ANIMATION_5      = 0xEC,
    MAIN_TRANSITION_ANIMATION_6      = 0xED,
    MAIN_TRANSITION_ANIMATION_7      = 0xEE,
    MAIN_TRANSITION_ANIMATION_8      = 0xEF,
    MAIN_TRANSITION_ANIMATION_9      = 0xF0,
    MAIN_CUST_INST_PAINT             = 0x132,
    MAIN_CUST_PAINT_COLOUR_LEFT      = 0x133,
    MAIN_CUST_PAINT_COLOUR_RIGHT     = 0x134,
    MAIN_CUST_PAINT_COLOUR_UP        = 0x135,
    MAIN_CUST_PAINT_COLOUR_DOWN      = 0x136,
    MAIN_CUST_VINYL_INSTALL          = 0x137,
    CUST_INST_EXHAUST                = 0x13C,
    CUST_INST_GENERIC                = 0x13D,
    CUST_INST_TURBO                  = 0x13E,
    CUST_INST_NOS                    = 0x13F,
    CUST_INST_TRANSMISSION           = 0x140,
    CUST_INST_TIRES                  = 0x141,
    EA_MSGR_OPEN                     = 0x142,
    EA_MSGR_LOGOFF                   = 0x143,
    EA_MSGR_CHAT_REQ                 = 0x144,
    EA_MSGR_MAIL_RECEIVE             = 0x145,
    EA_MSGR_CHALLENGE_REQ            = 0x146,
    MAIN_MENU_ENTER                  = 0x15A,
    MAIN_MENU_EXIT                   = 0x15B,
    MAIN_SUB_ENTER                   = 0x15C,
    MAIN_SUB_EXIT                    = 0x15D,
    MAIN_MAP_AREA_SELECT             = 0x15E,
    MAIN_MAP_MENU_APPEAR             = 0x15F,
    MAIN_MAP_MENU_DISAPPEAR          = 0x160,
    MAIN_MAP_MENU_NAV_UP             = 0x161,
    MAIN_MAP_MENU_NAV_DOWN           = 0x162,
    MAIN_MAP_MENU_NAV_LEFT           = 0x163,
    MAIN_MAP_MENU_NAV_RIGHT          = 0x164,
    MAIN_MAP_ZOOM_IN                 = 0x165,
    MAIN_MAP_ZOOM_OUT                = 0x166,
    MAIN_KEYBOARD_ACCEPT             = 0x167,
    MAIN_KEYBOARD_BACK               = 0x168,
    MAIN_KEYBOARD_NAV                = 0x169,
    MAIN_KEYBOARD_SELECT             = 0x16A,
    MAIN_MAP_MENU_NAV_LEFTRIGHT      = 0x16B,
    MAIN_MAP_MENU_NAV_UPDOWN         = 0x16C,
    MAIN_FEICECAM_CAM1               = 0x170,
    MAIN_FEICECAM_CAM1BCK            = 0x171,
    MAIN_FEICECAM_CAM2               = 0x172,
    MAIN_FEICECAM_CAM2BCK            = 0x173,
    MAIN_FEICECAM_CAM3               = 0x174,
    MAIN_FEICECAM_CAM3BCK            = 0x175,
    MAIN_FEICECAM_CAM4               = 0x176,
    MAIN_FEICECAM_CAM4BCK            = 0x177,
    MAIN_FEICECAM_CAM5               = 0x178,
    MAIN_FEICECAM_CAM5BCK            = 0x179,
    MAIN_FEICECAM_CAM6               = 0x17A,
    MAIN_FEICECAM_CAM6BCK            = 0x17B,
    MAIN_FEICECAM_CAM7               = 0x17C,
    MAIN_FEICECAM_CAM7BCK            = 0x17D,
    MAIN_FEICECAM_CAM8               = 0x17E,
    MAIN_FEICECAM_CAM8BCK            = 0x17F,
    MAIN_FEICECAM_CAM9               = 0x180,
    MAIN_FEICECAM_CAM9BCK            = 0x181,
    MAIN_FEICECAM_CAM10              = 0x182,
    MAIN_FEICECAM_CAM10BCK           = 0x183,
    MAIN_SWIRLING_MENU_INTRO         = 0x184,
    MAIN_UNLOCK                      = 0x185,
    FRONTEND_MAX_NUM                 = 0x18F,
    COMMON_DRIFT_NICE                = 0x190,
    COMMON_DRIFT_GOOD                = 0x190,
    COMMON_DRIFT_AWESOME             = 0x191,
    COMMON_DRIFT_AMAZING             = 0x191,
    COMMON_DRIFT_GREAT               = 0x191,
    COMMON_DRIFT_OUTRAGEOUS          = 0x192,
    COMMON_DRIFT_MULTIPLIER          = 0x193,
    COMMON_DRIFT_DRIFT_ENDED         = 0x194,
    COMMON_DRIFT_PERFECT_ENTRY       = 0x195
  };
  enum class eMiniMapModes : std::uint8_t { Off, Static };
  enum class ePlayerSettingsCameras : std::uint8_t { Bumper, Hood, Close, Far, Drift, Staging, Pause, CarSlot, Tuning };
  enum class eSensitivitySetting : std::uint8_t { Low, Medium, High };
  enum class eSkyStyle : std::uint32_t {
    None,
    Style1,
    Style2,
    Style3,
    Style4,
    Style5,
    Style6,
    Style7,
    Style8,
    Style9,
    Style10,
    Style11,
    Style12,
    Style13,
    Style14,
    Style15
  };
  enum class eSplitTimeTypes : std::uint8_t { Off, RaceLeader, LapRecord, BestLap, LastLap };
  enum class eTransmissionOverride : std::uint32_t { None, Manual, ManualClutch, Automatic };
  enum class eTransmissionType : std::uint8_t { Automatic, Manual, ManualClutch };
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
  enum class eWheelDamage : std::uint32_t { None, Bent };
  enum class eWingmanRole : std::uint32_t { Unknown, Leader, Blocky, Pathy, Speedy };
  enum class eWorldMapView : std::uint8_t { Navigation, Pursuit };
  enum class eWorldMapZoomLevels : std::uint8_t { All, Level1, Level2, Level4 };
  enum class FEKeyTrack_Indices : std::uint32_t {
    Color,
    Pivot,
    Position,
    Rotation,
    Size,
    UpperLeft,
    LowerRight,
    FrameNumber,
    Color1,
    Color2,
    Color3,
    Color4
  };
  enum class KitType : std::int32_t {
    Base,
    Stock,
    Autosculpt,
    Widebody,
  };

  enum class SurfaceSFX : std::uint32_t {
    None         = 0,
    LightCrack   = 1,
    TarStrip     = 3,
    RoadsidePath = 5,
    HeavyPath    = 6,
    Dirt         = 7
  };
  enum class TireCondition : std::uint32_t { Grip, Wet, Flat, Drift, Drag };

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

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(eVehicleParamFlags)
  DEFINE_ENUM_FLAG_OPERATORS(CollisionGeometry::BoundFlags)
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
