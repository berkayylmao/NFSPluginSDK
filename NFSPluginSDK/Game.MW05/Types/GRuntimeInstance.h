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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_GRUNTIMEINSTANCE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_GRUNTIMEINSTANCE_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/gameplay.h>

namespace NFSPluginSDK::MW05 {
  struct GRuntimeInstance : Attrib::Gen::gameplay {
    struct ConnectedInstance {
      std::uint32_t     mIndexedKey;
      GRuntimeInstance* mInstance;
    };

    std::uint16_t      mFlags;
    std::uint16_t      mNumConnected;
    ConnectedInstance* mConnected;
    GRuntimeInstance*  mPrev;
    GRuntimeInstance*  mNext;

    inline bool GetDirection(UMath::Vector3& out) {
      return reinterpret_cast<bool(__thiscall*)(GRuntimeInstance*, UMath::Vector3&)>(0x5DACF0)(this, out);
    }
    inline bool GetPosition(UMath::Vector3& out) {
      return reinterpret_cast<bool(__thiscall*)(GRuntimeInstance*, UMath::Vector3&)>(0x5E2970)(this, out);
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_GRUNTIMEINSTANCE_H
