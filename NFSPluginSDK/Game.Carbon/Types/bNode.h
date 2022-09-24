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

#ifndef NFSPLUGINSDK_GAME_CARBON_TYPES_BNODE_H
#define NFSPLUGINSDK_GAME_CARBON_TYPES_BNODE_H
#pragma once

#include <NFSPluginSDK/Game.Carbon/Types.h>

namespace NFSPluginSDK::Carbon {
  class bNode {
   protected:
    bNode* Next;
    bNode* Prev;

   public:
    auto* GetNext() { return Next; }
    auto* GetPrev() { return Prev; }
    auto* Remove() {
      if (this->Prev) this->Prev->Next = this->Next;
      if (this->Next) this->Next->Prev = this->Prev;
      return this;
    }
    auto* AddAfter(bNode* node) {
      node->Next = this->Next;
      node->Prev = this;
      this->Next = node;
      return this;
    }
    auto* AddBefore(bNode* node) {
      node->Prev = this->Prev;
      node->Next = this;
      this->Prev = node;
      return this;
    }

    bNode() = default;
    ~bNode() {
      Remove();
      // free(this);
    }
  };

  template <typename T>
  class bTNode {
   protected:
    bTNode<T>* Next;
    bTNode<T>* Prev;

   public:
    auto* GetNext() { return Next; }
    auto* GetPrev() { return Prev; }
    auto* Remove() {
      if (this->Prev) this->Prev->Next = this->Next;
      if (this->Next) this->Next->Prev = this->Prev;
      return this;
    }
    auto* AddAfter(T* node) {
      node->Next = this->Next;
      node->Prev = this;
      this->Next = node;
      return this;
    }
    auto* AddBefore(T* node) {
      node->Prev = this->Prev;
      node->Next = this;
      this->Prev = node;
      return this;
    }

    bTNode() = default;
    ~bTNode() {
      Remove();
      // free(this);
    }
  };

  struct bPNode : bTNode<bPNode> {
    void* Object;
  };
}  // namespace NFSPluginSDK::Carbon

#endif  // NFSPLUGINSDK_GAME_CARBON_TYPES_BNODE_H
