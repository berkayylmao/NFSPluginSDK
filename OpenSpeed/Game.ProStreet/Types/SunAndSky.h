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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_SUNANDSKY_H
#define OPENSPEED_GAME_PROSTREET_TYPES_SUNANDSKY_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>

namespace OpenSpeed::ProStreet {
  struct SunAndSky {
    std::uint32_t mCurrentKey;
    __declspec(align(16)) bVector4 mSunDirection;
    bVector4      mVisibleSunDirection;
    bVector4      mSunPosition;
    bVector4      mVisibleSunPosition;
    bVector4      mSunColour;
    bVector4      mAmbientColour;
    bVector4      mCarSunColour;
    bVector4      mCarAmbientColour;
    bVector4      mFogColour;
    float         mFogMixAmount;
    float         mFogStart;
    float         mFogEnd;
    float         mFogExponent;
    float         mFogFalloffPs2;
    float         mFogFalloffXPs2;
    float         mFogFalloffYPs2;
    bool          mOverrideSunPosition;
    float         mLatitudeOverride;
    float         mLongitudeOverride;
    float         mSkyLatitudeOverride;
    std::uint32_t mLensFlareIndex;
    float         mSkyDomeRotation;
    float         mSpecularSize;
    float         mRoadSpecularSize;
    float         mSpecularIntensity;
    bVector4      mSpecularColour;
    float         mShadowMixAmount;
    float         mShadowSoftness;
    float         mBloomIntensity;
    float         mBloomThreshold;
    eSkyStyle     mSkyStyle;

    static inline SunAndSky* gSunAndSky = reinterpret_cast<SunAndSky*>(0xA83AB0);
    static inline SunAndSky* Get() { return gSunAndSky; }
  };
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_SUNANDSKY_H
