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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_HUDELEMENT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_HUDELEMENT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/bList.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEObject.h>

namespace NFSPluginSDK::ProStreet {
  struct HudElement {
    enum class eHudElementIds : std::uint32_t {
      Tachometer,
      RaceOver,
      Leaderboard,
      Leaderboard4Up,
      SplitTime,
      WrongWay,
      FullScreenFade,
      SectorDisplay,
      _321Go,
      Nitrous,
      BoostGauge,
      Minimap,
      GenericMessage,
      TimeExtension,
      RaceInformation,
      DriftScores,
      RevolutionWheel,
      FadeToBlack,
      GameplayDebug,
      PositionIndicator,
      DragStats,
      TurnIndicator,
      DragStagingMeter,
      LapTime
    };

    enum class eHudEvent : std::uint32_t { DoLeaderBoardPopup };

    bPList<FEObject> mObjects;
    const char*      mpPackageName;
    bool             mIsVisible;

    virtual ~HudElement();
    virtual void        Update(IPlayer*);
    virtual void        StartNewMode(IPlayer*, std::int32_t);
    virtual void        Refresh();
    virtual void        OnEvent(eHudEvent event);
    virtual const char* GetDebugName();
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_HUDELEMENT_H
