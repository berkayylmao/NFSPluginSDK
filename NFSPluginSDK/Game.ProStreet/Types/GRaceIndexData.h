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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEINDEXDATA_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEINDEXDATA_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet {
  struct GRaceIndexData {
    std::uint32_t mKey;
    char          mEventID[10];
    std::uint32_t mRaceHash;  // Attrib::StringToKey for mEventID
    std::uint32_t mFlags;
    float         mLength;
    std::int16_t  mLocalizationTag;
    float16       mCash;
    std::uint16_t mRivalBest;  // 16-bit 10.2 fixed point
    std::int8_t   mNumLaps;
    GRace::Type   mRaceType;
    std::int8_t   mNumHeats;
    std::uint32_t mPlayerCarTypeHash;
    float         mTrackRecord;
    std::uint32_t mTrack;
    std::uint32_t mTrackLayout;
    std::uint32_t mParentKey;
    std::uint32_t mTrackRecordHolder;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEINDEXDATA_H
