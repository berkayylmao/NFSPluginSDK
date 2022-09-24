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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_UTL_LISTSET_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_UTL_LISTSET_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL/List.h>

namespace NFSPluginSDK::MW05::UTL {
  template <typename T, std::size_t nT, typename E, std::size_t nE>
  struct _ListSet {
    List<T, nT> _buckets[nE];

    List<T, nT>&       operator[](std::size_t index) noexcept { return _buckets[index]; }
    const List<T, nT>& operator[](std::size_t index) const noexcept { return _buckets[index]; }
    List<T, nT>&       operator[](E index) noexcept { return _buckets[static_cast<std::size_t>(index)]; }
    const List<T, nT>& operator[](E index) const noexcept { return _buckets[static_cast<std::size_t>(index)]; }
  };
}  // namespace NFSPluginSDK::MW05::UTL

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_UTL_LISTSET_H
