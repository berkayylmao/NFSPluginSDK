// clang-format off
//
//    BSD 3-Clause License
//    Copyright (c) 2022, Berkay Yigit (berkayylmao) <mail@berkay.link>
//    All rights reserved.
//
//    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//    AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//    DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    You should have received a copy of the BSD 3-Clause License along with
//    this program. If not, see <https://opensource.org/licenses/BSD-3-Clause/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_H
#pragma once

#include <cstdint>      // integer types
#include <type_traits>  // enable_if_t, is_base_of_v
#if defined(_WIN32)
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

#include <NFSPluginSDK/Shared/AllShared.h>
#include <NFSPluginSDK/Game.MW05/Types/UMath.h>

namespace NFSPluginSDK::MW05 {
#pragma region Forward declarations
  namespace Attrib {
    struct StringKey {
      std::uint64_t mHash64;
      std::uint32_t mHash32;
      const char*   mString;

      StringKey(std::uint64_t hash64, std::uint32_t hash32, const char* str) :
          mHash64(hash64), mHash32(hash32), mString(str) {}
      StringKey() : StringKey(0ui64, 0ui32, nullptr) {}
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
      return reinterpret_cast<std::uint32_t(__cdecl*)(const char*)>(0x454640)(name);
    }

    static inline Collection* FindCollection(std::uint32_t classKey, std::uint32_t collectionKey) {
      return reinterpret_cast<Collection*(__cdecl*)(std::uint32_t, std::uint32_t)>(0x455FD0)(classKey, collectionKey);
    }
    static inline Collection* FindCollection(const char* className, std::uint32_t collectionKey) {
      return FindCollection(StringToKey(className), collectionKey);
    }
    static inline Collection* FindCollection(const char* className, const char* collectionName) {
      return FindCollection(StringToKey(className), StringToKey(collectionName));
    }
  }  // namespace Attrib

  namespace CARP {
    enum class TriggerTypes : std::uint32_t { Undefined, Standard };
    enum class TriggerFlags : std::uint32_t {
      Enabled             = 1 << 0,
      OneShot             = 1 << 1,
      PlayerActivated     = 1 << 2,
      AIActivated         = 1 << 3,
      ExplosionActivated  = 1 << 4,
      VehicleActivated    = 1 << 5,
      BodyActivated       = 1 << 6,
      TimeActivated       = 1 << 7,
      UnManaged           = 1 << 8,
      PathAnimActivated   = 1 << 9,
      Silencable          = 1 << 10,
      UseEntry            = 1 << 11,
      NonUpYVec           = 1 << 12,
      PlayerCharActivated = 1 << 13,
      DebugOnly           = 1 << 14,
      FireOnExit          = 1 << 15,
      HumanActivated      = 1 << 16,
      CopActivated        = 1 << 17,
      FireOnEntry         = 1 << 18
    };
#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
    DEFINE_ENUM_FLAG_OPERATORS(TriggerFlags)
#endif

    struct EventList;
    struct EventStaticData;
    struct Trigger;
  }  // namespace CARP

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

  namespace Math {
    using Vector2 = NFSPluginSDK::Vector2;
    using Vector3 = NFSPluginSDK::Vector3;
    using Vector4 = NFSPluginSDK::Vector4;
    using Matrix4 = NFSPluginSDK::Matrix4;
  }  // namespace Math

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

