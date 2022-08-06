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

#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/IAttachable.h>
#include <OpenSpeed/Game.ProStreet/Types/UCrc32.h>
#include <OpenSpeed/Game.ProStreet/Types/Attrib/Gen/simsurface.h>

namespace OpenSpeed::ProStreet {
  namespace Sim {
    namespace Collision {
      struct IListener {
        virtual void OnCollision(const Info& cinfo);
      };
      struct Info {
        UMath::Vector3            position;
        const Attrib::Collection* objAsurface;
        UMath::Vector3            normal;
        CollisionType             type : 3;
        std::int32_t              objAImmobile : 1;
        std::int32_t              objADetached : 1;
        std::int32_t              objBImmobile : 1;
        std::int32_t              objBDetached : 1;
        std::int32_t              sliding : 1;
        std::int32_t              unused : 24;
        UMath::Vector3            closingVel;
        float                     force;
        UMath::Vector3            armA;
        HSIMABLE__*               objA;
        UMath::Vector3            armB;
        HSIMABLE__*               objB;
        UMath::Vector3            objAVel;
        float                     impulseA;
        UMath::Vector3            objBVel;
        float                     impulseB;
        UMath::Vector3            slidingVel;
        const Attrib::Collection* objBsurface;
      };
    }  // namespace Collision

    struct IActivity : UTL::COM::IUnknown {
      std::uint32_t _mHandle;  // from UTL::Instanceable<HACTIVITY__*, Sim::IActivity, n>

      virtual ~IActivity();
      virtual void         Release();
      virtual bool         Attach(UTL::COM::IUnknown* object) = 0;
      virtual bool         Detach(UTL::COM::IUnknown* object) = 0;
      virtual Attachments* GetAttachments()                   = 0;
    };
    struct IEntity : UTL::COM::IUnknown {
      virtual ~IEntity();
      virtual void                  AttachPhysics(ISimable*);
      virtual void                  DetachPhysics();
      virtual ISimable*             GetSimable();
      virtual const UMath::Vector3& GetPosition();
      virtual bool                  SetPosition(const UMath::Vector3& newPosition) = 0;
      virtual void                  Kill();
      virtual bool                  Attach(UTL::COM::IUnknown* object);
      virtual bool                  Detach(UTL::COM::IUnknown* object);
      virtual Attachments*          GetAttachments();
    };
    struct IServiceable {
      virtual bool OnService(HSIMSERVICE__* hCon, Packet* pkt) = 0;
    };
    struct ITaskable {
      virtual bool OnTask(HSIMTASK__* hTask, float deltaTime) = 0;
    };

    struct Object : IServiceable, ITaskable, UTL::COM::Object {
      std::uint8_t  _unk[0x4];
      std::uint32_t mTaskCount;
      std::uint32_t mServiceCount;

      virtual ~Object();
      virtual bool OnService(HSIMSERVICE__* p, Packet*) override;
      virtual bool OnTask(HSIMTASK__* hTask, float deltaTime) override;
    };

    struct Activity : Object, UTL::GarbageNode<Activity, 40>, IActivity, IAttachable {
      // std::uint8_t _unk[0x4];
      Attachments* mAttachments;

      virtual ~Activity();
#pragma region overrides
      virtual void         Release();
      virtual bool         Attach(UTL::COM::IUnknown* object) override;
      virtual bool         Detach(UTL::COM::IUnknown* object) override;
      virtual bool         IsAttached(UTL::COM::IUnknown* object) override;
      virtual void         OnAttached(IAttachable* pOther) override;
      virtual void         OnDetached(IAttachable* pOther) override;
      virtual Attachments* GetAttachments() override;
#pragma endregion
    };

    struct Entity : Object, UTL::GarbageNode<Entity, 12>, IEntity, IAttachable {
      ISimable*    mSimable;
      Attachments* mAttachments;

      virtual ~Entity();
    };

    struct Packet {
      virtual UCrc32        ConnectionClass() = 0;
      virtual std::uint32_t Compress(Packet*);
      virtual std::uint32_t Decompress(Packet*);
      virtual std::uint32_t Type() = 0;
      virtual std::uint32_t Size() = 0;
      virtual ~Packet();
    };

    struct Param {
      UCrc32       mType;
      void*        mData;
      std::uint8_t __pad[0x8];

      UCrc32 GetType() { return mType; }
      void*  GetData() { return &__pad + sizeof(__pad); }

      Param() : mData(this) {}
    };
  }  // namespace Sim

  struct SimSurface : Attrib::Gen::simsurface {};
}  // namespace OpenSpeed::ProStreet
