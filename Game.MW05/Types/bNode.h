// clang-format off
//
//    Copyright (C) 2020 Berkay Yigit <berkaytgy@gmail.com>
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU Affero General Public License as published
//    by the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public License
//    along with this program. If not, see <https://www.gnu.org/licenses/>.
//
// clang-format on

#pragma once
#include <Game.MW05/Types.h>

namespace OpenSpeed::MW05 {
  class bNode {
   protected:
    bNode* Next;
    bNode* Prev;

   public:
    bNode* GetNext() { return Next; }
    bNode* GetPrev() { return Prev; }
    bNode* Remove() {
      if (this->Prev) this->Prev->Next = this->Next;
      if (this->Next) this->Next->Prev = this->Prev;
      return this;
    }
    bNode* AddAfter(bNode* node) {
      node->Next = this->Next;
      node->Prev = this;
      this->Next = node;
      return this;
    }
    bNode* AddBefore(bNode* node) {
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

  template <class T>
  struct bTNode : bNode {
    T* GetNext() { return Next; }
    T* GetPrev() { return Prev; }
    T* Remove() {
      if (this->Prev) this->Prev->Next = this->Next;
      if (this->Next) this->Next->Prev = this->Prev;
      return this;
    }
    T* AddAfter(T* node) {
      node->Next = this->Next;
      node->Prev = this;
      this->Next = node;
      return this;
    }
    T* AddBefore(T* node) {
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
}  // namespace OpenSpeed::MW05
