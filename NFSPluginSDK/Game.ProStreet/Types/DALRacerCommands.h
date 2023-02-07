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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALRACERCOMMANDS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALRACERCOMMANDS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DLCommandObject.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GRacerInfo.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IPlayer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Timer.h>

namespace NFSPluginSDK::ProStreet::DALRacerCommands {
  struct IStatPrintable {
    enum class ePrintType : std::uint32_t { Off, Time, Score, Speed, Percent, OutOf };

    static void Print(char* buf, std::int32_t unk1, float unk2, ePrintType type) {
      reinterpret_cast<void(__cdecl*)(char*, std::int32_t, float, ePrintType)>(0x5CE6B0)(buf, unk1, unk2, type);
    }
  };

  struct RaceInformationCmd : DLCommandObject, IStatPrintable {
    IPlayer*       mPlayer;
    char           mPrimaryProgressLeftString[40];
    char           mPrimaryProgressRightString[40];
    char           mSecondaryProgressLeftString[40];
    char           mSecondaryProgressRightString[40];
    char           mPrimaryScoreString[40];
    char           mSecondaryScoreString[40];
    char           mTertiaryScoreString[40];
    std::int32_t   mIsPractice;
    GRace::Variant mRaceVariant;
    float          mDistToCheckpoint;
    SpeedUnitType  mSpeedUnits;
    std::int32_t   mCheckpointsCrossed;
    char           mDistanceMessage[96];
    float          mDistLastFlashed;
    GRacerInfo*    mTimeAttackLeader;
    bool           mIsNewTimeAttackLeader;
    bool           mShowLapToBeatTimeAttack;
    bool           mIsDragStaging;
    Timer          mTimer;

    virtual void Execute() override { reinterpret_cast<void(__thiscall*)(RaceInformationCmd*)>(0x550080)(this); }

    std::uint32_t GetPrimaryProgressHeader() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(RaceInformationCmd*)>(0x53D010)(this);
    }

    void Setup(IPlayer* player, void* unk) {
      reinterpret_cast<void(__thiscall*)(RaceInformationCmd*, IPlayer*, void*)>(0x54FDE0)(this, player, unk);
    }
  };

  struct TweakableFlashers : DLCommandObject {
    enum class eFlashers : std::uint32_t {
      FLASH_LAPTIME,
      FLASH_BEST_LAPTIME,
      FLASH_NEW_BEST_LAPTIME,
      FLASH_DAMAGE_LIGHT,
      FLASH_DAMAGE_HEAVY,
      FLASH_TOTALLED,
      FLASH_SPLIT_TIME,
      FLASH_OPPONENT_TOTALLED_CAR,
      FLASH_HURRY_UP_TIMER,
      FLASH_FINAL_LAP,
      FLASH_PLAYER_DISCONNECTED,
      FLASH_SECTOR_CLAIMED,
      FLASH_SECTOR_DOMINATED,
      FLASH_CHECKPOINT_SPEED,
      FLASH_CHECKPOINT_AHEAD,
      FLASH_OWN_BEST_LAP_TIME,
      FLASH_LOST_BEST_LAP_TIME,
      FLASH_SPLIT_SPEED,
      FLASH_FALSE_START,
      FLASH_OPPONENT_BLEW_ENGINE,
      FLASH_ENGINE_BLOWN,
      FLASH_OVERHEATING,
      FLASH_WHEELIE_DISTANCE,
      FLASH_DRIFT_OFF_TRACK,
      FLASH_DRIFT_SEAMLESS,
      FLASH_DRIFT_STAYED_ON_TRACK,
      FLASH_DRIFT_BEHIND_THE_PACE,
      FLASH_DRIFT_DOING_WELL,
      FLASH_DRIFT_GREAT_DRIFTING,
      FLASH_DRIFT_DOMINATING,
      FLASH_DRAG_25_GRIP_BONUS,
      FLASH_DRAG_50_GRIP_BONUS,
      FLASH_DRAG_75_GRIP_BONUS,
      FLASH_DRAG_100_GRIP_BONUS,
      FLASH_PERFECT_SHIFT,
      FLASH_GOOD_SHIFT,
      FLASH_MISSED_SHIFT,
      FLASH_PERFECT_LAUNCH,
      FLASH_GOOD_LAUNCH
    };
    enum class eScripts : std::uint32_t {
      DAMAGE_HEAVY,
      DAMAGE_LIGHT,
      DAMAGE_TOTALLED,
      ZOOMINWHITE,
      ZOOMINYELLOW,
      GO,
      REDGREEN,
      GREENRED,
      NEWSCRIPT1,
      NEWSCRIPT2,
      NEWSCRIPT3,
      NEWSCRIPT4,
      NEWSCRIPT5,
      NEWSCRIPT6,
      NEWSCRIPT7,
      NEWSCRIPT8,
      NEWSCRIPT9,
      NEWSCRIPT10,
    };

    eScripts mScripts[18];
  };
}  // namespace NFSPluginSDK::ProStreet::DALRacerCommands

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALRACERCOMMANDS_H
