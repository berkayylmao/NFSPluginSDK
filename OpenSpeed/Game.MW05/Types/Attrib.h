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
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/UMath.h>

namespace OpenSpeed::MW05::Attrib {
  struct HashMap {
    Node*         mTable;
    std::uint32_t mTableSize;
    std::uint32_t mNumEntries;
    std::uint16_t mWorstCollision;
    std::uint16_t mKeyShift;
  };

  struct Class {
    std::uint32_t mKey;
    std::uint32_t mRefCount;
    ClassPrivate& mPrivates;
  };

  struct Collection {
    HashMap       mTable;
    Collection*   mParent;
    Class*        mClass;
    void*         mLayout;
    std::uint32_t mRefCount;
    std::uint32_t mKey;
    Vault*        mSource;
    const char*   mNamePtr;

    Definition* GetDefinition(std::uint32_t key) {
      return reinterpret_cast<Definition*(__cdecl*)(std::uint32_t)>(0x457380)(key);
    }
    std::uint32_t GetNumDefinitions() { return reinterpret_cast<std::uint32_t(__cdecl*)()>(0x451660)(); }
    std::uint32_t GetFirstDefinition() { return reinterpret_cast<std::uint32_t(__cdecl*)()>(0x451670)(); }
    std::uint32_t GetNextDefinition(std::uint32_t key) {
      return reinterpret_cast<std::uint32_t(__cdecl*)(std::uint32_t)>(0x4573C0)(key);
    }

    Collection* GetCollection(std::uint32_t key) {
      return reinterpret_cast<Collection*(__cdecl*)(std::uint32_t)>(0x454CC0)(key);
    }
    std::uint32_t GetNumCollections() { return reinterpret_cast<std::uint32_t(__cdecl*)()>(0x453FC0)(); }
    std::uint32_t GetFirstCollection() { return reinterpret_cast<std::uint32_t(__cdecl*)()>(0x456B00)(); }
    std::uint32_t GetNextCollection(std::uint32_t key) {
      return reinterpret_cast<std::uint32_t(__cdecl*)(std::uint32_t)>(0x456B20)(key);
    }
  };

  struct Database {
    static inline Database* g_sThis = reinterpret_cast<Database*>(0x90DCBC);

    DatabasePrivate& mPrivates;

    virtual ~Database();
    Class* GetClass(std::uint32_t key) { return reinterpret_cast<Class*(__cdecl*)(std::uint32_t)>(0x454DB0)(key); }
  };

  struct Definition {
    enum class Flags : std::uint8_t {
      Array           = 1 << 0,
      InLayout        = 1 << 1,
      IsBound         = 1 << 2,
      IsNotSearchable = 1 << 3,
    };

    std::uint32_t mKey;
    std::uint32_t mType;
    std::uint16_t mOffset;
    std::uint16_t mSize;
    std::uint16_t mMaxCount;
    Flags         mFlags;
    std::uint8_t  mAlignment;
  };

  struct Instance {
    enum class Flags : std::uint16_t { Dynamic = 1 };

    UTL::COM::IUnknown* mOwner;
    Collection*         mCollection;
    void*               mLayoutPtr;
    std::uint32_t       mMsgPort;
    Flags               mFlags;
    std::uint16_t       mLock;
  };

  struct Private {
    std::uint16_t mCapacity;
    std::uint16_t mCount;
    std::uint16_t mElemSize;
    std::uint16_t mData;
  };

  struct RefSpec {
    std::uint32_t     mClassKey;
    std::uint32_t     mCollectionKey;
    const Collection* mCollectionPtr;
  };

  struct StringKey {
    std::uint32_t mHash32;
    const char*   mString;

    StringKey(std::uint32_t hash) : mHash32(hash) {}
  };

  namespace Gen {
    struct camerainfo : Instance {
      Private     _Array_STIFFNESS;
      float       STIFFNESS[2];
      Private     _Array_ANGLE;
      float       ANGLE[2];
      Private     _Array_LAG;
      float       LAG[2];
      Private     _Array_FOV;
      float       FOV[2];
      Private     _Array_HEIGHT;
      float       HEIGHT[2];
      Private     _Array_LATEOFFSET;
      float       LATEOFFSET[2];
      const char* CollectionName;
      Private     _Array_TILTING;
      bool        TILTING[2];
      Private     _Array_SELECTABLE;
      bool        SELECTABLE[2];

