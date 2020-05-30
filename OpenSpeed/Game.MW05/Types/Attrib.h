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
  struct Instance {
    enum class Flags : std::uint32_t { Dynamic = 1 };

    void*         p_mCollection;
    void*         mLayoutPtr;
    std::uint32_t mMsgPort;
    Flags         mFlags;
  };
  struct Private {
    std::uint16_t mCapacity;
    std::uint16_t mCount;
    std::uint16_t mElemSize;
    std::uint16_t mData;
  };
  struct StringKey {
    std::uint32_t mHash32;
    const char*   mString;

    StringKey(std::uint32_t hash, const char* cstring) : mHash32(hash), mString(cstring) {}
  };

  namespace Gen {
    struct collisionreactions {};
    struct pvehicle : Instance {
      std::uint32_t ClassKey;

      pvehicle(std::uint32_t classKey) : ClassKey(classKey) {}
    };
    struct rigidbodyspecs : Instance {
      struct _LayoutStruct {
        UMath::Vector4    WORLD_MOMENT_SCALE;
        UMath::Vector4    WALL_ELASTICITY;
        UMath::Vector4    OBJ_MOMENT_SCALE;
        UMath::Vector4    OBJ_ELASTICITY;
        UMath::Vector4    GROUND_MOMENT_SCALE;
        UMath::Vector4    GROUND_ELASTICITY;
        UMath::Vector4    DRAG_ANGULAR;
        UMath::Vector4    DRAG;
        UMath::Vector4    COLLISION_BOX_PAD;
        UMath::Vector4    CG;
        Attrib::StringKey DEFAULT_COL_BOX;
        Attrib::StringKey BASE_MATERIAL;
        Attrib::Private   _Array_WALL_FRICTION;
        float             WALL_FRICTION[2];
        Attrib::Private   _Array_OBJ_FRICTION;
        float             OBJ_FRICTION[2];
        Attrib::Private   _Array_GROUND_FRICTION;
        float             GROUND_FRICTION[2];
        float             GRAVITY;
        bool              NO_WORLD_COLLISIONS;
        bool              NO_OBJ_COLLISIONS;
        bool              NO_GROUND_COLLISIONS;
        float             NATURAL_ANGULAR_DAMPING;
        bool              INSTANCE_COLLISIONS_3D;
        bool              IMMOBILE_OBJECT_COLLISIONS;
      };

      _LayoutStruct mLayout;
    };
    struct simsurface {};
  }  // namespace Gen

  static inline auto StringToKey(const char* cstring) {
    return reinterpret_cast<StringKey(__cdecl*)(const char*)>(0x454640)(cstring);
  }
}  // namespace OpenSpeed::MW05::Attrib
