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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_AITARGET_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_AITARGET_H
#pragma once

#include <new>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/bNode.h>

namespace NFSPluginSDK::MW05 {
  struct AITarget : bTNode<AITarget> {
    ISimable*      mOwner;
    UMath::Vector3 mTargetPosition;
    ISimable*      mTargetSimable;
    UMath::Vector3 mTargetDirection;
    bool           mValid;
    UMath::Vector3 mDirTo;
    float          mDistTo;

    virtual ~AITarget();

    inline void Clear() { reinterpret_cast<void(__thiscall*)(AITarget*)>(0x409E60)(this); }
    inline void Acquire(ISimable* target) {
      reinterpret_cast<void(__thiscall*)(AITarget*, ISimable*)>(0x423860)(this, target);
    }
    inline void Register(ISimable* who) {
      reinterpret_cast<void(__thiscall*)(AITarget*, ISimable*)>(0x423750)(this, who);
    }
    inline void TrackInternal(ISimable* who) { reinterpret_cast<void(__thiscall*)(AITarget*)>(0x4180F0)(this); }

    /// <summary>
    /// Creates an AITarget object through game-code.
    /// </summary>
    /// <returns>A volatile pointer to a created <see cref="AITarget"/> object.</returns>
    static AITarget* Construct(ISimable* owner) {
      // A hacky way to create an object that we do not really have a control over
      AITarget* ret = reinterpret_cast<AITarget*>(::operator new(sizeof(AITarget), std::nothrow));
      if (!ret) return nullptr;

      reinterpret_cast<void(__thiscall*)(AITarget*, ISimable*)>(0x418000)(ret, owner);
      return ret;
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_AITARGET_H
