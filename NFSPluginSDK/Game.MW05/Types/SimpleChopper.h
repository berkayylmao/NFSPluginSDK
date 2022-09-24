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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLECHOPPER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLECHOPPER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/chopperspecs.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/pvehicle.h>
#include <NFSPluginSDK/Game.MW05/Types/ISimpleChopper.h>
#include <NFSPluginSDK/Game.MW05/Types/ITransmission.h>
#include <NFSPluginSDK/Game.MW05/Types/VehicleBehavior.h>

namespace NFSPluginSDK::MW05 {
  struct SimpleChopper : VehicleBehavior, ISimpleChopper {
    UMath::Vector3                              mLastBodyOffset;
    UMath::Vector3                              mLastAngVelocity;
    UMath::Vector3                              mLastAccelVector;
    UMath::Vector3                              mDesiredVelocity;
    UMath::Vector3                              mPreviousVelocity;
    UMath::Vector3                              mDesiredFacingVector;
    BehaviorSpecsPtr<Attrib::Gen::chopperspecs> mChopperSpecs;
    BehaviorSpecsPtr<Attrib::Gen::pvehicle>     mVehicleSpecs;
    bool                                        mMaxDecelFlag;
    IRigidBody*                                 mIRigidBody;
    ICollisionBody*                             mIRBComplex;
    IDamageable*                                mIDamage;

    virtual ~SimpleChopper();
    virtual float GetPower();
    virtual float GetRPM();
    virtual float GetMaxRPM();
    virtual float GetRedline();
    virtual float GetMinRPM();
    virtual float GetMinGearRPM(ITransmission::GearID gearId);
    virtual void  MatchSpeed(float speed);
    virtual float GetNOSCapacity();
    virtual bool  IsNOSEngaged();
    virtual bool  HasNOS();
#pragma region overrides
    virtual void Reset() override;
    virtual void OnTaskSimulate(float deltaTime) override;
    virtual void OnBehaviorChange(const UCrc32& mechanic) override;
    virtual void SetDesiredVelocity(const UMath::Vector3& velocity) override;
    virtual void GetDesiredVelocity(UMath::Vector3& out) override;
    virtual void MaxDeceleration(bool limit) override;
    virtual void SetDesiredFacingVector(const UMath::Vector3& vector) override;
    virtual void GetDesiredFacingVector(UMath::Vector3& out) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_SIMPLECHOPPER_H
