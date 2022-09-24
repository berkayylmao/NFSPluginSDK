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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_UNLOCKSYSTEM_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_UNLOCKSYSTEM_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/EA.h>

namespace NFSPluginSDK::ProStreet {
  struct UnlockSystem : EA::Memcard::IMemcardSavable {
    enum class eCategoryUnlockable : std::uint32_t {
      Vinyls,
      Paint,
      RimPaint,
      RideHeight,
    };
    enum class ePaintUnlockableLevel : std::uint32_t { Gloss, Metal, Pearl, Matte, Chrome, Iridescent, Candy };
    enum class eUnlockFilters : std::uint32_t { QuickRace = 1 << 0, Career = 1 << 1, Online = 1 << 2 };

    struct Unlockable {
      std::uint32_t mId;
      bool          mIsNew;
    };

    Unlockable*   mUnlockedUnlockables;
    std::uint32_t mUnlockableCount;
    std::uint32_t mUnlockedCarCount;
    std::uint32_t mUnlockedVisualCount;
    std::uint32_t mUnlockedPerfCount;

    static UnlockSystem* Get(std::size_t idx = 0) {
      static auto** spInstance = reinterpret_cast<UnlockSystem**>(0xAB0EC4);
      if (!spInstance) return nullptr;

      return *spInstance;
    }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_UNLOCKSYSTEM_H
