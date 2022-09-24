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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ISIMABLE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ISIMABLE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EventSequencer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IAttachable.h>
#include <NFSPluginSDK/Game.ProStreet/Types/WWorldPos.h>

namespace NFSPluginSDK::ProStreet {
  struct ISimable : UTL::COM::IUnknown, UTL::Instanceable<HSIMABLE__*, ISimable, 256> {
    virtual ~ISimable();
    virtual SimableType              GetSimableType()                       = 0;
    virtual void                     Kill()                                 = 0;
    virtual bool                     Attach(UTL::COM::IUnknown* object)     = 0;
    virtual bool                     Detach(UTL::COM::IUnknown* object)     = 0;
    virtual Attachments*             GetAttachments()                       = 0;
    virtual void                     AttachEntity(Sim::IEntity* entity)     = 0;
    virtual void                     DetachEntity()                         = 0;
    virtual IPlayer*                 GetPlayer()                            = 0;
    virtual bool                     IsPlayer()                             = 0;
    virtual bool                     IsOwnedByPlayer()                      = 0;
    virtual Sim::IEntity*            GetEntity()                            = 0;
    virtual void                     DebugObject()                          = 0;
    virtual HSIMABLE__*              GetOwnerHandle()                       = 0;
    virtual ISimable*                GetOwner()                             = 0;
    virtual bool                     IsOwnedBy(ISimable* pSimable)          = 0;
    virtual void                     SetOwnerObject(ISimable* pSimable)     = 0;
    virtual const Attrib::Instance&  GetAttributes()                        = 0;
    virtual const WWorldPos&         GetWPos() const                        = 0;
    virtual WWorldPos&               GetWPos()                              = 0;
    virtual const IRigidBody*        GetRigidBody() const                   = 0;
    virtual IRigidBody*              GetRigidBody()                         = 0;
    virtual bool                     IsRigidBodySimple()                    = 0;
    virtual bool                     IsRigidBodyComplex()                   = 0;
    virtual const UMath::Vector3&    GetPosition()                          = 0;
    virtual void                     GetTransform(UMath::Matrix4& matrix)   = 0;
    virtual void                     GetLinearVelocity(UMath::Vector3& to)  = 0;
    virtual void                     GetAngularVelocity(UMath::Vector3& to) = 0;
    virtual std::uint32_t            GetWorldID()                           = 0;
    virtual EventSequencer::IEngine* GetEventSequencer()                    = 0;
    virtual void                     ProcessStimulus(std::uint32_t)         = 0;
    virtual const IModel*            GetModel() const                       = 0;
    virtual IModel*                  GetModel()                             = 0;
    virtual void                     SetCausality(HCAUSE__* p, float time)  = 0;
    virtual HCAUSE__*                GetCausality()                         = 0;
    virtual float                    GetCausalityTime()                     = 0;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ISIMABLE_H
