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
#include <OpenSpeed/Game.MW05/Types.h>

namespace OpenSpeed::MW05::Physics {
  namespace Info {
    struct Performance {
      float mTopSpeed;
      float mHandling;
      float mAcceleration;
    };
  }  // namespace Info

  namespace Upgrades {
    struct Package {
      eCareerUpgradeLevels mTires;
      eCareerUpgradeLevels mBrakes;
      eCareerUpgradeLevels mChassis;
      eCareerUpgradeLevels mTransmission;
      eCareerUpgradeLevels mEngine;
      eCareerUpgradeLevels mInduction;
      eCareerUpgradeLevels mNOS;
      JunkmanParts         mJunkman;

      static void ApplyPreset(Attrib::Gen::pvehicle& to, const Attrib::Gen::presetride& preset) {
        reinterpret_cast<void(__cdecl*)(Attrib::Gen::pvehicle&, const Attrib::Gen::presetride&)>(0x67C080)(to, preset);
      }

      static bool CanInstallJunkman(const Attrib::Gen::pvehicle& instance, Type type) {
        return reinterpret_cast<bool(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x677FE0)(instance, type);
      }

      static eCareerUpgradeLevels GetLevel(const Attrib::Gen::pvehicle& instance, Type type) {
        return reinterpret_cast<eCareerUpgradeLevels(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x672D30)(instance,
                                                                                                              type);
      }
      static eCareerUpgradeLevels GetMaxLevel(const Attrib::Gen::pvehicle& instance, Type type) {
        return reinterpret_cast<eCareerUpgradeLevels(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x672E80)(instance,
                                                                                                              type);
      }
      static float GetPercent(const Attrib::Gen::pvehicle& instance, Type type) {
        return reinterpret_cast<float(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x677F80)(instance, type);
      }

      static void MatchPerformance(const Attrib::Gen::pvehicle& instance, const Info::Performance& performance) {
        reinterpret_cast<void(__cdecl*)(const Attrib::Gen::pvehicle&, const Info::Performance&)>(0x67C310)(instance,
                                                                                                           performance);
      }

      static void RemoveJunkman(const Attrib::Gen::pvehicle& instance, Type type) {
        reinterpret_cast<void(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x67C220)(instance, type);
      }
      static void RemovePart(const Attrib::Gen::pvehicle& instance, Type type) {
        reinterpret_cast<void(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x678530)(instance, type);
      }

      static void SetJunkman(const Attrib::Gen::pvehicle& instance, Type type) {
        reinterpret_cast<void(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x678150)(instance, type);
      }
      static void SetLevel(const Attrib::Gen::pvehicle& instance, Type type) {
        reinterpret_cast<void(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x678AD0)(instance, type);
      }
      static void SetMaximum(Attrib::Gen::pvehicle& to) {
        reinterpret_cast<void(__cdecl*)(Attrib::Gen::pvehicle&)>(0x67F950)(to);
      }
      static void SetPackage(const Attrib::Gen::pvehicle& instance, const Physics::Upgrades::Package& package) {
        reinterpret_cast<void(__cdecl*)(const Attrib::Gen::pvehicle&, const Physics::Upgrades::Package&)>(0x67F800)(
            instance, package);
      }
    };
  };  // namespace Upgrades

  struct Tunings {
    enum class Path { Steering, Handling, Brakes, RideHeight, Aerodynamics, NOS, Induction };

    float mSteering;
    float mHandling;
    float mBrakes;
    float mRideHeight;
    float mAerodynamics;
    float mNOS;
    float mInduction;

    explicit Tunings() :
        mSteering(0.0f),
        mHandling(0.0f),
        mBrakes(0.0f),
        mRideHeight(0.0f),
        mAerodynamics(0.0f),
        mNOS(0.0f),
        mInduction(0.0f) {}

    static inline const float g_GameDisplayMultiplier = 5.0f;
  };
}  // namespace OpenSpeed::MW05::Physics
