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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_SMACKABLE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_SMACKABLE_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/IDisposable.h>
#include <NFSPluginSDK/Game.MW05/Types/IExplodeable.h>
#include <NFSPluginSDK/Game.MW05/Types/IRenderable.h>
#include <NFSPluginSDK/Game.MW05/Types/PhysicsObject.h>
#include <NFSPluginSDK/Game.MW05/Types/SmackableParams.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Gen/smackable.h>

namespace NFSPluginSDK::MW05 {
  struct Smackable : PhysicsObject,
                     IDisposable,
                     IRenderable,
                     Sim::Collision::IListener,
                     IExplodeable,
                     EventSequencer::IContext {
    Attrib::Gen::smackable                        mAttributes;
    float                                         mSimplifyWeight;
    float                                         mAge;
    float                                         mLife;
    float                                         mDropTimer;
    const float                                   mDropOutTimerMax;
    float                                         mOffWorldTimer;
    const float                                   mAutoSimplify;
    const bool                                    mVirgin;
    IModel*                                       mModel;
    const CollisionGeometry::Bounds*              mGeometry;
    HSIMTASK__*                                   mManageTask;
    bool                                          mDroppingOut;
    bool                                          mPersistant;
    ICollisionBody*                               mCollisionBody;
    ISimpleBody*                                  mSimpleBody;
    UMath::Vector3                                mLastImpactSpeed;
    BehaviorSpecsPtr<Attrib::Gen::rigidbodyspecs> mRBSpecs;
    UMath::Vector4                                mLastCollisionPosition;

    virtual ~Smackable();
    virtual void OnDebugDraw();
#pragma region overrides
    virtual bool IsRequired() override;
#pragma endregion

    static Smackable* Construct(const SmackableParams& smackableParams) {
      ISimable* pSimable = reinterpret_cast<ISimable*(__cdecl*)(SmackableParams, UCrc32)>(0x6895A0)(
          smackableParams, smackableParams.mName);
      return static_cast<Smackable*>(pSimable);
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_SMACKABLE_H
