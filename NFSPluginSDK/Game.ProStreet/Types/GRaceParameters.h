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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEPARAMETERS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEPARAMETERS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/gameplay.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GRaceIndexData.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GVault.h>

namespace NFSPluginSDK::ProStreet {
  struct GRaceParameters {
    enum class ScoreUnitType : std::uint32_t { None, Time, Speed, Points };

    GRaceIndexData*        mIndex;
    Attrib::Gen::gameplay* mRaceRecord;
    GVault*                mParentVault;
    GVault*                mChildVault;
    GVault*                mTrackVault;
    GVault*                mRegionVault;

    virtual void GetCheckpointPosition(std::uint32_t, UMath::Vector3&);
    virtual void GetCheckpointDirection(std::uint32_t, UMath::Vector3&);
    virtual ~GRaceParameters();

    std::uint32_t GetEventHash() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(GRaceParameters*)>(0x6826F0)(this);
    }
    std::int8_t    GetNumLaps() { return reinterpret_cast<std::int8_t(__thiscall*)(GRaceParameters*)>(0x657CF0)(this); }
    GRace::Variant GetRaceVariant() {
      if (!mIndex) return GRace::Variant::Invalid;

      return reinterpret_cast<GRace::Variant(__cdecl*)(GRace::Type)>(0x657E10)(mIndex->mRaceType);
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GRACEPARAMETERS_H
