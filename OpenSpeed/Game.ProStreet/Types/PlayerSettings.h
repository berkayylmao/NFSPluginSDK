// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <mail@berkay.link>
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
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/EA.h>

namespace OpenSpeed::ProStreet {
  struct PlayerSettings : EA::Memcard::IMemcardSavable {
    bool                   GaugesOn;
    bool                   PositionOn;
    bool                   LapInfoOn;
    bool                   RaceInfoOn;
    bool                   ScoreOn;
    bool                   Rumble;
    bool                   LeaderboardOn;
    bool                   SectorDisplayOn;
    bool                   CrewInfoOn;
    bool                   TransmissionPromptOn;
    bool                   DriveWithAnalog;
    eTransmissionType      GripTransmission;
    ePlayerSettingsCameras GripCarCamera;
    char                   GripBrakes;
    char                   GripTractionControl;
    char                   GripElectronicControl;
    eTransmissionType      DriftTransmission;
    ePlayerSettingsCameras DriftCarCamera;
    char                   DriftTractionControl;
    char                   DriftElectronicControl;
    char                   DragClutch;
    ePlayerSettingsCameras DragCarCamera;
    eTransmissionType      SpeedTransmission;
    ePlayerSettingsCameras SpeedCarCamera;
    char                   SpeedTractionControl;
    char                   SpeedElectronicControl;
    eSensitivitySetting    SensitivitySetting;
    eControllerConfig      Config;
    ePlayerSettingsCameras CurCam;
    eDriverAssistLevel     DriverAssistLevel;
    eSplitTimeTypes        SplitTimeType;
    eTransmissionType      Transmission;
    eHandlingMode          Handling;
    std::int8_t            Player;
    bool                   TextPopupsOn;
    bool                   BestLineOn;
    bool                   ArrowIndicatorsOn;
    bool                   InGameLeaderboardOn;
  };
}  // namespace OpenSpeed::ProStreet