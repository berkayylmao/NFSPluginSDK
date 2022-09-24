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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ACIDEFFECT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ACIDEFFECT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/bList.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/emittergroup.h>

namespace NFSPluginSDK::ProStreet {
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
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ACIDEFFECT_H
