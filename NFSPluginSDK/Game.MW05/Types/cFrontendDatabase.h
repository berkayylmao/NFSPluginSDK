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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_CFRONTENDDATABASE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_CFRONTENDDATABASE_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/cFinishedRaceStats.h>
#include <NFSPluginSDK/Game.MW05/Types/FEKeyboardSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/OptionsSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/RaceSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/UserProfile.h>

namespace NFSPluginSDK::MW05 {
  struct cFrontEndDatabase {
    // GRace::Type
    enum class RaceType : std::uint32_t {
      Point2Point,  // Sprint
      Circuit,
      Drag,
      Knockout,
      Tollbooth,
      SpeedTrap,
      Checkpoint,
      CashGrab,
      Challenge,
      JumpToSpeedTrap,
      JumpToMilestone,
      None = UINT32_MAX
    };

    std::uint8_t           iNumPlayers;
    bool                   bComingFromBoot;
    bool                   bSavedProfileForMP;
    bool                   bProfileLoaded;
    bool                   bIsOptionsDirty;
    bool                   bAutoSaveOverwriteConfirmed;
    std::uint32_t          iDefaultStableHash;
    std::int8_t            PlayerJoyports[2];
    UserProfile*           CurrentUserProfiles[2];
    RaceType               RaceMode;
    RaceSettings           TheQuickRaceSettings[11];
    char*                  m_pCarStableBackup;
    char*                  m_pDBBackup;
    eFEGameModes           FEGameMode;
    eLoadSaveGame          LoadSaveGame;
    FEKeyboardSettings     mFEKeyboardSettings;
    std::int32_t           iCurPauseSubOptionType;
    std::int32_t           iCurPauseOptionType;
    FECustomizationRecord* SplitScreenCustomization;
    std::int8_t            SplitScreenCarType[256];
    cFinishedRaceStats     FinishedRaceStats;
    ePostRaceOptions       PostRaceOptionChosen;

    inline UserProfile*      GetUserProfile() { return CurrentUserProfiles[0]; }
    inline CareerSettings&   GetCareerSettings() { return this->GetUserProfile()->GetCareer(); }
    inline OptionsSettings&  GetOptionsSettings() { return this->GetUserProfile()->GetOptions(); }
    inline VideoSettings&    GetVideoSettings() { return this->GetOptionsSettings().GetVideoSettings(); }
    inline GameplaySettings& GetGameplaySettings() { return this->GetOptionsSettings().GetGameplaySettings(); }
    inline AudioSettings&    GetAudioSettings() { return this->GetOptionsSettings().GetAudioSettings(); }
    inline PlayerSettings&   GetPlayerSettings() { return this->GetOptionsSettings().GetPlayerSettings(); }

    static inline cFrontEndDatabase** g_mThis = reinterpret_cast<cFrontEndDatabase**>(0x91CF90);
    static cFrontEndDatabase*         Get() {
              if (!g_mThis) return nullptr;
      return *g_mThis;
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_CFRONTENDDATABASE_H
