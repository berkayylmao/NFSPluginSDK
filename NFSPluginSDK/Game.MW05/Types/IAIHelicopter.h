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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_IAIHELICOPTER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_IAIHELICOPTER_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct IAIHelicopter : UTL::COM::IUnknown {
    virtual ~IAIHelicopter();
    virtual float          GetDesiredHeightOverDest()                                                  = 0;
    virtual void           SetDesiredHeightOverDest(float height)                                      = 0;
    virtual void           SetLookAtPosition(UMath::Vector3 pos)                                       = 0;
    virtual UMath::Vector3 GetLookAtPosition()                                                         = 0;
    virtual void           SetDestinationVelocity(const UMath::Vector3& velocity)                      = 0;
    virtual void           SteerToNav(WRoadNav* road_nav, float height, float speed, bool bStopAtDest) = 0;
    virtual bool           StartPathToPoint(UMath::Vector3& point)                                     = 0;
    virtual bool           StrafeToDestIsSet()                                                         = 0;
    virtual void           SetStrafeToDest(bool strafe)                                                = 0;
    virtual bool           FilterHeliAltitude(UMath::Vector3& point)                                   = 0;
    virtual void           RestrictPointToRoadNet(UMath::Vector3& seekPosition)                        = 0;
    virtual void           SetFuelFull()                                                               = 0;
    virtual float          GetFuelTimeRemaining()                                                      = 0;
    virtual void           SetShadowScale(float scale)                                                 = 0;
    virtual float          GetShadowScale()                                                            = 0;
    virtual void           SetDustStormIntensity(float intensity)                                      = 0;
    virtual float          GetDustStormIntensity()                                                     = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x404060)(); }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_IAIHELICOPTER_H
