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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_H
#pragma once

#include <cstdint>      // integer types
#include <type_traits>  // enable_if_t, is_base_of_v
#if defined(_WIN32)
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

#include <NFSPluginSDK/Shared/AllShared.h>

namespace NFSPluginSDK::ProStreet {
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
    enum class RaceMode : std::uint32_t { Grip, Drift, Drag, Speed, Invalid = UINT32_MAX };
    enum class DriveTrain : std::uint32_t { FWD, RWD, AWD, Invalid = UINT32_MAX };
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

  namespace FECust {
    enum class VinylAreas : std::uint32_t { Colour0 = 0x0, Colour1 = 0x1, Colour2 = 0x2, Colour3 = 0x3 };
    enum class SelectableRegion : std::uint32_t {
      Front,
      Rear,
      Side,
      FrontBumper = Front,
      RearBumper  = Rear,
      Skirt       = Side,
      FrontWheel  = Front,
      RearWheel   = Rear,
      FrontTire   = Front,
      RearTire    = Rear,
    };
  }  // namespace FECust

  namespace Hermes {
    using _h_HHANDLER__ = std::uint32_t;
  }

  namespace Hub {
    enum class OrgBody : std::uint32_t {
      Nitrocide,
      NoiseBomb,
      GEffect,
      RogueSpeed,
      SuperPromotion,
      ReactTeam,
      BattleMachine
    };
  }

  namespace Math {
    using AxlePair      = NFSPluginSDK::AxlePair;
    using Curve         = NFSPluginSDK::Curve;
    using VariableArray = NFSPluginSDK::VariableArray;
    using Vector2       = NFSPluginSDK::Vector2;
    using Vector3       = NFSPluginSDK::Vector3;
    using Vector4       = NFSPluginSDK::Vector4;
    using Matrix4       = NFSPluginSDK::Matrix4;

  }  // namespace Math
  namespace UMath {
    using Vector2 = NFSPluginSDK::UVector2;
    using Vector3 = NFSPluginSDK::UVector3;
    using Vector4 = NFSPluginSDK::UVector4;
    using Matrix4 = NFSPluginSDK::UMatrix4;
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

  struct AcidEffect;
  struct AcidEmitter;
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
  struct ArrayDatum;
  struct ArrayScroller;
  struct ArraySlot;
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
  struct FEAnimMenu;
  struct FEAnimMenuLevel;
  struct FECareerRecord;
  struct FECarRecord;
  struct FECustomizationRecord;
  struct FEHubAnimController;
  struct FEImage;
  struct FEImpoundData;
  struct FEInfractionsData;
  struct FEKeyboardSettings;
  struct FEMapHub;
  struct FEMapStreamer;
  struct FEMapTier;
  struct FEngHud;
  struct FEObject;
  struct FEPackage;
  struct FEPlayerCarDB;
  struct FEString;
  struct FinishedRaceStatsEntry;
  struct FloatSpring;
  struct GameplaySettings;
  struct GActiveHubSaveData;
  struct GActivity;
  struct GCareer;
  struct GCareerElement;
  struct GCharacter;
  struct GDamageometer;
  struct GenericMessage;
  struct GEventTimer;
  struct GHub;
  struct GHubSimHelper;
  struct GHubWriter;
  struct GIcon;
  struct GIOpponent;
  struct GManager;
  struct GMilestone;
  struct GObjectBlock;
  struct GProgressionActivityWrapper;
  struct GProStreetGame;
  struct GRaceBin;
  struct GRaceIndexData;
  struct GRaceParameters;
  struct GRacerInfo;
  template <typename T>
  struct Grid;
  struct GroundSupportRequest;
  struct GRuntimeInstance;
  struct GSpeedTrap;
  struct GTier;
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
  struct HeavySupport;
  struct HighScoresDatabase;
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
  struct LeaderSupport;
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
  struct ResourceFile;
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
  struct WRoadNav;
  struct WRoadNavInfluence;
  struct WTrigger;
  struct WWorldPos;

#pragma endregion

#pragma region Enums

