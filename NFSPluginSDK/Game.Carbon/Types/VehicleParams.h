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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_VEHICLEPARAMS_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_VEHICLEPARAMS_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/Sim.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Gen/pvehicle.h>

namespace NFSPluginSDK::Carbon {
  struct VehicleParams : Sim::Param {
    DriverClass                 mDriverClass;
    Attrib::Gen::pvehicle       mAttributes;
    const UMath::Vector3*       mDirection;
    const UMath::Vector3*       mPosition;
    VehicleCustomizations*      mCustomization;
    IVehicleCache*              mVehicleCache;
    Physics::Info::Performance* mPerformanceMatch;
    std::uint32_t               __unk_VehicleParams_1__;
    eVehicleParamFlags          mFlags;
    std::uint32_t               __unk_VehicleParams_2__;

    explicit VehicleParams(DriverClass driverClass, const Attrib::Gen::pvehicle& attributes,
                           const UMath::Vector3& direction, const UMath::Vector3& position,
                           VehicleCustomizations* pCustomizations = nullptr,
                           eVehicleParamFlags     flags           = eVehicleParamFlags::SnapToGround |
                                                      eVehicleParamFlags::CalcPerformance,
                           IVehicleCache*              pVehicleCache     = nullptr,
                           Physics::Info::Performance* pPerformanceMatch = nullptr) :
        mDriverClass(driverClass),
        mAttributes(attributes),
        mDirection(&direction),
        mPosition(&position),
        mCustomization(pCustomizations),
        mVehicleCache(pVehicleCache),
        mPerformanceMatch(pPerformanceMatch),
        mFlags(flags),
        __unk_VehicleParams_1__(0),
        __unk_VehicleParams_2__(0) {
      AddTypeName(this);
    }

    static void AddTypeName(VehicleParams* to) { reinterpret_cast<void(__cdecl*)(VehicleParams*)>(0x404820)(to); }
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_VEHICLEPARAMS_H
