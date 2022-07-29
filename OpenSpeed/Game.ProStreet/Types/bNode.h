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
#include <OpenSpeed/Game.ProStreet/Types.h>

namespace OpenSpeed::ProStreet {
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
}  // namespace OpenSpeed::ProStreet
