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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ICOPMGR_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ICOPMGR_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct ICopMgr : UTL::COM::IUnknown {
    virtual ~ICopMgr();

    virtual bool  VehicleSpawningEnabled(bool isDespawn)   = 0;
    virtual void  ResetCopsForRestart(bool release)        = 0;
    virtual void  SetAllBustedTimersToZero()               = 0;
    virtual void  PursuitIsEvaded(IPursuit* ipursuit)      = 0;
    virtual bool  IsCopRequestPending()                    = 0;
    virtual bool  IsCopSpawnPending()                      = 0;
    virtual void  SpawnCop(UMath::Vector3& initialPos, UMath::Vector3& initialVec, const char* vehicleName,
                           bool inPursuit, bool roadBlock) = 0;
    virtual bool  PlayerPursuitHasCop()                    = 0;
    virtual bool  CanPursueRacers()                        = 0;
    virtual bool  IsPlayerPursuitActive()                  = 0;
    virtual void  LockoutCops(bool lockout)                = 0;
    virtual void  NoNewPursuitsOrCops()                    = 0;
    virtual void  PursueAtHeatLevel(int minHeatLevel)      = 0;
    virtual float GetLockoutTimeRemaining()                = 0;
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ICOPMGR_H
