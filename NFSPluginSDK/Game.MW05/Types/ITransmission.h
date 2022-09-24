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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ITRANSMISSION_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ITRANSMISSION_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct ITransmission : UTL::COM::IUnknown {
    enum class GearID : std::uint32_t { Reverse, Neutral, First, Second, Third, Fourth, Fifth, Sixth, Seventh, Eighth };
    enum class ShiftPotential : std::uint32_t {
      None,
      Down,
      Up,
      Good,
      Perfect,
      Miss,
    };
    enum class ShiftStatus : std::uint32_t {
      None,
      Normal,
      Good,
      Perfect,
      Missed,
    };

    virtual ~ITransmission();
    virtual GearID         GetGear()                             = 0;
    virtual GearID         GetTopGear()                          = 0;
    virtual bool           Shift(GearID gear)                    = 0;
    virtual bool           IsGearChanging()                      = 0;
    virtual bool           IsReversing()                         = 0;
    virtual float          GetSpeedometer()                      = 0;
    virtual float          GetMaxSpeedometer()                   = 0;
    virtual float          GetDriveTorque()                      = 0;
    virtual float          GetOptimalShiftRange(GearID gear)     = 0;
    virtual float          GetShiftPoint(GearID from, GearID to) = 0;
    virtual ShiftStatus    GetShiftStatus()                      = 0;
    virtual ShiftPotential GetShiftPotential()                   = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x404010)(); }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ITRANSMISSION_H
