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
#include <OpenSpeed/Game.MW05/Types/Attrib/RGBA.h>

namespace OpenSpeed::MW05::Attrib::Layouts {
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
      timeofdaylightinglayout _result = *this;
      _result.SpecularColour += rhs.SpecularColour;
      _result.DiffuseColour += rhs.DiffuseColour;
      _result.AmbientColour += rhs.AmbientColour;
      _result.FogHazeColour += rhs.FogHazeColour;
      _result.FixedFunctionSkyColour += rhs.FixedFunctionSkyColour;
      _result.FogDistanceScale += rhs.FogDistanceScale;
      _result.FogSkyColourScale += rhs.FogSkyColourScale;
      _result.FogHazeColourScale += rhs.FogHazeColourScale;
      _result.EnvSkyBrightness += rhs.EnvSkyBrightness;
      _result.CarSpecScale += rhs.CarSpecScale;
      _result.FogSkyColour += rhs.FogSkyColour;

      return _result;
    }
    timeofdaylightinglayout operator-(const timeofdaylightinglayout& rhs) {
      timeofdaylightinglayout _result = *this;
      _result.SpecularColour -= rhs.SpecularColour;
      _result.DiffuseColour -= rhs.DiffuseColour;
      _result.AmbientColour -= rhs.AmbientColour;
      _result.FogHazeColour -= rhs.FogHazeColour;
      _result.FixedFunctionSkyColour -= rhs.FixedFunctionSkyColour;
      _result.FogDistanceScale -= rhs.FogDistanceScale;
      _result.FogSkyColourScale -= rhs.FogSkyColourScale;
      _result.FogHazeColourScale -= rhs.FogHazeColourScale;
      _result.EnvSkyBrightness -= rhs.EnvSkyBrightness;
      _result.CarSpecScale -= rhs.CarSpecScale;
      _result.FogSkyColour -= rhs.FogSkyColour;

      return _result;
    }
    timeofdaylightinglayout operator*(float rhs) {
      timeofdaylightinglayout _result = *this;
      _result.SpecularColour *= rhs;
      _result.DiffuseColour *= rhs;
      _result.AmbientColour *= rhs;
      _result.FogHazeColour *= rhs;
      _result.FixedFunctionSkyColour *= rhs;
      _result.FogDistanceScale *= rhs;
      _result.FogSkyColourScale *= rhs;
      _result.FogHazeColourScale *= rhs;
      _result.EnvSkyBrightness *= rhs;
      _result.CarSpecScale *= rhs;
      _result.FogSkyColour *= rhs;

      return _result;
    }
    timeofdaylightinglayout operator/(float rhs) {
      timeofdaylightinglayout _result = *this;
      _result.SpecularColour /= rhs;
      _result.DiffuseColour /= rhs;
      _result.AmbientColour /= rhs;
      _result.FogHazeColour /= rhs;
      _result.FixedFunctionSkyColour /= rhs;
      _result.FogDistanceScale /= rhs;
      _result.FogSkyColourScale /= rhs;
      _result.FogHazeColourScale /= rhs;
      _result.EnvSkyBrightness /= rhs;
      _result.CarSpecScale /= rhs;
      _result.FogSkyColour /= rhs;

      return _result;
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
}  // namespace OpenSpeed::MW05::Attrib::Layouts
