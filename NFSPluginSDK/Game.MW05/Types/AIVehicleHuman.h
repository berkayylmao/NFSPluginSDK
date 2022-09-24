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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHUMAN_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHUMAN_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/AIVehicleRacecar.h>
#include <NFSPluginSDK/Game.MW05/Types/IHumanAI.h>

namespace NFSPluginSDK::MW05 {
  struct AIVehicleHuman : AIVehicleRacecar, IHumanAI {
    bool           bAiControl;
    UMath::Vector3 vMomentPosition;
    float          fMomentRadius;
    bool           mWrongWay;

    virtual ~AIVehicleHuman();
#pragma region overrides
    virtual void                  Update(float deltaTime) override;
    virtual float                 GetSkill() override;
    virtual float                 GetCatchupCheat() override;
    virtual void                  ChangeDragLanes(bool left) override;
    virtual bool                  IsPlayerSteering() override;
    virtual bool                  GetAiControl() override;
    virtual void                  SetAiControl(bool ai_control) override;
    virtual void                  SetWorldMoment(const UMath::Vector3& position, float radius) override;
    virtual const UMath::Vector3& GetWorldMomentPosition() override;
    virtual float                 GetWorldMomentRadius() override;
    virtual void                  ClearWorldMoment() override;
    virtual bool                  IsFacingWrongWay() override;
#pragma endregion
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AIVEHICLEHUMAN_H
