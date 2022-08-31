// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <mail@berkay.link>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/bList.h>
#include <OpenSpeed/Game.ProStreet/Types/MenuScreen.h>

namespace OpenSpeed::ProStreet {
  struct FEStateOption : bTNode<FEStateOption> {
    std::int32_t mState;
    std::int32_t mOption;
  };

  struct FEStateManager {
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
    enum class eGlobalStates : std::uint32_t { PushedToTop = UINT32_MAX };
    enum class eSubStates : std::uint32_t { None, SwitchingDialog, ExitAll, Exiting, Invalid = UINT32_MAX };

    std::int32_t          mCurState;
    std::int32_t          mEntryPoint;
    std::int32_t          mExitPoint;
    std::int32_t          mNextState;
    std::int32_t          mPrevState;
    std::int32_t          mSubState;
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
    std::int8_t           mCanSkipMovie;

    virtual ~FEStateManager();
    virtual std::int32_t       JUICE_GetMaxStates();
    virtual void               ChangeState(std::int32_t);
    virtual std::int32_t       GetCurState();
    virtual std::int32_t       GetPrevState();
    virtual std::int32_t       GetNextState();
    virtual std::int32_t       GetEntryPoint();
    virtual void               SetExitPoint(std::int32_t);
    virtual std::int32_t       GetExitPoint();
    virtual void               AddStateOption(struct FEStateOption*);
    virtual void               ClearStateOptions();
    virtual void               PopBack(std::int32_t);
    virtual void               PopForward(std::int32_t);
    virtual void               Push(const char*, std::int32_t);
    virtual void               SwitchBack(const char*, std::int32_t, std::int32_t);
    virtual void               SwitchForward(const char*, std::int32_t, std::int32_t);
    virtual const char*        GetNameOfLastScreenPushed();
    virtual std::int32_t       GetNumScreensPushed();
    virtual void               ShowDialog(std::int32_t);
    virtual void               SwitchDialogBack(std::int32_t);
    virtual void               SwitchDialogForward(std::int32_t);
    virtual void               PushMovie(const char*, std::int32_t, bool);
    virtual void               SwitchMovie(const char*, std::int32_t);
    virtual void               PushChildManager(FEStateManager*, std::int32_t);
    virtual void               SwitchChildManager(FEStateManager*, std::int32_t, std::int32_t);
    virtual void               PushChildManagerToStackTop(FEStateManager*);
    virtual FEStateManager*    GetActiveChildManager();
    virtual void               Start();
    virtual void               Exit(std::int32_t, bool);
    virtual void               Exit(bool);
    virtual void               ExitAll(std::int32_t);
    virtual void               ExitAll();
    virtual void               DeleteChildManagers(bool);
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
}  // namespace OpenSpeed::ProStreet
