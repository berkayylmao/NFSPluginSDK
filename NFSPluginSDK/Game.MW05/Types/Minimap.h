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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_MINIMAP_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_MINIMAP_H
#pragma once

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/HudElement.h>
#include <NFSPluginSDK/Game.MW05/Types/MinimapItem.h>

namespace NFSPluginSDK::MW05 {
  struct Minimap : HudElement {
    bTList<MiniMapItem> StaticMiniMapItems;
    FEObject*           TrackmapLayout;
    FEMultiImage*       TrackmapArt[4];
    FEVector2           TrackmapArtUVs[4][2];
    FEImage*            TrackmapNorth;
    FEImage*            mPlayerCarIndicator;
    FEImage*            mPlayerCarIndicator2;
    TrackInfo*          CurrentTrack;
    FEVector3           mMapDefaultPos;
    float               mSpeedZoomScale;
    float               mPolyRotation;
    bVector2            mTrackTargetNormalized;
    Math::Vector2       mTrackMapCentre;
    std::int32_t        mCopFlashCounter;
    bool                MinimapRotateWithPlayer;
    FEObject*           mHeliElementArt;
    FEObject*           mHeliLineOfSiteArt;
    FEImage*            mCopElementArt[8];
    FEImage*            mRacerElementArt[8];
    FEImage*            mCheckpointElementArt;
    FEImage*            mGPSSelectionElementArt;
    FEImage*            mGameplayIcons[17][8];
  };
}  // namespace NFSPluginSDK::MW05

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_MINIMAP_H
