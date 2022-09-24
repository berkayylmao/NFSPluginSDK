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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_DYNAMICS_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_DYNAMICS_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05::Dynamics {
  namespace Collision {
    struct Geometry {
      UMath::Vector4 mPosition;
      UMath::Vector4 mNormal[3];
      UMath::Vector4 mExtent[3];
      UMath::Vector4 mCollision_point;
      UMath::Vector4 mCollision_normal;
      float          mDimension[3];
      std::uint16_t  mShape;
      std::uint16_t  mPenetratesOther;
      UMath::Vector3 mDelta;
      float          mOverlap;
    };
  }  // namespace Collision

  struct IEntity {
    virtual const UMath::Vector3& GetPosition()                                                = 0;
    virtual void                  SetPosition(const UMath::Vector3& newPosition)               = 0;
    virtual const UMath::Vector3& GetAngularVelocity()                                         = 0;
    virtual void                  SetAngularVelocity(const UMath::Vector3& newAngularVelocity) = 0;
    virtual const UMath::Vector3& GetLinearVelocity()                                          = 0;
    virtual void                  SetLinearVelocity(const UMath::Vector3& newLinearVelocity)   = 0;
    virtual const UMath::Matrix4& GetRotation()                                                = 0;
    virtual void                  SetRotation(const UMath::Matrix4& newRotation)               = 0;
    virtual const UMath::Vector4& GetOrientation()                                             = 0;
    virtual void                  SetOrientation(const UMath::Vector4& newOrientation)         = 0;
    virtual const UMath::Vector3& GetPrincipalInertia()                                        = 0;
    virtual float                 GetMass()                                                    = 0;
    virtual const UMath::Vector3& GetCenterOfGravity()                                         = 0;
    virtual bool                  IsImmobile()                                                 = 0;
  };
}  // namespace NFSPluginSDK::MW05::Dynamics

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_DYNAMICS_H
