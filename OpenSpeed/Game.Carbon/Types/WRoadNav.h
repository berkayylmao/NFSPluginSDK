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

#ifndef OPENSPEED_GAME_CARBON_TYPES_WROADNAV_H
#define OPENSPEED_GAME_CARBON_TYPES_WROADNAV_H
#pragma once

#include <OpenSpeed/Game.Carbon/Types.h>
#include <OpenSpeed/Game.Carbon/Types/USpline.h>

namespace OpenSpeed::Carbon {
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
}  // namespace OpenSpeed::Carbon

#endif  // OPENSPEED_GAME_CARBON_TYPES_WROADNAV_H
