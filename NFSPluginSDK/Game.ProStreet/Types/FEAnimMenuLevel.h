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

#ifndef NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEANIMMENULEVEL_H
#define NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEANIMMENULEVEL_H
#pragma once

#include <NFSPluginSDK/Game.ProStreet/Types.h>
#include <NFSPluginSDK/Game.ProStreet/Types/bList.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FEObject.h>
#include <NFSPluginSDK/Game.ProStreet/Types/FETreeDataNode.h>

namespace NFSPluginSDK::ProStreet {
  struct FEAnimMenuLevel : bTNode<FEAnimMenuLevel> {
    bTList<FETreeDataNode> mDataNodes;
    FEAnimMenu*            mpMenu;
    const char*            mpPackageName;
    std::int32_t           mNumNodes;
    std::int32_t           mHighlightedIndex;
    FETreeDataNode*        mpHighlightedNode;

    virtual ~FEAnimMenuLevel();
    virtual void  NotificationMessage(std::uint_least32_t, FEObject*, std::uint_least32_t, std::uint_least32_t);
    virtual void  Enter(bool);
    virtual void  EnterPreview(std::int32_t, bool);
    virtual void  HidePreview();
    virtual void  Select();
    virtual void  Minimize(std::int32_t);
    virtual void  Transition();
    virtual float GetHighlightedValue();
    virtual void  HighlightCurNode();
    virtual void  ShowHighlighter();
    virtual void  SetNodeText(std::int32_t, const char*, FETreeDataNode*);
    virtual void  ShowPreviewRows(bool);
    virtual void  UnhighlightCurNode();
  };
}  // namespace NFSPluginSDK::ProStreet

#endif  // NFSPLUGINSDK_GAME_PROSTREET_TYPES_FEANIMMENULEVEL_H
