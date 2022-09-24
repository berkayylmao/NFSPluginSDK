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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FENGHUD_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FENGHUD_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ActionQueue.h>
#include <NFSPluginSDK/Game.ProStreet/Types/HudElement.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ICountdown.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IHud.h>

namespace NFSPluginSDK::ProStreet {
  struct FEngHud : UTL::COM::Object, IHud, ICountdown {
    ePlayerHudType         mPlayerHudType;
    IPlayer*               mPlayer;
    std::int32_t           mPlayerNumber;
    ActionQueue            mActionQ;
    bool                   mShouldDeleteHUD;
    std::int32_t           mUpdateCount;
    ResourceFile*          mpHudBundleFile;
    const char*            mpPackageName;
    FEObject*              mFEObjSpeedSensitiveGroup;
    FEObject*              mFEObjMainGroup;
    FEObject*              mFEObjRvmGroup;
    HudElement*            mHudElements[24];
    std::uint64_t          mCurrentHudFeatures;
    std::uint64_t          mRaceHudFeatures;
    std::uint64_t          mOptionsHudFeatures;
    std::uint64_t          mGameFlowHudFeatures;
    std::uint64_t          mEventDrivenHudFeatures;
    bool                   mWasInitialized;
    bool                   mCurrentWidescreenSetting;
    Hermes::_h_HHANDLER__* mMsgShowHUD;
    Hermes::_h_HHANDLER__* mMsgHideHUD;
    bool                   mHideAll;
    bool                   mHideHUDTillGo;

    virtual ~FEngHud();
    virtual void           Update(IPlayer*, float) override;
    virtual void           Release() override;
    virtual void           HideAll() override;
    virtual void           FadeAllForSpeedBreaker(bool fade) override;
    virtual void           FadeAll(bool fade) override;
    virtual bool           AreResourcesLoaded() override;
    virtual bool           IsHudVisible() override;
    virtual bool           IsRvmVisible() override;
    virtual void           JoyEnable() override;
    virtual void           JoyDisable() override;
    virtual void           RefreshMiniMapItems() override;
    virtual void           StartNewMode(IPlayer*) override;
    virtual bool           ShouldDeleteHUD() override;
    virtual void           SetShouldDeleteHUD(bool deleteHUD) override;
    virtual float          GetRearViewMirrorAlpha() override;
    virtual void           SetDebugText(int, const char* text) override;
    virtual ePlayerHudType GetHudType() override;
    virtual void           ShowGO() override;
    virtual bool           WasInitialized() override;
    virtual void           BeginCountdown(std::int32_t countdown) override;
    virtual bool           IsActive() override;
    virtual float          GetSecondsBeforeRaceStart() override;

    HudElement* GetHudElement(HudElement::eHudElementIds id) { return mHudElements[static_cast<std::uint32_t>(id)]; }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FENGHUD_H
