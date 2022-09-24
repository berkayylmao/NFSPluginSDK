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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_VAULT_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_VAULT_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>

namespace NFSPluginSDK::MW05::Attrib {
  struct Vault {
    std::uint32_t   mRefCount;
    ExportManager&  mExportMgr;
    DependencyNode* mDependencies;
    DataBlock*      mDepData;
    std::uint32_t*  mDepIDs;
    std::uint32_t   mNumDependencies;
    std::uint32_t   mResolvedCount;
    PointerNode*    mPointers;
    std::uint8_t*   mTransientData;
    ChunkBlock*     mStrings;
    ExportNode*     mExports;
    DataBlock*      mExportData;
    std::uint32_t*  mExportIDs;
    std::uint32_t   mNumExports;
    bool            mInited;
    bool            mDeinited;
  };
}  // namespace NFSPluginSDK::MW05::Attrib

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_VAULT_H
