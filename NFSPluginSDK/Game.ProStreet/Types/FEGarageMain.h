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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEGARAGEMAIN_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEGARAGEMAIN_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FrontEndRenderingCar.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GarageCarLoader.h>
#include <NFSPluginSDK/Game.ProStreet/Types/MenuScreen.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IUnplugErrorAllowable.h>
#include <NFSPluginSDK/Game.ProStreet/Types/TrackPositionMarker.h>

namespace NFSPluginSDK::ProStreet {
  struct FEGarageMain : MenuScreen, IUnplugErrorAllowable {
    enum class eSafehouse : std::uint32_t {
      None,
      Muscle,
      Tuner,
      Exotic,
      CarLotMuscle,
      CarLotTuner,
      CarLotExotic,
      CarLotMazda,
      Main,
      Generic,
      CarClass
    };

    FrontEndRenderingCar* mRenderingCar;
    GarageCarLoader*      mGarageCarLoader;
    std::uint32_t         mCarHandle;
    SelectCarCameraMover* mpCameraMover;
    TrackPositionMarker*  mCarPosition;
    std::int32_t          mCarState;
    char                  mCarPosMarkerId;
    float                 mTimeToMoveCarPos;
    float                 mTimeToStartFEngEnter;
    bool                  mICECamPlaying;
    ActionQueue*          mActionQ[4];
    std::int32_t          HideEntireScreen;
    std::int32_t          ViewID;
    std::uint32_t         mScreenKey;
    std::uint32_t         mCameraKey;
    std::uint32_t         mScreenKeyCamIsSetTo;
    bool                  bUserRotate;
    bool                  bUserZoom;
    bool                  bUserHasRotatedThisScreen;
    float                 mOrbitV;
    float                 mOrbitH;
    float                 mZoom;
    float                 mCarRotateSpeed;
    bool                  mWheelMouseScrolled;
    bool                  mBlackPolyVisible;
    char                  mTrackPositionMarkerName[32];
    bool                  mAutosculptResetHack;

    void SetRideInfo(std::uint32_t carHandle, BluePrintNumber bp) {
      reinterpret_cast<void(__thiscall*)(FEGarageMain*, std::uint32_t, BluePrintNumber)>(0x7E6EF0)(this, carHandle, bp);
    }
    void SetRideInfo(RideInfo* rideInfo, FECustomizationRecord* fecr, BluePrintNumber bp) {
      reinterpret_cast<void(__thiscall*)(FEGarageMain*, RideInfo*, FECustomizationRecord*, BluePrintNumber)>(0x7E6DD0)(
          this, rideInfo, fecr, bp);
    }

    static inline FEGarageMain** spInstance = reinterpret_cast<FEGarageMain**>(0xB32AAC);
    static FEGarageMain*         Get() {
              if (!spInstance) return nullptr;
      return *spInstance;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEGARAGEMAIN_H
