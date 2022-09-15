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

#pragma once
#include <functional>
#include <OpenSpeed/Game.ProStreet/Types.h>
#include <OpenSpeed/Game.ProStreet/Types/FEMinList.h>
#include <OpenSpeed/Game.ProStreet/Types/FEngFont.h>
#include <OpenSpeed/Game.ProStreet/Types/FERenderObject.h>
#include <OpenSpeed/Game.ProStreet/Types/FEScript.h>

namespace OpenSpeed::ProStreet {
  struct FEObject : FEMinNode {
    struct FEObjectCallback {
      std::function<bool(FEObject*)> fnCallback;

      virtual ~FEObjectCallback() = default;
      virtual bool Callback(FEObject* object) { return fnCallback(object); }

      FEObjectCallback(const std::function<bool(FEObject*)>& callback) : fnCallback(callback) {}
    };

    std::uint32_t   mGUID;
    std::uint32_t   mNameHash;
    char*           mpName;
    FEObjType       mType;
    FEObjFlags      mFlags;
    std::uint16_t   mRenderContext;
    std::uint16_t   mResourceIndex;
    std::uint32_t   mHandle;
    std::uint32_t   mUserParam;
    char*           mpData;
    std::uint32_t   mDataSize;
    FEMinList       mResponses;
    FEMinList       mScripts;
    FEScript*       mpCurrentScript;
    FERenderObject* mCached;

    FEngFont* FindFont() { return reinterpret_cast<FEngFont*(__cdecl*)(std::uint32_t)>(0x5A1530)(mHandle); }
    FEScript* FindScript(std::uint32_t scriptHash) {
      return reinterpret_cast<FEScript*(__thiscall*)(FEObject*, std::uint32_t)>(0x624F10)(this, scriptHash);
    }

    bool IsVisible() { return (mFlags & FEObjFlags::Hidden) != FEObjFlags::Hidden; }

    void SetScript(FEScript* script, bool reset) {
      if (script) reinterpret_cast<void(__thiscall*)(FEObject*, FEScript*, bool)>(0x629070)(this, script, reset);
    }

    static FEObject* FindObject(const char* fngName, std::uint32_t objectHash) {
      return reinterpret_cast<FEObject*(__cdecl*)(const char*, std::uint32_t)>(0x5BD520)(fngName, objectHash);
    }
    static FEObject* FindString(const char* fngName, std::uint32_t objectHash) {
      return reinterpret_cast<FEObject*(__cdecl*)(const char*, std::uint32_t)>(0x5BE5B0)(fngName, objectHash);
    }

    static void GetBottomRight(FEObject* object, float* x, float* y) {
      reinterpret_cast<void(__cdecl*)(FEObject*, float*, float*)>(0x5BDA80)(object, x, y);
    }
    static void GetCenter(FEObject* object, float* x, float* y) {
      reinterpret_cast<void(__cdecl*)(FEObject*, float*, float*)>(0x5BDCF0)(object, x, y);
    }
    static void GetSize(FEObject* object, float* x, float* y) {
      reinterpret_cast<void(__cdecl*)(FEObject*, float*, float*)>(0x5BDE70)(object, x, y);
    }
    static void GetTopLeft(FEObject* object, float* x, float* y) {
      reinterpret_cast<void(__cdecl*)(FEObject*, float*, float*)>(0x5BD670)(object, x, y);
    }

    static void SetCenter(FEObject* object, float x, float y) {
      reinterpret_cast<void(__cdecl*)(FEObject*, float, float)>(0x5B4980)(object, x, y);
    }
    static void SetScript(const char* fngName, std::uint32_t objectHash, std::uint32_t scriptHash, bool reset) {
      reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t, std::uint32_t, bool)>(0x5BD590)(fngName, objectHash,
                                                                                                  scriptHash, reset);
    }
    static void SetTopLeft(FEObject* object, float x, float y) {
      reinterpret_cast<void(__cdecl*)(FEObject*, float, float)>(0x5BD8F0)(object, x, y);
    }
    static void SetVisibility(FEObject* object, bool isVisible) {
      reinterpret_cast<void(__cdecl*)(FEObject*, bool)>(0x58DBE0)(object, isVisible);
    }
  };
}  // namespace OpenSpeed::ProStreet
