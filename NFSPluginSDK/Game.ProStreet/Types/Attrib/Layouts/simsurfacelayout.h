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
