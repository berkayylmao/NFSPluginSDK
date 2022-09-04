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
#include <OpenSpeed/Game.ProStreet/Types/bList.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Gen/emittergroup.h>

namespace OpenSpeed::ProStreet {
  struct AcidEffectAttribWrapper {
    Attrib::Gen::emittergroup mStaticData;
  };

  struct AcidEffect : bTNode<AcidEffect> {
    enum class Flags : std::uint32_t {
      AUTO_UPDATE = 1 << 0,
      IS_STATIC   = 1 << 1,
      LOADED      = 1 << 2,
      ENABLED     = 1 << 3,
    };

    bTList<AcidEmitter> mEmitters;
    std::uint32_t       mGroupKey;
    std::uint32_t       Padding;
    Flags               mFlags;
    std::uint16_t       mNumEmitters;
    std::uint16_t       mSectionNumber;
    bMatrix4            mLocalWorld;
    void*               mSubscriber;
    float               mFarClip;
    float               mIntensity;
    void(__cdecl* mDeleteCallback)(void*, AcidEffect*);
    bVector3                 mLastPosition;
    AcidEffectAttribWrapper* mDynamicData;
    std::uint32_t            mNumZeroParticleFrames;
    std::uint32_t            mCreationTimeStamp;
    std::uint32_t            pad;
  };

#ifdef _WIN32
  DEFINE_ENUM_FLAG_OPERATORS(AcidEffect::Flags)
#endif
}  // namespace OpenSpeed::ProStreet
