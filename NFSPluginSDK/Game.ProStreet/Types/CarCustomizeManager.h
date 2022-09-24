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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARCUSTOMIZEMANAGER_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARCUSTOMIZEMANAGER_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/stack.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Attrib/Gen/pvehicle.h>
#include <NFSPluginSDK/Game.ProStreet/Types/CurrentPartHelper.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FECarRecord.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ISelectablePart.h>
#include <NFSPluginSDK/Game.ProStreet/Types/Timer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/VinylCommand.h>

namespace NFSPluginSDK::ProStreet {
  struct CarCustomizeManager {
    CurrentPartHelper                                                mCurrentPartHelper;
    VinylCommandInvoker                                              mVinylInvoker;
    FECarRecord*                                                     TuningCar;
    BluePrintNumber                                                  mBluePrintNumber;
    Attrib::Gen::pvehicle                                            ThePVehicle;
    eastl::stack<ISelectablePart*, eastl::vector<ISelectablePart*> > mPreviewPartStack[4];
    Timer                                                            mPartLoadDelay;
    std::int32_t                                                     mCurrentEditingLayer;
    bool                                                             mDecal;

    static inline CarCustomizeManager* Get() { return reinterpret_cast<CarCustomizeManager*>(0xB32CE0); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_CARCUSTOMIZEMANAGER_H
