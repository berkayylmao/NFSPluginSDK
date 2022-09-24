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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FESTRING_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FESTRING_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEObject.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEWideString.h>

namespace NFSPluginSDK::ProStreet {
  struct FEString : FEObject {
    char*              pLabelName;
    std::uint32_t      LabelHash;
    FEWideString       string;
    FEStringFormatting Format;
    std::int32_t       Leading;
    std::uint32_t      MaxWidth;

    template <typename... Arguments>
    static void Printf(const char* fngName, std::uint32_t objectHash, const char* format, Arguments... args) {
      reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t, const char*, Arguments...)>(0x5CE4F0)(
          fngName, objectHash, format, args...);
    }
    static void SetLanguageHash(const char* fngName, std::uint32_t objectHash, std::uint32_t languageHash) {
      reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t, std::uint32_t)>(0x5BE5F0)(fngName, objectHash,
                                                                                            languageHash);
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FESTRING_H
