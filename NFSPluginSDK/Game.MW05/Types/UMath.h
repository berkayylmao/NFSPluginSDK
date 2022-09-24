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
