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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEANIMMENULEVEL_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEANIMMENULEVEL_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/bList.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEObject.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FETreeDataNode.h>

namespace NFSPluginSDK::ProStreet {
  struct FEAnimMenuLevel : bTNode<FEAnimMenuLevel> {
    bTList<FETreeDataNode> mDataNodes;
    FEAnimMenu*            mpMenu;
    const char*            mpPackageName;
    std::int32_t           mNumNodes;
    std::int32_t           mHighlightedIndex;
    FETreeDataNode*        mpHighlightedNode;

    virtual ~FEAnimMenuLevel();
    virtual void  NotificationMessage(std::uint_least32_t, FEObject*, std::uint_least32_t, std::uint_least32_t);
    virtual void  Enter(bool);
    virtual void  EnterPreview(std::int32_t, bool);
    virtual void  HidePreview();
    virtual void  Select();
    virtual void  Minimize(std::int32_t);
    virtual void  Transition();
    virtual float GetHighlightedValue();
    virtual void  HighlightCurNode();
    virtual void  ShowHighlighter();
    virtual void  SetNodeText(std::int32_t, const char*, FETreeDataNode*);
    virtual void  ShowPreviewRows(bool);
    virtual void  UnhighlightCurNode();
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEANIMMENULEVEL_H
