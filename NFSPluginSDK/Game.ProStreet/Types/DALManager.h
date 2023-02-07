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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALMANAGER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALMANAGER_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DALInterface.h>

namespace NFSPluginSDK::ProStreet {
  struct DALManager : DALInterface {
    DALInterface* mInterfaces[22];
    bool          mInited;

    virtual ~DALManager();
    virtual void HandleCommand(DLCommandObject*, const std::int32_t unk1);
    virtual void CancelCommand(DLCommandObject*, const std::int32_t unk1);

    static DALManager* Get() {
      static auto* g_instance = reinterpret_cast<DALManager*>(0xA50AD0);
      if (g_instance && g_instance->mInited) return g_instance;

      return nullptr;
    }
    static bool TryHandleCommand(DerivedFromDLCommandObject auto* pCommandObject) {
      auto* dal = Get();
      if (!dal) return false;

      dal->HandleCommand(pCommandObject, -1);
      return true;
    }
    static bool TryHandleCommand(DerivedFromDLCommandObject auto& commandObject) {
      return TryHandleCommand(&commandObject);
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALMANAGER_H
