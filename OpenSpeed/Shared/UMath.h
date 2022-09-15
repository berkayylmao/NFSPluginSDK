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

#ifndef OPENSPEED_SHARED_UMATH_H
#define OPENSPEED_SHARED_UMATH_H
#pragma once

#include <cmath>

namespace OpenSpeed {
  struct UVector2 {
    float y, x;

    float GetDistance(const UVector2& other) const noexcept {
      float dx = other.x - x;
      float dy = other.y - y;
      return std::sqrt(dx * dx + dy * dy);
    }
    UVector2 Normalize() const noexcept {
      float t = std::sqrt(x * x + y * y);
      return UVector2(x / t, y / t);
    }

    inline bool operator<(const UVector2& r) const noexcept { return (x < r.x) && (y < r.y); }
    inline bool operator>(const UVector2& r) const noexcept { return r < *this; }
    inline bool operator<=(const UVector2& r) const noexcept { return !(*this > r); }
    inline bool operator>=(const UVector2& r) const noexcept { return !(*this < r); }

    inline UVector2 operator+(const UVector2& r) const noexcept {
      UVector2 ret = *this;
      ret.x += r.x;
      ret.y += r.y;

      return ret;
    }
    inline UVector2 operator-(const UVector2& r) const noexcept {
      UVector2 ret = *this;
      ret.x -= r.x;
      ret.y -= r.y;

      return ret;
    }
    inline UVector2 operator*(const UVector2& r) const noexcept {
      UVector2 ret = *this;
      ret.x *= r.x;
      ret.y *= r.y;

      return ret;
    }
    inline UVector2 operator/(const UVector2& r) const noexcept {
      UVector2 ret = *this;
      ret.x /= r.x;
      ret.y /= r.y;

      return ret;
    }
    inline UVector2 operator*(float r) const noexcept {
      UVector2 ret = *this;
      ret.x *= r;
      ret.y *= r;

      return ret;
    }
    inline UVector2 operator/(float r) const noexcept {
      UVector2 ret = *this;
      ret.x /= r;
      ret.y /= r;

      return ret;
    }

    inline UVector2& operator=(const UVector2& r) noexcept {
      x = r.x;
      y = r.y;

      return *this;
    }
    inline void operator+=(const UVector2& r) noexcept { *this = *this + r; }
    inline void operator-=(const UVector2& r) noexcept { *this = *this - r; }
    inline void operator*=(const UVector2& r) noexcept { *this = *this * r; }
    inline void operator/=(const UVector2& r) noexcept { *this = *this / r; }
    inline void operator*=(float r) noexcept { *this = *this * r; }
    inline void operator/=(float r) noexcept { *this = *this / r; }

