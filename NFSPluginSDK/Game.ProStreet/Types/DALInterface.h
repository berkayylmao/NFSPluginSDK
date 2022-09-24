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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALINTERFACE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALINTERFACE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DLCommandObject.h>

namespace NFSPluginSDK::ProStreet {
  struct DALInterface {
    enum class Type : std::uint32_t {
      Template,
      Racer,
      Vehicle,
      Event,
      LangHash,
      Options,
      Career,
      FEVehicle,
      PauseStates,
      Player,
      Pursuit,
      Statistics,
      Online,
      Challenge,
      Hub,
      Async,
      Rewards,
      RaceDay,
      Opponent,
      Memcard,
      MemcardTasks,
      StatsMetrics
    };
    enum class Code : std::uint32_t {
      DAL_RACER_TOP_SPEED                              = 0x3E8,
      DAL_RACER_AVG_SPEED                              = 0x3E9,
      DAL_RACER_PERCENT_COMPLETED                      = 0x3EA,
      DAL_RACER_DISTANCE_AHEAD                         = 0x3EB,
      DAL_RACER_TIME_AHEAD                             = 0x3EC,
      DAL_RACER_POINTS_AHEAD                           = 0x3ED,
      DAL_RACER_FLT_POINTS                             = 0x3EE,
      DAL_RACER_RACE_TIME                              = 0x3EF,
      DAL_RACER_TOTAL_TIME                             = 0x3F0,
      DAL_RACER_SUMMED_TIME                            = 0x3F1,
      DAL_RACER_ELAPSE_TIME                            = 0x3F2,
      DAL_RACER_REMAIN_TIME                            = 0x3F3,
      DAL_RACER_LAP_TIME                               = 0x3F4,
      DAL_RACER_SPLIT_TIME                             = 0x3F5,
      DAL_RACER_SPLIT_TIME_TOTAL                       = 0x3F6,
      DAL_RACER_LASTLAP_TIME                           = 0x3F7,
      DAL_RACER_BESTLAP_TIME                           = 0x3F8,
      DAL_RACER_CURLAP_TIME                            = 0x3F9,
      DAL_RACER_TIME_BEHIND_LEAD                       = 0x3FA,
      DAL_RACER_BEST_LAP_TIME                          = 0x3FB,
      DAL_RACER_TOP_SPEED_RAW                          = 0x3FC,
      DAL_RACER_FLT_SPEEDTRAP_SPEED                    = 0x3FD,
      DAL_RACER_FLT_FINAL_SCORE                        = 0x3FE,
      DAL_RACER_FLT_SPEEDTRAP_TOTAL_SPEED              = 0x3FF,
      DAL_RACER_FLT_SPEEDTRAP_TOTAL_SPEED_RAW          = 0x400,
      DAL_RACER_FLT_SPEEDTRAP_BEST_SPEED               = 0x401,
      DAL_RACER_FLT_SPEEDTRAP_BEST_SPEED_RAW           = 0x402,
      DAL_RACER_FLT_SPEEDTRAP_AVERAGE_SPEED            = 0x403,
      DAL_RACER_FLT_SPEEDTRAP_TOTAL_SPEED_BEHIND       = 0x404,
      DAL_RACER_FLT_DRIFT_CURRENT_DISTANCE_TO_FRIEND   = 0x405,
      DAL_RACER_DRIFT_FURTHEST_DISTANCE_FROM_FOLLOWER  = 0x406,
      DAL_RACER_DRIFT_CLOSEST_DISTANCE_TO_LEADER       = 0x407,
      DAL_RACER_DRIFT_TOP_SCORE                        = 0x408,
      DAL_RACER_TOP_CHECKPOINT_SPEED                   = 0x409,
      DAL_RACER_TOTAL_CHECKPOINT_SPEED                 = 0x40A,
      DAL_RACER_AVG_CHECKPOINT_SPEED                   = 0x40B,
      DAL_RACER_DRAFT_TIME                             = 0x40C,
      DAL_RACER_AVG_LAP_TIME                           = 0x40D,
      DAL_RACER_SECTOR_WIN_PERCENT                     = 0x40E,
      DAL_RACER_SECTORS_WON                            = 0x40F,
      DAL_RACER_SECTOR_TOTAL_SPEED                     = 0x410,
      DAL_RACER_SECTOR_HIGHEST_SPEED                   = 0x411,
      DAL_RACER_SECTOR_TOTAL_TIME                      = 0x412,
      DAL_RACER_SECTOR_TOP_SPEED                       = 0x413,
      DAL_RACER_SECTOR_AVG_SPEED                       = 0x414,
      DAL_RACER_REACTION_TIME                          = 0x415,
      DAL_RACER_60_FEET_TIME                           = 0x416,
      DAL_RACER_ZERO_TO_100                            = 0x417,
      DAL_RACER_ZERO_TO_60                             = 0x418,
      DAL_RACER_FLT_CHECKPOINT_TIME_AHEAD_FOR_BOOTH    = 0x419,
      DAL_RACER_FLT_NOS_USED                           = 0x41A,
      DAL_RACER_FLT_SPEED_BREAKER_TIME_USED            = 0x41B,
      DAL_RACER_FLT_JUMP_TIME                          = 0x41C,
      DAL_RACER_FLT_ONLINE_XP_RACER_GAINED             = 0x41D,
      DAL_RACER_POSITION                               = 0x41E,
      DAL_RACER_LAPS_COMPLETED                         = 0x41F,
      DAL_RACER_CURR_LAP_NUM                           = 0x420,
      DAL_RACER_CURR_CAR_HANDLE                        = 0x421,
      DAL_RACER_CURR_CAR_CLASS                         = 0x422,
      DAL_RACER_IS_CRASHING                            = 0x423,
      DAL_RACER_IS_BUSTED                              = 0x424,
      DAL_RACER_IS_KOED                                = 0x425,
      DAL_RACER_IS_FINISHED                            = 0x426,
      DAL_RACER_INT_RACER_IS_TIMOUT_AHEAD              = 0x427,
      DAL_RACER_INT_RACER_IS_TIMOUT_BEHIND             = 0x428,
      DAL_RACER_INT_RACER_DNF                          = 0x429,
      DAL_RACER_IS_DISCONNECTED                        = 0x42A,
      DAL_RACER_IS_FALSE_START                         = 0x42B,
      DAL_RACER_IS_ENGINE_BLOWN                        = 0x42C,
      DAL_RACER_IS_CHALLENGE_COMPLETE                  = 0x42D,
      DAL_RACER_TRAFFIC_COLLISIONS                     = 0x42E,
      DAL_RACER_POSITION_ON_LAP                        = 0x42F,
      DAL_RACER_SPLIT_POSITION                         = 0x430,
      DAL_RACER_CURRDRIFT_SCORE                        = 0x431,
      DAL_RACER_CURRDRIFT_CHAINSCORE                   = 0x432,
      DAL_RACER_CURRDRIFT_MULTIPLIER                   = 0x433,
      DAL_RACER_INT_CURRDRIFT_NUM_WHEELS_IN_BONUS_ZONE = 0x434,
      DAL_RACER_LASTAWARDED_MULTIPLIER                 = 0x435,
      DAL_RACER_DRIFT_TOTAL_POINTS                     = 0x436,
      DAL_RACER_DRIFT_TOTAL_POINTS_100                 = 0x437,
      DAL_RACER_DRIFT_LAP_SCORE                        = 0x438,
      DAL_RACER_DRIFT_LAP_POSITION                     = 0x439,
      DAL_RACER_DRIFT_SPLIT_SCORE                      = 0x43A,
      DAL_RACER_DRIFT_SPLIT_POSITION                   = 0x43B,
      DAL_RACER_INT_RACER_SPEEDTRAP_POSITION_AT_TRAP   = 0x43C,
      DAL_RACER_INT_RACER_SPEEDTRAP_NUM_SPEEDTRAPS     = 0x43D,
      DAL_RACER_DRIFT_HIGHEST                          = 0x43E,
      DAL_RACER_DRIFT_LONGEST_DISTANCE                 = 0x43F,
      DAL_RACER_DRIFT_LONGEST_TIME                     = 0x440,
      DAL_RACER_DRIFT_AVERAGE_SCORE                    = 0x441,
      DAL_RACER_DRIFT_BEST_LAP_SCORE                   = 0x442,
      DAL_RACER_DRIFT_LAST_LAP_SCORE                   = 0x443,
      DAL_RACER_DRIFT_AVERAGE_LENGHT_DISTANCE          = 0x444,
      DAL_RACER_DRIFT_AVERAGE_LENGHT_TIME              = 0x445,
      DAL_RACER_INT_TURN_INDICATOR_LEVEL               = 0x446,
      DAL_RACER_DRAG_WHEELIE_DISTANCE                  = 0x447,
      DAL_RACER_RACE_RESULT                            = 0x448,
      DAL_RACER_INT_VOIP_STATUS_SCRIPT_HASH            = 0x449,
      DAL_RACER_INT_CANYON_IS_PLAYER_LEADER            = 0x44A,
      DAL_RACER_INT_CANYON_CURR_ZONE                   = 0x44B,
      DAL_RACER_INT_CANYON_PERFECT_DUEL                = 0x44C,
      DAL_RACER_INT_CANYON_COLLIDE_RACER               = 0x44D,
      DAL_RACER_INT_CANYON_COLLIDE_WORLD               = 0x44E,
      DAL_RACER_INT_DRIFT_WAS_TOO_SLOW                 = 0x44F,
      DAL_RACER_INT_RACER_BREAKERS_ACTIVATED           = 0x450,
      DAL_RACER_PLAYER_WAS_SHOWBOATING                 = 0x451,
      DAL_RACER_PLAYER_GAVE_HEADSTART                  = 0x452,
      DAL_RACER_INT_IS_CAMERA_ATTACHED                 = 0x453,
      DAL_RACER_SECTOR_TOTAL_POINTS                    = 0x454,
      DAL_RACER_SECTORS_CLAIMED                        = 0x455,
      DAL_RACER_SECTOR_DOMINATED_POINTS                = 0x456,
      DAL_RACER_SECTOR_BEST_SECTOR_POINTS              = 0x457,
      DAL_RACER_TOTAL_SECTOR_POINTS                    = 0x458,
      DAL_RACER_SECTOR_CHKPOINTS_WON                   = 0x459,
      DAL_RACER_CHECKPOINTS_WON                        = 0x45A,
      DAL_RACER_NAME                                   = 0x45B,
      DAL_RACER_CURR_CAR_NAME                          = 0x45C,
      DAL_RACER_CURR_BLUEPRINT_NAME                    = 0x45D,
      DAL_RACER_STR_CANYON_SPLIT_SCORE_RATING          = 0x45E,
      DAL_RACER_DAMAGE_STATE                           = 0x45F,
      DAL_VEHICLE_SPEED_LOCALIZED                      = 0x7D0,
      DAL_VEHICLE_SPEED_MPS                            = 0x7D1,
      DAL_VEHICLE_RPM                                  = 0x7D2,
      DAL_VEHICLE_REDLINE                              = 0x7D3,
      DAL_VEHICLE_MAXRPM                               = 0x7D4,
      DAL_VEHICLE_HEAT                                 = 0x7D5,
      DAL_VEHICLE_SPEED_BREAKER                        = 0x7D6,
      DAL_VEHICLE_ENGINE_TEMP                          = 0x7D7,
      DAL_VEHICLE_FLT_WHEEL_ANGLE                      = 0x7D8,
      DAL_VEHICLE_FLT_SPEED_DRIFT_CAP                  = 0x7D9,
      DAL_VEHICLE_FLT_SPEED_PERCENT_TO_DRIFT_CAP       = 0x7DA,
      DAL_VEHICLE_FLT_CURRENT_BOOST_PSI                = 0x7DB,
      DAL_VEHICLE_FLT_MAX_BOOST_PSI                    = 0x7DC,
      DAL_VEHICLE_INT_HAS_NOS                          = 0x7DD,
      DAL_VEHICLE_INT_HAS_BOOST                        = 0x7DE,
      DAL_VEHICLE_GEAR                                 = 0x7DF,
      DAL_VEHICLE_SHIFTPOTENTIAL                       = 0x7E0,
      DAL_VEHICLE_LASTSHIFTSTATUS                      = 0x7E1,
      DAL_VEHICLE_SHIFTING                             = 0x7E2,
      DAL_VEHICLE_STAGING                              = 0x7E3,
      DAL_VEHICLE_IN_PERFECTLAUNCH_RANGE               = 0x7E4,
      DAL_VEHICLE_IS_FACING_WRONG_WAY                  = 0x7E5,
      DAL_VEHICLE_IS_PLAYER_CONTROLLING                = 0x7E6,
      DAL_VEHICLE_IS_DRIVING_CAMERA                    = 0x7E7,
      DAL_VEHICLE_IS_HUD_VISIBLE                       = 0x7E8,
      DAL_VEHICLE_DAMAGE_LEVEL                         = 0x7E9,
      DAL_VEHICLE_ENGINE_BLOWN                         = 0x7EA,
      DAL_VEHICLE_DESTROYED                            = 0x7EB,
      DAL_VEHICLE_CAR_ID_HASH                          = 0x7EC,
      DAL_VEHICLE_STOCK_CAR_ID_HASH                    = 0x7ED,
      DAL_VEHICLE_INT_IS_NOS_ENABLED                   = 0x7EE,
      DAL_VEHICLE_INT_IS_SPEED_BREAKER_ENABLED         = 0x7EF,
      DAL_VEHICLE_INT_IS_REVOLUTION_WHEEL_VISIBLE      = 0x7F0,
      DAL_VEHICLE_INT_IS_REVOLUTION_WHEEL_IN_RANGE     = 0x7F1,
      DAL_VEHICLE_INT_IS_MANUAL_TRANSMISSION           = 0x7F2,
      DAL_VEHICLE_INT_IS_DRAG_STAGING                  = 0x7F3,
      DAL_VEHICLE_INT_IS_SHARED_BLUEPRINT              = 0x7F4,
      DAL_VEHICLE_STR_BLUEPRINT_GUID                   = 0x7F5,
      DAL_VEHICLE_STR_CURRENT_PLAYER_CAR_NAME          = 0x7F6,
      DAL_EVENT_FLT_LENGTH_LOCALIZED                   = 0xBB8,
      DAL_EVENT_FLT_LENGTH_METERS                      = 0xBB9,
      DAL_EVENT_FLT_CASH                               = 0xBBA,
      DAL_EVENT_FLT_HEAT                               = 0xBBB,
      DAL_EVENT_FLT_TIME_LIMIT                         = 0xBBC,
      DAL_EVENT_FLT_LOADED_SHADOW_SCORE                = 0xBBD,
      DAL_EVENT_INT_NUM_LAPS                           = 0xBBE,
      DAL_EVENT_INT_NUM_HEATS                          = 0xBBF,
      DAL_EVENT_INT_NUM_SPLITS                         = 0xBC0,
      DAL_EVENT_INT_NUM_RACERS                         = 0xBC1,
      DAL_EVENT_INT_NUM_RACERS_IN_SAME_CLASS           = 0xBC2,
      DAL_EVENT_INT_NUM_RACERS_FINISHED                = 0xBC3,
      DAL_EVENT_INT_CURRENT_HEAT                       = 0xBC4,
      DAL_EVENT_INT_TYPE                               = 0xBC5,
      DAL_EVENT_INT_VARIANT                            = 0xBC6,
      DAL_EVENT_INT_IS_CAREER                          = 0xBC7,
      DAL_EVENT_INT_IS_QUICKRACE                       = 0xBC8,
      DAL_EVENT_INT_IS_QUICKRACE_LOCKED                = 0xBC9,
      DAL_EVENT_INT_IS_CHALLENGE                       = 0xBCA,
      DAL_EVENT_INT_IS_TIME_LIMITED                    = 0xBCB,
      DAL_EVENT_INT_IS_LOADED_TRACK                    = 0xBCC,
      DAL_EVENT_INT_IS_LOOPING                         = 0xBCD,
      DAL_EVENT_INT_IS_PURSUIT                         = 0xBCE,
      DAL_EVENT_INT_HASH                               = 0xBCF,
      DAL_EVENT_INT_HASH_FROM_KEY                      = 0xBD0,
      DAL_EVENT_INT_IS_RANKED                          = 0xBD1,
      DAL_EVENT_INT_REP_REWARD                         = 0xBD2,
      DAL_EVENT_INT_IS_DDAY                            = 0xBD3,
      DAL_EVENT_INT_IS_REWARD_CARD_RACE                = 0xBD4,
      DAL_EVENT_INT_IS_CAR_CLASS_SELECT_RACE           = 0xBD5,
      DAL_EVENT_INT_IS_NEWLY_COMPLETED                 = 0xBD6,
      DAL_EVENT_INT_LOCALIZATION_TAG                   = 0xBD7,
      DAL_EVENT_INT_LOCALIZATION_TAG_FROM_KEY          = 0xBD8,
      DAL_EVENT_INT_HAS_CASH                           = 0xBD9,
      DAL_EVENT_INT_HAS_DAMAGE                         = 0xBDA,
      DAL_EVENT_INT_IS_SPLITSCREEN                     = 0xBDB,
      DAL_EVENT_INT_IS_ONLINE                          = 0xBDC,
      DAL_EVENT_INT_IS_MULTIPLAYER                     = 0xBDD,
      DAL_EVENT_INT_ALLOWS_VEHICLE_COLLISIONS          = 0xBDE,
      DAL_EVENT_INT_ICON                               = 0xBDF,
      DAL_EVENT_INT_ALLOWS_NOS                         = 0xBE0,
      DAL_EVENT_INT_ALLOWS_SPEED_BREAKER               = 0xBE1,
      DAL_EVENT_INT_ALLOWS_RESET                       = 0xBE2,
      DAL_EVENT_INT_IS_COPS_IN_EVENT                   = 0xBE3,
      DAL_EVENT_INT_IS_FREE_ROAM                       = 0xBE4,
      DAL_EVENT_INT_WAS_FULL_SHADOW_RECORDED           = 0xBE5,
      DAL_EVENT_INT_UNLOCKABLE_REWARDS_COUNT           = 0xBE6,
      DAL_EVENT_INT_NAME_HASH                          = 0xBE7,
      DAL_EVENT_INT_NAME_HASH_MC                       = 0xBE8,
      DAL_EVENT_INT_NAME_HASH_SHORT                    = 0xBE9,
      DAL_EVENT_INT_IS_PRACTICE_RACE                   = 0xBEA,
      DAL_EVENT_INT_TRACKINFO_ICON                     = 0xBEB,
      DAL_EVENT_INT_TRACK_ICON                         = 0xBEC,
      DAL_EVENT_INT_TRACKINFO_LAPS                     = 0xBED,
      DAL_EVENT_INT_TRACKINFO_SCORE                    = 0xBEE,
      DAL_EVENT_INT_TRACKINFO_RECORD                   = 0xBEF,
      DAL_EVENT_INT_TRACKINFO_PLAYER_RECORD            = 0xBF0,
      DAL_EVENT_INT_MODE                               = 0xBF1,
      DAL_EVENT_INT_MODE_ICON                          = 0xBF2,
      DAL_EVENT_INT_MODE_FROM_EVENT_TYPE               = 0xBF3,
      DAL_EVENT_INT_TYPE_NAME_LANG_HASH                = 0xBF4,
      DAL_EVENT_STR_ACTIVECREW_NAME                    = 0xBF5,
      DAL_EVENT_STR_ID                                 = 0xBF6,
      DAL_EVENT_STR_ALL_UNLOCKABLE_REWARD              = 0xBF7,
      DAL_EVENT_STR_LOADED_SHADOW_CAR_NAME             = 0xBF8,
      DAL_EVENT_STR_NAME                               = 0xBF9,
      DAL_EVENT_STR_MINIMAP_TEXTURE_PREFIX             = 0xBFA,
      DAL_EVENT_STR_TRACKINFO_ROUTE                    = 0xBFB,
      DAL_EVENT_STR_TRACK_MINIMAP                      = 0xBFC,
      DAL_OPTIONS_HIGHLIGHT_CAM                        = 0x1388,
      DAL_OPTIONS_FE_SCALE                             = 0x1389,
      DAL_OPTIONS_SCREEN_OFFSET_X                      = 0x138A,
      DAL_OPTIONS_SCREEN_OFFSET_Y                      = 0x138B,
      DAL_OPTIONS_TIME_OF_DAY                          = 0x138C,
      DAL_OPTIONS_BRIGHTNESS                           = 0x138D,
      DAL_OPTIONS_FF_SCALE                             = 0x138E,
      DAL_OPTIONS_MASTER_VOL                           = 0x138F,
      DAL_OPTIONS_SPEECH_VOL                           = 0x1390,
      DAL_OPTIONS_MASTERED_SPEECH_VOL                  = 0x1391,
      DAL_OPTIONS_FE_MUSIC_VOL                         = 0x1392,
      DAL_OPTIONS_MASTERED_FE_MUSIC_VOL                = 0x1393,
      DAL_OPTIONS_IG_MUSIC_VOL                         = 0x1394,
      DAL_OPTIONS_MASTERED_IG_MUSIC_VOL                = 0x1395,
      DAL_OPTIONS_SOUND_EFFECTS_VOL                    = 0x1396,
      DAL_OPTIONS_MASTERED_SOUND_EFFECTS_VOL           = 0x1397,
      DAL_OPTIONS_ENGINE_VOL                           = 0x1398,
      DAL_OPTIONS_MASTERED_ENGINE_VOL                  = 0x1399,
      DAL_OPTIONS_CAR_VOL                              = 0x139A,
      DAL_OPTIONS_MASTERED_CAR_VOL                     = 0x139B,
      DAL_OPTIONS_AMBIENT_VOL                          = 0x139C,
      DAL_OPTIONS_MASTERED_AMBIENT_VOL                 = 0x139D,
      DAL_OPTIONS_SPEED_VOL                            = 0x139E,
      DAL_OPTIONS_MASTERED_SPEED_VOL                   = 0x139F,
      DAL_OPTIONS_GAUGES_ON                            = 0x13A0,
      DAL_OPTIONS_POSITION_ON                          = 0x13A1,
      DAL_OPTIONS_LAP_INFO_ON                          = 0x13A2,
      DAL_OPTIONS_RACE_INFO_ON                         = 0x13A3,
      DAL_OPTIONS_SCORE_ON                             = 0x13A4,
      DAL_OPTIONS_RUMBLE_ON                            = 0x13A5,
      DAL_OPTIONS_LEADERBOARD_ON                       = 0x13A6,
      DAL_OPTIONS_SECTORDISPLAY_ON                     = 0x13A7,
      DAL_OPTIONS_CREW_INFO_ON                         = 0x13A8,
      DAL_OPTIONS_TRANSMISSION_PROMPT_ON               = 0x13A9,
      DAL_OPTIONS_DRIVE_WITH_ANALOG                    = 0x13AA,
      DAL_OPTIONS_SENSITIVITY_SETTING                  = 0x13AB,
      DAL_OPTIONS_CONTROLLER_CONFIG                    = 0x13AC,
      DAL_OPTIONS_CAMERA                               = 0x13AD,
      DAL_OPTIONS_SPLIT_TIME_TYPE                      = 0x13AE,
      DAL_OPTIONS_TRANSMISSION                         = 0x13AF,
      DAL_OPTIONS_HANDLING                             = 0x13B0,
      DAL_OPTIONS_ASSIST_LEVEL                         = 0x13B1,
      DAL_OPTIONS_INGAME_LEADERBOARD                   = 0x13B2,
      DAL_OPTIONS_TEXTPOPUP                            = 0x13B3,
      DAL_OPTIONS_BESTLINE                             = 0x13B4,
      DAL_OPTIONS_ARROWINDICATORS                      = 0x13B5,
      DAL_OPTIONS_AUTOSAVE_ON                          = 0x13B6,
      DAL_OPTIONS_REARVIEW_ON                          = 0x13B7,
      DAL_OPTIONS_PIP_ON                               = 0x13B8,
      DAL_OPTIONS_DAMAGE_ON                            = 0x13B9,
      DAL_OPTIONS_NAMES_ABOVE_ON                       = 0x13BA,
      DAL_OPTIONS_SPEEDO_UNITS                         = 0x13BB,
      DAL_OPTIONS_CURR_MINI_MAP_MODE                   = 0x13BC,
      DAL_OPTIONS_RACING_MINI_MAP_MODE                 = 0x13BD,
      DAL_OPTIONS_EXPLORING_MINI_MAP_MODE              = 0x13BE,
      DAL_OPTIONS_MAP_ITEMS                            = 0x13BF,
      DAL_OPTIONS_IS_MAP_ITEM_ENABLED                  = 0x13C0,
      DAL_OPTIONS_LAST_MAP_ZOOM                        = 0x13C1,
      DAL_OPTIONS_LAST_PURSUIT_MAP_ZOOM                = 0x13C2,
      DAL_OPTIONS_LAST_MAP_VIEW                        = 0x13C3,
      DAL_OPTIONS_MAP_HELP_SHOWN                       = 0x13C4,
      DAL_OPTIONS_MAP_RANDENC_HELP_SHOWN               = 0x13C5,
      DAL_OPTIONS_JUMP_CAM_ON                          = 0x13C6,
      DAL_OPTIONS_CRASH_PLAYBACK_ON                    = 0x13C7,
      DAL_OPTIONS_WIDESCREEN                           = 0x13C8,
      DAL_OPTIONS_AUDIO_MODE                           = 0x13C9,
      DAL_OPTIONS_INTERACTIVE_MUSIC_MODE               = 0x13CA,
      DAL_OPTIONS_EA_TRAX_MODE                         = 0x13CB,
      DAL_OPTIONS_EA_TRAX_ON                           = 0x13CC,
      DAL_OPTIONS_EA_TRAX_CLASS_FILTER                 = 0x13CD,
      DAL_OPTIONS_PLAY_STATE                           = 0x13CE,
      DAL_OPTIONS_EA_TRAX_PREVIEW                      = 0x13CF,
      DAL_OPTIONS_EA_TRAX_SONG_POSITION                = 0x13D0,
      DAL_OPTIONS_EA_TRAX_SONG_PLAYABLILITY            = 0x13D1,
      DAL_EATRAX_CURRENT_SONG                          = 0x13D2,
      DAL_OPTIONS_PC_PAD_INDEX                         = 0x13D3,
      DAL_OPTIONS_PC_DEVICE_TYPE                       = 0x13D4,
      DAL_PC_DISPLAY_APPLY_SETTINGS                    = 0x13D5,
      DAL_PC_DISPLAY_PERFORMANCE_LEVEL                 = 0x13D6,
      DAL_PC_DISPLAY_SCREEN_RESOLUTION                 = 0x13D7,
      DAL_PC_DISPLAY_AA                                = 0x13D8,
      DAL_PC_DISPLAY_TEXTURE_FILTERING                 = 0x13D9,
      DAL_PC_DISPLAY_SHADER_MODEL                      = 0x13DA,
      DAL_PC_DISPLAY_V_SYNC                            = 0x13DB,
      DAL_PC_DISPLAY_WORLD_LOD                         = 0x13DC,
      DAL_PC_DISPLAY_ROAD_REFLECTION_LOD               = 0x13DD,
      DAL_PC_DISPLAY_CAR_LOD                           = 0x13DE,
      DAL_PC_DISPLAY_CAR_REFELCTION_LOD                = 0x13DF,
      DAL_PC_DISPLAY_CAR_REFLECTION_UPDATE_RATE        = 0x13E0,
      DAL_PC_DISPLAY_RAIN_ENABLED                      = 0x13E1,
      DAL_PC_DISPLAY_OVER_BRIGHT_ENABLED               = 0x13E2,
      DAL_PC_DISPLAY_VISUAL_TREATEMENT_ENABLED         = 0x13E3,
      DAL_PC_DISPLAY_PARTICLE_SYSTEM_ENABLED           = 0x13E4,
      DAL_PC_DISPLAY_MOTION_BLUR_ENABLED               = 0x13E5,
      DAL_PC_DISPLAY_BRIGHTNESS                        = 0x13E6,
      DAL_PC_DISPLAY_WORLD_LIGHTING                    = 0x13E7,
      DAL_PC_DISPLAY_WORLD_SHADOWS                     = 0x13E8,
      DAL_PC_DISPLAY_WORLD_FX                          = 0x13E9,
      DAL_PC_DISPLAY_CAR_EFFECTS                       = 0x13EA,
      DAL_PC_DISPLAY_CAR_DAMAGE                        = 0x13EB,
      DAL_PC_DISPLAY_SMOKE                             = 0x13EC,
      DAL_GRIP_TRANSMISSION                            = 0x13ED,
      DAL_GRIP_CAR_CAMERA                              = 0x13EE,
      DAL_GRIP_BRAKES                                  = 0x13EF,
      DAL_GRIP_TRACTION_CONTROL                        = 0x13F0,
      DAL_GRIP_ELECTRONIC_CONTROL                      = 0x13F1,
      DAL_DRIFT_TRANSMISSION                           = 0x13F2,
      DAL_DRIFT_CAR_CAMERA                             = 0x13F3,
      DAL_DRIFT_TRACTION_CONTROL                       = 0x13F4,
      DAL_DRIFT_ELECTRONIC_CONTROL                     = 0x13F5,
      DAL_DRAG_TRANSMISSION                            = 0x13F6,
      DAL_DRAG_CAR_CAMERA                              = 0x13F7,
      DAL_DRAG_CLUTCH                                  = 0x13F8,
      DAL_DRAG_TRACTION_CONTROL                        = 0x13F9,
      DAL_DRAG_ELECTRONIC_CONTROL                      = 0x13FA,
      DAL_SPEED_TRANSMISSION                           = 0x13FB,
      DAL_SPEED_CAR_CAMERA                             = 0x13FC,
      DAL_SPEED_TRACTION_CONTROL                       = 0x13FD,
      DAL_SPEED_ELECTRONIC_CONTROL                     = 0x13FE,
      DAL_MUTE_PLAYER_1                                = 0x13FF,
      DAL_MUTE_PLAYER_2                                = 0x1400,
      DAL_MUTE_PLAYER_3                                = 0x1401,
      DAL_MUTE_PLAYER_4                                = 0x1402,
      DAL_MUTE_PLAYER_5                                = 0x1403,
      DAL_MUTE_PLAYER_6                                = 0x1404,
      DAL_MUTE_PLAYER_7                                = 0x1405,
      DAL_MUTE_PLAYER_8                                = 0x1406,
      DAL_MUTE_PLAYER_9                                = 0x1407,
      DAL_MUTE_PLAYER_10                               = 0x1408,
      DAL_MUTE_PLAYER_11                               = 0x1409,
      DAL_MUTE_PLAYER_12                               = 0x140A,
      DAL_OPTIONS_MUSIC_ON                             = 0x140B,
      DAL_OPTIONS_FE_MUSIC_TYPE                        = 0x140C,
      DAL_OPTIONS_REPLAY                               = 0x140D,
      DAL_OPTIONS_UNITS                                = 0x140E,
      DAL_OPTIONS_MUTE_PLAYER                          = 0x140F,
      DAL_CAREER_ADAPTIVE_DIFFICULTY                   = 0x1770,
      DAL_CAREER_IS_CURRENTLY_ACTIVE                   = 0x1771,
      DAL_CAREER_CAR                                   = 0x1772,
      DAL_CAREER_NUM_CARS                              = 0x1773,
      DAL_CAREER_BIN                                   = 0x1774,
      DAL_CAREER_CASH                                  = 0x1775,
      DAL_CAREER_REP                                   = 0x1776,
      DAL_CAREER_STARTED                               = 0x1777,
      DAL_CAREER_RACEWEEKEND_CAN_SHOW                  = 0x1778,
      DAL_CAREER_GAME_OVER                             = 0x1779,
      DAL_CAREER_COMPLETED                             = 0x177A,
      DAL_CAREER_COMPLETE_PERCENT                      = 0x177B,
      DAL_CAREER_GAME_COMPLETE_PERCENT                 = 0x177C,
      DAL_CAREER_TUTORIAL                              = 0x177D,
      DAL_CAREER_INT_CONTROLLER_CONFIG_LOADS           = 0x177E,
      DAL_CAREER_INT_FE_LOCATION                       = 0x177F,
      DAL_CAREER_IS_CAR_UNLOCKED                       = 0x1780,
      DAL_CAREER_INT_NUM_REPAIR_MARKERS                = 0x1781,
      DAL_CAREER_INT_NUM_TOTAL_REPAIR_MARKERS          = 0x1782,
      DAL_CAREER_INT_TIP_HAS_BEEN_SHOWN                = 0x1783,
      DAL_CAREER_DAMAGE_CURRENTCAR                     = 0x1784,
      DAL_CAREER_DAMAGE_CARHANDLE                      = 0x1785,
      DAL_CAREER_DAMAGE_COST_CARHANDLE                 = 0x1786,
      DAL_CAREER_FLOAT_DAMAGE_CURRENTCAR               = 0x1787,
      DAL_CAREER_FLOAT_DAMAGE_CARHANDLE                = 0x1788,
      DAL_CAREER_INT_START_CAR                         = 0x1789,
      DAL_CAREER_INT_IS_MOVIE_TO_PLAY                  = 0x178A,
      DAL_CAREER_INT_IS_CE_HUBS_AVAILABLE              = 0x178B,
      DAL_CAREER_INT_CROWN_ANIMATION_TO_PLAY           = 0x178C,
      DAL_CAREER_INT_ALL_KINGS_DEFEATED                = 0x178D,
      DAL_CAREER_INT_LAST_SHOWDOWN_DEFEATED            = 0x178E,
      DAL_CAREER_INT_LAST_SPEED_DEFEATED               = 0x178F,
      DAL_CAREER_INT_LAST_DRIFT_DEFEATED               = 0x1790,
      DAL_CAREER_INT_LAST_DRAG_DEFEATED                = 0x1791,
      DAL_CAREER_INT_LAST_GRIP_DEFEATED                = 0x1792,
      DAL_CAREER_INT_SET_HUB_KING_INTRO                = 0x1793,
      DAL_CAREER_INT_SET_HUB_KING_INTRO_SPEED          = 0x1794,
      DAL_CAREER_INT_SET_HUB_KING_INTRO_DRIFT          = 0x1795,
      DAL_CAREER_INT_SET_HUB_KING_INTRO_DRAG           = 0x1796,
      DAL_CAREER_INT_SET_HUB_KING_INTRO_GRIP           = 0x1797,
      DAL_CAREER_INT_SET_HUB_KING_PROGRESS             = 0x1798,
      DAL_CAREER_INT_CAN_RESUME                        = 0x1799,
      DAL_CAREER_INT_HAS_STARTUPHUB                    = 0x179A,
      DAL_CAREER_INT_CUSTOMIZATION_MOVIE_SEEN          = 0x179B,
      DAL_CAREER_INT_MAP_SEEN                          = 0x179C,
      DAL_CAREER_INT_RACEDAY_MAP_SEEN                  = 0x179D,
      DAL_CAREER_INT_RACEDAY_RANKED_WARNING_SEEN       = 0x179E,
      DAL_CAREER_INT_RACEDAY_UNRANKED_WARNING_SEEN     = 0x179F,
      DAL_CAREER_INT_TUNER_LEADERBOARD_SEEN            = 0x17A0,
      DAL_CAREER_MINIMAP_FILENAME                      = 0x17A1,
      DAL_CAREER_PROFILE_NAME                          = 0x17A2,
      DAL_CAREER_CAR_NAME                              = 0x17A3,
      DAL_CAREER_NAME_OF_MOVIE_TO_PLAY                 = 0x17A4,
      DAL_PAUSETATE_IS_PAUSED                          = 0x1F40,
      DAL_PAUSETATE_IS_PHOTOMODE_PAUSED                = 0x1F41,
      DAL_PAUSETATE_REQUEST_COUNT                      = 0x1F42,
      DAL_ONLINE_AUTO_LOGIN_ENABLED                    = 0x2EE0,
      DAL_ONLINE_ENABLE_GAME_INVITES_FRIENDS_ONLY      = 0x2EE1,
      DAL_ONLINE_ENABLE_CREW_INVITES_FRIENDS_ONLY      = 0x2EE2,
      DAL_ONLINE_APPEAR_OFFLINE                        = 0x2EE3,
      DAL_ONLINE_IS_FIRST_GAME_BOOT                    = 0x2EE4,
      DAL_ONLINE_FESL_CURRENT_USER_ID                  = 0x2EE5,
      DAL_ONLINE_GAME_TYPE                             = 0x2EE6,
      DAL_ONLINE_GAME_RANKED                           = 0x2EE7,
      DAL_ONLINE_HUB_TIME_LEFT                         = 0x2EE8,
      DAL_ONLINE_HUB_SHOW_TIMER                        = 0x2EE9,
      DAL_ONLINE_HUB_INACTIVE_TIMER                    = 0x2EEA,
      DAL_ONLINE_HUB_CAN_LEAVE                         = 0x2EEB,
      DAL_ONLINE_HUB_CAN_CHANGE_CAR                    = 0x2EEC,
      DAL_ONLINE_HUB_CAN_CHANGE_EVENT_SETTINGS         = 0x2EED,
      DAL_ONLINE_NUM_PLAYERS_INGAME                    = 0x2EEE,
      DAL_ONLINE_LEADER_NAME                           = 0x2EEF,
      DAL_ONLINE_IS_LOGGED_IN_USER_LEADER              = 0x2EF0,
      DAL_ONLINE_USERNAME                              = 0x2EF1,
      DAL_ONLINE_PASSWORD                              = 0x2EF2,
      DAL_ONLINE_LOGGEDIN_USERNAME                     = 0x2EF3,
      DAL_ONLINE_COUNTRY_CODE                          = 0x2EF4,
      DAL_ONLINE_CD_KEY                                = 0x2EF5,
      DAL_ONLINE_CAR_SELECT_ACCEPTED                   = 0x2EF6,
      DAL_ONLINE_IS_GAME_CREATED                       = 0x2EF7,
      DAL_HUB_INT_CURRENT_HUB                          = 0x36B0,
      DAL_HUB_INT_CURRENT_HUB_FROM_ATTRIB              = 0x36B1,
      DAL_HUB_INT_HUB_NAMEHASH_FROM_ATTRIB             = 0x36B2,
      DAL_HUB_INT_NUM_EVENTS                           = 0x36B3,
      DAL_HUB_INT_SCORE                                = 0x36B4,
      DAL_HUB_INT_WIN_CONDITION                        = 0x36B5,
      DAL_HUB_INT_DOMINATE_CONDITION                   = 0x36B6,
      DAL_HUB_INT_HASH                                 = 0x36B7,
      DAL_HUB_INT_KEY                                  = 0x36B8,
      DAL_HUB_INT_WON                                  = 0x36B9,
      DAL_HUB_INT_DOMINATED                            = 0x36BA,
      DAL_HUB_INT_WON_BYSCORE                          = 0x36BB,
      DAL_HUB_INT_DOMINATED_BYSCORE                    = 0x36BC,
      DAL_HUB_INT_CASHREWARD_DOMINATEDHUB              = 0x36BD,
      DAL_HUB_INT_CASHREWARD_WONHUB                    = 0x36BE,
      DAL_HUB_INT_ORG_ID                               = 0x36BF,
      DAL_HUB_INT_HUB_MAXCARTIER                       = 0x36C0,
      DAL_HUB_INT_IS_KING_HUB                          = 0x36C1,
      DAL_HUB_INT_IS_CHALLENGE                         = 0x36C2,
      DAL_HUB_INT_IS_CUSTOM_CHALLENGE                  = 0x36C3,
      DAL_HUB_INT_IS_SHOWDOWN                          = 0x36C4,
      DAL_HUB_INT_IS_CUSTOM                            = 0x36C5,
      DAL_HUB_INT_IS_CAREER                            = 0x36C6,
      DAL_HUB_INT_IS_FREESTYLE                         = 0x36C7,
      DAL_HUB_INT_IS_SPLIT_SCREEN                      = 0x36C8,
      DAL_HUB_INT_IS_FIRST_HUB_FOR_CAR                 = 0x36C9,
      DAL_HUB_INT_NUM_PLAYERS                          = 0x36CA,
      DAL_HUB_INT_HUB_KEY                              = 0x36CB,
      DAL_HUB_INT_NEWLY_UNLOCKED_HUBS                  = 0x36CC,
      DAL_HUB_INT_NUM_REPAIRMARKERS_FREESTYLE          = 0x36CD,
      DAL_HUB_INT_RECORD_JUST_BROKEN                   = 0x36CE,
      DAL_HUB_STR_ID                                   = 0x36CF,
      DAL_HUB_STR_CURRENT_HUB_ID                       = 0x36D0,
      DAL_HUB_STR_GUID                                 = 0x36D1,
      DAL_HUB_STR_RECORD_HOLDER                        = 0x36D2,
      DAL_RACEDAY_INT_LOCATION                         = 0x4268,
      DAL_RACEDAY_INT_DIFFICULTY                       = 0x4269,
      DAL_RACEDAY_INT_REPAIR_MARKERS                   = 0x426A,
      DAL_RACEDAY_INT_CAR_FOR_MODE                     = 0x426B,
      DAL_RACEDAY_INT_BACKUP_CAR_MODE                  = 0x426C,
      DAL_RACEDAY_INT_IS_CHALLENGE_CUSTOM_HUB          = 0x426D,
      DAL_RACEDAY_INT_PLAY_MODE                        = 0x426E,
      DAL_RACEDAY_INT_NUM_EVENTS                       = 0x426F,
      DAL_RACEDAY_INT_NUM_SAVES                        = 0x4270,
      DAL_RACEDAY_INT_TYPE                             = 0x4271,
      DAL_RACEDAY_INT_KEY                              = 0x4272,
      DAL_RACEDAY_INT_LAPS                             = 0x4273,
      DAL_RACEDAY_INT_HEATS                            = 0x4274,
      DAL_RACEDAY_INT_DATA                             = 0x4275,
      DAL_RACEDAY_INT_SETTINGS_RANKED                  = 0x4276,
      DAL_RACEDAY_INT_SETTINGS_COLLISIONS              = 0x4277,
      DAL_RACEDAY_INT_SETTINGS_AI_OPPONENTS            = 0x4278,
      DAL_RACEDAY_INT_SETTINGS_MIN_PLAYERS             = 0x4279,
      DAL_RACEDAY_INT_SETTINGS_PRIVATE_RACE            = 0x427A,
      DAL_RACEDAY_STR_SAVE_NAME                        = 0x427B
    };

