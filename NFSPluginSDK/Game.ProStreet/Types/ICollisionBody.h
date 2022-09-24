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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ICOLLISIONBODY_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ICOLLISIONBODY_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UCrc32.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct ICollisionBody : UTL::COM::IUnknown {
    virtual ~ICollisionBody();
    virtual const UMath::Vector3& GetPosition()                                                = 0;
    virtual const UMath::Vector3& GetLinearVelocity()                                          = 0;
    virtual const UMath::Vector3& GetAngularVelocity()                                         = 0;
    virtual void                  GetDimension(UMath::Vector3& to)                             = 0;
    virtual void                  Damp(float amount)                                           = 0;
    virtual void                  SetAnimating(bool isAnimating)                               = 0;
    virtual bool                  IsModeling()                                                 = 0;
    virtual void                  DisableModeling()                                            = 0;
    virtual void                  EnableModeling()                                             = 0;
    virtual bool                  IsTriggering()                                               = 0;
    virtual void                  DisableTriggering()                                          = 0;
    virtual void                  EnableTriggering()                                           = 0;
    virtual bool                  IsSleeping()                                                 = 0;
    virtual void                  SetCenterOfGravity(const UMath::Vector3& newCenterOfGravity) = 0;
    virtual const UMath::Vector3& GetCenterOfGravity()                                         = 0;
    virtual bool                  HasHadCollision()                                            = 0;
    virtual bool                  HasHadWorldCollision()                                       = 0;
    virtual bool                  HasHadObjectCollision()                                      = 0;
    virtual bool                  HasHadGroundCollision()                                      = 0;
    virtual void                  EnableCollisionGeometries(UCrc32 crc, bool isEnabled)        = 0;
    virtual bool                  DistributeMass()                                             = 0;
    virtual const UMath::Vector3& GetWorldMomentScale()                                        = 0;
    virtual const UMath::Vector3& GetGroundMomentScale()                                       = 0;
    virtual bool                  IsAttachedToWorld()                                          = 0;
    virtual void                  AttachedToWorld(bool, float)                                 = 0;
    virtual bool                  IsAnchored()                                                 = 0;
    virtual void                  SetAnchored(bool isAnchored)                                 = 0;
    virtual void                  SetInertiaTensor(const UMath::Vector3& newInertiaTensor)     = 0;
    virtual const UMath::Vector3& GetInertiaTensor()                                           = 0;
    virtual float                 GetOrientToGround()                                          = 0;
    virtual bool                  IsInGroundContact()                                          = 0;
    virtual std::int32_t          GetNumContactPoints()                                        = 0;
    virtual const UMath::Vector4& GetGroundNormal()                                            = 0;
    virtual void                  SetForce(const UMath::Vector3& newForce)                     = 0;
    virtual void                  SetTorque(const UMath::Vector3& newTorque)                   = 0;
    virtual const UMath::Vector3& GetForce()                                                   = 0;
    virtual const UMath::Vector3& GetTorque()                                                  = 0;
    virtual float                 GetGravity()                                                 = 0;
    virtual const UMath::Vector3& GetForwardVector()                                           = 0;
    virtual const UMath::Vector3& GetRightVector()                                             = 0;
    virtual const UMath::Vector3& GetUpVector()                                                = 0;
    virtual const UMath::Matrix4& GetMatrix4()                                                 = 0;
    virtual std::uint32_t         SetWorldCollisionMask(std::uint32_t flag)                    = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x406030)(); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ICOLLISIONBODY_H
