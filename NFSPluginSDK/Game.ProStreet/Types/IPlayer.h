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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_IPLAYER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_IPLAYER_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct IPlayer : UTL::COM::IUnknown {
    virtual ~IPlayer();
    virtual ISimable*             GetSimable()                                = 0;
    virtual bool                  IsLocal()                                   = 0;
    virtual const UMath::Vector3& GetPosition()                               = 0;
    virtual bool                  SetPosition(const UMath::Vector3& position) = 0;
    virtual PlayerSettings*       GetSettings()                               = 0;
    virtual void                  SetSettings(std::int32_t)                   = 0;
    virtual std::int32_t          GetSettingsIndex()                          = 0;
    virtual IHud*                 GetHud()                                    = 0;
    virtual void                  ResetHudType()                              = 0;
    virtual void                  ReleaseHud()                                = 0;
    virtual void                  SetRenderPort(std::int32_t)                 = 0;
    virtual std::int32_t          GetRenderPort()                             = 0;
    virtual void                  SetControllerPort(std::int32_t)             = 0;
    virtual std::int32_t          GetControllerPort()                         = 0;
    virtual IFeedback*            GetFFB()                                    = 0;
    virtual ISteeringWheel*       GetSteeringDevice()                         = 0;
    virtual bool                  InGameBreaker()                             = 0;
    virtual bool                  CanRechargeNOS()                            = 0;
    virtual void                  ResetGameBreaker(bool fill)                 = 0;
    virtual void                  ChargeGameBreaker(float amount)             = 0;
    virtual float                 GetGameBreakerCharge()                      = 0;
    virtual bool                  ToggleGameBreaker()                         = 0;
    virtual float                 GetNOSModifier()                            = 0;
    virtual void                  SetNOSModifier(float amount)                = 0;
    virtual void                  SetGameBreakerModifier(float amount)        = 0;
    virtual void                  SetEncounterMessage(std::int32_t)           = 0;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_IPLAYER_H