    Type mInterfaceIndex;

    virtual ~DALInterface();
    virtual bool IsInterfaceValid(Type type, std::int32_t unk1 = -1, std::int32_t unk2 = -1, std::int32_t unk3 = -1);
    virtual bool GetFloat(Code code, float* out, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                          std::int32_t unk3 = -1);
    virtual bool SetFloat(Code code, const float value, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                          std::int32_t unk3 = -1);
    virtual bool IncrementFloat(Code code, const float value, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                                std::int32_t unk3 = -1);
    virtual bool DecrementFloat(Code code, const float value, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                                std::int32_t unk3 = -1);
    virtual bool GetInt(Code code, std::int32_t* out, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                        std::int32_t unk3 = -1);
    virtual bool SetInt(Code code, const std::int32_t value, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                        std::int32_t unk3 = -1);
    virtual bool IncrementInt(Code code, const std::int32_t value, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                              std::int32_t unk3 = -1);
    virtual bool DecrementInt(Code code, const std::int32_t value, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                              std::int32_t unk3 = -1);
    virtual bool GetString(Code code, char* buf, const std::int32_t bufSize, std::int32_t unk1 = -1,
                           std::int32_t unk2 = -1, std::int32_t unk3 = -1);
    virtual bool SetString(Code code, const char* value, const std::int32_t len, std::int32_t unk1 = -1,
                           std::int32_t unk2 = -1, std::int32_t unk3 = -1);
    virtual bool GetDefaultInt(Code code, int* out, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                               std::int32_t unk3 = -1);
    virtual bool GetDefaultFloat(Code code, float* out, std::int32_t unk1 = -1, std::int32_t unk2 = -1,
                                 std::int32_t unk3 = -1);
    virtual void HandleCommand(DLCommandObject* command);
    virtual void CancelCommand(DLCommandObject* command);
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALINTERFACE_H
