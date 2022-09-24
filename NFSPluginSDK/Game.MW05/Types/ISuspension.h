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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ISUSPENSION_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ISUSPENSION_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct ISuspension : UTL::COM::IUnknown {
    virtual ~ISuspension();
    virtual float                 GetWheelTraction(std::uint32_t idx)                              = 0;
    virtual std::uint32_t         GetNumWheels()                                                   = 0;
    virtual const UMath::Vector3& GetWheelPos(std::uint32_t idx)                                   = 0;
    virtual const UMath::Vector3& GetWheelLocalPos(std::uint32_t idx)                              = 0;
    virtual UMath::Vector3        GetWheelCenterPos(std::uint32_t idx)                             = 0;
    virtual float                 GetWheelLoad(std::uint32_t idx)                                  = 0;
    virtual void                  ApplyVehicleEntryForces(bool, const UMath::Vector3&, bool)       = 0;
    virtual const float           GetWheelRoadHeight(std::uint32_t idx)                            = 0;
    virtual bool                  IsWheelOnGround(std::uint32_t idx)                               = 0;
    virtual float                 GetCompression(std::uint32_t)                                    = 0;
    virtual float                 GuessCompression(std::uint32_t, float)                           = 0;
    virtual float                 GetWheelSlip(std::uint32_t idx)                                  = 0;
    virtual float                 GetToleratedSlip(std::uint32_t)                                  = 0;
    virtual float                 GetWheelSkid(std::uint32_t idx)                                  = 0;
    virtual float                 GetWheelSlipAngle(std::uint32_t idx)                             = 0;
    virtual const UMath::Vector4& GetWheelRoadNormal(std::uint32_t idx)                            = 0;
    virtual const SimSurface&     GetWheelRoadSurface(std::uint32_t idx)                           = 0;
    virtual const UMath::Vector3& GetWheelVelocity(std::uint32_t idx)                              = 0;
    virtual std::uint32_t         GetNumWheelsOnGround()                                           = 0;
    virtual float                 GetWheelAngularVelocity(std::int32_t idx)                        = 0;
    virtual void                  SetWheelAngularVelocity(std::int32_t idx, float angularVelocity) = 0;
    virtual float                 GetWheelSteer(std::uint32_t idx)                                 = 0;
    virtual float                 CalculateUndersteerFactor()                                      = 0;
    virtual float                 CalculateOversteerFactor()                                       = 0;
    virtual float                 GetRideHeight(std::uint32_t)                                     = 0;
    virtual float                 GetWheelRadius(std::uint32_t idx)                                = 0;
    virtual float                 GetMaxSteering()                                                 = 0;
    virtual void                  MatchSpeed(float speed)                                          = 0;
    virtual float                 GetRenderMotion()                                                = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x404040)(); }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ISUSPENSION_H
