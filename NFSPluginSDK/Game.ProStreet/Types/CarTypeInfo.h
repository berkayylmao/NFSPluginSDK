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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARTYPEINFO_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARTYPEINFO_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet {
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
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARTYPEINFO_H
