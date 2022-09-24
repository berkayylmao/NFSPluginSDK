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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_TRACKINFO_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_TRACKINFO_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05 {
  struct TrackInfo {
    char             Name[32];
    char             TrackDirectory[32];
    char             RegionName[8];
    char             RegionDirectory[32];
    std::int32_t     LocationNumber;
    char             LocationDirectory[16];
    eLocationName    LocationName;
    eDriftType       DriftType;
    bool             IsValid;
    bool             Point2Point;
    bool             ReverseVersionExists;
    bool             Unused;
    bool             IsPerformanceTuning;
    std::int16_t     TrackNumber;
    std::int16_t     SameAsTrackNumber;
    std::uint32_t    SunInfoNameHash;
    std::uint32_t    UsageFlags;
    std::uint32_t    TrackLength;
    float            TimeToBeatForwards_ms;
    float            TimeToBeatReverse_ms;
    std::int32_t     ScoreToBeatForwards_DriftOnly;
    std::int32_t     ScoreToBeatReverse_DriftOnly;
    bVector2         TrackMapCalibrationUpperLeft;
    float            TrackMapCalibrationMapWidthMetres;
    std::uint16_t    TrackMapCalibrationRotation;
    std::uint16_t    TrackMapStartLineAngle;
    std::uint16_t    TrackMapFinishLineAngle;
    float            TrackMapZoomFactor;
    eTrackDifficulty ForwardDifficulty;
    eTrackDifficulty ReverseDifficulty;
    std::int16_t     OverrideStartingRouteForAI[2][4];
    std::int16_t     NumSecondsBeforeShortcutsAllowed;
    std::int16_t     nDriftSecondsMin;
    std::int16_t     nDriftSecondsMax;
    std::int16_t     pad2[1];
    std::int8_t      MaxTrafficCars[4][2];
    std::int8_t      TrafficAllowedNearStartLine[2];
    char             CarRaceStartConfig;
    char             padbyte;
    float            TrafficMinInitialDistanceFromStartLine[2];
    float            TrafficMinInitialDistanceBetweenCars[2];
    float            TrafficOncomingFraction[4];
    Math::Vector2    TrackMapZoomTopLeft;
    float            TrackMapZoomWidth;
    bool             TrackMapStartZoomed;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_TRACKINFO_H