  namespace WCollisionMgr {
    struct WorldCollisionInfo;
  }  // namespace WCollisionMgr

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
  using bVector2    = Math::Vector2;
  using bVector3    = Math::Vector3;
  using bVector4    = Math::Vector4;
  using bQuaternion = Math::Vector4;
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
  struct FEImage;
  struct FEImpoundData;
  struct FEInfractionsData;
  struct FEKeyboardSettings;
  struct FEMinList;
  struct FEMinNode;
  struct FEMultiImage;
  struct FEngHud;
  struct FEScript;
  struct FEObject;
  struct FEPlayerCarDB;
  struct FERenderObject;
  using FEVector2    = Math::Vector2;
  using FEVector3    = Math::Vector3;
  using FEVector4    = Math::Vector4;
  using FEQuaternion = Math::Vector4;
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
  using HACTIONQUEUE__ = std::uint32_t;
  using HACTIVITY__    = std::uint32_t;
  using HCAUSE__       = std::uint32_t;
  using HCOLPRIM__     = std::uint32_t;
  using HMODEL__       = std::uint32_t;
  using HSIMABLE__     = std::uint32_t;
  using HSIMPROFILE__  = std::uint32_t;
  using HSIMSERVICE__  = std::uint32_t;
  using HSIMTASK__     = std::uint32_t;
  struct HeliSheetCoordinate;
  struct HighScoresDatabase;
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
  struct MinimapItem;
  struct Minimap;
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
  struct TrackInfo;
  template <typename T, std::size_t N>
  struct UCircularQueue;
  struct UCrc32;
  struct UserProfile;
  struct VehicleBehavior;
  struct VehicleParams;
  struct VideoSettings;
  struct WCollider;
  struct WorldModel;
  struct WRoadNav;
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
    PORSCHE911TURBO,
    PORSCHECARRERAGT,
    VIPER,
    COPMIDSIZE,
    COPHELI,
    RX8,
    IMPREZAWRX,
    LANCEREVO8,
    MUSTANGGT,
    CAMARO,
    SEMI,
    GTO,
    SLR,
    TRAILERA,
    TRAILERB,
    CORVETTE,
    TRAFHA,
    TRAFSUVA,
    TRAF4DSEDB,
    TRAFFICCOUP,
    TT,
    A3,
    BMWM3GTR,
    SL500,
    PORSCHE997S,
    TRAF4DSEDA,
    TRAF4DSEDC,
    TRAFCAMPER,
    TRAFCEMTR,
    TRAFDMPTR,
    TRAFFIRE,
    TRAFGARB,
    TRAFMINIVAN,
    TRAFNEWS,
    TRAFPICKUPA,
    TRAFSTWAG,
    TRAFVANB,
    TRAFTAXI,
    TRAFCOURT,
    TRAFPIZZA,
    PORSCHE911GT2,
    BMWM3GTRE46,
    TRAFAMB,
    TRAILERLOG,
    TRAILERCON,
    TRAILERCRATE,
    TRAILERCMT,
    IS300,
    MONARO,
    SL65,
    ELISE,
    COPMIDSIZEINT,
    FORDGT,
    ECLIPSEGT,
    SUPRA,
    CORVETTEC6R,
    RX7,
    COPSUV,
    RX8SPEEDT,
    MURCIELAGO,
    A4,
    COPSPORT,
    GTI,
    CAYMANS,
    CLK500,
    CTS,
    DB9,
    GALLARDO,
    COBALTSS,
    BMWM3,
    CLIO,
    COPGHOST,
    COPSUVL,
    COPGTO,
    PUNTO,
    COPGTOGHOST,
    COPSPORTHENCH,
    COPSPORTGHOST,
    CEMTR,
    GARB,
    PIZZA,
    TAXI,
    MINIVAN,
    PICKUPA,
    NONE = UINT32_MAX
  };
  enum class CarUsageType : std::uint32_t { Racing, Cop, Traffic, Wheels, Universal };
  enum class DriverClass : std::uint32_t { Human, Traffic, Cop, Racer, None, NIS, Remote };
  enum class DriverStyle : std::uint32_t { Racing, Drag };
  enum class eAIDifficultyModifier : std::uint8_t { Easy, SomewhatEasy, Normal };
  enum class eCareerUpgradeLevels : std::uint32_t {
    LevelStock,
    Level1,
    Level2,
    Level3,
    LevelUnique,
    LevelUnspecified = UINT32_MAX
  };
  enum class eCrossState : std::uint32_t { Available, Spawned, Disabled };
  enum class eControllerConfig : std::uint32_t { MinConfig, Config1, Config2, Config3, Config4, MaxConfig, Config5 };
  enum class eDriftType : std::uint32_t { VsAI, Downhill, Team };
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
  enum class eLoadSaveGame : std::uint32_t { Load, Save };
  enum class eLocationName : std::uint32_t {
    UpperClass,
    CityCore,
    SuburbanHills,
    IndustrialPark,
    Airport,
    ModeSpecific
  };
  enum class eMiniMapModes : std::uint8_t { Static, Rotate, Off };
  enum class eOpponentStrength : std::uint8_t { Low, Medium, High };
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
  enum class ePlayerList : std::uint32_t { All, Local, Remote };
  enum class ePlayerSettingsCameras : std::uint32_t {
    Bumper,
    Hood,
    Close,
    Far,
    SuperFar,
    Drift,
    Pursuit,
    Invalid = UINT32_MAX
  };
  enum class ePostRaceOptions : std::uint32_t { NextRace, Quit, RestartRace, RestartEvent };
  enum class ePursuitStatus : std::uint32_t { InitialChase, BackupRequested, Cooldown, Busted, Evaded };
  enum class eSplitTimeTypes : std::uint8_t { RaceLeader, LapRecord, BestLap, LastLap, Off };
  enum class eTrackDifficulty : std::uint32_t { Easy, Medium, Hard };
  enum class eTrackDirection : std::uint8_t { Forward, Backward };
  enum class eTransmissionType : std::uint8_t { Automatic, Manual, Sport, ManualClutch };
  enum class eVehicleParamFlags : std::uint32_t {
    None,
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
  enum class eWorldMapView : std::uint8_t { Navigation, Event, Race, Pursuit };
  enum class JunkmanParts : std::uint32_t {
    None         = 0,
    Tires        = 1 << 0,
    Brakes       = 1 << 1,
    Chassis      = 1 << 2,
    Transmission = 1 << 3,
    Engine       = 1 << 4,
    Induction    = 1 << 5,
    NOS          = 1 << 6,
    All = static_cast<std::uint32_t>(Tires) | static_cast<std::uint32_t>(Brakes) | static_cast<std::uint32_t>(Chassis) |
          static_cast<std::uint32_t>(Transmission) | static_cast<std::uint32_t>(Engine) |
          static_cast<std::uint32_t>(Induction) | static_cast<std::uint32_t>(NOS)
  };
  enum class Region : std::uint8_t { College, Coastal, City, None = UINT8_MAX };

  namespace DamageZone {
    enum class ID : std::uint32_t { Front, Rear, Left, Right, LeftFront, RightFront, LeftRear, RightRear, Top, Bottom };
    struct Info;
  }  // namespace DamageZone

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(eFEGameModes)
  DEFINE_ENUM_FLAG_OPERATORS(eVehicleParamFlags)
  DEFINE_ENUM_FLAG_OPERATORS(JunkmanParts)
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
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_H
