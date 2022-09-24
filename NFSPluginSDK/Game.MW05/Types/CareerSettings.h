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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_CAREERSETTINGS_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_CAREERSETTINGS_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/SMSMessage.h>

namespace NFSPluginSDK::MW05 {
  struct CareerSettings {
    std::uint32_t CurrentCar;
    std::uint32_t SpecialFlags;
    std::uint8_t  CurrentBin;
    std::int32_t  CurrentCash;
    std::int16_t  AdaptiveDifficulty;
    SMSMessage    SMSMessages[150];
    std::uint16_t SMSSortOrder;
    char          CaseFileName[16];

    inline const char*   GetCaseFileName() { return CaseFileName; }
    inline void          AwardCash(std::int32_t amount) { CurrentCash += amount; }
    inline std::int32_t  GetCash() { return CurrentCash; }
    inline std::uint8_t  GetCurrentBin() { return CurrentBin; }
    inline void          SetCurrentBin(std::uint8_t bin) { CurrentBin = bin; }
    inline std::uint32_t GetCurrentCar() { return CurrentCar; }
    inline void          SetCurrentCar(std::uint32_t handle) { CurrentCar = handle; }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_CAREERSETTINGS_H
