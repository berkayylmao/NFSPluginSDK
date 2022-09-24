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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_PHYSICS_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_PHYSICS_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>

namespace NFSPluginSDK::Carbon::Physics {
  namespace Info {
    struct Performance {
      float mTopSpeed;
      float mHandling;
      float mAcceleration;

      explicit Performance() : mTopSpeed(0.0f), mHandling(0.0f), mAcceleration(0.0f) {}
    };
  }  // namespace Info

  namespace Upgrades {
    struct Part {
      eCareerUpgradeLevels mLevel;
      std::int32_t         mOptions;

      explicit Part() : mLevel(eCareerUpgradeLevels::LevelStock), mOptions(0) {}
    };

    struct Package {
      Part mTires;
      Part mBrakes;
      Part mChassis;
      Part mTransmission;
      Part mEngine;
      Part mInduction;
      Part mNOS;

      static void ApplyPreset(Attrib::Gen::pvehicle& to, const Attrib::Gen::presetride& preset) {
        reinterpret_cast<void(__cdecl*)(Attrib::Gen::pvehicle&, const Attrib::Gen::presetride&)>(0x6D1EB0)(to, preset);
      }

      static Part GetPart(Type type) {
        Part ret;
        return reinterpret_cast<Part(__cdecl*)(Part&, Type)>(0x6C8120)(ret, type);
      }
      static eCareerUpgradeLevels GetMaxLevel(const Attrib::Gen::pvehicle& instance, Type type) {
        return reinterpret_cast<eCareerUpgradeLevels(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x6C8320)(instance,
                                                                                                              type);
      }
      static float GetPercent(const Attrib::Gen::pvehicle& instance, Type type) {
        return reinterpret_cast<float(__cdecl*)(const Attrib::Gen::pvehicle&, Type)>(0x6CCFE0)(instance, type);
      }

      static void MatchPerformance(const Attrib::Gen::pvehicle& instance, const Info::Performance& performance) {
        reinterpret_cast<void(__cdecl*)(const Attrib::Gen::pvehicle&, const Info::Performance&)>(0x6D2070)(instance,
                                                                                                           performance);
      }

      static void SetMaximum(Attrib::Gen::pvehicle& to) {
        reinterpret_cast<void(__cdecl*)(Attrib::Gen::pvehicle&)>(0x6D2000)(to);
      }
      static void SetPackage(const Attrib::Gen::pvehicle& instance, const Physics::Upgrades::Package& package) {
        reinterpret_cast<void(__cdecl*)(const Attrib::Gen::pvehicle&, const Physics::Upgrades::Package&)>(0x6CD770)(
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
    explicit Tunings(float steering, float handling, float brakes, float rideHeight, float aerodynamics, float nos,
                     float induction) :
        mSteering(steering),
        mHandling(handling),
        mBrakes(brakes),
        mRideHeight(rideHeight),
        mAerodynamics(aerodynamics),
        mNOS(nos),
        mInduction(induction) {}

    static inline const float g_GameDisplayMultiplier = 5.0f;
  };
}  // namespace NFSPluginSDK::Carbon::Physics

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_PHYSICS_H
