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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_DEBUGVEHICLESELECTION_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_DEBUGVEHICLESELECTION_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/IVehicleCache.h>

namespace NFSPluginSDK::MW05 {
  struct DebugVehicleSelection : IVehicleCache {
    unsigned char _pad1[0x10];
    std::int32_t  mSelectionIndex;
    unsigned char _pad2[0x4];
    const char**  mSelectionList;
    unsigned char _pad3[0x8];
    const char*   mCollisionObject;
    const char*   mCollisionSurface;

    virtual ~DebugVehicleSelection();

    void ChangePlayerVehicle(std::int32_t selectionIndex) {
      mSelectionIndex        = selectionIndex;
      *g_ChangePlayerVehicle = true;
    }

    static inline DebugVehicleSelection** g_mThis               = reinterpret_cast<DebugVehicleSelection**>(0x9B08F8);
    static inline bool*                   g_ChangePlayerVehicle = reinterpret_cast<bool*>(0x9B08FD);

    static DebugVehicleSelection* Get() {
      if (!g_mThis) return nullptr;
      return *g_mThis;
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_DEBUGVEHICLESELECTION_H
