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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_USERPROFILE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_USERPROFILE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEPlayerCarDB.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EA.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Gameplay.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Jukebox.h>
#include <NFSPluginSDK/Game.ProStreet/Types/OptionsSettings.h>
#include <NFSPluginSDK/Game.ProStreet/Types/RaceDaySettings.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL/FixedVector.h>  // Jukebox typedef

namespace NFSPluginSDK::ProStreet {
  struct UserProfile : EA::Memcard::IMemcardSavable {
    char                 mName[32];
    Jukebox              mPlaylist;
    FEPlayerCarDB        mCarStable;
    OptionsSettings      mOptionsSettings;
    std::uint32_t        mNumRaceDaySaves;
    std::uint32_t        mNumRaceDaySavesTotal;
    Gameplay::GHubRecord mCurrentRaceDayConfig;
    RaceDaySettings      mRaceDaySettings;
    std::uint32_t        mOnlineXPLevel;
    std::uint32_t        mEasterEggs;

    static inline UserProfile (**spUserProfiles)[4] = reinterpret_cast<UserProfile (**)[4]>(0xAB0EAC);

    static UserProfile* Get(std::size_t idx = 0) {
      if (!spUserProfiles) return nullptr;
      return (*spUserProfiles)[idx];
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_USERPROFILE_H
