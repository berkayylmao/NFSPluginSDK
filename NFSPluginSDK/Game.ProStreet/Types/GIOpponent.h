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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GIOPPONENT_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GIOPPONENT_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct GIOpponent : UTL::COM::IUnknown {
    enum class DamageSeverity : std::uint32_t { None, Cosmetic, Light, Heavy, Totalled, _unk_5 };
    enum class Flags : std::uint32_t { LowResolution = 1 << 1 };
    enum class OpponentStatus : std::uint32_t { Free, Joining, Valid, Disconnected, Clean };
    enum class PerformanceLevel : std::uint32_t { Min, Current, Max };

    virtual ~GIOpponent();
    virtual std::uint32_t        Id()                                                   = 0;
    virtual void                 Prepare(Flags flags)                                   = 0;
    virtual void                 Cleanup()                                              = 0;
    virtual void                 Destroy()                                              = 0;
    virtual void                 DestroyFurther()                                       = 0;
    virtual const char*          GetOpponentName()                                      = 0;
    virtual const OpponentStatus GetStatus()                                            = 0;
    virtual void                 MarkValid()                                            = 0;
    virtual bool                 IsValid()                                              = 0;
    virtual ISimable*            GetSimable()                                           = 0;
    virtual const std::uint32_t  GetVehicleKey()                                        = 0;
    virtual float                GetPerformanceLevel(PerformanceLevel performanceLevel) = 0;
    virtual void                 StoreDamageData()                                      = 0;
    virtual void                 RestoreDamage()                                        = 0;
    virtual float                GetDamageLevel()                                       = 0;
    virtual void                 SetDamageLevel(float)                                  = 0;
    virtual float                GetInitialDamageLevel()                                = 0;
    virtual void                 SetInitialDamageLevel(float damageLevel)               = 0;
    virtual void                 RepairDamage()                                         = 0;
    virtual void                 RepairCareerDamage()                                   = 0;
    virtual void                 RepairEngineDamage()                                   = 0;
    virtual float                GetDynamicTargetTime()                                 = 0;
    virtual void                 SetDynamicTargetTime(float time)                       = 0;
    virtual DamageSeverity       GetDamageSeverity()                                    = 0;
    virtual std::int32_t         GetGridNumber()                                        = 0;
    virtual void                 SetGridNumber(std::int32_t gridNumber)                 = 0;
    virtual bool                 IsHidden()                                             = 0;
    virtual void                 SetHidden(bool hidden)                                 = 0;
    virtual void                 _unk_func1()                                           = 0;
    virtual void                 _unk_func2()                                           = 0;
    virtual std::int32_t         GetIndex()                                             = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*>(0x656340); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GIOPPONENT_H
