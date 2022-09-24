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
