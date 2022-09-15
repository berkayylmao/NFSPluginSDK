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

#ifndef OPENSPEED_GAME_PROSTREET_TYPES_CARTYPEINFO_H
#define OPENSPEED_GAME_PROSTREET_TYPES_CARTYPEINFO_H
#pragma once

#include <OpenSpeed/Game.ProStreet/Types.h>

namespace OpenSpeed::ProStreet {
#pragma pack(push, 1)
  struct CarTypeInfo {
    char          mCarTypeName[16];
    char          mBaseModelName[16];
    char          mGeometryFilename[32];
    char          mManufacturerName[16];
    std::uint32_t mCarTypeNameHash;
    float         mHeadlightFOV;
    std::int8_t   mPadHighPerformance;
    std::int8_t   mNumAvailableSkinNumbers;
    std::int8_t   mWhatGame;
    std::int8_t   mConvertableFlag;
    std::int8_t   mWheelOuterRadius;
    std::int8_t   mWheelInnerRadiusMin;
    std::int8_t   mWheelInnerRadiusMax;
    unsigned char __pad1;
    bVector3      mHeadlightPosition;
    unsigned char __pad2[4];
    bVector3      mDriverRenderingOffset;
    unsigned char __pad3[4];
    bVector3      mInCarSteeringWheelRenderingOffset;
    unsigned char __pad4[4];
    CarType       mType;
    CarUsageType  mUsageType;
    std::uint32_t mCarMemTypeHash;
    std::int8_t   mMaxInstances[5];
    std::int8_t   mWantToKeepLoaded[5];
    unsigned char __pad5[2];
    float         mMinTimeBetweenUses[5];
    std::int8_t   mAvailableSkinNumbers[10];
    std::int8_t   mDefaultSkinNumber;
    std::int8_t   mSkinnable;
    unsigned char __pad6[4];
    std::int32_t  mDefaultBasePaint;

    static CarTypeInfo* GetFromCarTypeNameHash(std::uint32_t hash) {
      return reinterpret_cast<CarTypeInfo*(__cdecl*)(std::uint32_t)>(0x754E00)(hash);
    }
  };
#pragma pack(pop)
}  // namespace OpenSpeed::ProStreet

#endif  // OPENSPEED_GAME_PROSTREET_TYPES_CARTYPEINFO_H
