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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DAMAGEVEHICLE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DAMAGEVEHICLE_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/damagespecs.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DamageZone.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EventSequencer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IDamageable.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IDamageableVehicle.h>
#include <NFSPluginSDK/Game.ProStreet/Types/VehicleBehavior.h>

namespace NFSPluginSDK::ProStreet {
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
    ICollisionBody*                            mCollisionBody;
    IRigidBody*                                mRB;
    IRenderable*                               mRenderable;
    DamageZone::Info                           mZoneDamage;
    UMath::Vector3                             mLastImpactSpeed;
    eastl::list<UCrc32>                        mBrokenParts;
    VehicleFX::LightID                         mLightDamage;
    VehicleFX::LightID                         mLightCracked;
    VehicleFX::WindowID                        mWindowDamage;
    VehicleFX::WindowID                        mWindowCracked;
    float                                      mHitPointsOverride;

    virtual ~DamageVehicle();
    virtual void OnImpact(const UMath::Vector3&, const UMath::Vector3&, float, float, const SimSurface&, ISimable*);
    virtual bool CanDamageVisuals();

#pragma region overrides
    virtual void                OnTaskSimulate(float deltaTime) override;
    virtual void                OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void                Reset() override;
    virtual void                SetInShock(float) override;
    virtual void                SetShockForce(float) override;
    virtual float               InShock() override;
    virtual void                ResetDamagePrivate() override;
    virtual float               GetHealth() override;
    virtual bool                IsDestroyed() override;
    virtual void                Destroy() override;
    virtual DamageZone::Info    GetZoneDamage() override;
    virtual void                OnCollision(const Sim::Collision::Info& cinfo) override;
    virtual bool                IsLightDamaged(VehicleFX::LightID idx) override;
    virtual void                DamageLight(VehicleFX::LightID idx, bool damage) override;
    virtual bool                IsLightCracked(VehicleFX::LightID idx) override;
    virtual void                CrackLight(VehicleFX::LightID idx, bool crack) override;
    virtual bool                IsWindowDamaged(VehicleFX::WindowID idx) override;
    virtual void                DamageWindow(VehicleFX::WindowID idx, bool damage) override;
    virtual bool                IsWindowCracked(VehicleFX::WindowID idx) override;
    virtual void                CrackWindow(VehicleFX::WindowID idx, bool crack) override;
    virtual void                SetHitPointsOverride(float hp) override;
    virtual UTL::COM::IUnknown* GetContextOwner() = 0;
    virtual std::int32_t        GetContextDebugName(char* out, std::uint32_t len) override;
    virtual bool                GetDynamicData(EventSequencer::System* system, void* pOutEventDynamicData) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DAMAGEVEHICLE_H
