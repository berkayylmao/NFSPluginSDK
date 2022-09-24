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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_DAMAGESPECSLAYOUT_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_DAMAGESPECSLAYOUT_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05::Attrib::Layouts {
  struct damagespecslayout {
    struct DamageScaleRecord {
      float VisualScale;
      float HitPointScale;
    };

    DamageScaleRecord DZ_LFRONT;
    DamageScaleRecord DZ_FRONT;
    DamageScaleRecord DZ_BOTTOM;
    DamageScaleRecord DZ_LEFT;
    DamageScaleRecord DZ_RREAR;
    DamageScaleRecord DZ_LREAR;
    DamageScaleRecord DZ_RIGHT;
    DamageScaleRecord DZ_REAR;
    DamageScaleRecord DZ_TOP;
    DamageScaleRecord DZ_RFRONT;
    float             SHOCK_TIME;
    float             HP_THRESHOLD;
    float             SUPPRESS_DIST;
    float             SHOCK_FORCE;
    float             FORCE;
    float             HIT_POINTS;
  };
}  // namespace NFSPluginSDK::MW05::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_DAMAGESPECSLAYOUT_H
