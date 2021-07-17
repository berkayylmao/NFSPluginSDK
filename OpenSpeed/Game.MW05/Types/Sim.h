// clang-format off
//
//    Copyright (C) 2021 Berkay Yigit <berkaytgy@gmail.com>
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

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Attrib.h>
#include <OpenSpeed/Game.MW05/Types/IAttachable.h>
#include <OpenSpeed/Game.MW05/Types/UCrc32.h>

namespace OpenSpeed::MW05 {
  namespace Sim {
    namespace Collision {
      struct IListener {
        virtual void OnCollision(const Info& cinfo);
      };
    }  // namespace Collision

    struct IEntity : UTL::COM::IUnknown {
      virtual ~IEntity();
      virtual void                       AttachPhysics(ISimable*);
      virtual void                       DetachPhysics();
      virtual ISimable*                  GetSimable();
      virtual const UMath::Vector3&      GetPosition();
      virtual bool                       SetPosition(const UMath::Vector3& newPosition) = 0;
      virtual void                       Kill();
      virtual bool                       Attach(UTL::COM::IUnknown* object);
      virtual bool                       Detach(UTL::COM::IUnknown* object);
      virtual eastl::list<IAttachable*>* GetAttachments();
    };
    struct IServiceable : UTL::COM::IUnknown {
      virtual ~IServiceable();
      virtual bool OnService(HSIMSERVICE__* p, Packet*) = 0;
    };
    struct ITaskable {
      virtual ~ITaskable();
      virtual bool OnTask(HSIMTASK__* p, float);
    };

    struct Object : UTL::COM::Object, IServiceable, ITaskable {
      std::uint32_t mTaskCount;
      std::uint32_t mServiceCount;

      virtual ~Object();
    };

    struct Entity : Object, UTL::GarbageNode<Entity>, IEntity, IAttachable {
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
      UCrc32       mName;
      void*        mData;
      std::uint8_t __pad[0x4];

      UCrc32 GetType() { return mType; }
      UCrc32 GetName() { return mName; }
      void*  GetData() { return &__pad + sizeof(__pad); }

      Param(UCrc32 hash) : mName(hash), mData(this) {}
    };
  }  // namespace Sim

  struct SimSurface : Attrib::Gen::simsurface {};
}  // namespace OpenSpeed::MW05
