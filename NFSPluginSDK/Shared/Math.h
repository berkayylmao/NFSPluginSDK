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

#ifndef NFSPLUGINSDK_SHARED_MATH_H
#define NFSPLUGINSDK_SHARED_MATH_H
#pragma once

#include <cmath>

namespace NFSPluginSDK {
  struct AxlePair {
    float Front;
    float Rear;

    AxlePair() : Front(0.0f), Rear(0.0f) {}
  };
  struct VariableArray {
    float*        mArray;
    std::uint32_t mLength;
  };
  struct Curve {
    float         xMin;
    float         xMax;
    float         yMin;
    float         yMax;
    VariableArray X;
    VariableArray Y;
    VariableArray Y2;
    bool          allocatedMemory;
  };
  struct Vector2 {
    float x, y;

    float GetDistance(const Vector2& other) const noexcept {
      float dx = other.x - x;
      float dy = other.y - y;
      return std::sqrt(dx * dx + dy * dy);
    }
    Vector2 Normalize() const noexcept {
      float t = std::sqrt(x * x + y * y);
      return Vector2(x / t, y / t);
    }

    inline bool operator<(const Vector2& r) const noexcept { return (x < r.x) && (y < r.y); }
    inline bool operator>(const Vector2& r) const noexcept { return r < *this; }
    inline bool operator<=(const Vector2& r) const noexcept { return !(*this > r); }
    inline bool operator>=(const Vector2& r) const noexcept { return !(*this < r); }

    inline Vector2 operator+(const Vector2& r) const noexcept {
      Vector2 ret = *this;
      ret.x += r.x;
      ret.y += r.y;

      return ret;
    }
    inline Vector2 operator-(const Vector2& r) const noexcept {
      Vector2 ret = *this;
      ret.x -= r.x;
      ret.y -= r.y;

      return ret;
    }
    inline Vector2 operator*(const Vector2& r) const noexcept {
      Vector2 ret = *this;
      ret.x *= r.x;
      ret.y *= r.y;

      return ret;
    }
    inline Vector2 operator/(const Vector2& r) const noexcept {
      Vector2 ret = *this;
      ret.x /= r.x;
      ret.y /= r.y;

      return ret;
    }
    inline Vector2 operator*(float r) const noexcept {
      Vector2 ret = *this;
      ret.x *= r;
      ret.y *= r;

      return ret;
    }
    inline Vector2 operator/(float r) const noexcept {
      Vector2 ret = *this;
      ret.x /= r;
      ret.y /= r;

      return ret;
    }

    inline Vector2& operator=(const Vector2& r) noexcept {
      x = r.x;
      y = r.y;

      return *this;
    }
    inline void operator+=(const Vector2& r) noexcept { *this = *this + r; }
    inline void operator-=(const Vector2& r) noexcept { *this = *this - r; }
    inline void operator*=(const Vector2& r) noexcept { *this = *this * r; }
    inline void operator/=(const Vector2& r) noexcept { *this = *this / r; }
    inline void operator*=(float r) noexcept { *this = *this * r; }
    inline void operator/=(float r) noexcept { *this = *this / r; }

