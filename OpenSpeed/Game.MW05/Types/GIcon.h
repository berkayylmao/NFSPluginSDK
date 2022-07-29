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
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05 {
  struct GIcon {
    struct EffectInfo {
      std::uint32_t mType;
      std::uint32_t mModelHash;
      std::uint32_t mParticleHash;
    };

    enum class Flags : std::uint16_t {
      ShowInWorld     = 1 << 0,
      ShowOnMap       = 1 << 1,
      Spawned         = 1 << 2,
      Enabled         = 1 << 3,
      Disposable      = 1 << 4,
      SnappedToGround = 1 << 5,
      ShowOnSpawn     = 1 << 6,
      GPSing          = 1 << 7
    };
    enum class Type : std::uint16_t {
      Invalid,
      RaceSprint,
      RaceCircuit,
      RaceDrag,
      RaceKnockout,
      RaceCheckPoint,
      RaceSpeedtrap,
      RaceRival,
      GateSafehouse,
      GateCarLot,
      GateCustomShop,
      HidingSpot,
      PursuitBreaker,
      SpeedTrapInRace,
      Checkpoint,
      GoalMarker
    };

    Type          mType;
    Flags         mFlags;
    std::int16_t  mSectionId;
    std::int16_t  mCombSectionId;
    WorldModel*   mModel;
    EmitterGroup* mEmitter;
    Math::Vector3 mPosition;
    std::uint16_t mRotation;
    std::uint16_t mPad;

   public:
    GIcon(Type type, const UMath::Vector3& initialPosition, float _unk = 0.0f) {
      reinterpret_cast<void(__thiscall*)(GIcon*, Type, const UMath::Vector3&, float)>(0x5E5970)(this, type,
                                                                                                initialPosition, _unk);
    }
    ~GIcon() { reinterpret_cast<void(__thiscall*)(GIcon*, bool)>(0x5EBED0)(this, true); }

    inline std::uint32_t FindSection() { return reinterpret_cast<std::uint32_t(__thiscall*)(GIcon*)>(0x5DE590)(this); }
    inline WorldModel*   CreateGeometry(std::uint32_t _unk) {
      return reinterpret_cast<WorldModel*(__thiscall*)(GIcon*, std::uint32_t)>(0x5DE690)(this, _unk);
    }
    inline void SetPosition() { reinterpret_cast<void(__thiscall*)(GIcon*)>(0x5E5A90)(this); }
    inline void Spawn() { reinterpret_cast<void(__thiscall*)(GIcon*)>(0x5EC270)(this); }
    inline void Unspawn() { reinterpret_cast<void(__thiscall*)(GIcon*)>(0x5E5A00)(this); }
    inline void SnapToGround() { reinterpret_cast<void(__thiscall*)(GIcon*)>(0x5EA0F0)(this); }

    inline Type         GetType() { return mType; }
    inline std::int16_t GetSectionID() { return mSectionId; }
    inline std::int16_t GetCombinedSectionID() { return mCombSectionId; }
    inline bool         GetVisibleInWorld() {
      return static_cast<std::uint16_t>(mFlags) & static_cast<std::uint16_t>(Flags::ShowInWorld);
    }
    inline bool GetVisibleOnMap() {
      return static_cast<std::uint16_t>(mFlags) & static_cast<std::uint16_t>(Flags::ShowOnMap);
    }
    inline bool GetIsDisposable() {
      return static_cast<std::uint16_t>(mFlags) & static_cast<std::uint16_t>(Flags::Disposable);
    }
    inline bool GetIsEnabled() {
      return static_cast<std::uint16_t>(mFlags) & static_cast<std::uint16_t>(Flags::Enabled);
    }
    inline bool GetIsGPSing() { return static_cast<std::uint16_t>(mFlags) & static_cast<std::uint16_t>(Flags::GPSing); }
    inline bool GetIsSnapped() {
      return static_cast<std::uint16_t>(mFlags) & static_cast<std::uint16_t>(Flags::SnappedToGround);
    }

    inline void MarkDisposable() {
      mFlags = static_cast<Flags>(static_cast<std::uint16_t>(mFlags) | static_cast<std::uint16_t>(Flags::Disposable));
    }
    inline void Show() {
      mFlags = static_cast<Flags>(static_cast<std::uint16_t>(mFlags) | static_cast<std::uint16_t>(Flags::ShowInWorld));
    }
    inline void Hide() {
      mFlags = static_cast<Flags>(static_cast<std::uint16_t>(mFlags) ^ static_cast<std::uint16_t>(Flags::ShowInWorld));
    }
    inline void HideUntilRespawn() {
      Hide();
      mFlags = static_cast<Flags>(static_cast<std::uint16_t>(mFlags) | static_cast<std::uint16_t>(Flags::ShowOnSpawn));
    }
    inline void ShowOnMap() {
      mFlags = static_cast<Flags>(static_cast<std::uint16_t>(mFlags) | static_cast<std::uint16_t>(Flags::ShowOnMap));
    }
    inline void HideOnMap() {
      mFlags = static_cast<Flags>(static_cast<std::uint16_t>(mFlags) ^ static_cast<std::uint16_t>(Flags::ShowOnMap));
    }
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(GIcon::Flags)
  DEFINE_ENUM_FLAG_OPERATORS(GIcon::Type)
#endif
}  // namespace OpenSpeed::MW05
