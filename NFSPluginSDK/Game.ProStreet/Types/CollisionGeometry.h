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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_COLLISIONGEOMETRY_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_COLLISIONGEOMETRY_H
#pragma once

#if defined(__linux__) || defined(_LINUX)
#include <byteswap.h>  // bswap_16()
#elif defined(_WIN32)
#include <intrin.h>  // _byteswap_ushort()
#else
#error This operating system is not supported.
#endif

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UCrc32.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  namespace CollisionGeometry {
    // Compressed Vector3 (UMath::Vector3)
    struct _V3c {
      std::int16_t x, y, z;

      void Compress(const UMath::Vector3& from) {
        x = static_cast<std::int16_t>(from.x * INT16_MAX / 10000.0f);
        y = static_cast<std::int16_t>(from.y * INT16_MAX / 10000.0f);
        z = static_cast<std::int16_t>(from.z * INT16_MAX / 10000.0f);
      }
      void Decompress(UMath::Vector3& to) {
        to.x = static_cast<float>(x * 10000.0f / INT16_MAX);
        to.y = static_cast<float>(y * 10000.0f / INT16_MAX);
        to.z = static_cast<float>(z * 10000.0f / INT16_MAX);
      }
      void EndianSwap() {
#if defined(__linux__) || defined(_LINUX)
        x = static_cast<std::int16_t>(bswap16(x));
        y = static_cast<std::int16_t>(bswap16(y));
        z = static_cast<std::int16_t>(bswap16(z));
#elif defined(_WIN32)
        x = static_cast<std::int16_t>(_byteswap_ushort(x));
        y = static_cast<std::int16_t>(_byteswap_ushort(y));
        z = static_cast<std::int16_t>(_byteswap_ushort(z));
#endif
      }
    };
    // Compressed quaternion (UMath::Vector4)
    struct _Q4c {
      std::int16_t x, y, z, w;

      void Compress(const UMath::Vector4& from) {
        x = static_cast<std::int16_t>(from.x * INT16_MAX / 10000.0f);
        y = static_cast<std::int16_t>(from.y * INT16_MAX / 10000.0f);
        z = static_cast<std::int16_t>(from.z * INT16_MAX / 10000.0f);
        w = static_cast<std::int16_t>(from.w * INT16_MAX / 10000.0f);
      }
      void Decompress(UMath::Vector4& to) {
        to.x = static_cast<float>(x * 10000.0f / INT16_MAX);
        to.y = static_cast<float>(y * 10000.0f / INT16_MAX);
        to.z = static_cast<float>(z * 10000.0f / INT16_MAX);
        to.w = static_cast<float>(w * 10000.0f / INT16_MAX);
      }
      void EndianSwap() {
#if defined(__linux__) || defined(_LINUX)
        x = static_cast<std::int16_t>(bswap16(x));
        y = static_cast<std::int16_t>(bswap16(y));
        z = static_cast<std::int16_t>(bswap16(z));
        w = static_cast<std::int16_t>(bswap16(w));
#elif defined(_WIN32)
        x = static_cast<std::int16_t>(_byteswap_ushort(x));
        y = static_cast<std::int16_t>(_byteswap_ushort(y));
        z = static_cast<std::int16_t>(_byteswap_ushort(z));
        w = static_cast<std::int16_t>(_byteswap_ushort(w));
#endif
      }
    };

    struct BoundsHeader {
      UCrc32 fNameHash;

      std::int32_t fNumBounds;
      std::int32_t fIsResolved;
      std::int32_t fPad;
    };
    struct PCloudHeader {
      std::int32_t fNumPClouds;
      std::int32_t fPad[3];
    };

#pragma pack(push, 1)
    struct Bounds {
      _Q4c          fOrientation;
      _V3c          fPosition;
      std::uint16_t fFlags;
      _V3c          fHalfDimensions;
      std::uint8_t  fNumChildren;
      std::int8_t   fPCloudIndex;
      _V3c          fPivot;
      std::int16_t  fChildIndex;
      UCrc32        fAttributeName;
      UCrc32        fSurface;
      UCrc32        fNameHash;
      Collection*   fCollection;

      void GetOrientation(UMath::Vector4& out) { fOrientation.Decompress(out); }
      void GetPosition(UMath::Vector3& out) { fPosition.Decompress(out); }
      void GetPivot(UMath::Vector3& out) { fPivot.Decompress(out); }
      void GetHalfDimensions(UMath::Vector3& out) { fHalfDimensions.Decompress(out); }

      /* fCollection functions: ->

          const CollisionGeometry::Bounds* GetRoot();
          const CollisionGeometry::Bounds* GetChild(UCrc32);
          const CollisionGeometry::Bounds* GetChild(std::uint32_t);
          const CollisionGeometry::PCloud* GetPointCloud();
          void GetTransform(UMath::Matrix4&);
      */
    };
#pragma pack(pop)

    struct Collection : BoundsHeader {
      const UCrc32& GetObjectName() { return fNameHash; }
    };

    struct IBoundable : UTL::COM::IUnknown {
      virtual ~IBoundable();
      virtual Bounds* GetGeometryNode()                                             = 0;
      virtual bool AddCollisionPrimitive(UCrc32, UMath::Vector3&, float, UMath::Vector3&, SimSurface*, UMath::Vector4*,
                                         NFSPluginSDK::CollisionGeometry::BoundFlags)  = 0;
      virtual bool AddCollisionMesh(UCrc32, UMath::Vector4&, std::uint32_t, SimSurface*,
                                    NFSPluginSDK::CollisionGeometry::BoundFlags, bool) = 0;
    };
  }  // namespace CollisionGeometry
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_COLLISIONGEOMETRY_H