      void operator=(const camerainfo& newCameraInfo) {
        std::memcpy(STIFFNESS, newCameraInfo.STIFFNESS, sizeof(float) * 2);
        std::memcpy(ANGLE, newCameraInfo.ANGLE, sizeof(float) * 2);
        std::memcpy(LAG, newCameraInfo.LAG, sizeof(float) * 2);
        std::memcpy(FOV, newCameraInfo.FOV, sizeof(float) * 2);
        std::memcpy(HEIGHT, newCameraInfo.HEIGHT, sizeof(float) * 2);
        std::memcpy(LATEOFFSET, newCameraInfo.LATEOFFSET, sizeof(float) * 2);
        std::memcpy(TILTING, newCameraInfo.TILTING, sizeof(bool) * 2);
        std::memcpy(SELECTABLE, newCameraInfo.SELECTABLE, sizeof(bool) * 2);
      }
    };

    struct collisionreactions {
      struct CollisionReactionRecord {
        float Elasticity;
        float RollHeight;
        float WeightBias;
        float MassScale;
        float StunSpeed;
        float StunTime;
      };

      CollisionReactionRecord REARSIDE_REACTION;
      CollisionReactionRecord FRONTSIDE_REACTION;
      CollisionReactionRecord FRONT_REACTION;
      CollisionReactionRecord REAR_REACTION;
    };

    struct pvehicle : Instance {
      enum class Type_car_type : std::uint32_t {
        McLaren     = 1 << 0,
        Porsche     = 1 << 1,
        FordGT      = 1 << 2,
        Viper       = 1 << 3,
        AstonMartin = 1 << 4,
        Corvette    = 1 << 5,
        BMW         = 1 << 6,
        Mercedes    = 1 << 7,
        Audi        = 1 << 8,
        Mitsubishi  = 1 << 9,
        Mustang     = 1 << 10,
        Lotus       = 1 << 11,
        Subaru      = 1 << 12,
        Camaro      = 1 << 13,
        GTO         = 1 << 14,
        Nissan      = 1 << 15,
        Mazda       = 1 << 16,
        Renault     = 1 << 17,
        Lexus       = 1 << 18,
        Mini        = 1 << 19,
        Volkswagen  = 1 << 20,
        SUV         = 1 << 21,
        Pickup      = 1 << 22,
        Pagani      = 1 << 23,
        Lamborghini = 1 << 24,
        Chrysler    = 1 << 25,
        Opel        = 1 << 26,
        Sedan       = 1 << 27,
        SportsCar   = 1 << 28,
        Supra       = 1 << 29,
        Cadillac    = 1 << 30
      };

      UMath::Vector4 TENSOR_SCALE;
      StringKey      MODEL;
      const char*    DefaultPresetRide;
      const char*    CollectionName;
      std::int32_t   engine_upgrades;
      std::int32_t   transmission_upgrades;
      std::int32_t   nos_upgrades;
      std::int32_t   brakes_upgrades;
      float          MASS;
      std::int32_t   tires_upgrades;
      Type_car_type  VerbalType;
      std::int32_t   induction_upgrades;
      std::int32_t   chassis_upgrades;
      std::uint8_t   HornType;
      std::uint8_t   TrafficEngType;
    };

    struct rigidbodyspecs : Instance {
      UMath::Vector4 COLLISION_BOX_PAD;
      UMath::Vector4 DRAG;
      UMath::Vector4 WORLD_MOMENT_SCALE;
      UMath::Vector4 OBJ_MOMENT_SCALE;
      UMath::Vector4 GROUND_ELASTICITY;
      UMath::Vector4 OBJ_ELASTICITY;
      UMath::Vector4 DRAG_ANGULAR;
      UMath::Vector4 WALL_ELASTICITY;
      UMath::Vector4 GROUND_MOMENT_SCALE;
      UMath::Vector4 CG;
      StringKey      BASE_MATERIAL;
      StringKey      DEFAULT_COL_BOX;
      Private        _Array_OBJ_FRICTION;
      float          OBJ_FRICTION[2];
      Private        _Array_WALL_FRICTION;
      float          WALL_FRICTION[2];
      Private        _Array_GROUND_FRICTION;
      float          GROUND_FRICTION[2];
      float          GRAVITY;
      float          NATURAL_ANGULAR_DAMPING;
      float          SLEEP_VELOCITY;
      bool           NO_GROUND_COLLISIONS;
      bool           IMMOBILE_OBJECT_COLLISIONS;
      bool           NO_WORLD_COLLISIONS;
      bool           INSTANCE_COLLISIONS_3D;
      bool           NO_OBJ_COLLISIONS;
    };

