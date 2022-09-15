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

#ifndef OPENSPEED_GAME_CARBON_TYPES_H
#define OPENSPEED_GAME_CARBON_TYPES_H
#pragma once

#include <cstdint>      // integer types
#include <type_traits>  // enable_if_t, is_base_of_v
#if defined(_WIN32)
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

#include <OpenSpeed/Shared/AllShared.h>

namespace OpenSpeed::Carbon {
#pragma region Forward declarations
  namespace Attrib {
    struct StringKey {
      std::uint32_t mHash32;
      const char*   mString;

      StringKey(std::uint32_t hash32, const char* str) : mHash32(hash32), mString(str) {}
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
      return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x4639D0)(name);
    }

    static inline Collection* FindCollection(std::uint32_t classKey, std::uint32_t collectionKey) {
      return reinterpret_cast<Collection*(__cdecl*)(std::uint32_t, std::uint32_t)>(0x465930)(classKey, collectionKey);
    }
    static inline Collection* FindCollection(const char* className, std::uint32_t collectionKey) {
      return FindCollection(StringToKey(className), collectionKey);
    }
    static inline Collection* FindCollection(const char* className, const char* collectionName) {
      return FindCollection(StringToKey(className), StringToKey(collectionName));
    }
  }  // namespace Attrib

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
  using ActionRef = ActionData*;
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
  struct WRoadNavInfluence;
  struct WTrigger;
  struct WWorldPos;

#pragma endregion

#pragma region Enums

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
  enum class DriverStyle : std::uint32_t { Racing, Drag, Drift };
  enum class eCareerUpgradeLevels : std::uint32_t {
    LevelStock,
    Level1,
    Level2,
    Level3,
    LevelUnique,
    LevelUnspecified = UINT32_MAX
  };
  enum class eVehicleParamFlags : std::uint32_t {
    None,
    Spooled         = 1 << 0,
    SnapToGround    = 1 << 1,
    NosRemoved      = 1 << 2,
    CalcPerformance = 1 << 3,
    NosAdded        = 1 << 4
  };
  enum class eWingmanRole : std::uint32_t { Unknown, Leader, Blocky, Pathy, Speedy };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(eVehicleParamFlags)
#endif

#pragma endregion
}  // namespace OpenSpeed::Carbon

#endif  // OPENSPEED_GAME_CARBON_TYPES_H
