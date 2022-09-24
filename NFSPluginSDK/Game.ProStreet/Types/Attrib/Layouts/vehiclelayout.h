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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_VEHICLELAYOUT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_VEHICLELAYOUT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/RefSpec.h>

namespace NFSPluginSDK::ProStreet::Attrib::Layouts {
  struct vehiclelayout {
    UMath::Vector4  TENSOR_SCALE;
    Math::Curve     UPSHIFT_THROTTLE;
    Math::Curve     UPSHIFT_CLUTCH;
    Math::Curve     TORQUE;
    Math::Curve     DOWNSHIFT_THROTTLE;
    Math::Curve     DOWNSHIFT_CLUTCH;
    Attrib::RefSpec FORCED_INDUCTION;
    Math::AxlePair  Tw;
    Math::AxlePair  TRAVEL;
    Math::AxlePair  TRACK_WIDTH;
    Math::AxlePair  Tp;
    Math::AxlePair  SWAYBAR_STIFFNESS;
    Math::AxlePair  SPRING_STIFFNESS;
    Math::AxlePair  SPRING_PROGRESSION;
    Math::AxlePair  SHOCK_VALVING;
    Math::AxlePair  SHOCK_DIGRESSION;
    Math::AxlePair  SECTION_WIDTH;
    Math::AxlePair  RIM_SIZE;
    Math::AxlePair  RIDE_HEIGHT;
    Math::AxlePair  Kmu;
    Math::AxlePair  Ka;
    Math::AxlePair  K1;
    Math::AxlePair  Fzt;
    Math::AxlePair  CSvsFZ;
    Math::AxlePair  C4;
    Math::AxlePair  C3;
    Math::AxlePair  C2;
    Math::AxlePair  C1;
    Math::AxlePair  BRAKES;
    Math::AxlePair  ASPECT_RATIO;
    Math::AxlePair  A4;
    Math::AxlePair  A3;
    Math::AxlePair  A2;
    Math::AxlePair  A1;
    Math::AxlePair  A0;
    float           WHEEL_BASE;
    float           TORQUE_SPLIT;
    float           TORQUE_SLIP_SLOPE0;
    float           TANK_SLAPPER_TIMER;
    float           _0xbe9cf1a0;
    float           _0xfdc201f0;
    float           _0x75e363f1;
    float           _0x618f8606;
    float           _0x516a8498;
    float           _0x55f90e57;
    float           STEERING_ALIGNING_TORQUE;
    float           SPOOL_TIME_UP;
    float           SPOOL_TIME_DOWN;
    float           SHOCK_BLOWOUT;
    float           SHIFT_SPEED;
    float           ROLL_CENTER;
    float           RENDER_MOTION;
    float           RED_LINE;
    float           OPTIMAL_SHIFT;
    float           MIN_TIRE_TRACTION_TO_SHIFT_UP_FIRST_GEAR;
    float           MIN_TIRE_TRACTION_TO_SHIFT_UP;
    float           MAX_RPM;
    float           MASS;
    float           LOW_BOOST;
    float           LIFT_HEIGHT_RATIO;
    float           IDLE;
    float           HIGH_BOOST;
    float           GROUNDEFFECT_HEIGHT_RATIO;
    float           FRONT_WEIGHT_BIAS;
    float           FRONT_AXLE;
    float           FLYWHEEL_MASS;
    float           FINAL_GEAR;
    float           EBRAKE;
    float           DYNAMIC_ROLL_CENTER_MIN_ANGLE;
    float           DYNAMIC_ROLL_CENTER_MAX_ANGLE;
    float           DYNAMIC_ROLL_CENTER_CORRECTION;
    float           DRAG_COEFFICIENT;
    float           COUNTER_STEER_MIN_ANGLE;
    float           CLUTCH_SLIP;
    float           CASTER;
    float           AERO_COEFFICIENT_MAX_LIFT;
    float           AERO_COEFFICIENT_MAX_GROUND_EFFECT;
    float           AERO_COEFFICIENT_90_DEG_LOSS;
    float           AERO_COEFFICIENT;
    float           AERO_CG;
  };
}  // namespace NFSPluginSDK::ProStreet::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_VEHICLELAYOUT_H
