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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_IPURSUITAI_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_IPURSUITAI_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL.h>

namespace NFSPluginSDK::Carbon {
  struct IPursuitAI : UTL::COM::IUnknown {
    virtual ~IPursuitAI();

    virtual void                  StartPatrol()                                            = 0;
    virtual void                  StartRoadBlock()                                         = 0;
    virtual void                  StartFlee()                                              = 0;
    virtual void                  SetInPursuit(bool inPursuit)                             = 0;
    virtual bool                  GetInPursuit()                                           = 0;
    virtual void                  StartPursuit(AITarget* target, ISimable* itargetSimable) = 0;
    virtual void                  DoInPositionGoal()                                       = 0;
    virtual void                  EndPursuit()                                             = 0;
    virtual AITarget*             GetPursuitTarget()                                       = 0;
    virtual bool                  StartSupportGoal()                                       = 0;
    virtual AITarget*             PursuitRequest()                                         = 0;
    virtual void                  SetInFormation(bool inFormation)                         = 0;
    virtual bool                  GetInFormation()                                         = 0;
    virtual void                  SetInPosition(bool inPosition)                           = 0;
    virtual bool                  GetInPosition()                                          = 0;
    virtual void                  SetInPositionGoal(const UCrc32& ipg)                     = 0;
    virtual const UCrc32&         GetInPositionGoal()                                      = 0;
    virtual void                  SetInPositionOffset(const UMath::Vector3& offset)        = 0;
    virtual const UMath::Vector3& GetInPositionOffset()                                    = 0;
    virtual void                  SetBreaker(bool breaker)                                 = 0;
    virtual bool                  GetBreaker()                                             = 0;
    virtual void                  SetDamagedByPerp(bool damaged)                           = 0;
    virtual bool                  GetDamagedByPerp()                                       = 0;
    virtual SirenState            GetSirenState()                                          = 0;
    virtual float                 GetTimeSinceTargetSeen()                                 = 0;
    virtual void                  ClearTimeSinceTargetSeen()                               = 0;
    virtual bool                  CanSeeTarget(AITarget* target)                           = 0;
    virtual const UCrc32&         GetSupportGoal()                                         = 0;
    virtual void                  SetSupportGoal(UCrc32 sg)                                = 0;
    virtual void                  SetWithinEngagementRadius()                              = 0;
    virtual bool                  WasWithinEngagementRadius()                              = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4055B0)(); }
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_IPURSUITAI_H
