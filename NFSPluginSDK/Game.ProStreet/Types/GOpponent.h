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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GOPPONENT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GOPPONENT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GIOpponent.h>

namespace NFSPluginSDK::ProStreet {
  struct GOpponent : GIOpponent, UTL::COM::Object {
    HSIMABLE__*    mHSimable;
    OpponentStatus mStatus;
    char           mOpponentName[32];
    std::uint32_t  mId;
    std::int32_t   mIndex;
    float          mDamageLevel;
    float          mInitialDamageLevel;
    float          mDynamicTargetTime;
    std::int32_t   mGridNum;
    bool           mHidden;
    void*          mDamageRestoreData;
    std::uint32_t  mDamageRestoreBufferSize;

    virtual ~GOpponent();
    virtual std::uint32_t        Id() override;
    virtual void                 Destroy() override;
    virtual void                 DestroyFurther() override;
    virtual const char*          GetOpponentName() override;
    virtual const OpponentStatus GetStatus() override;
    virtual void                 MarkValid() override;
    virtual bool                 IsValid() override;
    virtual ISimable*            GetSimable() override;
    virtual float                GetPerformanceLevel(PerformanceLevel performanceLevel) override;
    virtual void                 StoreDamageData() override;
    virtual void                 RestoreDamage() override;
    virtual float                GetDamageLevel() override;
    virtual void                 SetDamageLevel(float) override;
    virtual float                GetInitialDamageLevel() override;
    virtual void                 SetInitialDamageLevel(float damageLevel) override;
    virtual void                 RepairDamage() override;
    virtual void                 RepairCareerDamage() override;
    virtual void                 RepairEngineDamage() override;
    virtual float                GetDynamicTargetTime() override;
    virtual void                 SetDynamicTargetTime(float time) override;
    virtual DamageSeverity       GetDamageSeverity() override;
    virtual std::int32_t         GetGridNumber() override;
    virtual void                 SetGridNumber(std::int32_t gridNumber) override;
    virtual bool                 IsHidden() override;
    virtual void                 SetHidden(bool hidden) override;
    virtual void                 _unk_func1() override;
    virtual void                 _unk_func2() override;
    virtual std::int32_t         GetIndex() override;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GOPPONENT_H
