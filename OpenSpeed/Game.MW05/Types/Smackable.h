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
#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/IDisposable.h>
#include <OpenSpeed/Game.MW05/Types/IExplodeable.h>
#include <OpenSpeed/Game.MW05/Types/IRenderable.h>
#include <OpenSpeed/Game.MW05/Types/PhysicsObject.h>
#include <OpenSpeed/Game.MW05/Types/SmackableParams.h>
#include <OpenSpeed/Game.MW05/Types/Attrib/Gen/smackable.h>

namespace OpenSpeed::MW05 {
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
}  // namespace OpenSpeed::MW05