    struct simsurface {
      struct RoadNoiseRecord {
        float Frequency;
        float Amplitude;
        float MinSpeed;
        float MaxSpeed;
      };
      struct TireEffectRecord {
        RefSpec mEmitter;
        float   mMinSpeed;
        float   mMaxSpeed;
      };

      Private          _Array_TireDriveEffects;
      TireEffectRecord TireDriveEffects[3];
      Private          _Array_TireSlideEffects;
      TireEffectRecord TireSlideEffects[3];
      Private          _Array_TireSlipEffects;
      TireEffectRecord TireSlipEffects[3];
      RoadNoiseRecord  RenderNoise;
      const char*      CollectionName;
      float            GROUND_FRICTION;
      float            ROLLING_RESISTANCE;
      float            WORLD_FRICTION;
      float            DRIVE_GRIP;
      float            LATERAL_GRIP;
      float            STICK;
      std::uint16_t    WheelEffectFrequency;
      std::uint8_t     WheelEffectIntensity;
    };

    struct timeofdaylighting : Instance {
      struct RGBA {
        float R, G, B, A;

        RGBA operator+(const RGBA& rhs) {
          RGBA _result = *this;
          _result.R += rhs.R;
          _result.G += rhs.G;
          _result.B += rhs.B;
          _result.A += rhs.A;

          return _result;
        }

        void operator=(const RGBA& rhs) {
          this->R = rhs.R;
          this->G = rhs.G;
          this->B = rhs.B;
          this->A = rhs.A;
        }
        void operator+=(const RGBA& rhs) { *this = *this + rhs; }

        RGBA(float red, float green, float blue, float alpha) : R(red), G(green), B(blue), A(alpha) {}
        ~RGBA() = default;
      };

      RGBA          SpecularColour;
      RGBA          DiffuseColour;
      RGBA          AmbientColour;
      RGBA          FogHazeColour;
      RGBA          FixedFunctionSkyColour;
      float         FogDistanceScale;
      float         FogHazeColourScale;
      float         FogSkyColourScale;
      float         EnvSkyBrightness;
      float         CarSpecScale;
      unsigned char _pad[0x4 * 3];
      RGBA          FogSkyColour;

      timeofdaylighting operator+(const timeofdaylighting& rhs) {
        timeofdaylighting _result = *this;
        _result.SpecularColour += rhs.SpecularColour;
        _result.DiffuseColour += rhs.DiffuseColour;
        _result.AmbientColour += rhs.AmbientColour;
        _result.FogHazeColour += rhs.FogHazeColour;
        _result.FixedFunctionSkyColour += rhs.FixedFunctionSkyColour;
        _result.FogDistanceScale += rhs.FogDistanceScale;
        _result.FogSkyColourScale += rhs.FogSkyColourScale;
        _result.FogHazeColourScale += rhs.FogHazeColourScale;
        _result.EnvSkyBrightness += rhs.EnvSkyBrightness;
        _result.CarSpecScale += rhs.CarSpecScale;
        _result.FogSkyColour += rhs.FogSkyColour;

        return _result;
      }

      void operator=(const timeofdaylighting& rhs) {
        SpecularColour         = rhs.SpecularColour;
        DiffuseColour          = rhs.DiffuseColour;
        AmbientColour          = rhs.AmbientColour;
        FogHazeColour          = rhs.FogHazeColour;
        FixedFunctionSkyColour = rhs.FixedFunctionSkyColour;
        FogDistanceScale       = rhs.FogDistanceScale;
        FogSkyColourScale      = rhs.FogSkyColourScale;
        FogHazeColourScale     = rhs.FogHazeColourScale;
        EnvSkyBrightness       = rhs.EnvSkyBrightness;
        CarSpecScale           = rhs.CarSpecScale;
        FogSkyColour           = rhs.FogSkyColour;
      }
      void operator+=(const timeofdaylighting& rhs) { *this = *this + rhs; }
    };
  }  // namespace Gen

  static inline Collection* FindCollection(std::uint32_t classHash, std::uint32_t collectionHash) {
    return reinterpret_cast<Collection*(__cdecl*)(std::uint32_t, std::uint32_t)>(0x455FD0)(classHash, collectionHash);
  }

  static inline StringKey StringToKey(const char* cstring) {
    return reinterpret_cast<StringKey(__cdecl*)(const char*)>(0x454640)(cstring);
  }
#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(Attrib::Gen::pvehicle::Type_car_type)
#endif
}  // namespace OpenSpeed::MW05::Attrib