  enum class ActionID : std::uint32_t {
    NULL_ACTION,
    GAMEACTION_STEERLEFT,
    GAMEACTION_STEERRIGHT,
    GAMEACTION_OVERSTEER,
    GAMEACTION_OVERSTEERLEFT,
    GAMEACTION_OVERSTEERRIGHT,
    GAMEACTION_TURNLEFT,
    GAMEACTION_TURNRIGHT,
    GAMEACTION_GAS,
    GAMEACTION_GAS_SLOTCAR,
    GAMEACTION_BRAKE,
    GAMEACTION_HANDBRAKE,
    GAMEACTION_GAMEBREAKER,
    GAMEACTION_SHIFTUP,
    GAMEACTION_SHIFTDOWN,
    GAMEACTION_SHIFTFIRST,
    GAMEACTION_SHIFTSECOND,
    GAMEACTION_SHIFTTHIRD,
    GAMEACTION_SHIFTFOURTH,
    GAMEACTION_SHIFTFIFTH,
    GAMEACTION_SHIFTSIXTH,
    GAMEACTION_SHIFTNEUTRAL,
    GAMEACTION_SHIFTREVERSE,
    GAMEACTION_NOS,
    GAMEACTION_RESET,
    GAMEACTION_CREWAGGRESSIVE,
    GAMEACTION_CREWDEFENSIVE,
    GAMEACTION_CREWDEFAULT,
    GAMEACTION_CREWSPEED,
    GAMEACTION_FORWARD,
    GAMEACTION_BACK,
    GAMEACTION_JUMP,
    GAMEACTION_DEBUGHUMAN1,
    GAMEACTION_DEBUGHUMAN2,
    GAMEACTION_DEBUGHUMAN3,
    GAMEACTION_DEBUGHUMAN4,
    GAMEACTION_CLUTCH,
    GAMEACTION_CLUTCH_KICK,
    CAMERAACTION_CHANGE,
    CAMERAACTION_DEBUG,
    CAMERAACTION_ENABLE_ICE,
    CAMERAACTION_LOOKBACK,
    CAMERAACTION_PULLBACK,
    CAMERAACTION_ROT_LEFT,
    CAMERAACTION_ROT_RIGHT,
    CAMERAACTION_360,
    FRONTENDACTION_UP,
    FRONTENDACTION_DOWN,
    FRONTENDACTION_LEFT,
    FRONTENDACTION_RIGHT,
    FRONTENDACTION_RUP,
    FRONTENDACTION_RDOWN,
    FRONTENDACTION_RLEFT,
    FRONTENDACTION_RRIGHT,
    FRONTENDACTION_ACCEPT,
    FRONTENDACTION_CANCEL,
    FRONTENDACTION_CANCEL_ALT,
    FRONTENDACTION_START,
    FRONTENDACTION_BUTTON0,
    FRONTENDACTION_BUTTON1,
    FRONTENDACTION_BUTTON2,
    FRONTENDACTION_BUTTON3,
    FRONTENDACTION_BUTTON4,
    FRONTENDACTION_BUTTON5,
    FRONTENDACTION_LTRIGGER,
    FRONTENDACTION_RTRIGGER,
    HUDACTION_PAUSEREQUEST,
    HUDACTION_ENGAGE_EVENT,
    HUDACTION_PAD_LEFT,
    HUDACTION_PAD_DOWN,
    HUDACTION_PAD_RIGHT,
    HUDACTION_SKIPNIS,
    HUDACTION_NEXTSONG,
    HUDACTION_VOIPACTIVATION,
    HUDACTION_VOIPDEACTIVATION,
    HUDACTION_TOGGLE_LEADERBOARD,
    HUDACTION_TOGGLE_MINIMAP,
    HUDACTION_TOGGLE_BESTLINE,
    HUDACTION_TOGGLE_ARROWS,
    VOIPACTION_PUSHTOTALK,
    DEBUGACTION_MOVE_UP,
    DEBUGACTION_MOVE_DOWN,
    DEBUGACTION_MOVE_LEFT,
    DEBUGACTION_MOVE_RIGHT,
    DEBUGACTION_MOVE_FORWARD,
    DEBUGACTION_MOVE_BACK,
    DEBUGACTION_MOVE_D_LEFT,
    DEBUGACTION_MOVE_D_RIGHT,
    DEBUGACTION_MOVE_D_FORWARD,
    DEBUGACTION_MOVE_D_BACK,
    DEBUGACTION_LOOK_UP,
    DEBUGACTION_LOOK_DOWN,
    DEBUGACTION_LOOK_LEFT,
    DEBUGACTION_LOOK_RIGHT,
    DEBUGACTION_LOOK_D_UP,
    DEBUGACTION_LOOK_D_DOWN,
    DEBUGACTION_LOOK_D_LEFT,
    DEBUGACTION_LOOK_D_RIGHT,
    DEBUGACTION_TURBO,
    DEBUGACTION_SUPER_TURBO,
    DEBUGACTION_DROPCAR,
    DEBUGACTION_TOGGLEAI,
    DEBUGACTION_TOGGLESIMSTEP,
    DEBUGACTION_SIMSTEP,
    DEBUGACTION_SCREENSHOT,
    DEBUGACTION_STOPRECORDPATH,
    DEBUGACTION_TOGGLECARCOLOUR,
    DEBUGACTION_TOGGLEDEMOCAMERAS,
    ICE_ACTION_START,
    ICE_ACTION_SELECT,
    ICE_ACTION_SOUTH,
    ICE_ACTION_SOUTH_PRESS,
    ICE_ACTION_NORTH,
    ICE_ACTION_NORTH_PRESS,
    ICE_ACTION_WEST,
    ICE_ACTION_WEST_PRESS,
    ICE_ACTION_EAST,
    ICE_ACTION_EAST_PRESS,
    ICE_ACTION_DOWN,
    ICE_ACTION_DOWN_PRESS,
    ICE_ACTION_UP,
    ICE_ACTION_UP_PRESS,
    ICE_ACTION_LEFT,
    ICE_ACTION_LEFT_PRESS,
    ICE_ACTION_RIGHT,
    ICE_ACTION_RIGHT_PRESS,
    ICE_ACTION_L1,
    ICE_ACTION_L1_PRESS,
    ICE_ACTION_R1,
    ICE_ACTION_R1_PRESS,
    ICE_ACTION_L2,
    ICE_ACTION_L2_PRESS,
    ICE_ACTION_R2,
    ICE_ACTION_R2_PRESS,
    ICE_ACTION_L3,
    ICE_ACTION_L3_PRESS,
    ICE_ACTION_R3,
    ICE_ACTION_R3_RELEASE,
    ICE_ACTION_LEFTSTICK_LEFT,
    ICE_ACTION_LEFTSTICK_RIGHT,
    ICE_ACTION_LEFTSTICK_DOWN,
    ICE_ACTION_LEFTSTICK_UP,
    ICE_ACTION_RIGHTSTICK_LEFT,
    ICE_ACTION_RIGHTSTICK_RIGHT,
    ICE_ACTION_RIGHTSTICK_DOWN,
    ICE_ACTION_RIGHTSTICK_UP,
    ACTION_EXITAPPLICATION,
    ACTION_PLUGGED,
    ACTION_UNPLUGGED,
    ACTION_FLUSH
  };
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
  enum class eDriftChainState : std::uint32_t { Running, HitAWall, SpanOut, TimeOut, OffBounds };
  enum class eDriftDirection : std::uint32_t { NotDrifting, Left, Right };
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
  enum class eLiveryID : std::uint32_t {
    NONE = UINT32_MAX,
    BM_ORGOPP_240SX01,
    BM_ORGOPP_GTI01,
    BM_ORGOPP_COROLLA01,
    BM_ORGOPP_COBALTSS01,
    BM_ORGOPP_GTO01,
    BM_ORGOPP_CHEVELLE01,
    SHOWDOWN_KING_DDAY,
    SMR_SDENTOUR_LANCEREVO9,
    NOISE_BOMB_DRIFTKING_RX7,
    NOISE_BOMB_DRIFTENT_COROLLA,
    MAX_ATTACK_SPEEDENT_SUPRA,
    MAX_ATTACK_SPEEDENT_CORVETTEZ06,
    DRAG_CHEVELLE,
    SMR_GRIPENT_RS4,
    NOISEBOMB_DRIFT_ENT_CAMARO,
    DDAY_PLAYER_240SX,
    DDAY_SHOWDOWN_KING_SKYLINE,
    OUTLAWS_DRAGKING_MUSTANGGT,
    LOST_PUPPET_240SX,
    DRIFT_240SX,
    GRIP_240SX,
    SPEED_240SX,
    DRIFT_350Z,
    GRIP_350Z,
    SPEED_350Z,
    DRAG_350Z,
    DRAG_CAMARO,
    SPEED_CAMARO,
    DRAG_CAMARON,
    SPEED_CAMARON,
    GRIP_CAMARO,
    DRAG_CHALLENGER71,
    SPEED_CHALLENGER71,
    DRAG_CHARGER69,
    SPEED_CHARGER69,
    SPEED_CHEVELLE,
    DRAG_CIVICHB,
    SPEED_CIVICHB,
    GRIP_CIVICHB,
    DRAG_CIVICSI,
    SPEED_CIVICSI,
    GRIP_CIVICSI,
    DRAG_COBALTSS,
    SPEED_COBALTSS,
    GRIP_COBALTSS,
    DRIFT_COROLLA,
    GRIP_COROLLA,
    DRAG_CORVETTE_67,
    GRIP_CORVETTE67,
    DRAG_COSWORTH,
    SPEED_COSWORTH,
    GRIP_COSWORTH,
    DRAG_CTSV,
    GRIP_CTSV,
    SPEED_CTSV,
    DRAG_CUDA,
    SPEED_CUDA,
    DRAG_ECLIPSE,
    SPEED_ECLIPSE,
    GRIP_ECLIPSE,
    NUMBER_FRONT,
    DRAG_FOCUSST,
    SPEED_FOCUSST,
    GRIP_FOCUSST,
    DRIFT_G35,
    DRAG_G35,
    SPEED_35,
    GRIP_35,
    DRAG_GTI,
    SPEED_GTI,
    GRIP_GTI,
    GRIP_997GT2,
    SPEED_997GT2,
    GRIP_997GT3,
    SPEED_997GT3,
    GRIP_GT3RS,
    SPEED_GT3RS,
    GRIP_997T,
    SPEED_997T,
    GRIP_BMWM3,
    SPEED_BMWM3,
    GRIP_E92,
    SPEED_E92,
    GRIP_BMWZ4,
    SPEED_BMWZ4,
    GRIP_CARRERAGT,
    SPEED_CARRERAGT,
    GRIP_CAYMANS,
    SPEED_CAYMANS,
    SPEED_ZONDA,
    DRAG_VIPER,
    DRIFT_VIPER,
    GRIP_VIPER,
    SPEED_VIPER,
    DRAG_SUPRA,
    DRIFT_SUPRA,
    GRIP_SUPRA,
    SPEED_SUPA,
    DRAG_SKYLINE,
    GRIP_SKYLINE,
    SPEED_SKYLINE,
    DRIFT_SILVIA,
    SPEED_SILVIA,
    GRIP_S4,
    SPEED_S4,
    GRIP_S3,
    SPEED_S3,
    DRAG_RX8,
    DRIFT_RX8,
    GRIP_RX8,
    SPEED_RX8,
    DRAG_RX7,
    DRIFT_RX7,
    GRIP_RX7,
    SPEED_RX7,
    DRAG_RSX,
    GRIP_RSX,
    DRAG_R32,
    GRIP_R32,
    SPEED_R32,
    GRIP_NSX,
    SPEED_NSX,
    DRAG_MUSTANGGT,
    DRIFT_MUSTANGGT,
    GRIP_MURCIELAGO,
    SPEED_MURCIELAGO,
    DRAG_MAZDA3,
    GRIP_MAZDA3,
    SPEED_MAZDA3,
    DRAG_LANCEREVOX,
    GRIP_LANCEREVOX,
    SPEED_LANCEREVOX,
    DRAG_LANCEREVO9,
    GRIP_LANCEREVO9,
    SPEED_LANCEREVO9,
    DRAG_IS350,
    GRIP_IS350,
    SPEED_IS350,
    DRAG_INTEGRATYPER,
    GRIP_INTEGRATYPER,
    SPEED_INTEGRATYPER,
    DRAG_IMPREZA,
    GRIP_IMPREZA,
    SPEED_IMPREZA,
    DRAG_GTO65,
    SPEED_GTO65,
    DRAG_GTO,
    DRIFT_GTO,
    GRIP_ELISE,
    SPEED_ELISE,
    GRIP_CORVETTE,
    SPEED_CORVETTE,
    DRAG_CORVETTEZ06,
    GRIP_CORVETTEZ06,
    SPEED_CORVETTEZ06,
    HONDA_1INCHPUNCH_CIVICHB,
    DODGE_8PACK_CHARGER69,
    ADVANCE_CUDA,
    AFTERMIX_CHALLENGER71,
    AFTERMIX_CHEVELLE,
    AFTERMIX_GTO,
    AFTERMIX_MUSTANGGT,
    APEXGLIDE_SILVIA,
    APEXGLIDE_SKYLINE,
    APEXGLIDE_LANCER,
    APEXGLIDE_CIVICHB,
    BOD_CHEVELLE,
    BOUNDDYNAMIC_LANCER,
    BOXCUT_GTO65,
    BOXCUT_SUPRA,
    BOXCUT_Z06,
    BOXCUT_ZONDA,
    CLIPZONE_FOCUSST,
    DRIFTCLUB_SUPRA,
    DRIFTINFANTRY_SILVIA,
    FIREEFFECT_CAMARO,
    FLOWONE_M3,
    FUTOU_STI,
    FULLMODE_997T,
    GRIPENEMY_S3,
    GRIPRUNNERS_997T,
    GRIPRUNNERS_COSWORTH,
    GRIPRUNNERS_S4,
    GRIPRUNNERS_E92,
    HANAMACHI_RX8,
    HASHIRIYA_ECLIPSE,
    JBRILLZ_Z06,
    KOBELSTONE_SILVIA,
    LATERFIRE_240SX,
    LATERALFIRE_G35,
    LIBERTY_SHELBY,
    MOSHI_350Z,
    NIGHTSTALK_GTO,
    RACEBOY_CAYMANS,
    RAPIDCITY_MURCIELAGO,
    RALYESS_S4,
    RUBBERDUX_SKYLINE,
    SOFTPUPPET_Z06,
    SQUADSIS_COROLLA,
    STUFFED_RX7,
    PORSCHE_3FFF_CAYMANS,
    NISSAN_8610_R32,
    TEAMGO_GTO,
    PHAT_350Z,
    THROTTLEBODY_VIPER,
    TOGUEUNION_350Z,
    TOGUEUNION_CAMARO,
    TOGUEUNION_COROLLA,
    TOGUEUNION_RX7,
    TOGUECOMISSION_EVOX,
    TUFFBLAST_CHALLENGER71,
    VELOCITY_VIPER,
    WAKABAYASHI_COROLLA,
    ZERO_RX7,
    ZIPSTYLE_SUPRA,
    DRAG_MUSTANGSHLBYN,
    DRIFT_MUSTANGSHLBYN,
    SPEED_MUSTANGSHLBYN,
    DRAG_MUSTANGSHLBYO,
    TEAMGO_MUSTANGSHLBYO,
    TEAMGO_CHARGER69,
    HASHIRIYA_240SX,
    SOFTPUPPET_CORVETTE,
    THROTTLEBODY_MUSTANGGT,
    TOUGECOM_LANCEREVO9,
    ZERO_RX8,
    RUBBERDUX_350Z,
    FUTOUBATTLE_COROLLA,
    BOD_CHARGER69,
    TEAMGO_CHALLENGER71,
    SPEED_TTN,
    GRIP_TTN,
    GRIP_INTEGRALS,
    DRIFT_IS350,
    DRIFT_NSX,
    SPEED_RS4,
    DRIFT_SOLSTICEGXP,
    ENERGIZER_VIPER,
    COKE_ZERO,
    COMMERCIAL_S15,
    COMMERCIAL_EVO9,
    LATERALFIRE_CIVICHB,
    PREAMP_FORDGT,
    WEB_TTN,
    WEB_RSX,
    WEB_IMPREZA,
    WEB_FOCUSST,
    GENERIC_CIVICHB,
    GENERIC_COBALTSS,
    GENERIC_CHEVELLE,
    GENERIC_350Z,
    GENERIC_GTI,
    GENERIC_IS350,
    GENERIC_BMWM3,
    GENERIC_G35,
    GENERIC_GTO,
    GENERIC_SILVIA,
    GENERIC_SOLSTICEGXP,
    GENERIC_SUPRA,
    GENERIC_CAYMANS,
    GENERIC_CORVETTEZ06,
    GENERIC_VIPER,
    GENERIC_SKYLINE,
    GENERIC_RS4,
    GENERIC_NSX,
    HUB_CIVICHB,
    HUB_COBALTSS,
    HUB_GTI,
    HUB_CHEVELLE,
    HUB_350Z,
    HUB_IS350,
    HUB_SILVIA,
    HUB_SOLSTICEGXP,
    HUB_SUPRA,
    HUB_BMWM3E92,
    HUB_G35,
    HUB_GTO,
    HUB_CAYMANS,
    HUB_CORVETTEZ06,
    HUB_VIPER,
    HUB_SKYLINE,
    HUB_NSX,
    HUB_RS4,
    RAYLESS_ELISE,
    RAYLESS_BMWM3E92,
    VELOCITY_CORVETTE67,
    TEAM8610_RSX,
    GRIPENEMY_S3B,
    TEAMGO_INTEGRALS,
    TEAM8610_INTEGRATYPER,
    TEAM8610_BMWM3,
    RACEBOY_TTN,
    RACEBOY_CAMARON,
    RACEBOY_BMWM3E92,
    TOUGECOM_NSX,
    ZIPSTYLE_NSX,
    PREAMP_FORDGTB,
    WAKABAYASHI_SUPRA,
    BOUNDDYNAMIC_RX7,
    COMMERCIAL_S4,
    COMMERCIAL_GTRPROTO
  };
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
  enum class ePackageType : std::uint32_t {
    QuickPower,
    QuickHandling,
    QuickVisual,
    CustomEngineCore,
    CustomEngineManagement,
    CustomEngineExhaust,
    CustomEngineForced_induction,
    CustomEngineNitrous,
    CustomDrivetrain,
    CustomSuspension,
    CustomBrakes
  };
  enum class ePlayerSettingsCameras : std::uint8_t {
    Bumper,
    Hood,
    Close,
    Far,
    Drift,
    Staging,
    Pause,
    CarSlot,
    Tuning,
    Invalid = UINT8_MAX
  };
  enum class ePresetCarFilter : std::uint32_t { Bonus, Custom, AI, Debug };
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
  enum class FormationType : std::uint32_t { None, Pit, BoxUn, RollingBlock, Follow, HeliPursuit, Herd, StaggerFollow };
  enum class KitType : std::uint32_t {
    Base,
    Stock,
    Autosculpt,
    Widebody,
  };
  enum class InputUpdateType : std::uint32_t { Update, Press, Release, AnalogPress, AnalogRelease, CenterControl };
  enum class SurfaceSFX : std::uint32_t {
    None         = 0,
    LightCrack   = 1,
    TarStrip     = 3,
    RoadsidePath = 5,
    HeavyPath    = 6,
    Dirt         = 7
  };
  enum class TireCondition : std::uint32_t { Grip, Wet, Flat, Drift, Drag };

