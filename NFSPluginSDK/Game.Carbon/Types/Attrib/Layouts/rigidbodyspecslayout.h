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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_LAYOUTS_RIGIDBODYSPECSLAYOUT_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_LAYOUTS_RIGIDBODYSPECSLAYOUT_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>
#include <NFSPluginSDK/Game.Carbon/Types/Attrib/Private.h>

namespace NFSPluginSDK::Carbon::Attrib::Layouts {
  struct rigidbodyspecslayout {
    Math::Vector4 COLLISION_BOX_PAD;
    Math::Vector4 DRAG;
    Math::Vector4 WORLD_MOMENT_SCALE;
    Math::Vector4 OBJ_MOMENT_SCALE;
    Math::Vector4 GROUND_ELASTICITY;
    Math::Vector4 OBJ_ELASTICITY;
    Math::Vector4 DRAG_ANGULAR;
    Math::Vector4 WALL_ELASTICITY;
    Math::Vector4 GROUND_MOMENT_SCALE;
    Math::Vector4 CG;
    StringKey     BASE_MATERIAL;
    StringKey     DEFAULT_COL_BOX;
    Private       _Array_OBJ_FRICTION;
    Math::Vector2 OBJ_FRICTION;
    Private       _Array_WALL_FRICTION;
    Math::Vector2 WALL_FRICTION;
    Private       _Array_GROUND_FRICTION;
    Math::Vector2 GROUND_FRICTION;
    float         NATURAL_ANGULAR_DAMPING;
    float         GRAVITY;
    bool          NO_GROUND_COLLISIONS;
    bool          NO_OBJ_COLLISIONS;
    bool          INSTANCE_COLLISIONS_3D;
    __declspec(align(4)) float SLEEP_VELOCITY;
    bool IMMOBILE_OBJECT_COLLISIONS;
    bool NO_WORLD_COLLISIONS;
  };
}  // namespace NFSPluginSDK::Carbon::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_ATTRIB_LAYOUTS_RIGIDBODYSPECSLAYOUT_H
