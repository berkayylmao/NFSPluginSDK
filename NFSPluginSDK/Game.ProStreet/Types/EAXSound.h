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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_EAXSOUND_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_EAXSOUND_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet {
  struct EAXSound {
    enum class eMenuSoundTriggers : std::int32_t {
      NONE                             = -1,
      COMMON_UP                        = 0,
      COMMON_DOWN                      = 1,
      COMMON_SELECT                    = 2,
      COMMON_BACK                      = 3,
      COMMON_LEFT_AND_RIGHT            = 4,
      COMMON_WRONG                     = 5,
      COMMON_TRIGGER_LEFT              = 6,
      COMMON_TRIGGER_RIGHT             = 7,
      COMMON_DLGBOX_APPEAR             = 8,
      COMMON_DLGBOX_DISAPPEAR          = 9,
      COMMON_DLGBOX_DOWN               = 10,
      COMMON_DLGBOX_LEFT               = 11,
      COMMON_DLGBOX_RIGHT              = 12,
      COMMON_DLGBOX_UP                 = 13,
      ENTER_TRIGGER                    = 24,
      COMMON_ExpandingTree_Left_BASIC  = 31,
      COMMON_ExpandingTree_Left_P0     = 32,
      COMMON_ExpandingTree_Left_P1     = 33,
      COMMON_ExpandingTree_Left_P2     = 34,
      COMMON_ExpandingTree_Left_P3     = 35,
      COMMON_ExpandingTree_Left_P4     = 36,
      COMMON_ExpandingTree_Left_P5     = 37,
      COMMON_ExpandingTree_Left_P6     = 38,
      COMMON_ExpandingTree_Left_P7     = 39,
      COMMON_ExpandingTree_Left_P8     = 40,
      COMMON_ExpandingTree_Left_P9     = 41,
      COMMON_ExpandingTree_Right_BASIC = 42,
      COMMON_ExpandingTree_Right_P0    = 43,
      COMMON_ExpandingTree_Right_P1    = 44,
      COMMON_ExpandingTree_Right_P2    = 45,
      COMMON_ExpandingTree_Right_P3    = 46,
      COMMON_ExpandingTree_Right_P4    = 47,
      COMMON_ExpandingTree_Right_P5    = 48,
      COMMON_ExpandingTree_Right_P6    = 49,
      COMMON_ExpandingTree_Right_P7    = 50,
      COMMON_ExpandingTree_Right_P8    = 51,
      COMMON_ExpandingTree_Right_P9    = 52,
      COMMON_e3_Transition             = 73,
      COMMON_e3_Move_Left              = 74,
      COMMON_LIGHT_TREE_TICK           = 76,
      COMMON_LIGHT_TREE_GO             = 77,
      COMMON_OPTION_SLIDER_TICK        = 78,
      HUD_RACE_COMPLETE_IN             = 79,
      HUD_COUNTDOWN                    = 80,
      HUD_COUNTDOWN_GO                 = 83,
      HUD_MATCHUP_TEXT_IN              = 84,
      HUD_MATCHUP_TEXT_OUT             = 85,
      HUD_STUTTER_TEXT_OVERLAY_IN      = 86,
      HUD_STUTTER_TEXT_OVERLAY_OUT     = 87,
      HUD_BURNOUT_RATING_IN            = 88,
      HUD_BURNOUT_RATING_OUT           = 89,
      HUD_DRAG_COUNTDOWN               = 92,
      HUD_DRAG_COUNTDOWN_GO            = 93,
      COMMON_CHYRON_IN                 = 94,
      COMMON_CHYRON_OUT                = 95,
      COMMON_CHYRON_NOTIFICATION       = 96,
      HUD_COUNTDOWN_1                  = 97,
      HUD_COUNTDOWN_2                  = 98,
      HUD_COUNTDOWN_3                  = 99,
      COMMON_MUSIC_CHYRON_IN           = 100,
      COMMON_MUSIC_CHYRON_OUT          = 101,
      COMMON_LARGE_MENU_IN             = 102,
      COMMON_LARGE_MENU_OUT            = 103,
      COMMON_PAUSE_MENU_IN             = 104,
      COMMON_PAUSE_MENU_OUT            = 105,
      COMMON_YOU_WON                   = 106,
      MAIN_UP_AND_DOWN                 = 200,
      MAIN_LEFT_AND_RIGHT              = 201,
      MAIN_SCROLL_LEFT                 = 202,
      MAIN_SCROLL_RIGHT                = 203,
      MAIN_SELECT                      = 204,
      MAIN_BACK                        = 205,
      MAIN_WRONG                       = 207,
      MAIN_TRANSITION_IN               = 208,
      MAIN_TRANSITION_OUT              = 209,
      MAIN_DLGBOX_IN                   = 210,
      MAIN_DLGBOX_OUT                  = 211,
      UGNEW_KBTYPE                     = 224,
      UGNEW_ENTER                      = 225,
      UGNEW_DELETE                     = 226,
      MAIN_END_OF_LIST                 = 228,
      MAIN_KBCURSOR_UPDOWN             = 230,
      MAIN_KBCURSOR_LEFTRIGHT          = 231,
      MAIN_TRANSITION_ANIMATION_1      = 232,
      MAIN_TRANSITION_ANIMATION_2      = 233,
      MAIN_TRANSITION_ANIMATION_3      = 234,
      MAIN_TRANSITION_ANIMATION_4      = 235,
      MAIN_TRANSITION_ANIMATION_5      = 236,
      MAIN_TRANSITION_ANIMATION_6      = 237,
      MAIN_TRANSITION_ANIMATION_7      = 238,
      MAIN_TRANSITION_ANIMATION_8      = 239,
      MAIN_TRANSITION_ANIMATION_9      = 240,
      MAIN_CUST_INST_PAINT             = 306,
      MAIN_CUST_PAINT_COLOUR_LEFT      = 307,
      MAIN_CUST_PAINT_COLOUR_RIGHT     = 308,
      MAIN_CUST_PAINT_COLOUR_UP        = 309,
      MAIN_CUST_PAINT_COLOUR_DOWN      = 310,
      MAIN_CUST_VINYL_INSTALL          = 311,
      CUST_INST_EXHAUST                = 316,
      CUST_INST_GENERIC                = 317,
      CUST_INST_TURBO                  = 318,
      CUST_INST_NOS                    = 319,
      CUST_INST_TRANSMISSION           = 320,
      CUST_INST_TIRES                  = 321,
      EA_MSGR_OPEN                     = 322,
      EA_MSGR_LOGOFF                   = 323,
      EA_MSGR_CHAT_REQ                 = 324,
      EA_MSGR_MAIL_RECEIVE             = 325,
      EA_MSGR_CHALLENGE_REQ            = 326,
      MAIN_MENU_ENTER                  = 346,
      MAIN_MENU_EXIT                   = 347,
      MAIN_SUB_ENTER                   = 348,
      MAIN_SUB_EXIT                    = 349,
      MAIN_MAP_AREA_SELECT             = 350,
      MAIN_MAP_MENU_APPEAR             = 351,
      MAIN_MAP_MENU_DISAPPEAR          = 352,
      MAIN_MAP_MENU_NAV_UP             = 353,
      MAIN_MAP_MENU_NAV_DOWN           = 354,
      MAIN_MAP_MENU_NAV_LEFT           = 355,
      MAIN_MAP_MENU_NAV_RIGHT          = 356,
      MAIN_MAP_ZOOM_IN                 = 357,
      MAIN_MAP_ZOOM_OUT                = 358,
      MAIN_KEYBOARD_ACCEPT             = 359,
      MAIN_KEYBOARD_BACK               = 360,
      MAIN_KEYBOARD_NAV                = 361,
      MAIN_KEYBOARD_SELECT             = 362,
      MAIN_MAP_MENU_NAV_LEFTRIGHT      = 363,
      MAIN_MAP_MENU_NAV_UPDOWN         = 364,
      MAIN_FEICECAM_CAM1               = 368,
      MAIN_FEICECAM_CAM1BCK            = 369,
      MAIN_FEICECAM_CAM2               = 370,
      MAIN_FEICECAM_CAM2BCK            = 371,
      MAIN_FEICECAM_CAM3               = 372,
      MAIN_FEICECAM_CAM3BCK            = 373,
      MAIN_FEICECAM_CAM4               = 374,
      MAIN_FEICECAM_CAM4BCK            = 375,
      MAIN_FEICECAM_CAM5               = 376,
      MAIN_FEICECAM_CAM5BCK            = 377,
      MAIN_FEICECAM_CAM6               = 378,
      MAIN_FEICECAM_CAM6BCK            = 379,
      MAIN_FEICECAM_CAM7               = 380,
      MAIN_FEICECAM_CAM7BCK            = 381,
      MAIN_FEICECAM_CAM8               = 382,
      MAIN_FEICECAM_CAM8BCK            = 383,
      MAIN_FEICECAM_CAM9               = 384,
      MAIN_FEICECAM_CAM9BCK            = 385,
      MAIN_FEICECAM_CAM10              = 386,
      MAIN_FEICECAM_CAM10BCK           = 387,
      MAIN_SWIRLING_MENU_INTRO         = 388,
      MAIN_UNLOCK                      = 389,
      COMMON_DRIFT_NICE                = 400,
      COMMON_DRIFT_GOOD                = 400,
      COMMON_DRIFT_AWESOME             = 401,
      COMMON_DRIFT_AMAZING             = 401,
      COMMON_DRIFT_GREAT               = 401,
      COMMON_DRIFT_OUTRAGEOUS          = 402,
      COMMON_DRIFT_MULTIPLIER          = 403,
      COMMON_DRIFT_DRIFT_ENDED         = 404,
      COMMON_DRIFT_PERFECT_ENTRY       = 405,
    };

    void PlayUISoundFX(eMenuSoundTriggers triggerType) {
      reinterpret_cast<void(__thiscall*)(EAXSound*, eMenuSoundTriggers)>(0x4ED5D0)(this, triggerType);
    }

    static EAXSound* Get() {
      static EAXSound** fObj = reinterpret_cast<EAXSound**>(0xAAEC10);
      return *fObj;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_EAXSOUND_H
