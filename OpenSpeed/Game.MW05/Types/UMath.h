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

namespace OpenSpeed::MW05::UMath {
  struct Vector2 {
    float y, x;

    Vector2 operator+(const Vector2& rhs) const noexcept {
      Vector2 _result = *this;
      _result.x += rhs.x;
      _result.y += rhs.y;

      return _result;
    }
    Vector2 operator-(const Vector2& rhs) const noexcept {
      Vector2 _result = *this;
      _result.x -= rhs.x;
      _result.y -= rhs.y;

      return _result;
    }
    Vector2 operator*(const Vector2& rhs) const noexcept {
      Vector2 _result = *this;
      _result.x *= rhs.x;
      _result.y *= rhs.y;

      return _result;
    }
    Vector2 operator/(const Vector2& rhs) const noexcept {
      Vector2 _result = *this;
      _result.x /= rhs.x;
      _result.y /= rhs.y;

      return _result;
    }
    Vector2 operator*(float rhs) const noexcept {
      Vector2 _result = *this;
      _result.x *= rhs;
      _result.y *= rhs;

      return _result;
    }
    Vector2 operator/(float rhs) const noexcept {
      Vector2 _result = *this;
      _result.x /= rhs;
      _result.y /= rhs;

      return _result;
    }

    void operator=(const Vector2& rhs) {
      this->x = rhs.x;
      this->y = rhs.y;
    }
    void operator+=(const Vector2& rhs) { *this = *this + rhs; }
    void operator-=(const Vector2& rhs) { *this = *this - rhs; }
    void operator*=(const Vector2& rhs) { *this = *this * rhs; }
    void operator/=(const Vector2& rhs) { *this = *this / rhs; }
    void operator*=(float rhs) { *this = *this * rhs; }
    void operator/=(float rhs) { *this = *this / rhs; }

                 operator float*() noexcept { return reinterpret_cast<float*>(this); }
                 operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    const float& operator[](std::size_t index) const noexcept { return (reinterpret_cast<const float*>(this))[index]; }

    Vector2() : x(0.0f), y(0.0f) {}
    ~Vector2() = default;
    Vector2(float x, float y) : x(x), y(y) {}
  };
  struct Vector3 {
    float y, z, x;

    Vector3 operator+(const Vector3& rhs) const noexcept {
      Vector3 _result = *this;
      _result.x += rhs.x;
      _result.y += rhs.y;
      _result.z += rhs.z;

      return _result;
    }
    Vector3 operator-(const Vector3& rhs) const noexcept {
      Vector3 _result = *this;
      _result.x -= rhs.x;
      _result.y -= rhs.y;
      _result.z -= rhs.z;

      return _result;
    }
    Vector3 operator*(const Vector3& rhs) const noexcept {
      Vector3 _result = *this;
      _result.x *= rhs.x;
      _result.y *= rhs.y;
      _result.z *= rhs.z;

      return _result;
    }
    Vector3 operator/(const Vector3& rhs) const noexcept {
      Vector3 _result = *this;
      _result.x /= rhs.x;
      _result.y /= rhs.y;
      _result.z /= rhs.z;

      return _result;
    }
    Vector3 operator*(float rhs) const noexcept {
      Vector3 _result = *this;
      _result.x *= rhs;
      _result.y *= rhs;
      _result.z *= rhs;

      return _result;
    }
    Vector3 operator/(float rhs) const noexcept {
      Vector3 _result = *this;
      _result.x /= rhs;
      _result.y /= rhs;
      _result.z /= rhs;

      return _result;
    }

    void operator=(const Vector3& rhs) {
      this->x = rhs.x;
      this->y = rhs.y;
      this->z = rhs.z;
    }
    void operator+=(const Vector3& rhs) { *this = *this + rhs; }
    void operator-=(const Vector3& rhs) { *this = *this - rhs; }
    void operator*=(const Vector3& rhs) { *this = *this * rhs; }
    void operator/=(const Vector3& rhs) { *this = *this / rhs; }
    void operator*=(float rhs) { *this = *this * rhs; }
    void operator/=(float rhs) { *this = *this / rhs; }

                 operator float*() noexcept { return reinterpret_cast<float*>(this); }
                 operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    const float& operator[](std::size_t index) const noexcept { return (reinterpret_cast<const float*>(this))[index]; }

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    ~Vector3() = default;
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
  };
  struct Vector4 {
    float y, z, x, w;

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

