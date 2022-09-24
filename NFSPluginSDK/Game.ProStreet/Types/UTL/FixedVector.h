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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_UTL_FIXEDVECTOR_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_UTL_FIXEDVECTOR_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL/Vector.h>

namespace NFSPluginSDK::ProStreet::UTL {
  template <typename T, std::size_t nT, std::size_t VectorCapacity>
  struct FixedVector : Vector<T, VectorCapacity> {
    T mVectorSpace[nT];

    virtual ~FixedVector() {}
    virtual T*          AllocVectorSpace() { return mVectorSpace; }
    virtual void        FreeVectorSpace() { std::memset(mVectorSpace, 0, sizeof(T) * nT); }
    virtual std::size_t GetGrowSize() { return nT; }
    virtual std::size_t GetMaxCapacity() { return nT; }
    virtual void        OnGrowRequest() {}

    FixedVector() : Vector<T, nT>() { this->mBegin = mVectorSpace; }
  };
}  // namespace NFSPluginSDK::ProStreet::UTL

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_UTL_FIXEDVECTOR_H
