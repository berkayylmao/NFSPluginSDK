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
