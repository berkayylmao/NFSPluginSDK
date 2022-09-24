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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_MENUSCREEN_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_MENUSCREEN_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ScreenConstructorData.h>

namespace NFSPluginSDK::ProStreet {
  struct MenuScreen {
    bool                  mPlaySound;
    std::uint32_t         mDirectionForNextSound;
    const char*           mpPackageFilename;
    ScreenConstructorData mConstructData;
    bool                  mIsGarageScreen;

    virtual ~MenuScreen();
    virtual eMenuSoundTriggers NotifySoundMessage(std::uint32_t, eMenuSoundTriggers);
    virtual void               SetInitialOption(std::uint32_t);
    virtual void               SetInitialOptionUsingDescHash(std::uint32_t);
    virtual void               ShowHelpbar(char*);
    virtual void               ShowScreen(bool);
    virtual void               InitInstance();
    virtual void               SetAspectRatio();
    virtual void               __unk_related_to_lan_raceday();
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_MENUSCREEN_H
