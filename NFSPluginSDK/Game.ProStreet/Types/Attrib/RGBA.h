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
