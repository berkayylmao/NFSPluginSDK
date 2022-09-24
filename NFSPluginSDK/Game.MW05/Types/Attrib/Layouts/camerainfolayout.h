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

#ifndef NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_CAMERAINFOLAYOUT_H
#define NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_CAMERAINFOLAYOUT_H
#pragma once

#include <iterator>

#include <NFSPluginSDK/Game.MW05/Types.h>
#include <NFSPluginSDK/Game.MW05/Types/Attrib/Private.h>

namespace NFSPluginSDK::MW05::Attrib::Layouts {
  struct camerainfolayout {
    Private     _Array_STIFFNESS;
    float       STIFFNESS[2];
    Private     _Array_ANGLE;
    float       ANGLE[2];
    Private     _Array_LAG;
    float       LAG[2];
    Private     _Array_FOV;
    float       FOV[2];
    Private     _Array_HEIGHT;
    float       HEIGHT[2];
    Private     _Array_LATEOFFSET;
    float       LATEOFFSET[2];
    const char* CollectionName;
    Private     _Array_TILTING;
    bool        TILTING[2];
    Private     _Array_SELECTABLE;
    bool        SELECTABLE[2];

    void operator=(const camerainfolayout& rhs) {
      std::copy(std::cbegin(rhs.STIFFNESS), std::cend(rhs.STIFFNESS), std::begin(this->STIFFNESS));
      std::copy(std::cbegin(rhs.ANGLE), std::cend(rhs.ANGLE), std::begin(this->ANGLE));
      std::copy(std::cbegin(rhs.LAG), std::cend(rhs.LAG), std::begin(this->LAG));
      std::copy(std::cbegin(rhs.FOV), std::cend(rhs.FOV), std::begin(this->FOV));
      std::copy(std::cbegin(rhs.HEIGHT), std::cend(rhs.HEIGHT), std::begin(this->HEIGHT));
      std::copy(std::cbegin(rhs.LATEOFFSET), std::cend(rhs.LATEOFFSET), std::begin(this->LATEOFFSET));
      std::copy(std::cbegin(rhs.TILTING), std::cend(rhs.TILTING), std::begin(this->TILTING));
      std::copy(std::cbegin(rhs.SELECTABLE), std::cend(rhs.SELECTABLE), std::begin(this->SELECTABLE));
    }
  };
}  // namespace NFSPluginSDK::MW05::Attrib::Layouts

#endif  // NFSPLUGINSDK_GAME_MW05_TYPES_ATTRIB_LAYOUTS_CAMERAINFOLAYOUT_H
