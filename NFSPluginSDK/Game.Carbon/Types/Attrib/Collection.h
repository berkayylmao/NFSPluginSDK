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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_COLLECTION_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_COLLECTION_H
#pragma once

#include <NFSPluginSDK/Core/MemoryEditor.hpp>

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/HashMap.h>

namespace NFSPluginSDK::Carbon::Attrib {
  struct Collection {
    HashMap       mTable;
    Collection*   mParent;
    Class*        mClass;
    void*         mLayout;
    std::uint32_t mRefCount;
    std::uint32_t mKey;
    Vault*        mSource;
    const char**  mNamePtr;

    template <typename T>
    inline T* GetData(std::uint32_t fieldKey, std::int32_t idx = 0) {
      return reinterpret_cast<T*(__thiscall*)(Collection*, std::uint32_t, std::int32_t)>(0x463480)(this, fieldKey, idx);
    }
    template <typename T>
    inline T* GetData(const char* fieldName, std::int32_t idx = 0) {
      return GetData<T>(StringToKey(fieldName), idx);
    }

    template <typename T>
    inline T* GetLayout() {
      return reinterpret_cast<T*>(mLayout);
    }

    template <typename T>
    inline bool TrySetData(std::uint32_t fieldKey, T value, bool safe = true, std::int32_t idx = 0) {
      auto* p = GetData<T>(fieldKey, idx);
      if (p) {
        if (safe)
          MemoryEditor::Get().GetRawMemory(p).SetValue(value);
        else
          *p = value;
      }
      return p != nullptr;
    }
    template <typename T>
    inline bool TrySetData(const char* fieldName, T value, bool safe = true, std::int32_t idx = 0) {
      return TrySetData(StringToKey(fieldName), value, safe, idx);
    }
  };
}  // namespace NFSPluginSDK::Carbon::Attrib

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_COLLECTION_H
