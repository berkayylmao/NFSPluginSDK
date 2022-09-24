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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEMAPSCREEN_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEMAPSCREEN_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ActionQueue.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEGroup.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEMapHubPopupWindow.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEMapTier.h>
#include <NFSPluginSDK/Game.ProStreet/Types/MenuScreen.h>

namespace NFSPluginSDK::ProStreet {
  struct FEMapScreen : MenuScreen {
    enum class ZoomState : std::uint8_t { Tier, NonSelect, Hub, All };

    eastl::list<FEMapTier*>*                                  mTierList;
    FEMapHub*                                                 mSelectedHub;
    eastl::ListIterator<FEMapTier*, FEMapTier**, FEMapTier*&> mSelectedTierIter;
    ActionQueue*                                              mActionQ;
    bVector2                                                  mActionQDirection;
    float                                                     mSelectionWait;
    FEGroup* const                                            mTagGroup;
    FEMapStreamer*                                            mMapStreamer;
    FEMapHubPopupWindow*                                      mPopWindow;
    FEMapHubPopupWindow::eDirection                           mPopupEventDir;
    FEObject* const                                           mPopupBacking;
    ZoomState                                                 mZoomState;
    bVector2                                                  mLastZoom;
    FEHubAnimController*                                      mHubAnimController;
    bool                                                      mScreenEntered;
    bool                                                      mCameraMoving;
    std::uint32_t                                             mTierPanGroupHash;

    static FEMapScreen* Get() {
      static auto** spInstance = reinterpret_cast<FEMapScreen**>(0xB32BC4);
      if (!spInstance) return nullptr;

      return *spInstance;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEMAPSCREEN_H
