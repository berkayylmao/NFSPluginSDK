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
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/RefSpec.h>

namespace OpenSpeed::ProStreet::Attrib::Layouts {
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
    float           STEERING_ALIGNING_TORQUE;
    float           SPOOL_TIME_UP;
    float           SPOOL_TIME_DOWN;
    float           SHOCK_BLOWOUT;
    float           SHIFT_SPEED;
    float           ROLL_CENTER;
    float           RENDER_MOTION;
    float           RED_LINE;
    float           OPTIMAL_SHIFT;
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
}  // namespace OpenSpeed::ProStreet::Attrib::Layouts
