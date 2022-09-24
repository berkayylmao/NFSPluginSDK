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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GAMEPLAY_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GAMEPLAY_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::Gameplay {
  struct GHubRecord {
    enum class ePlayMode : std::uint32_t { Solo, Split, Multiplayer };
    enum class eCarMode : std::uint32_t { Grip, Drift, Drag, Speed, Backup, Invalid };

    struct GEventRecord {
      std::uint32_t Key;
      std::uint32_t Laps;
      std::uint32_t Heats;
    };

    std::uint32_t mTrackKey;
    std::uint32_t mDifficulty;
    std::uint32_t mRepairMarkerCount;
    std::uint32_t mEventCount;
    GEventRecord  mEvents[8];
    char          mSaveName[32];
    ePlayMode     mPlayMode;
    std::int32_t  mIsShared;
    bool          mIsSaved;
    char          mGUID[21];
    std::uint32_t mPresetCars[5];
    eCarMode      mBackupCarMode;
    bool          mIsChallengeCustomHub;
    std::uint32_t mCreatorFeslID;
  };
}  // namespace NFSPluginSDK::ProStreet::Gameplay

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GAMEPLAY_H
