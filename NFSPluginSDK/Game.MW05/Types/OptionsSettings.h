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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_OPTIONSSETTINGS_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_OPTIONSSETTINGS_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AudioSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/GameplaySettings.h>
#include <NFSPluginSDK/Game.MW05/Types/PlayerSettings.h>
#include <NFSPluginSDK/Game.MW05/Types/VideoSettings.h>

namespace NFSPluginSDK::MW05 {
  struct OptionsSettings {
    eOptionsCategory CurrentCategory;
    VideoSettings    TheVideoSettings;
    GameplaySettings TheGameplaySettings;
    AudioSettings    TheAudioSettings;
    PlayerSettings   ThePlayerSettings[2];

    inline VideoSettings&    GetVideoSettings() { return TheVideoSettings; }
    inline GameplaySettings& GetGameplaySettings() { return TheGameplaySettings; }
    inline AudioSettings&    GetAudioSettings() { return TheAudioSettings; }
    inline PlayerSettings&   GetPlayerSettings(std::size_t index = 0) { return ThePlayerSettings[index]; }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_OPTIONSSETTINGS_H
