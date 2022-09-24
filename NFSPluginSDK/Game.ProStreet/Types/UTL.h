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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_UTL_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_UTL_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL/FixedVector.h>

namespace NFSPluginSDK::ProStreet::UTL {
  template <typename T, std::size_t nT>
  struct GarbageNode {
    struct Collector {
      struct _Node {
        T*           myptr;
        std::int32_t refcount;
      };
      UTL::FixedVector<GarbageNode<T, nT>::Collector::_Node, nT> _mDirty;
      UTL::FixedVector<GarbageNode<T, nT>::Collector::_Node, nT> _mClean;
      std::uint32_t                                              _mCount;
    };

    bool mDirty;
  };

  template <typename HandleType, typename T, std::size_t nMaxInstances>
  struct Instanceable {
    HandleType _mHandle;
  };

  namespace COM {
    struct Object {
      struct _IPair {
        struct _Finder {
          const IUnknown* ref;
        };

        void*     handle;
        IUnknown* ref;
      };
      struct _IList : eastl::vector<UTL::COM::Object::_IPair> {
        template <typename T>
        T* Find() {
          return reinterpret_cast<T*(__thiscall*)(_IList*, IHandle*)>(0x4614B0)(this, T::GetIHandle());
        }
      };

      _IList _mInterfaces;
    };

    struct IUnknown {
      Object* _mCOMObject;

      virtual ~IUnknown();
    };
  }  // namespace COM
}  // namespace NFSPluginSDK::ProStreet::UTL

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_UTL_H
