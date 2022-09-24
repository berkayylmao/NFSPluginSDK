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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_BEHAVIOR_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_BEHAVIOR_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Sim.h>
#include <NFSPluginSDK/Game.MW05/Types/UCrc32.h>

namespace NFSPluginSDK::MW05 {
  struct Behavior : Sim::Object {
    struct Container {
      struct Elements : eastl::list<Behavior*> {};

      Elements _mElements;
    };

    bool           mPaused;
    PhysicsObject* mOwner;
    ISimable*      mIOwner;
    UCrc32         mMechanic;
    UCrc32         mSignature;
    std::int32_t   mPriority;
    HSIMPROFILE__* mProfile;

    virtual ~Behavior();
    virtual void         Reset() = 0;
    virtual std::int32_t GetPriority();
    virtual void         OnOwnerAttached(IAttachable* pOther);
    virtual void         OnOwnerDetached(IAttachable* pOther);
    virtual void         OnTaskSimulate(float deltaTime);
    virtual void         OnBehaviorChange(const UCrc32& mechanic);
    virtual void         OnPause();
    virtual void         OnUnPause();
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_BEHAVIOR_H
