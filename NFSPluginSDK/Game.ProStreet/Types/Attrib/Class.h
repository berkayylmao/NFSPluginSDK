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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_CLASS_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_CLASS_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::Attrib {
  struct Class {
    std::uint32_t         mKey;
    Attrib::ClassPrivate* mPrivates;

    inline Collection* GetCollection(std::uint32_t key) {
      return reinterpret_cast<Collection*(__thiscall*)(Class*, std::uint32_t)>(0x52C820)(this, key);
    }
    inline std::uint32_t GetNumCollections() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x52B520)(this);
    }
    inline std::uint32_t GetFirstCollection() {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*)>(0x402BC0)(this);
    }
    inline std::uint32_t GetNextCollection(std::uint32_t key) {
      return reinterpret_cast<std::uint32_t(__thiscall*)(Class*, std::uint32_t)>(0x4F4390)(this, key);
    }
  };
}  // namespace NFSPluginSDK::ProStreet::Attrib

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_ATTRIB_CLASS_H
