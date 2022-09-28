// clang-format off
//
//  BSD 3-Clause License
//  
//  Copyright (c) 2019, Electronic Arts
//  All rights reserved.
//  
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are met:
//  
//  1. Redistributions of source code must retain the above copyright notice, this
//     list of conditions and the following disclaimer.
//  
//  2. Redistributions in binary form must reproduce the above copyright notice,
//     this list of conditions and the following disclaimer in the documentation
//     and/or other materials provided with the distribution.
//  
//  3. Neither the name of the copyright holder nor the names of its
//     contributors may be used to endorse or promote products derived from
//     this software without specific prior written permission.
//  
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
//  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
//  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
//  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
//  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
//  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
//  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
//  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
//  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// clang-format on

#ifndef EASTL_INITIALIZER_LIST_H
#define EASTL_INITIALIZER_LIST_H

#include <NFSPluginSDK/Core/EASTL/EASTL/internal/config.h>
#include <NFSPluginSDK/Core/EASTL/EABase/eahave.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
#pragma once  // Some compilers (e.g. VC++) benefit significantly from using this. We've measured 3-4% build speed
              // improvements in apps as a result.
#endif

#if defined(EA_HAVE_CPP11_INITIALIZER_LIST)  // If the compiler can generate calls to std::initializer_list...

// The initializer_list type must be declared in the std namespace, as that's the
// namespace the compiler uses when generating code to use it.
EA_DISABLE_ALL_VC_WARNINGS()
#include <initializer_list>
EA_RESTORE_ALL_VC_WARNINGS()

#else

// If you get an error here about initializer_list being already defined, then the EA_HAVE_CPP11_INITIALIZER_LIST define
// from <EABase/eahave.h> needs to be updated.
namespace std {
  // See the C++11 Standard, section 18.9.
  template <class E>
  class initializer_list {
   public:
    typedef E        value_type;
    typedef const E& reference;
    typedef const E& const_reference;
    typedef size_t   size_type;
    typedef const E* iterator;  // Must be const, as initializer_list (and its mpArray) is an immutable temp object.
    typedef const E* const_iterator;

   private:
    iterator  mpArray;
    size_type mArraySize;

    // This constructor is private, but the C++ compiler has the ability to call it, as per the C++11 Standard.
    initializer_list(const_iterator pArray, size_type arraySize) : mpArray(pArray), mArraySize(arraySize) {}

   public:
    initializer_list() EA_NOEXCEPT  // EA_NOEXCEPT requires a recent version of EABase.
        : mpArray(NULL),
          mArraySize(0) {}

    size_type      size() const EA_NOEXCEPT { return mArraySize; }
    const_iterator begin() const EA_NOEXCEPT {
      return mpArray;
    }  // Must be const_iterator, as initializer_list (and its mpArray) is an immutable temp object.
    const_iterator end() const EA_NOEXCEPT { return mpArray + mArraySize; }
  };

  template <class T>
  const T* begin(std::initializer_list<T> ilist) EA_NOEXCEPT {
    return ilist.begin();
  }

  template <class T>
  const T* end(std::initializer_list<T> ilist) EA_NOEXCEPT {
    return ilist.end();
  }
}  // namespace std

#endif

#endif  // Header include guard
