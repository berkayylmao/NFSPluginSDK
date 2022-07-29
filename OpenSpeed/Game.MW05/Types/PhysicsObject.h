// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <mail@berkay.link>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <OpenSpeed/Core/EASTL/EASTL/list.h>
#include <OpenSpeed/Core/EASTL/EASTL/slist.h>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Attachments.h>
#include <OpenSpeed/Game.MW05/Types/Behavior.h>
#include <OpenSpeed/Game.MW05/Types/IBody.h>
#include <OpenSpeed/Game.MW05/Types/ISimable.h>
#include <OpenSpeed/Game.MW05/Types/Attrib/Instance.h>

namespace OpenSpeed::MW05 {
  struct PhysicsObject : Sim::Object,
                         ISimable,
                         IBody,
                         IAttachable,
                         UTL::GarbageNode<PhysicsObject>,
                         Behavior::Container {
    WWorldPos*              mWPos;
    SimableType             mObjType;
    Attrib::Instance        mPhysicsObjectAttributes;
    IRigidBody*             mRigidBody;
    HSIMTASK__*             mSimulateTask;
    Sim::IEntity*           mEntity;
    IPlayer*                mPlayer;
    HSIMSERVICE__*          mBodyService;
    std::uint32_t           mWorldID;
    eastl::slist<Behavior*> mMechanics;
    eastl::slist<Behavior*> mBehaviors;
    Attachments*            mAttachments;

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
}  // namespace OpenSpeed::MW05
