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
#include <OpenSpeed/Game.Carbon/Types.h>
#include <OpenSpeed/Game.Carbon/Types/Attrib/Private.h>

namespace OpenSpeed::Carbon::Attrib::Layouts {
  struct rigidbodyspecslayout {
    Math::Vector4 COLLISION_BOX_PAD;
    Math::Vector4 DRAG;
    Math::Vector4 WORLD_MOMENT_SCALE;
    Math::Vector4 OBJ_MOMENT_SCALE;
    Math::Vector4 GROUND_ELASTICITY;
    Math::Vector4 OBJ_ELASTICITY;
    Math::Vector4 DRAG_ANGULAR;
    Math::Vector4 WALL_ELASTICITY;
    Math::Vector4 GROUND_MOMENT_SCALE;
    Math::Vector4 CG;
    StringKey     BASE_MATERIAL;
    StringKey     DEFAULT_COL_BOX;
    Private       _Array_OBJ_FRICTION;
    Math::Vector2 OBJ_FRICTION;
    Private       _Array_WALL_FRICTION;
    Math::Vector2 WALL_FRICTION;
    Private       _Array_GROUND_FRICTION;
    Math::Vector2 GROUND_FRICTION;
    float         NATURAL_ANGULAR_DAMPING;
    float         GRAVITY;
    bool          NO_GROUND_COLLISIONS;
    bool          NO_OBJ_COLLISIONS;
    bool          INSTANCE_COLLISIONS_3D;
    __declspec(align(4)) float SLEEP_VELOCITY;
    bool IMMOBILE_OBJECT_COLLISIONS;
    bool NO_WORLD_COLLISIONS;
  };
}  // namespace OpenSpeed::Carbon::Attrib::Layouts
