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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FENGFONT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FENGFONT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/bNode.h>
#include <NFSPluginSDK/Game.ProStreet/Types/eTexture.h>

namespace NFSPluginSDK::ProStreet {
  namespace RealFontOld {
    struct Font {
      char          mSignature[4];
      std::uint32_t mSize;
      std::uint16_t mVersion;
      std::uint16_t mNum;
      std::uint32_t mFlags;
      std::int8_t   mCenterX;
      std::int8_t   mCenterY;
      std::int8_t   mAscent;
      std::int8_t   mDescent;
      std::int32_t  mGlyphTbl;
      std::int32_t  mKernTbl;
      std::int32_t  mShape;
      std::int32_t  mStates[24];
    };
  }  // namespace RealFontOld

  struct FEngFont : bTNode<FEngFont> {
    eTexture           mTexture;
    RealFontOld::Font* mpFont;
    float              mZValue;
    std::uint32_t      mFontHash;
    char*              mpFontName;
    char*              mpTextureName;
    float              mHeight;
    float              mBaselineOffset;
    float              mLeadingScale;

    float GetTextWidth(FEString* string) {
      return reinterpret_cast<float(__thiscall*)(FEngFont*, FEString*, std::uint32_t)>(0x5A1D50)(this, string, 0);
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FENGFONT_H
