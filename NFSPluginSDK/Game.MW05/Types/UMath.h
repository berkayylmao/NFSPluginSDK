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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_UMATH_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_UMATH_H
#pragma once

#include <NFSPluginSDK/Shared/UMath.h>

namespace NFSPluginSDK::MW05::UMath {
  using Vector2 = NFSPluginSDK::UVector2;
  using Vector3 = NFSPluginSDK::UVector3;

  struct Vector4 : NFSPluginSDK::UVector4 {
    // RightVector [Roll]
    inline void ExtractXAxis(Vector3* to) const {
      reinterpret_cast<void(__cdecl*)(const Vector4*, Vector3*)>(0x5CA6F0)(this, to);
    }
    // UpVector [Pitch]
    inline void ExtractYAxis(Vector3* to) const {
      reinterpret_cast<void(__cdecl*)(const Vector4*, Vector3*)>(0x5CA7B0)(this, to);
    }
    // ForwardVector [Yaw]
    inline void ExtractZAxis(Vector3* to) const {
      reinterpret_cast<void(__cdecl*)(const Vector4*, Vector3*)>(0x5CA870)(this, to);
    }

    inline void ToMatrix4(Matrix4* to) const {
      reinterpret_cast<void(__cdecl*)(const Vector4*, Matrix4*)>(0x5CA910)(this, to);
    }

    inline Vector4& operator=(const UVector4& r) {
      x = r.x;
      y = r.y;
      z = r.z;
      w = r.w;

      return *this;
    }
  };
  struct Matrix4 : NFSPluginSDK::UMatrix4 {
    Vector4 v0, v1, v2, v3;

    inline void ToQuaternion(Vector4* to) const {
      reinterpret_cast<void(__cdecl*)(const Matrix4*, Vector4*)>(0x5D06A0)(this, to);
    }

    inline Matrix4& operator=(const UMatrix4& r) {
      v0 = r.v0;
      v1 = r.v1;
      v2 = r.v2;
      v3 = r.v3;

      return *this;
    }
  };
}  // namespace NFSPluginSDK::MW05::UMath

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_UMATH_H