    inline              operator float*() noexcept { return reinterpret_cast<float*>(this); }
    inline              operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    inline float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    inline const float& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const float*>(this))[index];
    }

    UVector2(float x, float y) : x(x), y(y) {}
    UVector2() : UVector2(0.0f, 0.0f) {}
  };
  struct UVector3 {
    float y, z, x;

    float GetDistance(const UVector3& other) const noexcept {
      float dx = other.x - x;
      float dy = other.y - y;
      float dz = other.z - z;
      return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
    UVector3 Normalize() const noexcept {
      float t = std::sqrt(x * x + y * y + z * z);
      return UVector3(x / t, y / t, z / t);
    }

    inline bool operator<(const UVector3& r) const noexcept { return (x < r.x) && (y < r.y) && (z < r.z); }
    inline bool operator>(const UVector3& r) const noexcept { return r < *this; }
    inline bool operator<=(const UVector3& r) const noexcept { return !(*this > r); }
    inline bool operator>=(const UVector3& r) const noexcept { return !(*this < r); }

    inline UVector3 operator+(const UVector3& r) const noexcept {
      UVector3 ret = *this;
      ret.x += r.x;
      ret.y += r.y;
      ret.z += r.z;

      return ret;
    }
    inline UVector3 operator-(const UVector3& r) const noexcept {
      UVector3 ret = *this;
      ret.x -= r.x;
      ret.y -= r.y;
      ret.z -= r.z;

      return ret;
    }
    inline UVector3 operator*(const UVector3& r) const noexcept {
      UVector3 ret = *this;
      ret.x *= r.x;
      ret.y *= r.y;
      ret.z *= r.z;

      return ret;
    }
    inline UVector3 operator/(const UVector3& r) const noexcept {
      UVector3 ret = *this;
      ret.x /= r.x;
      ret.y /= r.y;
      ret.z /= r.z;

      return ret;
    }
    inline UVector3 operator*(float r) const noexcept {
      UVector3 ret = *this;
      ret.x *= r;
      ret.y *= r;
      ret.z *= r;

      return ret;
    }
    inline UVector3 operator/(float r) const noexcept {
      UVector3 ret = *this;
      ret.x /= r;
      ret.y /= r;
      ret.z /= r;

      return ret;
    }

    inline UVector3& operator=(const UVector3& r) noexcept {
      x = r.x;
      y = r.y;
      z = r.z;

      return *this;
    }
    inline void operator+=(const UVector3& r) noexcept { *this = *this + r; }
    inline void operator-=(const UVector3& r) noexcept { *this = *this - r; }
    inline void operator*=(const UVector3& r) noexcept { *this = *this * r; }
    inline void operator/=(const UVector3& r) noexcept { *this = *this / r; }
    inline void operator*=(float r) noexcept { *this = *this * r; }
    inline void operator/=(float r) noexcept { *this = *this / r; }

    inline              operator float*() noexcept { return reinterpret_cast<float*>(this); }
    inline              operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    inline float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    inline const float& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const float*>(this))[index];
    }

    UVector3(float x, float y, float z) : x(x), y(y), z(z) {}
    UVector3() : UVector3(0.0f, 0.0f, 0.0f) {}
  };
  struct UVector4 {
    float y, z, x, w;

    float GetDistance(const UVector4& other) const noexcept {
      float dx = other.x - x;
      float dy = other.y - y;
      float dz = other.z - z;
      float dw = other.w - w;
      return std::sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
    }
    UVector4 Normalize() const noexcept {
      float t = std::sqrt(x * x + y * y + z * z + w * w);
      return UVector4(x / t, y / t, z / t, w / t);
    }

    inline bool operator<(const UVector4& r) const noexcept { return (x < r.x) && (y < r.y) && (z < r.z) && (w < r.w); }
    inline bool operator>(const UVector4& r) const noexcept { return r < *this; }
    inline bool operator<=(const UVector4& r) const noexcept { return !(*this > r); }
    inline bool operator>=(const UVector4& r) const noexcept { return !(*this < r); }

    inline UVector4 operator+(const UVector4& r) const noexcept {
      UVector4 ret = *this;
      ret.x += r.x;
      ret.y += r.y;
      ret.z += r.z;
      ret.w += r.w;

      return ret;
    }
    inline UVector4 operator-(const UVector4& r) const noexcept {
      UVector4 ret = *this;
      ret.x -= r.x;
      ret.y -= r.y;
      ret.z -= r.z;
      ret.w -= r.w;

      return ret;
    }
    inline UVector4 operator*(const UVector4& r) const noexcept {
      UVector4 ret = *this;
      ret.x *= r.x;
      ret.y *= r.y;
      ret.z *= r.z;
      ret.w *= r.w;

      return ret;
    }
    inline UVector4 operator/(const UVector4& r) const noexcept {
      UVector4 ret = *this;
      ret.x /= r.x;
      ret.y /= r.y;
      ret.z /= r.z;
      ret.w /= r.w;

      return ret;
    }
    inline UVector4 operator*(float r) const noexcept {
      UVector4 ret = *this;
      ret.x *= r;
      ret.y *= r;
      ret.z *= r;
      ret.w *= r;

      return ret;
    }
    inline UVector4 operator/(float r) const noexcept {
      UVector4 ret = *this;
      ret.x /= r;
      ret.y /= r;
      ret.z /= r;
      ret.w /= r;

      return ret;
    }

    inline UVector4& operator=(const UVector4& r) noexcept {
      x = r.x;
      y = r.y;
      z = r.z;
      w = r.w;

      return *this;
    }
    inline void operator+=(const UVector4& r) noexcept { *this = *this + r; }
    inline void operator-=(const UVector4& r) noexcept { *this = *this - r; }
    inline void operator*=(const UVector4& r) noexcept { *this = *this * r; }
    inline void operator/=(const UVector4& r) noexcept { *this = *this / r; }
    inline void operator*=(float r) noexcept { *this = *this * r; }
    inline void operator/=(float r) noexcept { *this = *this / r; }

    inline              operator float*() noexcept { return reinterpret_cast<float*>(this); }
    inline              operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    inline float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    inline const float& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const float*>(this))[index];
    }

    UVector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    UVector4() : UVector4(0.0f, 0.0f, 0.0f, 0.0f) {}
  };
  struct UMatrix4 {
    UVector4 v0, v1, v2, v3;

    inline UMatrix4 operator+(const UMatrix4& r) const noexcept {
      UMatrix4 ret = *this;
      ret.v0 += r.v0;
      ret.v1 += r.v1;
      ret.v2 += r.v2;
      ret.v3 += r.v3;

      return ret;
    }
    inline UMatrix4 operator-(const UMatrix4& r) const noexcept {
      UMatrix4 ret = *this;
      ret.v0 -= r.v0;
      ret.v1 -= r.v1;
      ret.v2 -= r.v2;
      ret.v3 -= r.v3;

      return ret;
    }
    inline UMatrix4 operator*(const UMatrix4& r) const noexcept {
      UMatrix4 ret = *this;
      ret.v0 *= r.v0;
      ret.v1 *= r.v1;
      ret.v2 *= r.v2;
      ret.v3 *= r.v3;

      return ret;
    }
    inline UMatrix4 operator/(const UMatrix4& r) const noexcept {
      UMatrix4 ret = *this;
      ret.v0 /= r.v0;
      ret.v1 /= r.v1;
      ret.v2 /= r.v2;
      ret.v3 /= r.v3;

      return ret;
    }
    inline UMatrix4 operator*(float r) const noexcept {
      UMatrix4 ret = *this;
      ret.v0 *= r;
      ret.v1 *= r;
      ret.v2 *= r;
      ret.v3 *= r;

      return ret;
    }
    inline UMatrix4 operator/(float r) const noexcept {
      UMatrix4 ret = *this;
      ret.v0 /= r;
      ret.v1 /= r;
      ret.v2 /= r;
      ret.v3 /= r;

      return ret;
    }

    inline UMatrix4& operator=(const UMatrix4& r) noexcept {
      v0 = r.v0;
      v1 = r.v1;
      v2 = r.v2;
      v3 = r.v3;

      return *this;
    }
    inline void operator+=(const UMatrix4& r) noexcept { *this = *this + r; }
    inline void operator-=(const UMatrix4& r) noexcept { *this = *this - r; }
    inline void operator*=(const UMatrix4& r) noexcept { *this = *this * r; }
    inline void operator/=(const UMatrix4& r) noexcept { *this = *this / r; }
    inline void operator*=(float r) noexcept { *this = *this * r; }
    inline void operator/=(float r) noexcept { *this = *this / r; }

    inline                 operator float*() noexcept { return reinterpret_cast<float*>(this); }
    inline                 operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    inline                 operator UVector4*() noexcept { return reinterpret_cast<UVector4*>(this); }
    inline                 operator const UVector4*() const noexcept { return reinterpret_cast<const UVector4*>(this); }
    inline UVector4&       operator[](std::size_t index) noexcept { return (reinterpret_cast<UVector4*>(this))[index]; }
    inline const UVector4& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const UVector4*>(this))[index];
    }

    UMatrix4(UVector4 v0, UVector4 v1, UVector4 v2, UVector4 v3) : v0(v0), v1(v1), v2(v2), v3(v3) {}
    UMatrix4() : UMatrix4(UVector4(), UVector4(), UVector4(), UVector4()) {}
  };
}  // namespace OpenSpeed

#endif  // OPENSPEED_SHARED_UMATH_H
