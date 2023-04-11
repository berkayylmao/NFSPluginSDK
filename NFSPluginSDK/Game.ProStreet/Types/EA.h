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
//    SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS std::int32_tERRUPTION) HOWEVER
//    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//    OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//    OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//    You should have received a copy of the BSD 3-Clause License along with
//    this program. If not, see <https://opensource.org/licenses/BSD-3-Clause/>.
//
// clang-format on

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
#pragma once

#include <NFSPluginSDK/Core/EASTL/EASTL/vector.h>

#include <NFSPluginSDK/Game.ProStreet/Types.h>

namespace NFSPluginSDK::ProStreet::EA {
  namespace Localizer::LocalizerManager {
    static const char* const GetPackedString(std::uint32_t labelHash) {
      return reinterpret_cast<const char* const(__cdecl*)(std::uint32_t)>(0x5B8410)(labelHash);
    }
  }  // namespace Localizer::LocalizerManager

  namespace Memcard {
    enum class eSaveType : std::int32_t {
      SAVETYPE_NONE    = -1,
      SAVETYPE_ALL     = -1,
      SAVETYPE_PROFILE = 0,
      SAVETYPE_CAREER  = 1,
      SAVETYPE_SHADOW  = 2
    };
    using enum eSaveType;

    enum class OperationMode : std::uint32_t {
      OPERATION_DELETE  = 0x4F91333,
      OPERATION_LOAD    = 0x4F91334,
      OPERATION_SAVE    = 0x4F91335,
      OPEARTION_UNKNOWN = 0x4F91336
    };
    using enum OperationMode;

    struct MemcardChunk {
      std::uint32_t ID;
      std::int32_t  Size;
      bool          isNestedChunk;
    };
    struct MemcardEntry {
      // struct RealmcIface::DateTime
      struct DateTime {
        std::uint16_t mYear;
        std::uint16_t mMonth;
        std::uint16_t mDayOfWeek;
        std::uint16_t mDay;
        std::uint16_t mHour;
        std::uint16_t mMinute;
        std::uint16_t mSecond;
        std::uint16_t mMilliseconds;
      };

      char      mFilename[31];
      eSaveType mSaveType;
      DateTime  mTime;
      char      mSubTitle[128];
    };

    struct IMemcardHeader {
      std::int32_t  mBinaryDataSize;
      std::int32_t  mVersion;
      std::uint32_t mDataVersion;

      virtual ~IMemcardHeader();
      virtual void Default() = 0;
    };
    struct IMemcardFile {
      char*        mpDataBuffer;
      char*        mpHeaderBuffer;
      bool         mJustSaved;
      char*        mpUnalignedDataBuffer;
      char         mFilename[31];
      wchar_t      mwFilename[31];
      void*        mpSaveInfo;
      bool         mSavablesSorted;
      wchar_t      mwSaveTypeName[15];
      std::int32_t mSaveSlot;
      bool         mDontLoad;
      bool         mAutosaveOverwriteConfirmed;
      bool         mAutosaveEntryFound;
      bool         mLoaded;
      bool         mSaved;
      std::int32_t mNumEntriesFound;

      virtual ~IMemcardFile();
      virtual void            OnExitFlow() = 0;
      virtual void            OnFailed()   = 0;
      virtual const char*     GetSavePrefix();
      virtual const char*     GetSavePostFix();
      virtual const char*     GetSaveTypePrefix() = 0;
      virtual const char*     GetSavePrefixSeperator();
      virtual const wchar_t*  GetUnicodeSaveTypeName();
      virtual eSaveType       GetSaveType()        = 0;
      virtual std::int32_t    GetNumSavesForType() = 0;
      virtual bool            GetDataOk(std::int32_t headerSize, std::int32_t bodySize);
      virtual void*           CheckLoadedData(const char* data) = 0;
      virtual void            InitWSaveTypeName();
      virtual void            InitFilename(const char* fileName);
      virtual void            InitSaveInfo(void**) = 0;
      virtual void            InitSaveInfo()       = 0;
      virtual void            DeleteSaveInfo();
      virtual void            ResetToDefault()    = 0;
      virtual bool            CreateDataBuffers() = 0;
      virtual void            DeleteDataBuffers() = 0;
      virtual const char*     GetSaveTypeName()   = 0;
      virtual std::int32_t    GetFilenamePrefixLength();
      virtual void            SortEntries(eastl::vector<MemcardEntry*>* pEntries);
      virtual IMemcardHeader* GetHeader()     = 0;
      virtual void            DeleteHeader()  = 0;
      virtual std::uint32_t   GetHeaderSize() = 0;
      virtual std::uint32_t   GetSaveSize()   = 0;
      virtual const char*     GetNonPrefixFilename();
      virtual const wchar_t*  GetUnicodeNonPrefixFilename();
      virtual std::int32_t    GetSizeofWSaveTypeName();
      virtual void            InitWFilename();
      virtual void            CommonInitSaveInfo(void**);
      virtual void            InitPS3SaveInfo(void**);
      virtual void            InitX360SaveInfo(void**);
      virtual void            InitPS2SaveInfo(void**);
      virtual void            InitPCSaveInfo(void**);
      virtual void            InitWiiSaveInfo(void**);
    };
    struct IMemcardSavable {
      std::uint32_t mNameHash;
      MemcardChunk* mpChunk;
      void*         mpEndOfBuffer;
      void*         mpStartOfBuffer;
      std::uint32_t mSize;

