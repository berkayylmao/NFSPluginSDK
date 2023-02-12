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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GCAREER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GCAREER_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GActiveHubSaveData.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GHub.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GTier.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct GCareer {
    struct GCareerItemSaveInfo {
      enum class Flags : std::uint32_t {
        None,
        Unlocked                = 1 << 1,
        Won                     = 1 << 2,
        Dominated               = 1 << 3,
        RecordReached           = 1 << 4,
        FirstTime_Won           = 1 << 5,
        FirstTime_Dominated     = 1 << 6,
        FirstTime_RecordReached = 1 << 7,
        TrackRecordJustBroken   = 1 << 8
      };

      std::uint32_t mCollection;
      Flags         mFlags;
      std::uint32_t mPoints;
    };
    struct GTierSaveInfo {
      std::uint32_t mCollection;
      std::uint32_t mFlags;
      std::uint32_t mHubsDominated;
      std::uint32_t mHubsWon;
      std::uint32_t mHubsRecordReached;
    };
    struct GCareerModeSaveInfo {
      std::uint32_t mNumRaces;
      std::uint32_t mNumWins;
    };
    struct GCareerSaveInfo {
      GCareerModeSaveInfo mModeRecords[4];
      GActiveHubSaveData  mActiveHubData;
      bool                mDDayFlowDone;
    };

    GCareerItemSaveInfo* mHubData;
    GTierSaveInfo*       mTierData;
    eastl::list<GHub*>   mUnlockHubList;
    GCareerSaveInfo      mCareerSaveInfo;
    GTier*               mDominatedTier;
    bool                 mHasTotalledCar;
    bool                 mSetActiveHubKeyOnSave;

    bool IsHubWon(GHub* hub) { return reinterpret_cast<bool(__thiscall*)(GCareer*, GHub*)>(0x6629F0)(this, hub); }
    bool IsHubDominated(GHub* hub) { return reinterpret_cast<bool(__thiscall*)(GCareer*, GHub*)>(0x662A20)(this, hub); }
    bool IsHubUnlocked(GHub* hub) { return reinterpret_cast<bool(__thiscall*)(GCareer*, GHub*)>(0x66A650)(this, hub); }
    bool IsTierDominated(std::uint32_t collectionNameHash) {
      return reinterpret_cast<bool(__thiscall*)(GCareer*, std::uint32_t)>(0x67ED00)(this, collectionNameHash);
    }

    GCareerItemSaveInfo* GetHubSaveFromKey(std::uint32_t collectionNameHash) {
      return reinterpret_cast<GCareerItemSaveInfo*(__thiscall*)(GCareer*, std::uint32_t)>(0x65A490)(this,
                                                                                                    collectionNameHash);
    }
    GTierSaveInfo* GetTierSaveFromKey(std::uint32_t collectionNameHash) {
      return reinterpret_cast<GTierSaveInfo*(__thiscall*)(GCareer*, std::uint32_t)>(0x65A4D0)(this, collectionNameHash);
    }

    static GCareer* Get() { return reinterpret_cast<GCareer*(__cdecl*)()>(0x5341D0)(); }
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(GCareer::GCareerItemSaveInfo::Flags)
#endif
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GCAREER_H
