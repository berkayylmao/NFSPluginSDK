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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_RACEPARAMETERS_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_RACEPARAMETERS_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Timer.h>

namespace NFSPluginSDK::MW05 {
  struct RaceParameters {
    enum class RaceTypes : std::uint8_t {
      None,
      SingleRace,
      TimeTrial,
      LapKnockout,
      RaceRnockout,
      Tournament,
      CarShow,
      GetAway
    };

    std::int32_t          TrackNumber;
    eTrackDirection       TrackDirection;
    eTrafficDensity       TrafficDensity;
    float                 TrafficOncoming;
    bool                  AIDemoMode;
    bool                  ReplayDemoMode;
    RaceTypes             RaceType;
    std::int32_t          Point2Point;
    float                 RollingStartSpeed;
    std::int32_t          NumLapsInRace;
    std::int32_t          NumPlayerCars;
    std::int32_t          NumAICars;
    std::int32_t          NumOnlinePlayerCars;
    std::int32_t          NumOnlineAICars;
    std::int8_t           PlayerStartPosition[2];
    bool                  DamageEnabled;
    eHandlingMode         HandlingMode;
    std::int32_t          FinishLineNumber;
    bool                  bDragRaceFlag;
    bool                  bDriftRaceFlag;
    bool                  bBurnoutFlag;
    bool                  bShortRaceFlag;
    bool                  bOnlineRace;
    bool                  bCarShowFlag;
    bool                  bGamebreakerOn;
    std::int32_t          PlayerJoyports[2];
    std::int32_t          nMaxCops;
    eOpponentStrength     CopStrength;
    float                 DriftOpponentScoreMultiplier;
    eOpponentStrength     OpponentStrength;
    std::int32_t          Boost;
    float                 BoostScale[2];
    eAIDifficultyModifier AIDifficultyModifier;
    std::int32_t          PlayerDriverNumber[2];
    std::int32_t          NumDriverInfo;
    Timer                 TimeTrialTime;
    bool                  bCareerEventRace;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_RACEPARAMETERS_H
