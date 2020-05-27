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
#include <cstdint>  // integer types
#include <cstring>  // memcpy
#if defined(_WIN32)
#include <winnt.h>  // DEFINE_ENUM_FLAG_OPERATORS
#endif

namespace OpenSpeed::MW05 {
  struct ActionRef;
  struct AIVehicle;
  template <class T>
  struct AttributeStructPtr;
  struct Behavior;
  template <class T>
  struct BehaviorSpecsPtr;
  struct bList;
  template <class T>
  struct bTList;
  struct bNode;
  template <class T>
  struct bTNode;
  struct CameraInfo;
  struct EventSequencer;
  struct FECustomizationRecord;
  struct GIcon;
  struct GManager;
  struct HCAUSE__;
  struct HSIMABLE__;
  struct HSIMPROFILE__;
  struct HSIMSERVICE__;
  struct HSIMTASK__;
  struct IArticulatedVehicle;
  struct IAttachable;
  struct IAttributeable;
  struct IAudible;
  struct IBody;
  struct IChassis;
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
  struct InputPlayer;
  struct IPlayer;
  struct IRBVehicle;
  struct IRenderable;
  struct IRigidBody;
  struct ISimable;
  struct ISteeringWheel;
  struct ITransmission;
  struct IVehicle;
  struct IVehicleAI;
  struct IVehicleCache;
  struct LocalPlayer;
  struct PhysicsObject;
  struct PInput;
  struct PlayerSettings;
  struct PVehicle;
  struct RBTractor;
  struct RBVehicle;
  struct RideInfo;
  struct RigidBody;
  template <class T>
  struct ScratchPtr;
  struct SimSurface;
  struct TimeOfDay;
  struct TimeOfDayLighting;
  struct TimeOfDayLightingData;
  struct UCrc32;
  struct VehicleCustomizations;
  struct VehicleParams;
  struct WCollider;
  struct WorldModel;
  struct WWorldPos;

  namespace Attrib {
    struct Collection;
    struct Instance;
    struct Private;
    struct StringKey;

    namespace Gen {
      struct collisionreactions;
      struct pvehicle;
      struct rigidbodyspecs;
      struct simsurface;
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
  namespace Game {}
  namespace Physics {
    struct Tunings;

    namespace Info {
      struct CorrectedPerformance;
      struct PerformanceMatching;
    }  // namespace Info
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
    template <typename T>
    struct GarbageNode;
    namespace COM {
      struct IUnknown;
      struct Object;
    }  // namespace COM
  }    // namespace UTL
  namespace WCollisionMgr {
    struct WorldCollisionInfo;
  }

