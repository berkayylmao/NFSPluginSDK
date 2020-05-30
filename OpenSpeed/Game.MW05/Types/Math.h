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

namespace OpenSpeed::MW05::Math {
  struct Vector2 {
    float x, y;

    Vector2() : x(0.0f), y(0.0f) {}
    Vector2(float x, float y) : x(x), y(y) {}

    float&       operator[](size_t index) { return ((float*)this)[index]; }
    const float& operator[](size_t index) const { return ((float*)this)[index]; }
    void         operator=(const Vector2& newVec) {
      this->x = newVec.x;
      this->y = newVec.y;
    }

    void operator-=(const Vector2& decVec) {
      this->x -= decVec.x;
      this->y -= decVec.y;
    }
    Vector2 operator-(const Vector2& rhs) const {
      Vector2 result = *this;
      result -= rhs;
      return result;
    }

    void operator+=(const Vector2& incVec) {
      this->x += incVec.x;
      this->y += incVec.y;
    }
    Vector2 operator+(const Vector2& rhs) const {
      Vector2 result = *this;
      result += rhs;
      return result;
    }

    void operator*=(const Vector2& mulVec) {
      this->x *= mulVec.x;
      this->y *= mulVec.y;
    }
    Vector2 operator*(const Vector2& rhs) const {
      Vector2 result = *this;
      result *= rhs;
      return result;
    }
    void    operator*=(const float mulFactor) { *this *= Vector2(mulFactor, mulFactor); }
    Vector2 operator*(const float mulFactor) const {
      Vector2 result = *this;
      result *= mulFactor;
      return result;
    }
  };
  struct Vector3 {
    float x, y, z;

    Vector3() : x(0.0f), y(0.0f), z(0.0f) {}
    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    float&       operator[](size_t index) { return ((float*)this)[index]; }
    const float& operator[](size_t index) const { return ((float*)this)[index]; }
    void         operator=(const Vector3& newVec) {
      this->x = newVec.x;
      this->y = newVec.y;
      this->z = newVec.z;
    }

    void operator-=(const Vector3& decVec) {
      this->x -= decVec.x;
      this->y -= decVec.y;
      this->z -= decVec.z;
    }
    Vector3 operator-(const Vector3& rhs) const {
      Vector3 result = *this;
      result -= rhs;
      return result;
    }

    void operator+=(const Vector3& incVec) {
      this->x += incVec.x;
      this->y += incVec.y;
      this->z += incVec.z;
    }
    Vector3 operator+(const Vector3& rhs) const {
      Vector3 result = *this;
      result += rhs;
      return result;
    }

    void operator*=(const Vector3& mulVec) {
      this->x *= mulVec.x;
      this->y *= mulVec.y;
      this->z *= mulVec.z;
    }
    Vector3 operator*(const Vector3& rhs) const {
      Vector3 result = *this;
      result *= rhs;
      return result;
    }

    void    operator*=(const float mulFactor) { *this *= Vector3(mulFactor, mulFactor, mulFactor); }
    Vector3 operator*(const float mulFactor) const {
      Vector3 result = *this;
      result *= mulFactor;
      return result;
    }
  };
  struct Vector4 {
    float x, y, z, w;

    Vector4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f) {}
    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

    float&       operator[](size_t index) { return ((float*)this)[index]; }
    const float& operator[](size_t index) const { return ((float*)this)[index]; }
    void         operator=(const Vector4& newVec) {
      this->x = newVec.x;
      this->y = newVec.y;
      this->z = newVec.z;
      this->w = newVec.w;
    }

    void operator-=(const Vector4& decVec) {
      this->x -= decVec.x;
      this->y -= decVec.y;
      this->z -= decVec.z;
      this->w -= decVec.w;
    }
    Vector4 operator-(const Vector4& rhs) const {
      Vector4 result = *this;
      result -= rhs;
      return result;
    }

    void operator+=(const Vector4& incVec) {
      this->x += incVec.x;
      this->y += incVec.y;
      this->z += incVec.z;
      this->w += incVec.w;
    }
    Vector4 operator+(const Vector4& rhs) const {
      Vector4 result = *this;
      result += rhs;
      return result;
    }

    void operator*=(const Vector4& mulVec) {
      this->x *= mulVec.x;
      this->y *= mulVec.y;
      this->z *= mulVec.z;
      this->w *= mulVec.w;
    }
    Vector4 operator*(const Vector4& rhs) const {
      Vector4 result = *this;
      result *= rhs;
      return result;
    }

    void    operator*=(const float mulFactor) { *this *= Vector4(mulFactor, mulFactor, mulFactor, mulFactor); }
    Vector4 operator*(const float mulFactor) const {
      Vector4 result = *this;
      result *= mulFactor;
      return result;
    }
  };
  struct Matrix4 {
    Vector4 v0, v1, v2, v3;

    Matrix4() : v0(), v1(), v2(), v3() {}
    Matrix4(const Vector4& v0, const Vector4& v1, const Vector4& v2, const Vector4& v3) :
        v0(v0), v1(v1), v2(v2), v3(v3) {}

    Vector4&       operator[](size_t index) { return ((Vector4*)this)[index]; }
    const Vector4& operator[](size_t index) const { return ((Vector4*)this)[index]; }
    void           operator=(const Matrix4& newMatrix) {
      this->v0 = newMatrix.v0;
      this->v1 = newMatrix.v1;
      this->v2 = newMatrix.v2;
      this->v3 = newMatrix.v3;
    }

    void operator-=(const Matrix4& decVec) {
      this->v0 -= decVec.v0;
      this->v1 -= decVec.v1;
      this->v2 -= decVec.v2;
      this->v3 -= decVec.v3;
    }
    Matrix4 operator-(const Matrix4& rhs) const {
      Matrix4 result = *this;
      result -= rhs;
      return result;
    }

    void operator+=(const Matrix4& incVec) {
      this->v0 += incVec.v0;
      this->v1 += incVec.v1;
      this->v2 += incVec.v2;
      this->v3 += incVec.v3;
    }
    Matrix4 operator+(const Matrix4& rhs) const {
      Matrix4 result = *this;
      result += rhs;
      return result;
    }

    void operator*=(const Matrix4& mulVec) {
      this->v0 *= mulVec.v0;
      this->v1 *= mulVec.v1;
      this->v2 *= mulVec.v2;
      this->v3 *= mulVec.v3;
    }
    Matrix4 operator*(const Matrix4& rhs) const {
      Matrix4 result = *this;
      result *= rhs;
      return result;
    }

    void operator*=(const float mulFactor) {
      Vector4 mulVec(mulFactor, mulFactor, mulFactor, mulFactor);
      *this *= Matrix4(mulVec, mulVec, mulVec, mulVec);
    }
    Matrix4 operator*(const float mulFactor) const {
      Matrix4 result = *this;
      result *= mulFactor;
      return result;
    }
  };
}  // namespace OpenSpeed::MW05::Math
