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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_RBVEHICLE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_RBVEHICLE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IRBVehicle.h>
#include <NFSPluginSDK/Game.ProStreet/Types/RigidBody.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/collisionreactions.h>

namespace NFSPluginSDK::ProStreet {
  struct RBVehicle : RigidBody, IRBVehicle {
    IVehicle*                                     mVehicle;
    IChassis*                                     mChassis;
    BehaviorSpecsPtr<Attrib::Gen::rigidbodyspecs> mSpecs;
    float                                         mDeadOnWheels;
    CollisionGeometry::Collection*                mGeoms;
    std::uint32_t                                 mFrame;
    unsigned char                                 _pad[4];
    UMath::Vector3                                mCollisionCenterOfGravity;
    float                                         mCollisionMass;
    bool                                          mObjectCollisionsEnabled;
    bool                                          mVehicleCollisionsEnabled;
    bool                                          mTumblingFlag;
    std::int32_t                                  mTumblingIndex;
    eInvulnerability                              mInvulnerableState;
    float                                         mInvulnerableTimer;
    float                                         mLastPenetration;
    Attrib::Gen::collisionreactions               mReactions[10];

    virtual ~RBVehicle();
    virtual void             SetTargetPosition(const UMath::Vector3& position) override;
    virtual void             SetCollisionMass(float mass) override;
    virtual void             SetCollisionCOG(const UMath::Vector3& newCenterOfGravity) override;
    virtual void             EnableObjectCollisions(bool isEnabled) override;
    virtual bool             AreObjectCollisionsEnabled() override;
    virtual void             EnableVehicleCollisions(bool isEnabled) override;
    virtual void             SetInvulnerability(eInvulnerability type, float durationInSeconds) override;
    virtual eInvulnerability GetInvulnerability() override;
    virtual void             SetPlayerReactions(const Attrib::Gen::collisionreactions& reactions) override;
    virtual const Attrib::Gen::collisionreactions& GetPlayerReactions() override;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_RBVEHICLE_H
