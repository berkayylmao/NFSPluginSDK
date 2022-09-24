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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_FENGHUD_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_FENGHUD_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/ActionQueue.h>
#include <NFSPluginSDK/Game.MW05/Types/IHud.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct FEngHud : UTL::COM::Object, IHud {
    std::uint64_t  CurrentHudFeatures;
    ePlayerHudType mPlayerHudType;
    const char*    pPackageName;
    IPlayer*       pPlayer;
    std::int32_t   PlayerNumber;
    ActionQueue    mActionQ;
    bool           mInPursuit;
    bool           mHasTurbo;
    HudElement*    pSpeedometer;
    HudElement*    pTachometer;
    HudElement*    pTachometerDrag;
    HudElement*    pShiftUpdater;
    HudElement*    pCostToState;
    HudElement*    pReputation;
    HudElement*    pHeatMeter;
    HudElement*    pTurboMeter;
    HudElement*    pEngineTemp;
    HudElement*    pNitrous;
    HudElement*    pSpeedBreakerMeter;
    HudElement*    pRaceOverMessage;
    HudElement*    pGenericMessage;
    HudElement*    pAutoSaveIcon;
    HudElement*    pRaceInformation;
    HudElement*    pLeaderBoard;
    HudElement*    pPursuitBoard;
    HudElement*    pMilestoneBoard;
    HudElement*    pBustedMeter;
    HudElement*    pTimeExtension;
    HudElement*    pWrongWIndi;
    HudElement*    pOnlineSupport;
    HudElement*    p321Go;
    HudElement*    pRadarDetector;
    HudElement*    pMinimap;
    HudElement*    pGetAwayMeter;
    HudElement*    pMenuZoneTrigger;
    HudElement*    pInfractions;
    bool           mCurrentWidescreenSetting;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_FENGHUD_H
