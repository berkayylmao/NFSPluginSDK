// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/cFinishedRaceStats.h>
#include <OpenSpeed/Game.MW05/Types/FEKeyboardSettings.h>
#include <OpenSpeed/Game.MW05/Types/OptionsSettings.h>
#include <OpenSpeed/Game.MW05/Types/RaceSettings.h>
#include <OpenSpeed/Game.MW05/Types/UserProfile.h>

namespace OpenSpeed::MW05 {
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
}  // namespace OpenSpeed::MW05