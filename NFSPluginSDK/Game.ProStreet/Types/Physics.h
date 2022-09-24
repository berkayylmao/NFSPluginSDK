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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::Physics {
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

  namespace Info {
    struct AbsolutePerformanceStats {
      float performanceTypeMap[47];
    };
    struct PerformanceLevels {
      float performanceTypeMap[47];
    };

    struct Performance {
      AbsolutePerformanceStats absolutePerformanceStats;
      PerformanceLevels        performanceLevels;
      BluePrintType            bluePrintType;
    };

    struct PerformanceMatching {
      ePerformanceType performanceType;
      bool             isPerformanceLevel;
      float            performanceValue;
    };

    struct CorrectedPerformance {
      AbsolutePerformanceStats absolutePerformanceStats;
      PerformanceLevels        performanceLevels;
      Performance              stockMeasuredPerformance;
      Performance              highendMeasuredPerformance;
      BluePrintType            bluePrintType;
      Performance              stockFastPerformance;
      Performance              highendFastPerformance;
    };
  }  // namespace Info

  namespace Upgrades {
    struct Part {
      std::int32_t mLevel;
      std::int32_t mOptions;
    };

    struct Package {
      Part mTires;
      Part mBrakes;
      Part mChassis;
      Part mTransmission;
      Part mEngine;
      Part mInduction;
      Part mNOS;
    };

    struct Tuning {
      float lowerBound;
      float upperBound;
      float position;
    };
  };  // namespace Upgrades
}  // namespace NFSPluginSDK::ProStreet::Physics

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICS_H
