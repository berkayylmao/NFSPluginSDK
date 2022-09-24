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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_WROADNAV_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_WROADNAV_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/USpline.h>

namespace NFSPluginSDK::MW05 {
  struct WRoadNav {
    template <typename T, std::int32_t N = 32>
    struct CookieTrail {
      std::int32_t       mCount;
      std::int32_t       mLast;
      const std::int32_t mCapacity;
      std::int32_t       pad;
      T                  mData[N];
    };
    struct NavCookie {
      enum class eFlags : std::uint32_t { CutByObject = 1, CutFromBehind = 2 };

      UMath::Vector2 Left;
      UMath::Vector2 Right;
      UMath::Vector2 Forward;
      float          Length;
      float          Curvature;
      float          LeftOffset;
      float          RightOffset;
      eFlags         Flags;
      float          Padding;
      UMath::Vector3 Centre;
      std::int16_t   SegmentParameter;
      std::uint16_t  SegmentNumber : 15;
      std::uint16_t  SegmentNodeInd : 1;
    };

    std::int32_t                nCookieIndex;
    CookieTrail<NavCookie, 32>* pCookieTrail;
    NavCookie                   mCurrentCookie;
    float                       mOutOfBounds;
    bool                        fValid;
    bool                        bRaceFilter;
    bool                        bTrafficFilter;
    bool                        bCopFilter;
    bool                        bDecisionFilter;
    bool                        bCookieTrail;
    std::int32_t                nRoadOcclusion;
    std::int32_t                nAvoidableOcclusion;
    bool                        bOccludedFromBehind;
    float                       fOccludingTrailSpeed;
    Math::Vector2               vCookieTrailBoxMin;
    Math::Vector2               vCookieTrailBoxMax;
    eNavType                    fNavType;
    ePathType                   fPathType;
    eLaneType                   fLaneType;
    AIVehicle*                  pAIVehicle;
    float                       fVehicleHalfWidth;
    std::int8_t                 fNodeInd;
    std::int16_t                fSegmentInd;
    float                       fSegTime;
    float                       fCurvature;
    UMath::Vector3              fPosition;
    UMath::Vector3              fLeftPosition;
    UMath::Vector3              fRightPosition;
    UMath::Vector3              fForwardVector;
    UMath::Vector3              fEndPos;
    UMath::Vector3              fStartPos;
    UMath::Vector3              fEndControl;
    UMath::Vector3              fStartControl;
    UMath::Vector3              fLeftEndPos;
    UMath::Vector3              fLeftStartPos;
    UMath::Vector3              fLeftEndControl;
    UMath::Vector3              fLeftStartControl;
    UMath::Vector3              fRightEndPos;
    UMath::Vector3              fRightStartPos;
    UMath::Vector3              fRightEndControl;
    UMath::Vector3              fRightStartControl;
    UMath::Vector3              fApexPosition;
    UMath::Vector3              fOccludedPosition;
    USpline                     fRoadSpline;
    USpline                     fLeftSpline;
    USpline                     fRightSpline;
    std::int8_t                 fDeadEnd;
    std::int8_t                 fLaneInd;
    std::int8_t                 fFromLaneInd;
    std::int8_t                 fToLaneInd;
    float                       fLaneOffset;
    float                       fFromLaneOffset;
    float                       fToLaneOffset;
    float                       fLaneChangeDist;
    float                       fLaneChangeInc;
    bool                        bCrossedPathGoal;
    std::uint8_t                nPathGoalSegment;
    std::uint16_t               fPathGoalParam;

    virtual ~WRoadNav();
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_WROADNAV_H
