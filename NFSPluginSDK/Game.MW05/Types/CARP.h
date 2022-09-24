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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_CARP_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_CARP_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05::CARP {
  struct EventList {
    std::uint32_t fNumEvents;
    std::uint32_t fPad[3];
  };

  struct EventStaticData {
    std::uint32_t fEventID;
    std::uint32_t fEventSize;
    std::uint32_t fDataOffset;
    std::uint32_t fPad;
  };

  struct Trigger {
    UMath::Vector4 fMatRow0Width;
    TriggerTypes   fType : 4;
    std::uint32_t  fShape : 4;
    TriggerFlags   fFlags : 24;
    float          fHeight;
    EventList*     fEvents;
    std::uint16_t  fIterStamp;
    std::uint16_t  fFingerprint;
    UMath::Vector4 fMatRow2Length;
    UMath::Vector4 fPosRadius;
  };
}  // namespace NFSPluginSDK::MW05::CARP

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_CARP_H
