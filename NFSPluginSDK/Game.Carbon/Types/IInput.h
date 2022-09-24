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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_IINPUT_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_IINPUT_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/UTL.h>

namespace NFSPluginSDK::Carbon {
  struct IInput : UTL::COM::IUnknown {
    virtual ~IInput();
    virtual void  ClearInput()                       = 0;
    virtual float GetControlBrake()                  = 0;
    virtual float GetControlGas()                    = 0;
    virtual float GetControlSteering()               = 0;
    virtual float GetControlOverSteer()              = 0;
    virtual bool  GetControlNOS()                    = 0;
    virtual float GetControlHandBrake()              = 0;
    virtual float GetControlClutch()                 = 0;
    virtual void  SetControlSteering(float amount)   = 0;
    virtual void  SetControlOverSteer(float amount)  = 0;
    virtual void  SetControlGas(float amount)        = 0;
    virtual void  SetControlBrake(float amount)      = 0;
    virtual void  SetControlNOS(bool isPressed)      = 0;
    virtual void  SetControlHandBrake(float amount)  = 0;
    virtual void  SetControlClutch(float amount)     = 0;
    virtual bool  IsLookBackButtonPressed()          = 0;
    virtual bool  IsPullBackButtonPressed()          = 0;
    virtual bool  IsWingmanActivationButtonPressed() = 0;
    virtual bool  IsAutomaticShift()                 = 0;

    static IHandle* GetIHandle() { return reinterpret_cast<IHandle*(__cdecl*)()>(0x403AA0)(); }
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_IINPUT_H