    Vector4 operator+(const Vector4& rhs) const noexcept {
      Vector4 _result = *this;
      _result.x += rhs.x;
      _result.y += rhs.y;
      _result.z += rhs.z;
      _result.w += rhs.w;

      return _result;
    }
    Vector4 operator-(const Vector4& rhs) const noexcept {
      Vector4 _result = *this;
      _result.x -= rhs.x;
      _result.y -= rhs.y;
      _result.z -= rhs.z;
      _result.w -= rhs.w;

      return _result;
    }
    Vector4 operator*(const Vector4& rhs) const noexcept {
      Vector4 _result = *this;
      _result.x *= rhs.x;
      _result.y *= rhs.y;
      _result.z *= rhs.z;
      _result.w *= rhs.w;

      return _result;
    }
    Vector4 operator/(const Vector4& rhs) const noexcept {
      Vector4 _result = *this;
      _result.x /= rhs.x;
      _result.y /= rhs.y;
      _result.z /= rhs.z;
      _result.w /= rhs.w;

      return _result;
    }
    Vector4 operator*(float rhs) const noexcept {
      Vector4 _result = *this;
      _result.x *= rhs;
      _result.y *= rhs;
      _result.z *= rhs;
      _result.w *= rhs;

      return _result;
    }
    Vector4 operator/(float rhs) const noexcept {
      Vector4 _result = *this;
      _result.x /= rhs;
      _result.y /= rhs;
      _result.z /= rhs;
      _result.w /= rhs;

      return _result;
    }

    void operator=(const Vector4& rhs) {
      this->x = rhs.x;
      this->y = rhs.y;
      this->z = rhs.z;
      this->w = rhs.w;
    }
    void operator+=(const Vector4& rhs) { *this = *this + rhs; }
    void operator-=(const Vector4& rhs) { *this = *this - rhs; }
    void operator*=(const Vector4& rhs) { *this = *this * rhs; }
    void operator/=(const Vector4& rhs) { *this = *this / rhs; }
    void operator*=(float rhs) { *this = *this * rhs; }
    void operator/=(float rhs) { *this = *this / rhs; }

                 operator float*() noexcept { return reinterpret_cast<float*>(this); }
                 operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    const float& operator[](std::size_t index) const noexcept { return (reinterpret_cast<const float*>(this))[index]; }

    Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    ~Vector4() = default;
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
  };
  struct Matrix4 {
    Vector4 v0, v1, v2, v3;

    inline void ToQuaternion(Vector4* to) const {
      reinterpret_cast<void(__cdecl*)(const Matrix4*, Vector4*)>(0x5D06A0)(this, to);
    }

    Matrix4 operator+(const Matrix4& rhs) {
      Matrix4 _result = *this;
      _result.v0 += rhs.v0;
      _result.v1 += rhs.v1;
      _result.v2 += rhs.v2;
      _result.v3 += rhs.v3;

      return _result;
    }
    Matrix4 operator-(const Matrix4& rhs) {
      Matrix4 _result = *this;
      _result.v0 -= rhs.v0;
      _result.v1 -= rhs.v1;
      _result.v2 -= rhs.v2;
      _result.v3 -= rhs.v3;

      return _result;
    }
    Matrix4 operator*(const Matrix4& rhs) {
      Matrix4 _result = *this;
      _result.v0 *= rhs.v0;
      _result.v1 *= rhs.v1;
      _result.v2 *= rhs.v2;
      _result.v3 *= rhs.v3;

      return _result;
    }
    Matrix4 operator/(const Matrix4& rhs) {
      Matrix4 _result = *this;
      _result.v0 /= rhs.v0;
      _result.v1 /= rhs.v1;
      _result.v2 /= rhs.v2;
      _result.v3 /= rhs.v3;

      return _result;
    }
    Matrix4 operator*(float rhs) {
      Matrix4 _result = *this;
      _result.v0 *= rhs;
      _result.v1 *= rhs;
      _result.v2 *= rhs;
      _result.v3 *= rhs;

      return _result;
    }
    Matrix4 operator/(float rhs) {
      Matrix4 _result = *this;
      _result.v0 /= rhs;
      _result.v1 /= rhs;
      _result.v2 /= rhs;
      _result.v3 /= rhs;

      return _result;
    }

    void operator=(const Matrix4& rhs) {
      this->v0 = rhs.v0;
      this->v1 = rhs.v1;
      this->v2 = rhs.v2;
      this->v3 = rhs.v3;
    }
    void operator+=(const Matrix4& rhs) { *this = *this + rhs; }
    void operator-=(const Matrix4& rhs) { *this = *this - rhs; }
    void operator*=(const Matrix4& rhs) { *this = *this * rhs; }
    void operator/=(const Matrix4& rhs) { *this = *this / rhs; }
    void operator*=(float rhs) { *this = *this * rhs; }
    void operator/=(float rhs) { *this = *this / rhs; }

                   operator float*() noexcept { return reinterpret_cast<float*>(this); }
                   operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
                   operator Vector4*() noexcept { return reinterpret_cast<Vector4*>(this); }
                   operator const Vector4*() const noexcept { return reinterpret_cast<const Vector4*>(this); }
    Vector4&       operator[](std::size_t index) noexcept { return (reinterpret_cast<Vector4*>(this))[index]; }
    const Vector4& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const Vector4*>(this))[index];
    }

    Matrix4()  = default;
    ~Matrix4() = default;
    Matrix4(Vector4 v0, Vector4 v1, Vector4 v2, Vector4 v3) : v0(v0), v1(v1), v2(v2), v3(v3) {}
  };
}  // namespace OpenSpeed::MW05::UMath
