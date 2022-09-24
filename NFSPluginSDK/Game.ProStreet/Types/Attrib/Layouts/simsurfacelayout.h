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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_SIMSURFACELAYOUT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_SIMSURFACELAYOUT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Private.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/RefSpec.h>

namespace NFSPluginSDK::ProStreet::Attrib::Layouts {
  struct simsurfacelayout {
    struct RoadNoiseRecord {
      float Frequency;
      float Amplitude;
      float MinSpeed;
      float MaxSpeed;
    };
    struct TireEffectRecord {
      TireCondition   mTireCondition;
      Attrib::RefSpec mEmitter;
      Attrib::RefSpec mEmitterLowLod;
      float           mMinSpeed;
      float           mMaxSpeed;
    };

    Attrib::Private  _Array_TireSlipEffects;
    TireEffectRecord TireSlipEffects[5];
    const char*      CollectionName;
    RoadNoiseRecord  RenderNoise;
    float            WORLD_FRICTION;
    SurfaceSFX       SurfaceFX_ID;
    float            STICK;
    ScrapeSurfaces   ScrapeFX_ID;
    float            ROLLING_RESISTANCE;
    float            LATERAL_GRIP;
    float            GROUND_FRICTION;
    float            DRIVE_GRIP;
    eDecalType       Decal;
    std::uint16_t    WheelEffectFrequency;
    std::uint8_t     WheelEffectIntensity;
  };
}  // namespace NFSPluginSDK::ProStreet::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_LAYOUTS_SIMSURFACELAYOUT_H
