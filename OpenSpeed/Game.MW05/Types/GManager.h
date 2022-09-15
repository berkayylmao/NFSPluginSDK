// clang-format off
//
//    Copyright (C) 2022 Berkay Yigit <mail@berkay.link>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#ifndef OPENSPEED_GAME_MW05_TYPES_GMANAGER_H
#define OPENSPEED_GAME_MW05_TYPES_GMANAGER_H
#pragma once

#include <OpenSpeed/Core/EASTL/EASTL/list.h>
#include <OpenSpeed/Core/EASTL/EASTL/map.h>
#include <OpenSpeed/Core/EASTL/EASTL/vector.h>

#include <OpenSpeed/Game.MW05/Types.h>
#include <OpenSpeed/Game.MW05/Types/Attrib.h>
#include <OpenSpeed/Game.MW05/Types/GEventTimer.h>
#include <OpenSpeed/Game.MW05/Types/GIcon.h>
#include <OpenSpeed/Game.MW05/Types/IVehicleCache.h>
#include <OpenSpeed/Game.MW05/Types/MilestoneTypeInfo.h>
#include <OpenSpeed/Game.MW05/Types/UTL.h>

namespace OpenSpeed::MW05 {
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
}  // namespace OpenSpeed::MW05

#endif  // OPENSPEED_GAME_MW05_TYPES_GMANAGER_H