      virtual ~IMemcardSavable();
      virtual void RegisterForSave(const char*, std::int32_t);
      virtual void SaveData(std::int32_t);
      virtual bool LoadData(std::int32_t);
      virtual void DefaultData(std::int32_t);
    };
    struct IFEMemcard {
      using BootupCheckResults = void*;
      using CardInfo           = void*;
      using EntryInfo          = void*;
      // RealmcIface::AutosaveState
      enum class AutosaveState : std::int32_t { DISABLE, ENABLE };
      // RealmcIface::CardStatus
      enum class CardStatus : std::int32_t {
        UNKNOWN            = -1,
        OK                 = 0,
        CARD_ERROR         = 1,
        ENTRY_CORRUPTED    = 2,
        ENTRY_NOT_FOUND    = 3,
        INSUFFICIENT_SPACE = 4,
        USER_NOT_SIGNED    = 5,
        CARD_CHANGED       = 6,
        NO_CARD            = 7,
        CARD_REMOVED       = 8
      };
      // RealmcIface::MonitorState
      enum class MonitorState : std::int32_t { OFF, ON };
      // RealmcIface::TaskResult
      enum class TaskResult : std::int32_t { SUCCESS, FAILED, CANCELLED, RETRY, UNKNOWN };

      virtual ~IFEMemcard();
      virtual void          OnAutosave()                                                           = 0;
      virtual const char*   GetProfileName()                                                       = 0;
      virtual const char*   GetCareerName()                                                        = 0;
      virtual const char*   GetWiiSecondBannerComment()                                            = 0;
      virtual const char*   MemcardGameTitleFull()                                                 = 0;
      virtual std::int32_t  GetSizeofGameTitleFull()                                               = 0;
      virtual const char*   MemcardGameTitleShort()                                                = 0;
      virtual std::int32_t  GetSizeofGameTitleShort()                                              = 0;
      virtual bool          NeedToShowAutosaveOverwriteMsg()                                       = 0;
      virtual bool          CanAutoSave()                                                          = 0;
      virtual void          OnShowMessage(const wchar_t*, std::uint32_t, const wchar_t**)          = 0;
      virtual void          OnClearMessage()                                                       = 0;
      virtual void          OnExitFlow()                                                           = 0;
      virtual void          OnBootupCheckDone(CardStatus, BootupCheckResults)                      = 0;
      virtual void          OnSaveCheckDone(TaskResult, CardStatus)                                = 0;
      virtual void          OnSaveDone(const char*)                                                = 0;
      virtual void          OnLoadReady(const char*, std::uint32_t, std::uint32_t, char**, char**) = 0;
      virtual void          OnCheckLoadedData(const char*)                                         = 0;
      virtual void          OnLoadDone(const char*)                                                = 0;
      virtual void          OnDeleteDone(const char*)                                              = 0;
      virtual void          OnFoundEntry(EntryInfo)                                                = 0;
      virtual void          OnFindEntriesDone(CardStatus)                                          = 0;
      virtual void          OnClearEntries()                                                       = 0;
      virtual void          OnRetry(CardStatus)                                                    = 0;
      virtual void          OnFailed(TaskResult, CardStatus)                                       = 0;
      virtual void          OnSetActiveCardDone(TaskResult, CardStatus)                            = 0;
      virtual void          OnSetAutosaveDone(TaskResult, CardStatus, AutosaveState)               = 0;
      virtual void          OnCardRemoved()                                                        = 0;
      virtual void          OnSetMonitorDone(CardStatus, MonitorState)                             = 0;
      virtual void          OnCardChanged(TaskResult, CardStatus)                                  = 0;
      virtual void          OnCardChecked(CardInfo)                                                = 0;
      virtual void          OnSignInComplete()                                                     = 0;
      virtual void          OnShowSystemUtility(bool)                                              = 0;
      virtual bool          IsFindingOldEntries()                                                  = 0;
      virtual const char*   GetFirstAutosaveWarning()                                              = 0;
      virtual const char*   GetSecondAutosaveWarning()                                             = 0;
      virtual const char*   GetConfirmAutosaveOverwrite()                                          = 0;
      virtual const char*   autosaveGetConfirmAutosaveOverwrite()                                  = 0;
      virtual IMemcardFile* GetIMemcardFile(std::int32_t)                                          = 0;
      virtual IMemcardFile* GetCurrentlyActiveProfile()                                            = 0;
      virtual IMemcardFile* GetCurrentlyActiveCareer()                                             = 0;
      virtual std::uint32_t GetNumSaveTypes()                                                      = 0;
      virtual std::uint32_t GetNumBootCheckSaveTypes()                                             = 0;
      virtual std::int32_t  GetSaveTypeFromEntryName(const char*)                                  = 0;
      virtual OperationMode GetCurrentOperation()                                                  = 0;
      virtual void          InitWSaveTypeNames()                                                   = 0;
      virtual std::uint32_t GetParentalLevel()                                                     = 0;
      virtual bool          IsAutoSaveEnabled()                                                    = 0;
      virtual bool          IsMemcardEnabled()                                                     = 0;
      virtual bool          IsMemcardVersioningEnabled()                                           = 0;
      virtual bool          IsMemCardBusy_DAL()                                                    = 0;
      virtual bool          IsMemCardEnabled_DAL()                                                 = 0;
      virtual bool          IsLogReplaying();
      virtual bool          IsCapturing();
      virtual void          OnUpdateLogReplay();
      virtual void          OnUpdateCapture();
    };

