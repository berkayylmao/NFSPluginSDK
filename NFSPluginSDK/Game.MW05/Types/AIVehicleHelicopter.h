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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHELICOPTER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHELICOPTER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehiclePursuit.h>
#include <NFSPluginSDK/Game.MW05/Types/IAIHelicopter.h>
#include <NFSPluginSDK/Game.MW05/Types/HeliSheetCoordinate.h>

namespace NFSPluginSDK::MW05 {
  struct AIVehicleHelicopter : AIVehiclePursuit, IAIHelicopter {
    UMath::Vector3      mDestinationVelocity;
    UMath::Vector3      mLookAtPosition;
    UMath::Vector3      mLastPlaceHeliSawPerp;
    float               mHeight;
    bool                mStrafeToDest;
    bool                mPerpHiddenFromMe;
    float               mHeliFuelTimeRemaining;
    float               mShadowScale;
    float               mDustStormIntensity;
    HeliSheetCoordinate mHeliSheetCoord;
    HeliSheetCoordinate mSecondaryHeliSheetCoord;
    HeliSheetCoordinate mThirdHeliSheetCoord;
    ISimpleChopper*     mISimpleChopper;

    virtual ~AIVehicleHelicopter();
    virtual const HeliSheetCoordinate& GetHeliSheetCoord();
#pragma region overrides
    virtual void           Update(float deltaTime) override;
    virtual void           OnDriving(float deltaTime) override;
    virtual bool           CanSeeTarget(AITarget* target) override;
    virtual float          GetDesiredHeightOverDest() override;
    virtual void           SetDesiredHeightOverDest(float height) override;
    virtual void           SetLookAtPosition(UMath::Vector3 pos) override;
    virtual UMath::Vector3 GetLookAtPosition() override;
    virtual void           SetDestinationVelocity(const UMath::Vector3& velocity) override;
    virtual void           SteerToNav(WRoadNav* road_nav, float height, float speed, bool bStopAtDest) override;
    virtual bool           StartPathToPoint(UMath::Vector3& point) override;
    virtual bool           StrafeToDestIsSet() override;
    virtual void           SetStrafeToDest(bool strafe) override;
    virtual bool           FilterHeliAltitude(UMath::Vector3& point) override;
    virtual void           RestrictPointToRoadNet(UMath::Vector3& seekPosition) override;
    virtual void           SetFuelFull() override;
    virtual float          GetFuelTimeRemaining() override;
    virtual void           SetShadowScale(float scale) override;
    virtual float          GetShadowScale() override;
    virtual void           SetDustStormIntensity(float intensity) override;
    virtual float          GetDustStormIntensity() override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHELICOPTER_H
