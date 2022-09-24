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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_RESETCAR_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_RESETCAR_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/BehaviorParams.h>
#include <NFSPluginSDK/Game.MW05/Types/IRBVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/IResetable.h>
#include <NFSPluginSDK/Game.MW05/Types/VehicleBehavior.h>
#include <NFSPluginSDK/Game.MW05/Types/WRoadNav.h>

namespace NFSPluginSDK::MW05 {
  struct ResetCar : VehicleBehavior, IResetable {
    enum class Flags : std::uint32_t { None, FindRoad };
    struct ResetCookie {
      UMath::Vector3 position;
      Flags          flags;
      UMath::Vector3 direction;
      float          time;
    };

    float                                 mFlippedOver;
    WRoadNav::CookieTrail<ResetCookie, 4> mCookies;
    ICollisionBody*                       mCollisionBody;
    ISuspension*                          mSuspension;
    IRBVehicle*                           mVehicleBody;
    HSIMTASK__*                           mCheckTask;

    virtual ~ResetCar();
#pragma region overrides
    virtual void Reset() override;
    virtual void OnBehaviorChange(const UCrc32& mechanic) override;
    virtual bool HasResetPosition() override;
    virtual bool ResetVehicle(bool findRoad) override;
    virtual void SetResetPosition(const UMath::Vector3& position, const UMath::Vector3& direction) override;
    virtual void ClearResetPosition() override;
#pragma endregion

    static IResetable* Construct(const BehaviorParams& params) {
      IResetable* p = reinterpret_cast<IResetable*(__cdecl*)(BehaviorParams)>(0x689820)(params);
      return static_cast<ResetCar*>(p);
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_RESETCAR_H
