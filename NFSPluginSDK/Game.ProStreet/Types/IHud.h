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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_IHUD_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_IHUD_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IPlayer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct IHud : UTL::COM::IUnknown {
    virtual ~IHud();
    virtual void           Update(IPlayer*, float)             = 0;
    virtual void           Release()                           = 0;
    virtual void           HideAll()                           = 0;
    virtual void           FadeAllForSpeedBreaker(bool fade)   = 0;
    virtual void           FadeAll(bool fade)                  = 0;
    virtual bool           AreResourcesLoaded()                = 0;
    virtual bool           IsHudVisible()                      = 0;
    virtual bool           IsRvmVisible()                      = 0;
    virtual void           JoyEnable()                         = 0;
    virtual void           JoyDisable()                        = 0;
    virtual void           RefreshMiniMapItems()               = 0;
    virtual void           StartNewMode(IPlayer*)              = 0;
    virtual bool           ShouldDeleteHUD()                   = 0;
    virtual void           SetShouldDeleteHUD(bool deleteHUD)  = 0;
    virtual float          GetRearViewMirrorAlpha()            = 0;
    virtual void           SetDebugText(int, const char* text) = 0;
    virtual ePlayerHudType GetHudType()                        = 0;
    virtual void           ShowGO()                            = 0;
    virtual bool           WasInitialized()                    = 0;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_IHUD_H
