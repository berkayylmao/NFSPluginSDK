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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_RGBA_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_RGBA_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::Attrib {
  struct RGBA {
    float r, g, b, a;

    RGBA operator+(const RGBA& rhs) const noexcept {
      RGBA _result = *this;
      _result.r += rhs.r;
      _result.g += rhs.g;
      _result.b += rhs.b;
      _result.a += rhs.a;

      return _result;
    }
    RGBA operator-(const RGBA& rhs) const noexcept {
      RGBA _result = *this;
      _result.r -= rhs.r;
      _result.g -= rhs.g;
      _result.b -= rhs.b;
      _result.a -= rhs.a;

      return _result;
    }
    RGBA operator*(const RGBA& rhs) const noexcept {
      RGBA _result = *this;
      _result.r *= rhs.r;
      _result.g *= rhs.g;
      _result.b *= rhs.b;
      _result.a *= rhs.a;

      return _result;
    }
    RGBA operator/(const RGBA& rhs) const noexcept {
      RGBA _result = *this;
      _result.r /= rhs.r;
      _result.g /= rhs.g;
      _result.b /= rhs.b;
      _result.a /= rhs.a;

      return _result;
    }
    RGBA operator*(float rhs) const noexcept {
      RGBA _result = *this;
      _result.r *= rhs;
      _result.g *= rhs;
      _result.b *= rhs;
      _result.a *= rhs;

      return _result;
    }
    RGBA operator/(float rhs) const noexcept {
      RGBA _result = *this;
      _result.r /= rhs;
      _result.g /= rhs;
      _result.b /= rhs;
      _result.a /= rhs;

      return _result;
    }

    void operator=(const RGBA& rhs) {
      this->r = rhs.r;
      this->g = rhs.g;
      this->b = rhs.b;
      this->a = rhs.a;
    }
    void operator+=(const RGBA& rhs) { *this = *this + rhs; }
    void operator-=(const RGBA& rhs) { *this = *this - rhs; }
    void operator*=(const RGBA& rhs) { *this = *this * rhs; }
    void operator/=(const RGBA& rhs) { *this = *this / rhs; }
    void operator*=(float rhs) { *this = *this * rhs; }
    void operator/=(float rhs) { *this = *this / rhs; }

                 operator float*() noexcept { return reinterpret_cast<float*>(this); }
                 operator const float*() const noexcept { return reinterpret_cast<const float*>(this); }
    float&       operator[](std::size_t index) noexcept { return (reinterpret_cast<float*>(this))[index]; }
    const float& operator[](std::size_t index) const noexcept { return (reinterpret_cast<const float*>(this))[index]; }

    RGBA() : r(0.0f), g(0.0f), b(0.0f), a(0.0f) {}
    ~RGBA() = default;
    RGBA(float red, float green, float blue, float alpha) : r(red), g(green), b(blue), a(alpha) {}
  };
}  // namespace NFSPluginSDK::ProStreet::Attrib

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_RGBA_H
