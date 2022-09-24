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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEPURSUIT_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEPURSUIT_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehiclePid.h>
#include <NFSPluginSDK/Game.MW05/Types/IPursuitAI.h>
#include <NFSPluginSDK/Game.MW05/Types/Timer.h>

namespace NFSPluginSDK::MW05 {
  struct AIVehiclePursuit : AIVehiclePid, IPursuitAI {
    bool           mInPursuit;
    bool           mBreaker;
    bool           mChicken;
    bool           mDamagedByPerp;
    SirenState     mSirenState;
    bool           mSirenInit;
    Timer          mT_siren[3];
    bool           mInFormation;
    bool           mInPosition;
    bool           mWithinEngagementRadius;
    UMath::Vector3 mPursuitOffset;
    UMath::Vector3 mInPositionOffset;
    UCrc32         mInPositionGoal;
    float          mTimeSinceTargetSeen;
    float          mVisibiltyTestTimer;
    UCrc32         mSupportGoal;

    virtual ~AIVehiclePursuit();
    virtual void UpdateSiren(float deltaTime);
#pragma region overrides
    virtual void                  Update(float deltaTime) override;
    virtual void                  ResetInternals() override;
    virtual void                  StartPatrol() override;
    virtual void                  StartRoadBlock() override;
    virtual void                  StartFlee() override;
    virtual void                  SetInPursuit(bool inPursuit) override;
    virtual bool                  GetInPursuit() override;
    virtual void                  StartPursuit(AITarget* target, ISimable* itargetSimable) override;
    virtual void                  DoInPositionGoal() override;
    virtual void                  EndPursuit() override;
    virtual AITarget*             GetPursuitTarget() override;
    virtual bool                  StartSupportGoal() override;
    virtual AITarget*             PursuitRequest() override;
    virtual void                  SetInFormation(bool inFormation) override;
    virtual bool                  GetInFormation() override;
    virtual void                  SetInPosition(bool inPosition) override;
    virtual bool                  GetInPosition() override;
    virtual void                  SetPursuitOffset(const UMath::Vector3& offset) override;
    virtual const UMath::Vector3& GetPursuitOffset() override;
    virtual void                  SetInPositionGoal(const UCrc32& ipg) override;
    virtual const UCrc32&         GetInPositionGoal() override;
    virtual void                  SetInPositionOffset(const UMath::Vector3& offset) override;
    virtual const UMath::Vector3& GetInPositionOffset() override;
    virtual void                  SetBreaker(bool breaker) override;
    virtual bool                  GetBreaker() override;
    virtual void                  SetChicken(bool chicken) override;
    virtual bool                  GetChicken() override;
    virtual void                  SetDamagedByPerp(bool damaged) override;
    virtual bool                  GetDamagedByPerp() override;
    virtual SirenState            GetSirenState() override;
    virtual float                 GetTimeSinceTargetSeen() override;
    virtual void                  ZeroTimeSinceTargetSeen() override;
    virtual bool                  CanSeeTarget(AITarget* target) override;
    virtual const UCrc32&         GetSupportGoal() override;
    virtual void                  SetSupportGoal(UCrc32 sg) override;
    virtual void                  SetWithinEngagementRadius() override;
    virtual bool                  WasWithinEngagementRadius() override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEPURSUIT_H
