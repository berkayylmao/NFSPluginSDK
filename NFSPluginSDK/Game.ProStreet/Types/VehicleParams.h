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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_VEHICLEPARAMS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_VEHICLEPARAMS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Game.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Sim.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/pvehicle.h>

namespace NFSPluginSDK::ProStreet {
  struct VehicleParams : Sim::Param {
    DriverClass                 mDriverClass;
    Attrib::Gen::pvehicle       mAttributes;
    const UMath::Vector3*       mDirection;
    const UMath::Vector3*       mPosition;
    RideInfo*                   mRideInfo;
    IVehicleCache*              mVehicleCache;
    Physics::Info::Performance* mPerformanceMatch;
    eVehicleParamFlags          mFlags;

    explicit VehicleParams(DriverClass driverClass, const Attrib::Gen::pvehicle& attributes,
                           const UMath::Vector3& direction, const UMath::Vector3& position,
                           RideInfo*          pRideInfo = nullptr,
                           eVehicleParamFlags flags     = eVehicleParamFlags::SnapToGround |
                                                      eVehicleParamFlags::ComputePerformance,
                           IVehicleCache*              pVehicleCache     = nullptr,
                           Physics::Info::Performance* pPerformanceMatch = nullptr) :
        mDriverClass(driverClass),
        mAttributes(attributes),
        mDirection(&direction),
        mPosition(&position),
        mRideInfo(pRideInfo),
        mVehicleCache(pVehicleCache),
        mPerformanceMatch(pPerformanceMatch),
        mFlags(flags) {
      AddTypeName(this);
    }

    static void AddTypeName(VehicleParams* to) { to->mType = Game::stringhash32("VehicleParams"); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_VEHICLEPARAMS_H
