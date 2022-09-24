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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICSOBJECT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICSOBJECT_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attachments.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Behavior.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IBody.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ISimable.h>

namespace NFSPluginSDK::ProStreet {
  struct PhysicsObject : Sim::Object,
                         ISimable,
                         IBody,
                         IAttachable,
                         UTL::GarbageNode<PhysicsObject, 256>,
                         Behavior::Container {
    WWorldPos*             mWPos;
    SimableType            mObjType;
    HSIMABLE__*            mOwner;
    Attrib::Instance       mPhysicsObjectAttributes;
    IRigidBody*            mRigidBody;
    HSIMTASK__*            mSimulateTask;
    Sim::IEntity*          mEntity;
    IPlayer*               mPlayer;
    HSIMSERVICE__*         mBodyService;
    std::uint32_t          mWorldID;
    eastl::list<Behavior*> mMechanics;
    eastl::list<Behavior*> mBehaviors;
    Attachments*           mAttachments;
    std::uint8_t           pad[0xC];

    virtual ~PhysicsObject();
    virtual void Reset();
    virtual void OnTaskSimulate(float) = 0;
    virtual void OnBehaviorChange(const UCrc32&);
#pragma region overrides
    virtual bool                     OnTask(HSIMTASK__*, float) override;
    virtual SimableType              GetSimableType() override;
    virtual void                     Kill() override;
    virtual bool                     Attach(UTL::COM::IUnknown* object) override;
    virtual bool                     Detach(UTL::COM::IUnknown* object) override;
    virtual Attachments*             GetAttachments() override;
    virtual void                     AttachEntity(Sim::IEntity* entity) override;
    virtual void                     DetachEntity() override;
    virtual IPlayer*                 GetPlayer() override;
    virtual bool                     IsPlayer() override;
    virtual bool                     IsOwnedByPlayer() override;
    virtual Sim::IEntity*            GetEntity() override;
    virtual void                     DebugObject() override;
    virtual HSIMABLE__*              GetOwnerHandle() override;
    virtual ISimable*                GetOwner() override;
    virtual bool                     IsOwnedBy(ISimable* pSimable) override;
    virtual void                     SetOwnerObject(ISimable* pSimable) override;
    virtual const Attrib::Instance&  GetAttributes() override;
    virtual const WWorldPos&         GetWPos() const override;
    virtual WWorldPos&               GetWPos() override;
    virtual const IRigidBody*        GetRigidBody() const override;
    virtual IRigidBody*              GetRigidBody() override;
    virtual bool                     IsRigidBodySimple() override;
    virtual bool                     IsRigidBodyComplex() override;
    virtual const UMath::Vector3&    GetPosition() override;
    virtual void                     GetTransform(UMath::Matrix4& matrix) override;
    virtual void                     GetLinearVelocity(UMath::Vector3& to) override;
    virtual void                     GetAngularVelocity(UMath::Vector3& to) override;
    virtual std::uint32_t            GetWorldID() override;
    virtual EventSequencer::IEngine* GetEventSequencer() override;
    virtual void                     ProcessStimulus(std::uint32_t) override;
    virtual const IModel*            GetModel() const override;
    virtual IModel*                  GetModel() override;
    virtual void                     SetCausality(HCAUSE__* p, float time) override;
    virtual HCAUSE__*                GetCausality() override;
    virtual float                    GetCausalityTime() override;
    virtual void                     GetDimension(UMath::Vector3& to) override;
    virtual bool                     IsAttached(UTL::COM::IUnknown* pOther) override;
    virtual void                     OnAttached(IAttachable* pOther) override;
    virtual void                     OnDetached(IAttachable* pOther) override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_PHYSICSOBJECT_H
