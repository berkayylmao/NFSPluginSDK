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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALHUBCOMMANDS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALHUBCOMMANDS_H
#pragma once

#include <memory>  // unique_ptr
#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/DLCommandObject.h>

namespace NFSPluginSDK::ProStreet::DALHubCommands {
  struct GetScoresAndConditions : DLCommandObject {
    std::int32_t mScorePlayer1;
    std::int32_t mScorePlayer2;
    std::int32_t mWinCondition;
    std::int32_t mDominateCondition;

    virtual ~GetScoresAndConditions();
    virtual void Execute() override;

    static std::unique_ptr<GetScoresAndConditions> Construct() {
      auto dummy  = std::make_unique<uint8_t[]>(sizeof(GetScoresAndConditions));
      auto ret    = std::unique_ptr<GetScoresAndConditions>{reinterpret_cast<GetScoresAndConditions*>(dummy.release())};
      ret->mState = DLCommandObject::CommandState::WaitingToExecute;

      *reinterpret_cast<std::uintptr_t*>(ret.get()) = 0x96FC04;
      return ret;
    }
  };
}  // namespace NFSPluginSDK::ProStreet::DALHubCommands

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_DALHUBCOMMANDS_H
