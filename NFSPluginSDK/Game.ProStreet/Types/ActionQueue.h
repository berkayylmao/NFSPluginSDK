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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ACTIONQUEUE_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ACTIONQUEUE_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/controller.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ActionData.h>
#include <NFSPluginSDK/Game.ProStreet/Types/InputMapping.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Timer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL/CircularQueue.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL/Listable.h>

namespace NFSPluginSDK::ProStreet {
  struct ActionQueue : UTL::Listable<ActionQueue, 32>, UTL::Instanceable<HACTIONQUEUE__*, ActionQueue, 32> {
    enum class eState : std::uint32_t { Disabled, Enabled };

    UTL::CircularQueue<ActionData, 50> fQueue;
    std::int32_t                       mPort;
    eState                             mState;
    InputMapping*                      mMappings;
    Attrib::Gen::controller            mAttributes;
    const char*                        mQueueName;
    std::int32_t                       mUniqueID;
    bool                               mConnected;
    bool                               mRequired;
    Timer                              mActionTime;
    Timer                              mActivationTime;
    bool                               mDebouncing;
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ACTIONQUEUE_H
