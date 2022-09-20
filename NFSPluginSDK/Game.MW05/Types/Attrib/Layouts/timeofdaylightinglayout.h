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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_TIMEOFDAYLIGHTINGLAYOUT_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_TIMEOFDAYLIGHTINGLAYOUT_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/RGBA.h>

namespace NFSPluginSDK::MW05::Attrib::Layouts {
  struct timeofdaylightinglayout {
    RGBA         SpecularColour;
    RGBA         DiffuseColour;
    RGBA         AmbientColour;
    RGBA         FogHazeColour;
    RGBA         FixedFunctionSkyColour;
    float        FogDistanceScale;
    float        FogHazeColourScale;
    float        FogSkyColourScale;
    float        EnvSkyBrightness;
    float        CarSpecScale;
    std::uint8_t _pad[0x4 * 3];
    RGBA         FogSkyColour;

    timeofdaylightinglayout operator+(const timeofdaylightinglayout& rhs) {
      timeofdaylightinglayout ret = *this;
      ret.SpecularColour += rhs.SpecularColour;
      ret.DiffuseColour += rhs.DiffuseColour;
      ret.AmbientColour += rhs.AmbientColour;
      ret.FogHazeColour += rhs.FogHazeColour;
      ret.FixedFunctionSkyColour += rhs.FixedFunctionSkyColour;
      ret.FogDistanceScale += rhs.FogDistanceScale;
      ret.FogSkyColourScale += rhs.FogSkyColourScale;
      ret.FogHazeColourScale += rhs.FogHazeColourScale;
      ret.EnvSkyBrightness += rhs.EnvSkyBrightness;
      ret.CarSpecScale += rhs.CarSpecScale;
      ret.FogSkyColour += rhs.FogSkyColour;

      return ret;
    }
    timeofdaylightinglayout operator-(const timeofdaylightinglayout& rhs) {
      timeofdaylightinglayout ret = *this;
      ret.SpecularColour -= rhs.SpecularColour;
      ret.DiffuseColour -= rhs.DiffuseColour;
      ret.AmbientColour -= rhs.AmbientColour;
      ret.FogHazeColour -= rhs.FogHazeColour;
      ret.FixedFunctionSkyColour -= rhs.FixedFunctionSkyColour;
      ret.FogDistanceScale -= rhs.FogDistanceScale;
      ret.FogSkyColourScale -= rhs.FogSkyColourScale;
      ret.FogHazeColourScale -= rhs.FogHazeColourScale;
      ret.EnvSkyBrightness -= rhs.EnvSkyBrightness;
      ret.CarSpecScale -= rhs.CarSpecScale;
      ret.FogSkyColour -= rhs.FogSkyColour;

      return ret;
    }
    timeofdaylightinglayout operator*(float rhs) {
      timeofdaylightinglayout ret = *this;
      ret.SpecularColour *= rhs;
      ret.DiffuseColour *= rhs;
      ret.AmbientColour *= rhs;
      ret.FogHazeColour *= rhs;
      ret.FixedFunctionSkyColour *= rhs;
      ret.FogDistanceScale *= rhs;
      ret.FogSkyColourScale *= rhs;
      ret.FogHazeColourScale *= rhs;
      ret.EnvSkyBrightness *= rhs;
      ret.CarSpecScale *= rhs;
      ret.FogSkyColour *= rhs;

      return ret;
    }
    timeofdaylightinglayout operator/(float rhs) {
      timeofdaylightinglayout ret = *this;
      ret.SpecularColour /= rhs;
      ret.DiffuseColour /= rhs;
      ret.AmbientColour /= rhs;
      ret.FogHazeColour /= rhs;
      ret.FixedFunctionSkyColour /= rhs;
      ret.FogDistanceScale /= rhs;
      ret.FogSkyColourScale /= rhs;
      ret.FogHazeColourScale /= rhs;
      ret.EnvSkyBrightness /= rhs;
      ret.CarSpecScale /= rhs;
      ret.FogSkyColour /= rhs;

      return ret;
    }

    void operator=(const timeofdaylightinglayout& rhs) {
      SpecularColour         = rhs.SpecularColour;
      DiffuseColour          = rhs.DiffuseColour;
      AmbientColour          = rhs.AmbientColour;
      FogHazeColour          = rhs.FogHazeColour;
      FixedFunctionSkyColour = rhs.FixedFunctionSkyColour;
      FogDistanceScale       = rhs.FogDistanceScale;
      FogSkyColourScale      = rhs.FogSkyColourScale;
      FogHazeColourScale     = rhs.FogHazeColourScale;
      EnvSkyBrightness       = rhs.EnvSkyBrightness;
      CarSpecScale           = rhs.CarSpecScale;
      FogSkyColour           = rhs.FogSkyColour;
    }
    void operator+=(const timeofdaylightinglayout& rhs) { *this = *this + rhs; }
    void operator-=(const timeofdaylightinglayout& rhs) { *this = *this - rhs; }
    void operator*=(float rhs) { *this = *this * rhs; }
    void operator/=(float rhs) { *this = *this / rhs; }
  };
}  // namespace NFSPluginSDK::MW05::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_TIMEOFDAYLIGHTINGLAYOUT_H
