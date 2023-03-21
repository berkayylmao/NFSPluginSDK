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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_IRIGIDBODY_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_IRIGIDBODY_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct IRigidBody : UTL::COM::IUnknown {
    virtual ~IRigidBody();
    virtual ISimable*             GetOwner()                                                      = 0;
    virtual bool                  IsSimple()                                                      = 0;
    virtual std::int32_t          GetIndex()                                                      = 0;
    virtual SimableType           GetSimableType()                                                = 0;
    virtual float                 GetRadius()                                                     = 0;
    virtual float                 GetMass()                                                       = 0;
    virtual float                 GetOOMass()                                                     = 0;
    virtual const UMath::Vector3& GetPosition()                                                   = 0;
    virtual const UMath::Vector3& GetLinearVelocity()                                             = 0;
    virtual const UMath::Vector3& GetAngularVelocity()                                            = 0;
    virtual float                 GetSpeed()                                                      = 0;
    virtual float                 GetSpeedXZ()                                                    = 0;
    virtual void                  GetForwardVector(UMath::Vector3& to)                            = 0;
    virtual void                  GetRightVector(UMath::Vector3& to)                              = 0;
    virtual void                  GetUpVector(UMath::Vector3& to)                                 = 0;
    virtual void                  GetMatrix4(UMath::Matrix4& matrix)                              = 0;
    virtual const UMath::Vector4& GetOrientation()                                                = 0;
    virtual void                  GetDimension(UMath::Vector3& to) const                          = 0;
    virtual void                  GetDimension(UMath::Vector3& to)                                = 0;
    virtual std::uint32_t         GetTriggerFlags()                                               = 0;
    virtual WCollider*            GetWCollider()                                                  = 0;
    virtual void                  GetPointVelocity(const UMath::Vector3& vec, UMath::Vector3& to) = 0;
    virtual void                  SetPosition(const UMath::Vector3& newPosition)                  = 0;
    virtual void                  SetLinearVelocity(const UMath::Vector3& newLinearVelocity)      = 0;
    virtual void                  SetAngularVelocity(const UMath::Vector3& newAngularVelocity)    = 0;
    virtual void                  SetRadius(float newRadius)                                      = 0;
    virtual void                  SetMass(float newMass)                                          = 0;
    virtual void                  SetOrientation(const UMath::Matrix4& newOrientation)            = 0;
    virtual void                  SetOrientation(const UMath::Vector4& newOrientation)            = 0;
    virtual void                  ModifyXPos(float newPosX)                                       = 0;
    virtual void                  ModifyYPos(float newPosY)                                       = 0;
    virtual void                  ModifyZPos(float newPosZ)                                       = 0;
    virtual bool                  IsIntegrating()                                                 = 0;
    virtual void                  DisableIntegration()                                            = 0;
    virtual void                  EnableIntegration()                                             = 0;
    virtual bool                  IsActive()                                                      = 0;
    virtual void                  SetActive(bool isActive)                                        = 0;
    virtual void                  Resolve(const UMath::Vector3&, const UMath::Vector3&)           = 0;
    virtual void                  ResolveForce(const UMath::Vector3&, const UMath::Vector3&)      = 0;
    virtual void                  ResolveForce(const UMath::Vector3&)                             = 0;
    virtual void                  ResolveTorque(const UMath::Vector3&, const UMath::Vector3&)     = 0;
    virtual void                  ResolveTorque(const UMath::Vector3&)                            = 0;
    virtual void                  PlaceObject(const UMath::Matrix4&, const UMath::Vector3&)       = 0;
    virtual void                  Accelerate(const UMath::Vector3& distribution, float amount)    = 0;
    virtual void                  ConvertLocalToWorld(UMath::Vector3& out, bool normalize)        = 0;
    virtual void                  ConvertWorldToLocal(UMath::Vector3& out, bool normalize)        = 0;
    virtual void                  Debug()                                                         = 0;
    virtual bool                  IsTumbling()                                                    = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*>(0x402280); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_IRIGIDBODY_H
