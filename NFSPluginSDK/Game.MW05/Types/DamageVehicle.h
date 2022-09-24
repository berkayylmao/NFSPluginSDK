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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGEVEHICLE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGEVEHICLE_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/slist.h>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/damagespecs.h>
#include <NFSPluginSDK/Game.MW05/Types/DamageZone.h>
#include <NFSPluginSDK/Game.MW05/Types/EventSequencer.h>
#include <NFSPluginSDK/Game.MW05/Types/IDamageable.h>
#include <NFSPluginSDK/Game.MW05/Types/IDamageableVehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/VehicleBehavior.h>

namespace NFSPluginSDK::MW05 {
  struct DamageVehicle : VehicleBehavior,
                         IDamageable,
                         Sim::Collision::IListener,
                         IDamageableVehicle,
                         EventSequencer::IContext {
    float                                      mShockTimer;
    int                                        fTempInvincibilityTimer;
    BehaviorSpecsPtr<Attrib::Gen::damagespecs> mSpecs;
    float                                      mOffScreenTimer;
    float                                      mDamageTotal;
    ICollisionBody*                            mIRBComplex;
    IRigidBody*                                mRB;
    IRenderable*                               mRenderable;
    DamageZone::Info                           mZoneDamage;
    UMath::Vector3                             mLastImpactSpeed;
    eastl::slist<UCrc32>                       mBrokenParts;
    VehicleFX::LightID                         mLightDamage;

    virtual ~DamageVehicle();
    virtual void OnImpact(const UMath::Vector3&, const UMath::Vector3&, float, float, const SimSurface&, ISimable*);
    virtual bool CanDamageVisuals();

#pragma region overrides
    virtual void                  Reset() override;
    virtual void                  OnTaskSimulate(float deltaTime) override;
    virtual void                  OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void                  SetInShock(float) override;
    virtual void                  SetShockForce(float) override;
    virtual float                 InShock() override;
    virtual void                  ResetDamage() override;
    virtual float                 GetHealth() override;
    virtual bool                  IsDestroyed() override;
    virtual void                  Destroy() override;
    virtual Sim::Collision::Info* GetZoneDamage() override;
    virtual void                  OnCollision(const Sim::Collision::Info& cinfo) override;
    virtual bool                  IsLightDamaged(VehicleFX::LightID idx) override;
    virtual void                  DamageLight(VehicleFX::LightID idx, bool damage) override;
    virtual bool                  SetDynamicData(void* System, void* pOutEventDynamicData) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_DAMAGEVEHICLE_H
