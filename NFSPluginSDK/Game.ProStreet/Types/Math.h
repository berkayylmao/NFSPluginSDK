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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_MATH_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_MATH_H
#pragma once

namespace NFSPluginSDK::ProStreet::Math {
  struct Vector2;
  struct Vector3;
  struct Vector4;
  struct Matrix4;

  struct Vector2 {
    float x, y;

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

    Vector2 Normalize() {
      float t = std::sqrt(x * x + y * y);
      return Vector2(x / t, y / t);
    }
  };
  struct Vector3 {
    float x, y, z;

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

    Vector3 Normalize() {
      float t = std::sqrt(x * x + y * y + z * z);
      return Vector3(x / t, y / t, z / t);
    }
  };
  struct Vector4 {
    float x, y, z, w;

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

    Vector4 Normalize() {
      float t = std::sqrt(x * x + y * y + z * z + w * w);
      return Vector4(x / t, y / t, z / t, w / t);
    }
  };
  struct Matrix4 {
    Vector4 v0, v1, v2, v3;

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
}  // namespace NFSPluginSDK::ProStreet::Math

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_MATH_H