  namespace FEManager {
    enum class eEntryPoints : std::uint32_t {
      None,
      BootFlow,
      DebugCarCustomize,
      MainMenu,
      Mazda,
      CarClassSelect,
      CarLot,
      Quickrace,
      CareerMain,
      CareerManager,
      CareerCarSelect,
      CareerBusted,
      CareerNewWingman,
      CareerNewWingmanJustMovie,
      CareerCrewTutorial,
      BossDefeated,
      WorldMap,
      ChallengeSeries,
      GameRoom,
      CustomMatchJoin,
      PostRaceJoin,
      WingmanSelectFromInGame,
      GameWon,
      GameOver,
      Hub,
      HubMap,
      HubMapRaceDay,
      HubMapCarSelect,
      HubMapKingIntro,
      HubMapKingProgess,
      HubMapKingDefeated,
      HubMapKingIntroSpeed,
      HubMapKingIntroDrift,
      HubMapKingIntroDrag,
      HubMapKingIntroGrip,
    };
    enum class eEvents : std::uint32_t {
      GarageCarLoaded,
      ChatButtonPressed,
      AnimationDone,
      ControllerErrorCleared,
      XenonPauseFinished,
    };
    enum class eState : std::uint32_t {
      Autosave,
      Bootflow,
      DebugCarCustomize,
      MainMenu,
      Hub,
      WaitingForHub,
      Pause,
      ConfirmSafehouse,
      ConfirmCarLot,
      PostRace,
      SeriesPostRace,
      PreRace,
      Spectator,
      SMS,
      Movie,
      CareerMap,
      GameRoom,
      InviteGameRoom,
      Tutorial,
      LoadingMain,
      CrashFlow,
      IceGradient,
      Idle
    };
  }  // namespace FEManager

