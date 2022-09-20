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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_ISIMABLE_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_ISIMABLE_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib.h>
#include <NFSPluginSDK/Game.Carbon/Types/EventSequencer.h>
#include <NFSPluginSDK/Game.Carbon/Types/IAttachable.h>
#include <NFSPluginSDK/Game.Carbon/Types/WWorldPos.h>

namespace NFSPluginSDK::Carbon {
  struct ISimable : UTL::COM::IUnknown {
    std::uint32_t _mHandle;  // from UTL::Instanceable<HSIMABLE__ *, ISimable, n>

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
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_ISIMABLE_H
