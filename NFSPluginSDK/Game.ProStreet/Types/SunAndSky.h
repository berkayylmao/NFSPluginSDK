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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_SUNANDSKY_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_SUNANDSKY_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet {
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
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_SUNANDSKY_H
