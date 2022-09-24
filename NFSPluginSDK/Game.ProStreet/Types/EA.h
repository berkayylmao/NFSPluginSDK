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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::EA {
  namespace Localizer::LocalizerManager {
    static const char* const GetPackedString(std::uint32_t labelHash) {
      return reinterpret_cast<const char* const(__cdecl*)(std::uint32_t)>(0x5B8410)(labelHash);
    }
  }  // namespace Localizer::LocalizerManager

  namespace Memcard {
    struct MemcardChunk {
      std::uint32_t ID;
      std::int32_t  Size;
      bool          isNestedChunk;
    };

    struct IMemcardSavable {
      std::uint32_t mNameHash;
      MemcardChunk* mpChunk;
      void*         mpEndOfBuffer;
      void*         mpStartOfBuffer;
      std::uint32_t mSize;

      virtual ~IMemcardSavable();
      virtual void RegisterForSave(const char*, std::int32_t);
      virtual void SaveData(std::int32_t);
      virtual bool LoadData(std::int32_t);
      virtual void DefaultData(std::int32_t);
    };
  }  // namespace Memcard
  namespace Thread {
    struct alignas(8) EAMutexData {
      std::uint8_t mData[32];
      std::int32_t mnLockCount;
      bool         mbIntraProcess;
      void*        mThreadId;
    };

    struct Mutex {
      EAMutexData mMutexData;
    };
  }  // namespace Thread
}  // namespace NFSPluginSDK::ProStreet::EA

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
