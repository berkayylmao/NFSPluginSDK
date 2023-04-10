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

    struct MemcardChunk {
      std::uint32_t ID;
      std::int32_t  Size;
      bool          isNestedChunk;
    };
    struct MemcardEntry {
      char          mFilename[31];
      std::int32_t  mSaveType;
      unsigned char __date[16];
      char          mSubTitle[128];
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

    struct MemcardSavableImpl {
      eastl::vector<IMemcardSavable*>* mpSavables;

      virtual ~MemcardSavableImpl();
      virtual std::uint32_t GetHeaderSize();
      virtual std::uint32_t GetSaveSize();
      virtual eSaveType     GetSaveType();
    };

    struct MemcardCareerHeader : IMemcardHeader {
      std::int32_t mPercentComplete;
      char         mLocation[64];
    };
    struct MemcardCareer : IMemcardFile, MemcardSavableImpl {
      MemcardCareerHeader* mpHeader;
      char                 mPostfix[32];
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
