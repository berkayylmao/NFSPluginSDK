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
