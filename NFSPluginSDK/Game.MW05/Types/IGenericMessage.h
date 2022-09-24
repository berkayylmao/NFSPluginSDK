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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_IGENERICMESSAGE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_IGENERICMESSAGE_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct IGenericMessage : UTL::COM::IUnknown {
    enum class FEngTypes : std::uint32_t {
      None,
      Type1 = 0x8AB83EDB,  // [White Text] Fades out towards bottom of the screen
      Type2 = 0x9D73BC15,  // [White Text] Fades out towards player camera
      Type3 = 0x5230FAF6,  // [Red Text] Fades out towards top of the screen
      Type4 = 0xA19BB14C,  // [Green Text] Fades out towards bottom of the screen
      Type5 = 0x821E6378   // [Green/White Text] Flashes and is kept alive
    };
    enum class IconDisplayTypes : std::uint32_t {
      HideIcon,
      ShowIcon = 0x609F6B15,  // [Flashing background] Fades out towards bottom of the screen
    };
    enum class Priority : std::uint32_t { Priority5, Priority4, Priority3, Priority2, Priority1 };

    virtual ~IGenericMessage();
    virtual void     RequestGenericMessage(char const* text, bool playOneFrame, Attrib::StringKey fengHash,
                                           std::uint32_t iconHash, Attrib::StringKey iconDisplayKey, Priority priority) = 0;
    virtual void     RequestGenericMessageZoomOut(std::uint32_t) = 0;
    virtual bool     IsGenericMessageShowing()                   = 0;
    virtual Priority GetCurrentGenericMessagePriority()          = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x5650B0)(); }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_IGENERICMESSAGE_H