  namespace GRace {
    enum class AI_AggressionLevel : std::uint32_t { Careful, Intermediate, Aggressive };
    enum class AI_MistakeLevel : std::uint32_t { Rookie, Intermediate, Veteran };
    enum class Behaviour : std::uint32_t { None, Single, Dual };
    enum class CareerElementDrawStyle : std::uint32_t { Box, Ellipse, Diamond };
    enum class Context : std::uint32_t { QuickRace, TimeTrial, Online, Career };
    enum class CopDensity : std::uint32_t {
      Off,
      Light,
      Medium,
      Heavy,
    };
    enum class Difficulty : std::uint32_t { Easy, Medium, Hard, Insane };
    enum class EventStyle : std::uint32_t { BestRound, Elimination };
    enum class HandicapMode : std::uint32_t { None, Performance, Group };
    enum class Mode : std::uint32_t { None, Grip, HighSpeedChallenge, Drag, Drift };
    enum class OpponentGender : std::uint32_t { Male, Female, Ambiguous };
    enum class OpponentTeam : std::uint32_t {
      Default,
      ApexGlide,
      AfterMix,
      TougeUnion,
      GripRunners,
      Boxcut,
      LaterFire
    };
    enum class OpponentType : std::uint32_t { Default, Challenge, Rival, King };
    enum class RaceCarClass : std::uint32_t { None, Exotic, Muscle, Tuner };
    enum class RaceLigthingMode : std::uint32_t { Normal, Drift, Canyon };
    enum class RaceRouteFlags : std::uint32_t {
      OK,
      NoRoute           = 1 << 0,
      ShorcutInFirstLeg = 1 << 1,
      CantTakeShortcut  = 1 << 3
    };
    enum class ShortcutType : std::uint32_t {
      None,
      ParkRight,
      AlleyRight,
      SideStreetRight,
      TunnelRight,
      GenericRight,
      ParkLeft,
      AlleyLeft,
      SideStreetLeft,
      TunnelLeft,
      GenericLeft
    };
    enum class Tier : std::uint32_t { None, Tier1, Tier2, Tier3 };
    enum class Type : std::uint8_t {
      None                   = UINT8_MAX,
      P2P                    = 0,
      SpeedChallenge_HeadsUp = P2P,
      SpeedChallenge_Mixed   = 1,
      SpeedChallenge_Class   = 2,
      TopSpeed_HeadsUp       = 3,
      TopSpeed_Mixed         = 4,
      TopSpeed_Class         = 5,
      Circuit_HeadsUp        = 6,
      Circuit_Mixed          = 7,
      Circuit_Class          = 8,
      SectorShootout_HeadsUp = 9,
      SectorShootout_Mixed   = 10,
      SectorShootout_Class   = 11,
      TimeAttack_HeadsUp     = 12,
      TimeAttack_Mixed       = 13,
      TimeAttack_Class       = 14,
      Drag_HeadsUp           = 16,
      Drag_Mixed             = 17,
      Drag_Class             = 18,
      Drag_Wheelie_HeadsUp   = 19,
      Drag_Wheelie_Mixed     = 20,
      Drag_Wheelie_Class     = 21,
      Drift_Solo_HeadsUp     = 23,
      Drift_Solo_Mixed       = 24,
      Drift_Solo_Class       = 25,
      Drift_Race_HeadsUp     = 26,
      Drift_Race_Mixed       = 27,
      Drift_Race_Class       = 28,
      Drift_Tandem_HeadsUp   = 29,
      Drift_Tandem_Mixed     = 30,
      Drift_Tandem_Class     = 31,
      Knockout               = 33,
      SpeedTrap              = 34,
      Checkpoint             = 35,
      Challenge              = 36
    };
    enum class Variant : std::uint32_t {
      None,
      SpeedChallenge,
      TopSpeed,
      Circuit,
      SectorShootout,
      TimeAttack,
      Drag,
      DragWheelie,
      DriftSolo,
      DriftRace,
      DriftTandem,
      Invalid = UINT32_MAX
    };
    enum class WingmanShortcutTriggerHint : std::uint32_t { None, Init, Entry, Pos, Exit };
  }  // namespace GRace

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(eVehicleParamFlags)
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

  struct float16 {
    std::uint16_t buf;

    operator float() const {
      return (((buf & 0x7C00) == 0) ? 0 : ((buf & 0x7FFF) << 13) + 0x38000000) | ((buf & 0x8000) << 16);
    }

    float16() = default;
    float16(float value) {
      std::uint32_t i = *reinterpret_cast<std::uint32_t*>(&value);
      std::uint32_t e = i & 0x7F800000;
      std::uint32_t m = (((i & 0x7FFFFFFF) >> 13) - 0x1C000);

      m   = (e < 0x38800000) ? 0 : m;
      m   = (e > 0x47000000) ? 0x7BFF : m;
      buf = m | ((i & 0x80000000) >> 16);
    }
  };

#pragma endregion

}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_H
