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

///////////////////////////////////////////////////////////////////////////////
// The design for call_traits here is very similar to that found in template
// metaprogramming libraries such as Boost, GCC, and Metrowerks, given that
// these libraries have established this interface as a defacto standard for
// solving this problem. Also, these are described in various books on the
// topic of template metaprogramming, such as "Modern C++ Design".
//
// See http://www.boost.org/libs/utility/call_traits.htm or search for
// call_traits in Google for a description of call_traits.
///////////////////////////////////////////////////////////////////////////////

#ifndef EASTL_CALL_TRAITS_H
#define EASTL_CALL_TRAITS_H

#include <NFSPluginSDK/Core/EASTL/EASTL/internal/config.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/type_traits.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
#pragma once  // Some compilers (e.g. VC++) benefit significantly from using this. We've measured 3-4% build speed
              // improvements in apps as a result.
#endif

namespace eastl {

  template <typename T, bool small_>
  struct ct_imp2 {
    typedef const T& param_type;
  };

  template <typename T>
  struct ct_imp2<T, true> {
    typedef const T param_type;
  };

  template <typename T, bool isp, bool b1>
  struct ct_imp {
    typedef const T& param_type;
  };

  template <typename T, bool isp>
  struct ct_imp<T, isp, true> {
    typedef typename ct_imp2<T, sizeof(T) <= sizeof(void*)>::param_type param_type;
  };

  template <typename T, bool b1>
  struct ct_imp<T, true, b1> {
    typedef T const param_type;
  };

  template <typename T>
  struct call_traits {
   public:
    typedef T                                                                             value_type;
    typedef T&                                                                            reference;
    typedef const T&                                                                      const_reference;
    typedef typename ct_imp<T, is_pointer<T>::value, is_arithmetic<T>::value>::param_type param_type;
  };

  template <typename T>
  struct call_traits<T&> {
    typedef T&       value_type;
    typedef T&       reference;
    typedef const T& const_reference;
    typedef T&       param_type;
  };

  template <typename T, size_t N>
  struct call_traits<T[N]> {
   private:
    typedef T array_type[N];

   public:
    typedef const T*          value_type;
    typedef array_type&       reference;
    typedef const array_type& const_reference;
    typedef const T* const    param_type;
  };

  template <typename T, size_t N>
  struct call_traits<const T[N]> {
   private:
    typedef const T array_type[N];

   public:
    typedef const T*          value_type;
    typedef array_type&       reference;
    typedef const array_type& const_reference;
    typedef const T* const    param_type;
  };

}  // namespace eastl

#endif  // Header include guard
