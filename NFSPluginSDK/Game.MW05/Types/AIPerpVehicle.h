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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AIPERPVEHICLE_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AIPERPVEHICLE_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehiclePid.h>
#include <NFSPluginSDK/Game.MW05/Types/ICause.h>
#include <NFSPluginSDK/Game.MW05/Types/ICheater.h>
#include <NFSPluginSDK/Game.MW05/Types/IPerpetrator.h>

namespace NFSPluginSDK::MW05 {
  struct AIPerpVehicle : AIVehiclePid, IPerpetrator, ICause, ICheater {
    float                           mHeat;
    std::int32_t                    mCostToState;
    std::int32_t                    mPendingRepPointsNormal;
    std::int32_t                    mPendingRepPointsFromCopDestruction;
    bool                            mHiddenFromCars;
    bool                            mHiddenFromHelicopters;
    bool                            mWasInRaceEventLastHeatUpdate;
    float                           mHiddenZoneTimer;
    float                           mHiddenZoneLatchTime;
    bool                            mWasInZoneLastUpdate;
    std::int32_t                    mPursuitZoneCheck;
    Attrib::Gen::pursuitlevels*     mPursuitLevelAttrib;
    Attrib::Gen::pursuitsupport*    mPursuitSupportAttrib;
    Attrib::Gen::pursuitescalation* mPursuitEscalationAttrib;
    GRacerInfo*                     pRacerInfo;
    float                           fBaseSkill;
    float                           fGlueSkill;
    PidError*                       pGlueError;
    float                           fGlueTimer;
    float                           fGlueOutput;
    float                           LastTrafficHitTime;
    float                           m911CallTimer;

    virtual ~AIPerpVehicle();
#pragma region overrides
    virtual void                            Update(float deltaTime) override;
    virtual void                            OnClearCausality(float startTime) override;
    virtual void                            OnBehaviorChange(const UCrc32& mechanic) override;
    virtual float                           GetSkill() override;
    virtual float                           GetShortcutSkill() override;
    virtual float                           GetPercentRaceComplete() override;
    virtual float                           GetHeat() override;
    virtual void                            SetHeat(float heat) override;
    virtual Attrib::Gen::pursuitescalation* GetPursuitEscalationAttrib() override;
    virtual Attrib::Gen::pursuitlevels*     GetPursuitLevelAttrib() override;
    virtual Attrib::Gen::pursuitsupport*    GetPursuitSupportAttrib() override;
    virtual void                            AddCostToState(std::int32_t cost) override;
    virtual std::int32_t                    GetCostToState() override;
    virtual void                            SetCostToState(std::int32_t costToState) override;
    virtual bool                            IsRacing() override;
    virtual bool                            IsBeingPursued() override;
    virtual bool                            IsHiddenFromCars() override;
    virtual bool                            IsHiddenFromHelicopters() override;
    virtual bool                            IsPartiallyHidden(float& howHidden) override;
    virtual void                            AddToPendingRepPointsFromCopDestruction(std::int32_t amount) override;
    virtual void                            AddToPendingRepPointsNormal(std::int32_t amount) override;
    virtual std::int32_t                    GetPendingRepPointsNormal() override;
    virtual std::int32_t                    GetPendingRepPointsFromCopDestruction() override;
    virtual void                            ClearPendingRepPoints() override;
    virtual void                            SetRacerInfo(GRacerInfo* info) override;
    virtual GRacerInfo*                     GetRacerInfo() override;
    virtual float                           GetLastTrafficHitTime() override;
    virtual void                            Set911CallTime(float time) override;
    virtual float                           Get911CallTime() override;
    virtual void  OnCausedCollision(const Sim::Collision::Info& cInfo, ISimable* from, ISimable* to) override;
    virtual void  OnCausedExplosion(IExplosion* explosion, ISimable* to) override;
    virtual float GetCatchupCheat() override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AIPERPVEHICLE_H