    struct MemcardSavableImpl {
      eastl::vector<IMemcardSavable*>* mpSavables;

      virtual ~MemcardSavableImpl();
      virtual std::uint32_t GetHeaderSize() = 0;
      virtual std::uint32_t GetSaveSize()   = 0;
      virtual eSaveType     GetSaveType()   = 0;
    };

    struct MemcardCareerHeader : IMemcardHeader {
      std::int32_t mPercentComplete;
      char         mLocation[64];
    };
    struct MemcardCareer : IMemcardFile, MemcardSavableImpl {
      MemcardCareerHeader* mpHeader;
      char                 mPostfix[32];
    };

    struct MemcardProfileHeader : IMemcardHeader {
      char  mProfileName[35];
      float mHeroPath;
      float mAntiHeroPath;
    };
    struct MemcardProfile : IMemcardFile, MemcardSavableImpl {
      MemcardProfileHeader* mpHeader;
    };

    struct MemcardShadowHeader : IMemcardHeader {
      std::uint32_t mEventHash;
      float         mScore;
      char          mCarName[64];
    };
    struct MemcardShadow : IMemcardFile {
      MemcardShadowHeader* mpHeader;
    };

    using GameplayBinarySavableHelper = IMemcardSavable;
    using RaceDataBinarySavableHelper = IMemcardSavable;
    using VehicleBinarySavableHelper  = IMemcardSavable;
    using MCStateManager              = void;

    struct NFSMemcardInterface : IFEMemcard {
      MemcardProfile*             mpProfile;
      MemcardShadow*              mpShadow;
      MemcardCareer*              mpCareer;
      MemcardProfileHeader*       mProfilesHeaders[1];
      MemcardCareerHeader*        mCareerHeaders[3];
      MCStateManager*             mpStateManagerInterface;
      GameplayBinarySavableHelper mGameplaySavable;
      RaceDataBinarySavableHelper mRaceDataSavable;
      VehicleBinarySavableHelper  mVehicleDBSavable;
      std::uint32_t               mShadowEventHash;
      bool                        mIsFindingOldEntries;
      bool                        mDidJustLoad;
      std::int32_t                mNumSaveFiles;

      virtual void            DefaultAllData();
      virtual MemcardShadow*  GetCurrentShadow();
      virtual MCStateManager* GetMCStateManager();
      virtual bool            GetDidJustLoad();
      virtual void            SetDidJustLoad(bool value);
      virtual void            TaskDone();

      static NFSMemcardInterface* Get() {
        static auto** spInstance = reinterpret_cast<NFSMemcardInterface**>(0xAB29B0);
        if (!spInstance) return nullptr;

        return *spInstance;
      }
    };
  }  // namespace Memcard
  namespace Thread {
    struct alignas(8) EAMutexData {
      std::uint8_t mData[32];
      std::int32_t mnLockCount;
      bool         mbIntraProcess;
      void*        mThreadId;
    };

    struct Mutex {
      EAMutexData mMutexData;
    };
  }  // namespace Thread
}  // namespace NFSPluginSDK::ProStreet::EA

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_EA_H
