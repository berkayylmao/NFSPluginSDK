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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_FECUSTOMIZATIONRECORD_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_FECUSTOMIZATIONRECORD_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>

namespace NFSPluginSDK::Carbon {
  struct FECustomizationRecord {
    std::uint8_t __unk_FECustomizationRecord_1__[0x666];  // unksize

    inline void WriteRideIntoRecord(const RideInfo& rideInfo) {
      reinterpret_cast<void(__thiscall*)(FECustomizationRecord*, const RideInfo&)>(0x4C47F0)(this, rideInfo);
    }
    inline void WriteToGame(Attrib::StringKey collectionKey, VehicleCustomizations* out_VehicleParams) {
      reinterpret_cast<void(__thiscall*)(FECustomizationRecord*, Attrib::StringKey, VehicleCustomizations*)>(0x4BAD10)(
          this, collectionKey, out_VehicleParams);
    }
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_FECUSTOMIZATIONRECORD_H
