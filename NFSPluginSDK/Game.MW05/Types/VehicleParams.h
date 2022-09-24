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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_VEHICLEPARAMS_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_VEHICLEPARAMS_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Sim.h>

namespace NFSPluginSDK::MW05 {
  struct VehicleParams : Sim::Param {
    DriverClass                 mDriverClass;
    std::uint32_t               mVehicleKey;
    const UMath::Vector3*       mDirection;
    const UMath::Vector3*       mPosition;
    FECustomizationRecord*      mCustomization;
    IVehicleCache*              mVehicleCache;
    Physics::Info::Performance* mPerformanceMatch;
    eVehicleParamFlags          mFlags;

    explicit VehicleParams(DriverClass driverClass, std::uint32_t vehicleKey, const UMath::Vector3& direction,
                           const UMath::Vector3& position, FECustomizationRecord* pFECR = nullptr,
                           eVehicleParamFlags flags = eVehicleParamFlags::SnapToGround |
                                                      eVehicleParamFlags::CalcPerformance,
                           IVehicleCache*              pVehicleCache     = nullptr,
                           Physics::Info::Performance* pPerformanceMatch = nullptr) :
        Sim::Param(0x0A6B47FAC),
        mDriverClass(driverClass),
        mVehicleKey(vehicleKey),
        mDirection(&direction),
        mPosition(&position),
        mCustomization(pFECR),
        mVehicleCache(pVehicleCache),
        mPerformanceMatch(pPerformanceMatch),
        mFlags(flags) {
      AddTypeName(this);
    }

    static void AddTypeName(VehicleParams* to) { reinterpret_cast<void(__cdecl*)(VehicleParams*)>(0x4040F0)(to); }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_VEHICLEPARAMS_H
