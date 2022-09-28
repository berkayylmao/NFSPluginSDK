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

#ifndef EASTL_INTRUSIVE_HASH_SET_H
#define EASTL_INTRUSIVE_HASH_SET_H

#include <NFSPluginSDK/Core/EASTL/EASTL/internal/config.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/internal/intrusive_hashtable.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/functional.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/utility.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
#pragma once  // Some compilers (e.g. VC++) benefit significantly from using this. We've measured 3-4% build speed
              // improvements in apps as a result.
#endif

namespace eastl {

  /// intrusive_hash_set
  ///
  /// Template parameters:
  ///     T               The type of object the set holds (a.k.a. value).
  ///     bucketCount     The number of buckets to use. Best if it's a prime number.
  ///     Hash            Hash function. See functional.h for examples of hash functions.
  ///     Equal           Equality testing predicate; tells if two elements are equal.
  ///
  template <typename T, size_t bucketCount, typename Hash = eastl::hash<T>, typename Equal = eastl::equal_to<T> >
  class intrusive_hash_set : public intrusive_hashtable<T, T, Hash, Equal, bucketCount, true, true> {
   public:
    typedef intrusive_hashtable<T, T, Hash, Equal, bucketCount, true, true> base_type;
    typedef intrusive_hash_set<T, bucketCount, Hash, Equal>                 this_type;

   public:
    explicit intrusive_hash_set(const Hash& h = Hash(), const Equal& eq = Equal()) : base_type(h, eq) {
      // Empty
    }

    // To consider: Is this feasible, given how initializer_list works by creating a temporary array? Even if it is
    // feasible, is it a good idea?
    // intrusive_hash_set(std::initializer_list<value_type> ilist);

  };  // intrusive_hash_set

  /// intrusive_hash_multiset
  ///
  /// Implements a intrusive_hash_multiset, which is the same thing as a intrusive_hash_set
  /// except that contained elements need not be unique. See the documentation
  /// for intrusive_hash_set for details.
  ///
  /// Template parameters:
  ///     T               The type of object the set holds (a.k.a. value).
  ///     bucketCount     The number of buckets to use. Best if it's a prime number.
  ///     Hash            Hash function. See functional.h for examples of hash functions.
  ///     Equal           Equality testing predicate; tells if two elements are equal.
  ///
  template <typename T, size_t bucketCount, typename Hash = eastl::hash<T>, typename Equal = eastl::equal_to<T> >
  class intrusive_hash_multiset : public intrusive_hashtable<T, T, Hash, Equal, bucketCount, true, false> {
   public:
    typedef intrusive_hashtable<T, T, Hash, Equal, bucketCount, true, false> base_type;
    typedef intrusive_hash_multiset<T, bucketCount, Hash, Equal>             this_type;

   public:
    explicit intrusive_hash_multiset(const Hash& h = Hash(), const Equal& eq = Equal()) : base_type(h, eq) {
      // Empty
    }

    // To consider: Is this feasible, given how initializer_list works by creating a temporary array? Even if it is
    // feasible, is it a good idea?
    // intrusive_hash_multiset(std::initializer_list<value_type> ilist);

  };  // intrusive_hash_multiset

}  // namespace eastl

#endif  // Header include guard
