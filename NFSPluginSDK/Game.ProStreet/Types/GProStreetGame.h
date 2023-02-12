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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_GPROSTREETGAME_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_GPROSTREETGAME_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/map.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GDamageometer.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GHub.h>
#include <NFSPluginSDK/Game.ProStreet/Types/GHubSimHelper.h>
#include <NFSPluginSDK/Game.ProStreet/Types/IVehicleCache.h>
#include <NFSPluginSDK/Game.ProStreet/Types/ISelectionSet.h>
#include <NFSPluginSDK/Game.ProStreet/Types/UTL.h>

namespace NFSPluginSDK::ProStreet {
  struct GProStreetGame : UTL::COM::Object, IVehicleCache, GHubSimHelper, ISelectionSet {
    std::uint32_t                      mHubCount;
    eastl::map<std::uint32_t, GHub*>   mHubsSet;
    unsigned char                      _pad1[4];
    GHub*                              mHubs;
    GHub*                              mCurrentHub;
    GVault*                            mRegionVault;
    std::uint32_t                      mTierCount;
    GTier*                             mTiers;
    GTier*                             mCurrentTier;
    Attrib::Class*                     mGameplayClass;
    HSIMABLE__*                        mHubVehicles[2];
    std::uint32_t                      mHubVehicleFEHandles[2];
    std::uint32_t                      mEmergencyHubVehicleFEHandles[2];
    GDamageometer*                     mDamageometer;
    char                               mCustomKeys[5][10];
    std::uint32_t                      mCustomHubs[5];
    std::uint32_t                      mCustomPlayHub;
    /*LuaHubBinder**/ void*            mHubBinder;
    /*LuaTierBinder**/ void*           mTierBinder;
    /*LuaRaceParametersBinder**/ void* mRaceParametersBinder;
    std::uint32_t                      mGripTrackRecordCount;
    std::uint32_t                      mDragTrackRecordCount;
    std::uint32_t                      mDriftTrackRecordCount;
    std::uint32_t                      mSpeedTrackRecordCount;
    std::uint8_t                       mEliteOrgUnlockFlags;
    /*GProStreetRaceStats**/ void*     mProStreetStats;
    Hermes::_h_HHANDLER__*             mMsgNotifyVehicleDestroyed;
    // GDamageSaveData                  mDamageSaveData[10];

    virtual ~GProStreetGame();
    virtual const char*         GetCacheName() override;
    virtual eVehicleCacheResult OnQueryVehicleCache(const IVehicle*      removethis,
                                                    const IVehicleCache* whosasking) override;
    virtual void                OnRemovedVehicleCache(IVehicle* ivehicle) override;
    virtual void                CreateVehicle(std::int32_t, std::uint32_t, std::uint32_t) override;
    virtual void                WarpVehicle(std::int32_t, std::uint32_t) override;
    virtual void                DestroyVehicle(std::int32_t, bool) override;
    virtual void                SetPlayerVehicle(std::int32_t, std::uint32_t, std::uint32_t) override;
    virtual void GetEnabledSelectionSets(GPresentationController&, eastl::list<std::uint32_t>&, bool) override;

    GHub* GetHub(std::uint32_t collectionNameHash) {
      return reinterpret_cast<GHub*(__thiscall*)(GProStreetGame*, std::uint32_t)>(0x6741A0)(this, collectionNameHash);
    }
    GHub* GetCurrentHub() { return reinterpret_cast<GHub*(__thiscall*)(GProStreetGame*)>(0x861F50)(this); }

    static GProStreetGame* Get() { return reinterpret_cast<GProStreetGame*(__cdecl*)()>(0x408660)(); }
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_GPROSTREETGAME_H
