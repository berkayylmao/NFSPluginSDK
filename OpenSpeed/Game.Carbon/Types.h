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

#include <OpenSpeed/Game.Carbon/Types/Math.h>
#include <OpenSpeed/Game.Carbon/Types/UMath.h>

namespace OpenSpeed::Carbon {
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
      struct Part;
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
  struct AISpawnManager;
  struct AISplinePath;
  struct AITarget;
  struct AIVehicle;
  struct AIVehicleCopCar;
  struct AIVehicleEmpty;
  struct AIVehicleHelicopter;
  struct AIVehicleHuman;
  struct AIVehiclePursuit;
  struct AIVehicleRacecar;
  struct AIVehicleTraffic;
  struct Attachments;
  struct AttributeSet;
  struct AttribVaultPackImage;
  struct AudioSettings;
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
  struct EmitterGroup;
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
  struct HeliSheetCoordinate;
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
  struct IAttributeable;
  struct IAudible;
  struct IBody;
  struct ICause;
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
  struct WCollider;
  struct WorldModel;
  struct WRoadNav;
  struct WTrigger;
  struct WWorldPos;

#pragma endregion

#pragma region Enums

  enum class CARPART_LOD : std::uint32_t { A, B, C, D, E, OFF = UINT32_MAX };
  enum class CarRenderUsage : std::uint32_t {
    Player,
    RemotePlayer,
    AIRacer,
    AICop,
    AITraffic,
    AIHeli,
    NISCar,
    Invalid
  };
  enum class CarType : std::uint32_t {
    PORSCHE_911TURBO,
    PORSCHE_CARRERAGT,
    DODGE_VIPER,
    MAZDA_RX8,
    FORD_MUSTANGGT,
    CHEVROLET_CAMARO,
    PONTIAC_GTO,
    MERCEDES_SLR,
    PORSCHE_997S,
    BMW_BMWM3GTRE46,
    LEXUS_IS300,
    HOLDEN_MONARO,
    PORSCHE_SL65,
    LOTUS_ELISE,
    FORD_FORDGT,
    MITSUBISHI_ECLIPSEGT,
    TOYOTA_SUPRA,
    MAZDA_RX7,
    LAMBORGHINI_MURCIELAGO,
    PORSCHE_CAYMANS,
    MERCEDES_CLK500,
    ASTONMARTIN_DB9,
    LAMBORGHINI_GALLARDO,
    RENAULT_CLIO,
    MITSUBISHI_ECLIPSE,
    MITSUBISHI_LANCEREVO9,
    TOYOTA_COROLLA,
    PLYMOUTH_CUDA,
    CHRYSLER_300C,
    TOYOTA_MR2,
    MAZDA_MAZDA3SPORT,
    FORD_MUSTANGSHLBYN,
    NISSAN_350Z,
    NISSAN_240SX,
    INFINITI_G35,
    NISSAN_SKYLINE,
    SUBARU_IMPREZAWRXSTI,
    VOLKSWAGEN_R32,
    DODGE_CHARGER69,
    PORSCHE_997TT,
    ALFAROMEO_BRERA,
    PORSCHE_997GT3RS,
    CHEVROLET_CORVETTEZ06,
    DODGE_CHALLENGERN,
    AUDI_R8,
    DODGE_CHALLENGER71,
    DODGE_CHEVELLE,
    LOTUS_EUROPA,
    MAZDA_MAZDASPEED3,
    CHEVROLET_CAMARON,
    JAGUAR_JAGUARXK,
    DODGE_CHARGER06,
    KOENIGSEGG_CCX,
    PAGANI_ZONDA,
    LAMBORGHINI_MURCIELAGO640,
    PLYMOUTH_ROADRUNNER,
    FORD_MUSTANGSHLBYO,
    GENERIC_SEMI,
    GENERIC_TRAILERA,
    GENERIC_TRAILERB,
    GENERIC_TRAFHA,
    GENERIC_TRAFSUVA,
    GENERIC_TRAF4DSEDB,
    GENERIC_TRAFFICCOUP,
    GENERIC_TRAF4DSEDA,
    GENERIC_TRAF4DSEDC,
    GENERIC_TRAFCAMPER,
    GENERIC_TRAFCEMTR,
    GENERIC_TRAFDMPTR,
    GENERIC_TRAFFIRE,
    GENERIC_TRAFGARB,
    GENERIC_TRAFMINIVAN,
    GENERIC_TRAFNEWS,
    GENERIC_TRAFPICKUPA,
    GENERIC_TRAFSTWAG,
    GENERIC_TRAFVANB,
    GENERIC_TRAFTAXI,
    GENERIC_TRAFCOURT,
    GENERIC_TRAFAMB,
    GENERIC_TRAILERLOG,
    GENERIC_TRAILERCON,
    GENERIC_TRAILERCRATE,
    GENERIC_TRAILERCMT,
    GENERIC_TRAILERBOX,
    GENERIC_COPMIDSIZE,
    GENERIC_COPHELI,
    GENERIC_COPMIDSIZEINT,
    GENERIC_COPSUV,
    GENERIC_COPSPORT,
    GENERIC_COPGHOST,
    GENERIC_COPSUVL,
    GENERIC_COPGTO,
    GENERIC_COPGTOGHOST,
    GENERIC_COPSPORTHENCH,
    GENERIC_COPSPORTGHOST,
    NONE = UINT32_MAX
  };
  enum class Difficulty : std::uint8_t { Easy, Medium, Hard };
  enum class DriverClass : std::uint32_t { Human, Traffic, Cop, Racer, None, NIS, Remote };
  enum class DriverStyle : std::uint32_t { Racing, Drag };
  enum class eCareerUpgradeLevels : std::uint32_t {
    LevelStock,
    Level1,
    Level2,
    Level3,
    LevelUnique,
    LevelUnspecified = UINT32_MAX
  };
  enum class eVehicleParamFlags : std::uint32_t {
    Spooled         = 1 << 0,
    SnapToGround    = 1 << 1,
    NosRemoved      = 1 << 2,
    CalcPerformance = 1 << 3,
    NosAdded        = 1 << 4
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
  DEFINE_ENUM_FLAG_OPERATORS(eVehicleParamFlags)
  DEFINE_ENUM_FLAG_OPERATORS(VehicleFX::LightID)
#endif

#pragma endregion
}  // namespace OpenSpeed::Carbon
