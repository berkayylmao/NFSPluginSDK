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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ISIMPLEBODY_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ISIMPLEBODY_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct ISimpleBody : UTL::COM::IUnknown {
    enum class BodyFlags : std::uint16_t {
      None                   = 0,
      SkipSRBCollisions      = 1 << 0,
      SkipRBCollisions       = 1 << 1,
      SkipCollisions         = 3,
      ApplyBasicPhysics      = 1 << 2,
      LinearMotion           = 1 << 3,
      OBBCollideWith_RB      = 1 << 6,
      OBBCollideWith_SRB     = 1 << 7,
      CanHitTriggers         = 1 << 8,
      AngularMotion          = 1 << 9,
      SkipSameTypeCollisions = 1 << 14,
      SOBBCollideWith_RB     = 1 << 15,
    };

    virtual ~ISimpleBody();
    virtual void                   ModifyFlags(BodyFlags remove, BodyFlags add) = 0;
    virtual bool                   CanCollideWithSRB()                          = 0;
    virtual bool                   CanCollideWithRB()                           = 0;
    virtual bool                   CanHitTrigger()                              = 0;
    virtual const SimCollisionMap* GetCollisionMap() const                      = 0;
    virtual SimCollisionMap*       GetCollisionMap()                            = 0;
  };

#if defined(_WIN32)  // DEFINE_ENUM_FLAG_OPERATORS
  DEFINE_ENUM_FLAG_OPERATORS(ISimpleBody::BodyFlags)
#endif
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ISIMPLEBODY_H
