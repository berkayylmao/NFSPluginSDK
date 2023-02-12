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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GHUB_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GHUB_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GCareerElement.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GTier.h>

namespace NFSPluginSDK::ProStreet {
  struct GHub : GCareerElement {
    enum class Flags : std::uint32_t { NormalMode, PracticeMode };

    Flags                                    mFlags;
    std::uint32_t                            mScores[2];
    std::uint32_t                            mEventCount;
    std::uint32_t                            mCurrentEventKey;
    std::uint32_t                            mRequestedEventKey;
    GTier*                                   mTier;
    GHubWriter*                              mHubWriter;
    eastl::map<std::uint32_t, std::uint32_t> mCurrentScores;
    unsigned char                            _pad1[4];
    eastl::map<std::uint32_t, std::uint32_t> mCurrentRankings;
    unsigned char                            _pad2[4];
    std::int32_t                             mCurrentSunAndSky;
    std::uint32_t                            mWonRaces[8];

    std::uint32_t GetEventCount() { return reinterpret_cast<std::uint32_t(__thiscall*)(GHub*)>(0x419C30)(this); }
    Hub::OrgBody  GetOrgBody() { return reinterpret_cast<Hub::OrgBody(__thiscall*)(GHub*)>(0x661CE0)(this); }
    bool          HaveAllRacesBeenWon() { return reinterpret_cast<bool(__thiscall*)(GHub*)>(0x659FB0)(this); }
    bool          IsCareer() { return reinterpret_cast<bool(__thiscall*)(GHub*)>(0x531D90)(this); }
    bool          IsWon() { return reinterpret_cast<bool(__thiscall*)(GHub*)>(0x661B90)(this); }
    bool          IsDominated() { return reinterpret_cast<bool(__thiscall*)(GHub*)>(0x661C60)(this); }
    bool          IsRecordBeat() { return reinterpret_cast<bool(__thiscall*)(GHub*)>(0x694D10)(this); }
    void          Reset() { reinterpret_cast<void(__thiscall*)(GHub*)>(0x6816C0)(this); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GHUB_H
