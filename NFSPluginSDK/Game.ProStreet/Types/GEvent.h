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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GEVENT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GEVENT_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/sort.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GRacerInfo.h>

namespace NFSPluginSDK::ProStreet {
  struct GEvent {
    GActivity*                                              mEventActivity;
    eastl::vector<std::uint32_t>                            mOpponents;
    eastl::map<std::uint32_t, GRacerInfo::GRacerHeatStats*> mOpponentStats;
    unsigned char                                           __pad1[4];
    eastl::map<std::uint32_t, GRacerInfo::GRacerPoints*>    mOpponentPoints;
    unsigned char                                           __pad2[132];
    GRacerInfo::GRacerHeatStats                             mHeatStats[8][4];
    GRacerInfo::GRacerPoints                                mPoints[8];
    std::int32_t                                            mNumHeats;
    std::int32_t                                            mCurrentHeat;
    bool                                                    mAscending;

    void AssignGridNumbersBasedOnPerformance() { reinterpret_cast<void(__thiscall*)(GEvent*)>(0x68B5D0)(this); }
    std::uint32_t GetEventKey() { return reinterpret_cast<std::uint32_t(__thiscall*)(GEvent*)>(0x6595F0)(this); }

    static GEvent* Get() {
      static GEvent** fObj = reinterpret_cast<GEvent**>(0xAB9DB0);
      return *fObj;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GEVENT_H
