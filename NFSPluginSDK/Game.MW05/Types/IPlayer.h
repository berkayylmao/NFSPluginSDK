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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_IPLAYER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_IPLAYER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct IPlayer : UTL::COM::IUnknown {
    virtual ISimable*             GetSimable()                                   = 0;
    virtual bool                  IsLocal()                                      = 0;
    virtual const UMath::Vector3& GetPosition()                                  = 0;
    virtual bool                  SetPosition(const UMath::Vector3& newPosition) = 0;
    virtual PlayerSettings*       GetSettings()                                  = 0;
    virtual void                  SetSettings(std::int32_t)                      = 0;
    virtual std::int32_t          GetSettingsIndex()                             = 0;
    virtual IHud*                 GetHud()                                       = 0;
    virtual void                  SetHud(ePlayerHudType newHudType)              = 0;
    virtual void                  SetRenderPort(int32_t)                         = 0;
    virtual std::int32_t          GetRenderPort()                                = 0;
    virtual void                  SetControllerPort(std::int32_t)                = 0;
    virtual std::int32_t          GetControllerPort()                            = 0;
    virtual IFeedback*            GetFFB()                                       = 0;
    virtual ISteeringWheel*       GetSteeringDevice()                            = 0;
    virtual bool                  InGameBreaker()                                = 0;
    virtual bool                  CanRechargeNOS()                               = 0;
    virtual void                  ResetGameBreaker(bool fill)                    = 0;
    virtual void                  ChargeGameBreaker(float amount)                = 0;
    virtual bool                  ToggleGameBreaker()                            = 0;

    static inline UTL::ListableSet<IPlayer, 8, ePlayerList, 3>* g_mLists =
        reinterpret_cast<UTL::ListableSet<IPlayer, 8, ePlayerList, 3>*>(0x92D87C);

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x6200D0)(); }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_IPLAYER_H
