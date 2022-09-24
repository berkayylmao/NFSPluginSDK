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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_IPERPETRATOR_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_IPERPETRATOR_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct IPerpetrator : UTL::COM::IUnknown {
    virtual ~IPerpetrator();

    virtual float                           GetHeat()                                                    = 0;
    virtual void                            SetHeat(float heat)                                          = 0;
    virtual Attrib::Gen::pursuitescalation* GetPursuitEscalationAttrib()                                 = 0;
    virtual Attrib::Gen::pursuitlevels*     GetPursuitLevelAttrib()                                      = 0;
    virtual Attrib::Gen::pursuitsupport*    GetPursuitSupportAttrib()                                    = 0;
    virtual void                            AddCostToState(std::int32_t cost)                            = 0;
    virtual std::int32_t                    GetCostToState()                                             = 0;
    virtual void                            SetCostToState(std::int32_t costToState)                     = 0;
    virtual bool                            IsRacing()                                                   = 0;
    virtual bool                            IsBeingPursued()                                             = 0;
    virtual bool                            IsHiddenFromCars()                                           = 0;
    virtual bool                            IsHiddenFromHelicopters()                                    = 0;
    virtual bool                            IsPartiallyHidden(float& howHidden)                          = 0;
    virtual void                            AddToPendingRepPointsFromCopDestruction(std::int32_t amount) = 0;
    virtual void                            AddToPendingRepPointsNormal(std::int32_t amount)             = 0;
    virtual std::int32_t                    GetPendingRepPointsNormal()                                  = 0;
    virtual std::int32_t                    GetPendingRepPointsFromCopDestruction()                      = 0;
    virtual void                            ClearPendingRepPoints()                                      = 0;
    virtual void                            SetRacerInfo(GRacerInfo* info)                               = 0;
    virtual GRacerInfo*                     GetRacerInfo()                                               = 0;
    virtual float                           GetLastTrafficHitTime()                                      = 0;
    virtual void                            Set911CallTime(float time)                                   = 0;
    virtual float                           Get911CallTime()                                             = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x4037E0)(); }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_IPERPETRATOR_H
