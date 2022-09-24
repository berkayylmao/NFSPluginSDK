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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGERACER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGERACER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/ISpikeable.h>

namespace NFSPluginSDK::MW05 {
  struct DamageRacer : DamageVehicle, ISpikeable {
    ISuspension* mSuspension;
    union {
      float mBlowOutTimes[4];
      union {
        float mFrontLeftBlowOutTime;
        float mFrontRightBlowOutTime;
        float mRearRightBlowOutTime;
        float mRearLeftBlowOutTime;
      };
    };
    union {
      eTireDamage mDamage[4];
      union {
        eTireDamage mFrontLeftDamage;
        eTireDamage mFrontRightDamage;
        eTireDamage mRearRightDamage;
        eTireDamage mRearLeftDamage;
      };
    };

    virtual ~DamageRacer();

#pragma region overrides
    virtual bool                  CanDamageVisuals() override;
    virtual void                  OnTaskSimulate(float deltaTime) override;
    virtual void                  OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void                  ResetDamage() override;
    virtual Sim::Collision::Info* GetZoneDamage() override;
    virtual void                  OnCollision(const Sim::Collision::Info& cinfo) override;
    virtual bool                  IsLightDamaged(VehicleFX::LightID idx) override;
    virtual eTireDamage           GetTireDamage(eTireIdx idx) override;
    virtual std::int32_t          GetNumBlowouts() override;
    virtual void                  Puncture(eTireIdx idx) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGERACER_H
