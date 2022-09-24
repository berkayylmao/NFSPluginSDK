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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_SIM_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_SIM_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/IAttachable.h>
#include <NFSPluginSDK/Game.MW05/Types/UCrc32.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/simsurface.h>

namespace NFSPluginSDK::MW05 {
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
    struct IServiceable : UTL::COM::IUnknown {
      virtual ~IServiceable();
      virtual bool OnService(HSIMSERVICE__* hCon, Packet* pkt) = 0;
    };
    struct ITaskable : UTL::COM::IUnknown {
      virtual ~ITaskable();
      virtual bool OnTask(HSIMTASK__* hTask, float deltaTime) = 0;
    };

    struct Object : UTL::COM::Object, IServiceable, ITaskable {
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
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_SIM_H
