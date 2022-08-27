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

#pragma once
#include <memory>  // unique_ptr
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/DLCommandObject.h>
#include <OpenSpeed/Game.ProStreet/Types/GRacerInfo.h>
#include <OpenSpeed/Game.ProStreet/Types/IPlayer.h>
#include <OpenSpeed/Game.ProStreet/Types/Timer.h>

namespace OpenSpeed::ProStreet::DALRacerCommands {
  struct IStatPrintable {
    enum class ePrintType : std::uint32_t { Off, Time, Score, Speed, Percent, OutOf };
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

    virtual ~RaceInformationCmd();
    virtual void Execute() override;

    std::uint32_t GetPrimaryProgressHeader() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(RaceInformationCmd*)>(0x53D010)(this);
    }

    void Setup(IPlayer* player, void* unk) {
      reinterpret_cast<void(__thiscall*)(RaceInformationCmd*, IPlayer*, void*)>(0x54FDE0)(this, player, unk);
    }

    static std::unique_ptr<RaceInformationCmd> Construct() {
      auto dummy  = std::make_unique<uint8_t[]>(sizeof(RaceInformationCmd));
      auto ret    = std::unique_ptr<RaceInformationCmd>{reinterpret_cast<RaceInformationCmd*>(dummy.release())};
      ret->mState = DLCommandObject::CommandState::WaitingToExecute;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x96FDFC;
      return ret;
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

    virtual ~TweakableFlashers();

    static std::unique_ptr<TweakableFlashers> Construct() {
      auto dummy  = std::make_unique<uint8_t[]>(sizeof(TweakableFlashers));
      auto ret    = std::unique_ptr<TweakableFlashers>{reinterpret_cast<TweakableFlashers*>(dummy.release())};
      ret->mState = DLCommandObject::CommandState::WaitingToExecute;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x9705E8;
      return ret;
    }
  };
}  // namespace OpenSpeed::ProStreet::DALRacerCommands
