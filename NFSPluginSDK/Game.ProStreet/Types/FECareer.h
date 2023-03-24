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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECAREER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECAREER_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EA.h>

namespace NFSPluginSDK::ProStreet::FE::Career {
  struct FECareer : EA::Memcard::IMemcardSavable {
    struct alignas(4) HubCarInfoStruct {
      std::int32_t mCarHandle[5][2];
      std::int32_t mCarNameHash[5][2];
      std::int32_t mCarManuLogoHash[5][2];
      float        mCarResaleValue[5][2];
      char         mBackupCarType[2];
    };

    std::int32_t                                         CurrentCar[2];
    HubCarInfoStruct                                     mHubCarInfoStruct[2];
    bool                                                 mHubEnteredFromCarSelect;
    std::int32_t                                         mRepairMarkers[2];
    std::int32_t                                         mTotalRepairMarkers[2];
    std::uint32_t                                        ssEventsPlayed;
    std::uint32_t                                        ssEventsNoCars[2];
    std::int32_t                                         ssEventIndexToBeLocked;
    std::int32_t                                         ssDriverAssistLevel[2];
    std::int8_t                                          ssPlayerPorts[2];
    eastl::map<std::int32_t, DALCareer::eCarDamageLevel> mCustomHubDamageInfoMap[2];
    std::uint32_t                                        __pad[2];
    std::uint32_t                                        CrewCarStyleTargetCar;
    std::uint32_t                                        mCurrentHub;
    std::uint32_t                                        SpecialFlags;
    std::int8_t                                          CurrentBin;
    std::int32_t                                         CurrentCash;
    std::int32_t                                         CareerRep;
    __int16                                              AdaptiveDifficulty;
    // FE::Career::SMSMessage                                SMSMessages[150];
    // std::uint32_t                                         SMSSortOrder;
    // bool                                                  TutorialFlags;
    // bool                                                  TimesShowenControllerConfigLoadingScreen;
    // bool                                                  mCareerFeLocation;
    // bool                                                  mCareerName[32];
    // FEBitField<67>                                        mTipHasShownFlags;
    // CustomRaceDayMemcard                                  mCustomRaceDayMemcard;

    static FECareer* Get() {
      static FECareer** fObj = reinterpret_cast<FECareer**>(0xAB0EA8);
      return *fObj;
    }
  };

  using namespace FE::Career;
}  // namespace NFSPluginSDK::ProStreet::FE::Career

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FECAREER_H
