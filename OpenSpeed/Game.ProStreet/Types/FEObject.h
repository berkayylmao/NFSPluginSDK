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

    std::uint32_t   GUID;
    std::uint32_t   NameHash;
    char*           pName;
    FEObjType       Type;
    FEObjFlags      Flags;
    std::uint16_t   RenderContext;
    std::uint16_t   ResourceIndex;
    std::uint32_t   Handle;
    std::uint32_t   UserParam;
    char*           pData;
    std::uint32_t   DataSize;
    FEMinList       Responses;
    FEMinList       Scripts;
    FEScript*       pCurrentScript;
    FERenderObject* Cached;

    static FEObject* FindObject(const char* fngName, std::uint32_t objectHash) {
      return reinterpret_cast<FEObject*(__cdecl*)(const char*, std::uint32_t)>(0x5BD520)(fngName, objectHash);
    }

    static void SetScript(const char* fngName, std::uint32_t objectHash, std::uint32_t scriptHash, bool reset) {
      reinterpret_cast<void(__cdecl*)(const char*, std::uint32_t, std::uint32_t, bool)>(0x5BD590)(fngName, objectHash,
                                                                                                  scriptHash, reset);
    }
    static void SetVisibility(FEObject* object, bool isVisible) {
      reinterpret_cast<void(__cdecl*)(FEObject*, bool)>(0x58DBE0)(object, isVisible);
    }

    FEScript* FindScript(std::uint32_t scriptHash) {
      return reinterpret_cast<FEScript*(__thiscall*)(FEObject*, std::uint32_t)>(0x624F10)(this, scriptHash);
    }

    void SetScript(FEScript* script, bool reset) {
      if (script) reinterpret_cast<void(__thiscall*)(FEObject*, FEScript*, bool)>(0x629070)(this, script, reset);
    }
    void SetVisibility(bool isVisible) { SetVisibility(this, isVisible); }
  };
}  // namespace OpenSpeed::ProStreet
