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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_LOCALPLAYER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_LOCALPLAYER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/IPlayer.h>
#include <NFSPluginSDK/Game.MW05/Types/Sim.h>

namespace NFSPluginSDK::MW05 {
  struct LocalPlayer : Sim::Entity, IPlayer, Sim::Collision::IListener {
    IFeedback*      mFFB;
    ISteeringWheel* mWheelDevice;
    std::int32_t    mRenderPort;
    std::int32_t    mControllerPort;
    std::int32_t    mSettingIndex;
    const char*     mName;
    std::uint32_t   mNeighbourhoodHash;
    IHud*           mHud;
    HSIMTASK__*     mHudTask;
    Sim::IActivity* mSpeech;
    bool            mInGameBreaker;
    float           mGameBreakerCharge;
    HACTIVITY__*    mLastPursuit;

    virtual ~LocalPlayer();
#pragma region overrides
    virtual ISimable*             GetSimable() override;
    virtual bool                  IsLocal() override;
    virtual const UMath::Vector3& GetPosition() override;
    virtual bool                  SetPosition(const UMath::Vector3& newPosition) override;
    virtual PlayerSettings*       GetSettings() override;
    virtual void                  SetSettings(std::int32_t) override;
    virtual std::int32_t          GetSettingsIndex() override;
    virtual IHud*                 GetHud() override;
    virtual void                  SetHud(ePlayerHudType newHudType) override;
    virtual void                  SetRenderPort(int32_t) override;
    virtual std::int32_t          GetRenderPort() override;
    virtual void                  SetControllerPort(std::int32_t) override;
    virtual std::int32_t          GetControllerPort() override;
    virtual IFeedback*            GetFFB() override;
    virtual ISteeringWheel*       GetSteeringDevice() override;
    virtual bool                  InGameBreaker() override;
    virtual bool                  CanRechargeNOS() override;
    virtual void                  ResetGameBreaker(bool fill) override;
    virtual void                  ChargeGameBreaker(float amount) override;
    virtual bool                  ToggleGameBreaker() override;
    virtual void                  OnAttached(IAttachable* pOther) override;
    virtual void                  OnDetached(IAttachable* pOther) override;
    virtual void                  OnCollision(const Sim::Collision::Info& cInfo) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_LOCALPLAYER_H
