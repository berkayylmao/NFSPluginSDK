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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_GMANAGER_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_GMANAGER_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/list.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib.h>
#include <NFSPluginSDK/Game.MW05/Types/GEventTimer.h>
#include <NFSPluginSDK/Game.MW05/Types/GIcon.h>
#include <NFSPluginSDK/Game.MW05/Types/IVehicleCache.h>
#include <NFSPluginSDK/Game.MW05/Types/MilestoneTypeInfo.h>
#include <NFSPluginSDK/Game.MW05/Types/UTL.h>

namespace NFSPluginSDK::MW05 {
  struct GManager : UTL::COM::Object, IVehicleCache {
    struct HashEntry {
      std::uint32_t     mKey32;
      GRuntimeInstance* mInstance;
    };
    struct SavedGameplayDataHeader {
      std::uint32_t mChecksum[16];
      std::uint32_t mMagic;
      std::uint32_t mVersion;
      std::uint32_t mNumPersistent;
      std::uint32_t mNumSavedTimers;
      std::uint32_t mNumMilestoneTypes;
      std::uint32_t mNumMilestoneRecords;
      std::uint32_t mNumSpeedTrapRecords;
      std::uint32_t mNumUnlockedGates;
      std::uint32_t mNumHidingSpotFlags;
      std::uint32_t mNumBytesBinStats;
      std::uint32_t mNumPendingSMS;
    };

    const char*                                        mVaultPackFileName;
    bFile*                                             mVaultPackFile;
    std::uint32_t                                      mVaultCount;
    GVault*                                            mVaults;
    const char*                                        mVaultNameStrings;
    AttribVaultPackImage*                              mLoadingPackImage;
    std::uint32_t                                      mBinSlotSize;
    std::uint8_t*                                      mStreamedBinSlots;
    GVault*                                            mBinVaultInSlot[1];
    std::uint32_t                                      mRaceSlotSize;
    std::uint8_t*                                      mStreamedRaceSlots;
    GVault*                                            mRaceVaultInSlot[1];
    std::uint8_t*                                      mTempLoadData;
    std::int32_t                                       mTransientPoolNumber;
    void*                                              mTransientPoolMemory;
    Attrib::Class*                                     mGameplayClass;
    Attrib::Class*                                     mMilestoneClass;
    std::uint32_t                                      mAttributeKeyShiftTo24;
    std::uint32_t                                      mCollectionKeyShiftTo32;
    std::uint32_t                                      mMaxObjects;
    void*                                              mClassTempBuffer;
    std::uint32_t                                      mInstanceHashTableSize;
    std::uint32_t                                      mInstanceHashTableMask;
    std::uint32_t                                      mWorstHashCollision;
    HashEntry*                                         mKeyToInstanceMap;
    eastl::vector<GCharacter*>                         mActiveCharacters;
    eastl::map<std::uint32_t, ISimable*>               mStockCars;
    eastl::map<std::uint32_t, MilestoneTypeInfo>       mMilestoneTypeInfo;
    std::uint32_t                                      mNumMilestones;
    GMilestone*                                        mMilestones;
    std::uint32_t                                      mNumSpeedTraps;
    GSpeedTrap*                                        mSpeedTraps;
    std::uint32_t                                      mNumBountySpawnPoints;
    std::uint32_t                                      mBountySpawnPoint[20];
    std::uint32_t                                      mFreeRoamStartMarker;
    std::uint32_t                                      mFreeRoamFromSafeHouseStartMarker;
    bool                                               mStartFreeRoamFromSafeHouse;
    bool                                               mStartFreeRoamPursuit;
    float                                              mQueuedPursuitMinHeat;
    bool                                               mInGameplay;
    std::uint32_t                                      mOverrideFreeRoamStartMarker;
    std::uint8_t*                                      mObjectStateBuffer;
    std::uint8_t*                                      mObjectStateBufferFree;
    std::uint32_t                                      mObjectStateBufferSize;
    eastl::map<std::uint32_t, ObjectStateBlockHeader*> mPersistentStateBlocks;
    eastl::map<std::uint32_t, ObjectStateBlockHeader*> mSessionStateBlocks;
    GEventTimer                                        mTimers[8];
    std::uint32_t                                      mHidingSpotFound[16];
    eastl::list<std::int32_t>                          mPendingSMS;
    float                                              mLastCouldSendTime;
    bool                                               mWarping;
    bool                                               mWarpStartPursuit;
    std::uint32_t                                      mWarpTargetMarker;
    std::uint32_t                                      mNumIcons;
    std::uint32_t                                      mNumVisibleIcons;
    GIcon**                                            mIcons;
    bool                                               mPursuitBreakerIconsShown;
    bool                                               mHidingSpotIconsShown;
    bool                                               mEventIconsShown;
    bool                                               mMenuGateIconsShown;
    bool                                               mSpeedTrapIconsShown;
    bool                                               mSpeedTrapRaceIconsShown;
    bool                                               mAllowEngageEvents;
    bool                                               mAllowEngageSafehouse;
    bool                                               mAllowMenuGates;
    std::uint32_t                                      mRestartEventHash;

    inline GIcon* AllocIcon(GIcon::Type type, const Math::Vector3& initialPosition, float unk1 = 0.0f,
                            bool unk2 = true) {
      return reinterpret_cast<GIcon*(__thiscall*)(GManager*, GIcon::Type, const Math::Vector3&, float, bool)>(0x5E9EC0)(
          this, type, initialPosition, unk1, unk2);
    }
    inline void SpawnAllLoadedSectionIcons() { reinterpret_cast<void(__thiscall*)(GManager*)>(0x5EDE20)(this); }
    inline void UnspawnAllIcons() { reinterpret_cast<void(__thiscall*)(GManager*)>(0x5EA010)(this); }

    static inline GManager** g_mThis = reinterpret_cast<GManager**>(0x91E00C);
    static GManager*         Get() {
              if (!g_mThis) return nullptr;
      return *g_mThis;
    }
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_GMANAGER_H
