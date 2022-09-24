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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_GCHARACTER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_GCHARACTER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/GRuntimeInstance.h>
#include <NFSPluginSDK/Game.MW05/Types/IAttachable.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct GCharacter : GRuntimeInstance, UTL::COM::Object, IAttachable {
    enum class Flags : std::uint8_t { UsingStockCar, AttachedToManager };
    enum class State : std::uint8_t {
      Invalid,
      Unspawned,
      SpawningWaitingForModel,
      SpawningWaitingForTrack,
      Spawned,
      UnspawningWaitingUntilOffscreen
    };

    UMath::Vector3 mSpawnPos;
    State          mState;
    Flags          mFlags;
    std::uint16_t  mCreateAttemptsMade;
    UMath::Vector3 mSpawnDir;
    float          mSpawnSpeed;
    UMath::Vector3 mTargetPos;
    IVehicle*      mVehicle;
    UMath::Vector3 mTargetDir;
    Attachments*   mAttachments;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_GCHARACTER_H
