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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEHUMAN_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEHUMAN_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/AIVehicleRacecar.h>
#include <NFSPluginSDK/Game.Carbon/Types/IHumanAI.h>
#include <NFSPluginSDK/Game.Carbon/Types/IInputPlayer.h>

namespace NFSPluginSDK::Carbon {
  struct AIVehicleHuman : AIVehicleRacecar, IHumanAI, IInputPlayer {
    bool           bAiControl;
    UMath::Vector3 vMomentPosition;
    float          fMomentRadius;
    bool           mWrongWay;
    ActionQueue*   mActionQ;
    float          mSteerRight;
    float          mSteerLeft;
    float          mOverSteer;
    bool           mOverSteering;
    float          mOverSteerRight;
    float          mOverSteerLeft;
    float          mGasButton;
    float          mBrakeButton;
    float          mClutchButton;
    float          mClutchKickButton;
    float          mLookBackButton;
    float          mPullBackButton;
    float          mCameraRotInput;
    float          mWingmanButton;
    bool           mGasInputUsedSinceStart;
    bool           mGaveHeadStart;
    bool           mIOBlocked;
    bool           mEnableDampening;

    virtual ~AIVehicleHuman();
#pragma region overrides
    virtual void                  Reset() override;
    virtual void                  OnTaskSimulate(float deltaTime) override;
    virtual bool                  IsLookBackButtonPressed() override;
    virtual bool                  IsPullBackButtonPressed() override;
    virtual bool                  IsWingmanActivationButtonPressed() override;
    virtual bool                  IsAutomaticShift() override;
    virtual float                 GetCatchupCheat() override;
    virtual void                  StartRace(DriverStyle style) override;
    virtual bool                  GaveHeadStart() override;
    virtual bool                  IsPlayerSteering() override;
    virtual bool                  GetAiControl() override;
    virtual void                  SetAiControl(bool aiControl) override;
    virtual void                  SetWorldMoment(const UMath::Vector3& position, float radius) override;
    virtual const UMath::Vector3& GetWorldMomentPosition() override;
    virtual float                 GetWorldMomentRadius() override;
    virtual void                  ClearWorldMoment() override;
    virtual bool                  IsFacingWrongWay() override;
    virtual void                  BlockInput(bool block) override;
    virtual bool                  IsBlocked() override;
    virtual void                  FetchInput() override;
    virtual void                  ClearInput() override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_AIVEHICLEHUMAN_H
