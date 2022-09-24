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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_LAYOUTS_PVEHICLELAYOUT_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_LAYOUTS_PVEHICLELAYOUT_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>

namespace NFSPluginSDK::Carbon::Attrib::Layouts {
  struct pvehiclelayout {
    enum class CarType : std::uint32_t {
      McLaren     = 1 << 0,
      Porsche     = 1 << 1,
      FordGT      = 1 << 2,
      Viper       = 1 << 3,
      AstonMartin = 1 << 4,
      Corvette    = 1 << 5,
      BMW         = 1 << 6,
      Mercedes    = 1 << 7,
      Audi        = 1 << 8,
      Mitsubishi  = 1 << 9,
      Mustang     = 1 << 10,
      Lotus       = 1 << 11,
      Subaru      = 1 << 12,
      Camaro      = 1 << 13,
      GTO         = 1 << 14,
      Nissan      = 1 << 15,
      Mazda       = 1 << 16,
      Renault     = 1 << 17,
      Lexus       = 1 << 18,
      Mini        = 1 << 19,
      Volkswagen  = 1 << 20,
      SUV         = 1 << 21,
      Pickup      = 1 << 22,
      Pagani      = 1 << 23,
      Lamborghini = 1 << 24,
      Chrysler    = 1 << 25,
      Opel        = 1 << 26,
      Sedan       = 1 << 27,
      SportsCar   = 1 << 28,
      Supra       = 1 << 29,
      Cadillac    = 1 << 30
    };

    UMath::Vector4 TENSOR_SCALE;
    StringKey      MODEL;
    const char*    DefaultPresetRide;
    const char*    CollectionName;
    std::int32_t   engine_upgrades;
    std::int32_t   transmission_upgrades;
    std::int32_t   nos_upgrades;
    std::int32_t   brakes_upgrades;
    float          MASS;
    std::int32_t   tires_upgrades;
    CarType        VerbalType;
    std::int32_t   induction_upgrades;
    std::int32_t   chassis_upgrades;
    std::uint8_t   HornType;
    std::uint8_t   TrafficEngType;
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(pvehiclelayout::CarType)
#endif
}  // namespace NFSPluginSDK::Carbon::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_LAYOUTS_PVEHICLELAYOUT_H