  enum class DriverClass : std::uint_least32_t {
    Human,
    Traffic,
    Cop,
    Racer,
    None,
    NIS,
    Remote,
    RemoteRacer,
    Ghost
  };
  enum class DriverStyle : std::uint_least32_t { Racing, Drag, Drift, HighSpeed, Traffic };
  enum class EAILaneChangeType : std::uint_least32_t { None, Left, Right };
  enum class eMode : std::uint_least32_t { MODE_AWAKE, MODE_SLEEPING, MODE_NOMODEL };
  enum class eInvulnerability : std::uint_least32_t {
    None,
    FromManualReset,
    FromReset,
    FromControlSwitch,
    FromPhysicsSwitch
  };
  enum class ePlayerHudType : std::uint_least32_t {
    None,
    Standard,
    Drag,
    Split1,
    Split2,
    DragSplit1,
    DragSplit2
  };
  enum class eTurnSignalState : std::uint_least32_t { None, Left, Right };
  enum class eVehicleCacheResult : std::uint_least32_t { Want, DontCare };
  enum class GameFlowState : std::uint_least32_t {
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
  enum class PhysicsMode : std::uint_least32_t { Inactive, Simulated, Emulated };
  enum class SimableType : std::uint_least32_t {
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
  enum class SpeedUnitType : std::uint_least8_t { MPH, KMH, MPS };
  enum class StatusType : std::uint_least32_t {
    NoTrigger         = 1 << 0,
    Attached          = 1 << 1,
    CollisionWorld    = 1 << 2,
    CollisionObject   = 1 << 3,
    EnableDrag        = 1 << 5,
    CheckWorld        = 1 << 6,
    FixedCG           = 1 << 7,
    Animating         = 1 << 8,
    Initiliazed       = 1 << 9,
    Integrating       = 1 << 10,
    EnableDragAngular = 1 << 11,
    DisableIntegrator = 1 << 12,
    ModifyPrims       = 1 << 13,
    Inactive          = 1 << 14,
    CollisionGround   = 1 << 15
  };
  enum class VehicleCreateFlags : std::uint_least32_t {
    Valid           = 1 << 0,
    Spooled         = 1 << 1,
    Critical        = 1 << 2,
    NosAdded        = 1 << 3,
    NosRemoved      = 1 << 4,
    Composited      = 1 << 5,
    Unlimited       = 1 << 6,
    CachedType      = 1 << 7,
    CachedOnly      = 1 << 8,
    PhysicsOnly     = 1 << 9,
    SnapToGround    = 1 << 10,
    LowResolution   = 1 << 11,
    CalcPerformance = 1 << 12
  };
  namespace CollisionGeometry {
    enum class BoundFlags : std::uint_least32_t {
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
      Joint_Invert         = 1 << 13,
      PrimVsOwnParts       = 1 << 14
    };
  }
  namespace VehicleFX {
    enum class LightID : std::uint_least32_t {
      None       = 0,
      LeftHead   = 1 << 0,
      RightHead  = 1 << 1,
      CenterHead = 1 << 2,
      Headlights = (std::uint_least32_t)LeftHead | (std::uint_least32_t)RightHead |
                   (std::uint_least32_t)CenterHead,
      LeftBrake   = 1 << 3,
      RightBrake  = 1 << 4,
      CenterBrake = 1 << 5,
      Brakelights = (std::uint_least32_t)LeftBrake | (std::uint_least32_t)RightBrake |
                    (std::uint_least32_t)CenterBrake,
      LeftReverse      = 1 << 6,
      RightReverse     = 1 << 7,
      Reverse          = (std::uint_least32_t)LeftReverse | (std::uint_least32_t)RightReverse,
      LeftRearSignal   = 1 << 8,
      RightRearSignal  = 1 << 9,
      LeftFrontSignal  = 1 << 10,
      RightFrontSignal = 1 << 11,
      LeftSignal       = (std::uint_least32_t)LeftFrontSignal | (std::uint_least32_t)LeftRearSignal,
      RightSignal = (std::uint_least32_t)RightFrontSignal | (std::uint_least32_t)RightRearSignal,
      CopRed      = 1 << 12,
      CopBlue     = 1 << 13,
      CopWhite    = 1 << 14,
      Cop =
          (std::uint_least32_t)CopRed | (std::uint_least32_t)CopBlue | (std::uint_least32_t)CopWhite
    };
  }  // namespace VehicleFX

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(DriverClass)
  DEFINE_ENUM_FLAG_OPERATORS(DriverStyle)
  DEFINE_ENUM_FLAG_OPERATORS(EAILaneChangeType)
  DEFINE_ENUM_FLAG_OPERATORS(eMode)
  DEFINE_ENUM_FLAG_OPERATORS(eInvulnerability)
  DEFINE_ENUM_FLAG_OPERATORS(ePlayerHudType)
  DEFINE_ENUM_FLAG_OPERATORS(eTurnSignalState)
  DEFINE_ENUM_FLAG_OPERATORS(eVehicleCacheResult)
  DEFINE_ENUM_FLAG_OPERATORS(GameFlowState)
  DEFINE_ENUM_FLAG_OPERATORS(PhysicsMode)
  DEFINE_ENUM_FLAG_OPERATORS(SimableType)
  DEFINE_ENUM_FLAG_OPERATORS(SpeedUnitType)
  DEFINE_ENUM_FLAG_OPERATORS(StatusType)
  DEFINE_ENUM_FLAG_OPERATORS(VehicleCreateFlags)
  DEFINE_ENUM_FLAG_OPERATORS(CollisionGeometry::BoundFlags)
  DEFINE_ENUM_FLAG_OPERATORS(VehicleFX::LightID)
#endif
}  // namespace OpenSpeed::MW05
