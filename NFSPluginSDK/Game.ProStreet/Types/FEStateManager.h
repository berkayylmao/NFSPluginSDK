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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FESTATEMANAGER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FESTATEMANAGER_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/bList.h>
#include <NFSPluginSDK/Game.ProStreet/Types/MenuScreen.h>

namespace NFSPluginSDK::ProStreet {
  struct FEStateOption : bTNode<FEStateOption> {
    std::int32_t mState;
    std::int32_t mOption;
  };

  template <typename EntryPoints = FEManager::eEntryPoints, typename State = FEManager::eState,
            typename ExitPoints = std::uint32_t>
  struct FEStateManager {
    enum class eGlobalStates : std::uint32_t { PushedToTop = UINT32_MAX };
    enum class ePadButton : std::uint32_t {
      Button_0,
      Button_1,
      Button_2,
      Button_3,
      Button_4,
      Button_5,
      Button_6,
      Button_7,
      Button_8,
      Button_9,
      PadLTrigger,
      PadRTrigger,
      PadAccept,
      PadStart,
      PadButtonPressed,
      PadButtonUndefined,
    };
    enum class eSubStates : std::uint32_t { None, SwitchingDialog, ExitAll, Exiting, Invalid = UINT32_MAX };

    State                 mCurState;
    EntryPoints           mEntryPoint;
    ExitPoints            mExitPoint;
    State                 mNextState;
    State                 mPrevState;
    eSubStates            mSubState;
    char                  mLastScreenPushed[128];
    char*                 mNextScreen;
    bool                  mNextStateValid;
    bool                  mExitingAllStateManagers;
    std::int32_t          mNumScreensPushed;
    std::int32_t          mNumScreensToPop;
    FEStateManager*       mParentManager;
    FEStateManager*       mChildManager;
    FEStateManager*       mNextManager;
    bTList<FEStateOption> mStateOptions;
    bool                  mCanSkipMovie;

    virtual ~FEStateManager();
    virtual void               OnEvent(FEManager::eEvents event);
    virtual eMenuSoundTriggers OnNotifySound(std::uint32_t, eMenuSoundTriggers);
    virtual void               OnPadButton(ePadButton button);
    virtual void               OnPadButtonRelease(ePadButton button);
    virtual void               OnRefresh();
    virtual void               OnScreenConstructed(MenuScreen*);
    virtual void               OnScreenDestructed();
    virtual void               OnScreenTick();
    virtual void               SetCanSkipMovie(bool canSkipMovie);
    virtual bool               GetCanSkipMovie();
    virtual void               Start();
    virtual void               SetInitialOption(MenuScreen*);
    virtual void               HandleAnimationLoaded(const char*, const char*);
    virtual void               HandleAutosave();
    virtual void               HandleButtonPressed(std::uint32_t);
    virtual void               HandleButtonReleased(std::uint32_t);
    virtual void               HandleButtonHighlight(std::uint32_t);
    virtual void               HandleChildFlowStart();
    virtual void               HandleChildFlowDone(std::int32_t);
    virtual void               HandleEasterEggActivated(std::int32_t);
    virtual void               HandleEnterComplete();
    virtual void               HandleEnterStarted();
    virtual void               HandleShowScreen();
    virtual void               HandleHideScreen();
    virtual void               HandleEvent(std::int32_t);
    virtual void               HandleExitAll();
    virtual void               HandleExitComplete();
    virtual void               HandleFlowDone();
    virtual bool               HandleIsGameMode(std::int32_t);
    virtual void               HandleMouseChanged();
    virtual void               HandleMouseWheelDown();
    virtual void               HandleMouseWheelUp();
    virtual void               HandleMovieComplete();
    virtual void               HandleMovieStarted();
    virtual eMenuSoundTriggers HandleNotifySound(std::uint32_t, eMenuSoundTriggers);
    virtual void               HandleOnlineDisconnect();
    virtual void               HandleOnlineGameDisconnect();
    virtual void               HandleOptionHighlighted(std::uint32_t);
    virtual void               HandleOptionSelected(std::uint32_t, ePadButton);
    virtual void               HandlePadAccept();
    virtual void               HandlePadBack();
    virtual void               HandlePadDown();
    virtual void               HandlePadButton0();
    virtual void               HandlePadButton1();
    virtual void               HandlePadButton2();
    virtual void               HandlePadButton3();
    virtual void               HandlePadButton4();
    virtual void               HandlePadButton5();
    virtual void               HandlePadButton6();
    virtual void               HandlePadButton7();
    virtual void               HandlePadButton8();
    virtual void               HandlePadButton9();
    virtual void               HandlePadButton0Release();
    virtual void               HandlePadButton1Release();
    virtual void               HandlePadButton2Release();
    virtual void               HandlePadButton3Release();
    virtual void               HandlePadButton4Release();
    virtual void               HandlePadButton5Release();
    virtual void               HandlePadButton6Release();
    virtual void               HandlePadButton7Release();
    virtual void               HandlePadButton8Release();
    virtual void               HandlePadButton9Release();
    virtual void               HandleLTrigger();
    virtual void               HandleLTriggerRelease();
    virtual void               HandlePadLeft(std::uint32_t);
    virtual void               HandlePadUp();
    virtual void               HandlePadRight(std::uint32_t);
    virtual void               HandlePadStart();
    virtual void               HandlePadQuit();
    virtual void               HandleRefresh();
    virtual void               HandleRTrigger();
    virtual void               HandleRTriggerRelease();
    virtual void               HandleScreenConstructed();
    virtual void               HandleScreenDestructed();
    virtual void               HandleScreenTick();
    virtual void               HandleScreenTimeout();
    virtual void               HandleShowDialog();
    virtual void               HandleSignInComplete();
    virtual void               HandleStateChange();
    virtual void               HandleWidgetValueChanged(std::uint32_t, std::uint32_t);
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FESTATEMANAGER_H
