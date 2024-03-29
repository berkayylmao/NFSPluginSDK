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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_FEOBJECT_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_FEOBJECT_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/FEMinList.h>

namespace NFSPluginSDK::MW05 {
  struct FEObject : FEMinNode {
    std::uint_least32_t GUID;
    std::uint_least32_t NameHash;
    char*               pName;
    FEObjType           Type;
    std::uint_least32_t Flags;
    std::uint_least16_t RenderContext;
    std::uint_least16_t ResourceIndex;
    std::uint_least32_t Handle;
    std::uint_least32_t UserParam;
    void*               pData;
    std::uint_least32_t DataSize;
    FEMinList           Responses;
    FEMinList           Scripts;
    FEScript*           pCurrentScript;
    FERenderObject*     Cached;

    /// VISIBLE

    void SetVisible(bool visible) { reinterpret_cast<void(__cdecl*)(FEObject*)>(visible ? 0x514CC0 : 0x514C70)(this); }

    /// COLOR

    void SetColor(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) {
      reinterpret_cast<void(__cdecl*)(FEObject*, std::uint8_t, std::uint8_t, std::uint8_t, std::uint8_t)>(0x5157E0)(
          this, b, g, r, a);
    }

    /// CENTER

    FEVector2 GetCenter() {
      FEVector2 ret;
      reinterpret_cast<void(__cdecl*)(FEObject*, float*, float*)>(0x524EE0)(this, &ret.x, &ret.y);

      return ret;
    }
    void SetCenter(FEVector2 center) {
      reinterpret_cast<void(__cdecl*)(FEObject*, float, float)>(0x525050)(this, center.x, center.y);
    }

    /// SIZE

    FEVector2 GetSize() {
      FEVector2 ret;
      reinterpret_cast<void(__cdecl*)(FEObject*, float*, float*)>(0x515520)(this, &ret.x, &ret.y);

      return ret;
    }
    void SetSize(FEVector2 size) {
      reinterpret_cast<void(__cdecl*)(FEObject*, float, float)>(0x5155E0)(this, size.x, size.y);
    }

    /// ROTATION

    void SetRotationZ(float rot) { reinterpret_cast<void(__cdecl*)(FEObject*, float)>(0x514E20)(this, rot); }

    /// GET INSTANCE

    static inline FEObject* GetObject(const char* fng, std::uint32_t hash) {
      return reinterpret_cast<FEObject*(__cdecl*)(const char*, std::uint32_t)>(0x524850)(fng, hash);
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_FEOBJECT_H