    inline              operator float*() noexcept { return reinterpret_cast<float*>(this); }
    inline              operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    inline float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    inline const float& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const float*>(this))[index];
    }

    Vector2(float x, float y) : x(x), y(y) {}
    Vector2() : Vector2(0.0f, 0.0f) {}
  };
  struct Vector3 {
    float x, y, z;

    float GetDistance(const Vector3& other) const noexcept {
      float dx = other.x - x;
      float dy = other.y - y;
      float dz = other.z - z;
      return std::sqrt(dx * dx + dy * dy + dz * dz);
    }
    Vector3 Normalize() const noexcept {
      float t = std::sqrt(x * x + y * y + z * z);
      return Vector3(x / t, y / t, z / t);
    }

    inline bool operator<(const Vector3& r) const noexcept { return (x < r.x) && (y < r.y) && (z < r.z); }
    inline bool operator>(const Vector3& r) const noexcept { return r < *this; }
    inline bool operator<=(const Vector3& r) const noexcept { return !(*this > r); }
    inline bool operator>=(const Vector3& r) const noexcept { return !(*this < r); }

    inline Vector3 operator+(const Vector3& r) const noexcept {
      Vector3 ret = *this;
      ret.x += r.x;
      ret.y += r.y;
      ret.z += r.z;

      return ret;
    }
    inline Vector3 operator-(const Vector3& r) const noexcept {
      Vector3 ret = *this;
      ret.x -= r.x;
      ret.y -= r.y;
      ret.z -= r.z;

      return ret;
    }
    inline Vector3 operator*(const Vector3& r) const noexcept {
      Vector3 ret = *this;
      ret.x *= r.x;
      ret.y *= r.y;
      ret.z *= r.z;

      return ret;
    }
    inline Vector3 operator/(const Vector3& r) const noexcept {
      Vector3 ret = *this;
      ret.x /= r.x;
      ret.y /= r.y;
      ret.z /= r.z;

      return ret;
    }
    inline Vector3 operator*(float r) const noexcept {
      Vector3 ret = *this;
      ret.x *= r;
      ret.y *= r;
      ret.z *= r;

      return ret;
    }
    inline Vector3 operator/(float r) const noexcept {
      Vector3 ret = *this;
      ret.x /= r;
      ret.y /= r;
      ret.z /= r;

      return ret;
    }

    inline Vector3& operator=(const Vector3& r) noexcept {
      x = r.x;
      y = r.y;
      z = r.z;

      return *this;
    }
    inline void operator+=(const Vector3& r) noexcept { *this = *this + r; }
    inline void operator-=(const Vector3& r) noexcept { *this = *this - r; }
    inline void operator*=(const Vector3& r) noexcept { *this = *this * r; }
    inline void operator/=(const Vector3& r) noexcept { *this = *this / r; }
    inline void operator*=(float r) noexcept { *this = *this * r; }
    inline void operator/=(float r) noexcept { *this = *this / r; }

    inline              operator float*() noexcept { return reinterpret_cast<float*>(this); }
    inline              operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    inline float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    inline const float& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const float*>(this))[index];
    }

    Vector3(float x, float y, float z) : x(x), y(y), z(z) {}
    Vector3() : Vector3(0.0f, 0.0f, 0.0f) {}
  };
  struct Vector4 {
    float x, y, z, w;

    float GetDistance(const Vector4& other) const noexcept {
      float dx = other.x - x;
      float dy = other.y - y;
      float dz = other.z - z;
      float dw = other.w - w;
      return std::sqrt(dx * dx + dy * dy + dz * dz + dw * dw);
    }
    Vector4 Normalize() const noexcept {
      float t = std::sqrt(x * x + y * y + z * z + w * w);
      return Vector4(x / t, y / t, z / t, w / t);
    }

    inline bool operator<(const Vector4& r) const noexcept { return (x < r.x) && (y < r.y) && (z < r.z) && (w < r.w); }
    inline bool operator>(const Vector4& r) const noexcept { return r < *this; }
    inline bool operator<=(const Vector4& r) const noexcept { return !(*this > r); }
    inline bool operator>=(const Vector4& r) const noexcept { return !(*this < r); }

    inline Vector4 operator+(const Vector4& r) const noexcept {
      Vector4 ret = *this;
      ret.x += r.x;
      ret.y += r.y;
      ret.z += r.z;
      ret.w += r.w;

      return ret;
    }
    inline Vector4 operator-(const Vector4& r) const noexcept {
      Vector4 ret = *this;
      ret.x -= r.x;
      ret.y -= r.y;
      ret.z -= r.z;
      ret.w -= r.w;

      return ret;
    }
    inline Vector4 operator*(const Vector4& r) const noexcept {
      Vector4 ret = *this;
      ret.x *= r.x;
      ret.y *= r.y;
      ret.z *= r.z;
      ret.w *= r.w;

      return ret;
    }
    inline Vector4 operator/(const Vector4& r) const noexcept {
      Vector4 ret = *this;
      ret.x /= r.x;
      ret.y /= r.y;
      ret.z /= r.z;
      ret.w /= r.w;

      return ret;
    }
    inline Vector4 operator*(float r) const noexcept {
      Vector4 ret = *this;
      ret.x *= r;
      ret.y *= r;
      ret.z *= r;
      ret.w *= r;

      return ret;
    }
    inline Vector4 operator/(float r) const noexcept {
      Vector4 ret = *this;
      ret.x /= r;
      ret.y /= r;
      ret.z /= r;
      ret.w /= r;

      return ret;
    }

    inline Vector4& operator=(const Vector4& r) noexcept {
      x = r.x;
      y = r.y;
      z = r.z;
      w = r.w;

      return *this;
    }
    inline void operator+=(const Vector4& r) noexcept { *this = *this + r; }
    inline void operator-=(const Vector4& r) noexcept { *this = *this - r; }
    inline void operator*=(const Vector4& r) noexcept { *this = *this * r; }
    inline void operator/=(const Vector4& r) noexcept { *this = *this / r; }
    inline void operator*=(float r) noexcept { *this = *this * r; }
    inline void operator/=(float r) noexcept { *this = *this / r; }

    inline              operator float*() noexcept { return reinterpret_cast<float*>(this); }
    inline              operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    inline float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    inline const float& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const float*>(this))[index];
    }

    Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    Vector4() : Vector4(0.0f, 0.0f, 0.0f, 0.0f) {}
  };
  struct Matrix4 {
    Vector4 v0, v1, v2, v3;

    inline Matrix4 operator+(const Matrix4& r) const noexcept {
      Matrix4 ret = *this;
      ret.v0 += r.v0;
      ret.v1 += r.v1;
      ret.v2 += r.v2;
      ret.v3 += r.v3;

      return ret;
    }
    inline Matrix4 operator-(const Matrix4& r) const noexcept {
      Matrix4 ret = *this;
      ret.v0 -= r.v0;
      ret.v1 -= r.v1;
      ret.v2 -= r.v2;
      ret.v3 -= r.v3;

      return ret;
    }
    inline Matrix4 operator*(const Matrix4& r) const noexcept {
      Matrix4 ret = *this;
      ret.v0 *= r.v0;
      ret.v1 *= r.v1;
      ret.v2 *= r.v2;
      ret.v3 *= r.v3;

      return ret;
    }
    inline Matrix4 operator/(const Matrix4& r) const noexcept {
      Matrix4 ret = *this;
      ret.v0 /= r.v0;
      ret.v1 /= r.v1;
      ret.v2 /= r.v2;
      ret.v3 /= r.v3;

      return ret;
    }
    inline Matrix4 operator*(float r) const noexcept {
      Matrix4 ret = *this;
      ret.v0 *= r;
      ret.v1 *= r;
      ret.v2 *= r;
      ret.v3 *= r;

      return ret;
    }
    inline Matrix4 operator/(float r) const noexcept {
      Matrix4 ret = *this;
      ret.v0 /= r;
      ret.v1 /= r;
      ret.v2 /= r;
      ret.v3 /= r;

      return ret;
    }

    inline Matrix4& operator=(const Matrix4& r) noexcept {
      v0 = r.v0;
      v1 = r.v1;
      v2 = r.v2;
      v3 = r.v3;

      return *this;
    }
    inline void operator+=(const Matrix4& r) noexcept { *this = *this + r; }
    inline void operator-=(const Matrix4& r) noexcept { *this = *this - r; }
    inline void operator*=(const Matrix4& r) noexcept { *this = *this * r; }
    inline void operator/=(const Matrix4& r) noexcept { *this = *this / r; }
    inline void operator*=(float r) noexcept { *this = *this * r; }
    inline void operator/=(float r) noexcept { *this = *this / r; }

    inline                operator float*() noexcept { return reinterpret_cast<float*>(this); }
    inline                operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    inline                operator Vector4*() noexcept { return reinterpret_cast<Vector4*>(this); }
    inline                operator const Vector4*() const noexcept { return reinterpret_cast<const Vector4*>(this); }
    inline Vector4&       operator[](std::size_t index) noexcept { return (reinterpret_cast<Vector4*>(this))[index]; }
    inline const Vector4& operator[](std::size_t index) const noexcept {
      return (reinterpret_cast<const Vector4*>(this))[index];
    }

    Matrix4(Vector4 v0, Vector4 v1, Vector4 v2, Vector4 v3) : v0(v0), v1(v1), v2(v2), v3(v3) {}
    Matrix4() : Matrix4(Vector4(), Vector4(), Vector4(), Vector4()) {}
  };
}  // namespace NFSPluginSDK

#endif  // NFSPLUGINSDK_SHARED_MATH_H
