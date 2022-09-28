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

#ifndef EASTL_INTEGER_SEQUENCE_H
#define EASTL_INTEGER_SEQUENCE_H

#include <NFSPluginSDK/Core/EASTL/EABase/config/eacompiler.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/internal/config.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/type_traits.h>

namespace eastl {

#if EASTL_VARIADIC_TEMPLATES_ENABLED && !defined(EA_COMPILER_NO_TEMPLATE_ALIASES)

  // integer_sequence
  template <typename T, T... Ints>
  class integer_sequence {
   public:
    typedef T value_type;
    static_assert(is_integral<T>::value, "eastl::integer_sequence can only be instantiated with an integral type");
    static EA_CONSTEXPR size_t size() EA_NOEXCEPT { return sizeof...(Ints); }
  };

  template <size_t N, typename IndexSeq>
  struct make_index_sequence_impl;

  template <size_t N, size_t... Is>
  struct make_index_sequence_impl<N, integer_sequence<size_t, Is...>> {
    typedef typename make_index_sequence_impl<N - 1, integer_sequence<size_t, N - 1, Is...>>::type type;
  };

  template <size_t... Is>
  struct make_index_sequence_impl<0, integer_sequence<size_t, Is...>> {
    typedef integer_sequence<size_t, Is...> type;
  };

  template <size_t... Is>
  using index_sequence = integer_sequence<size_t, Is...>;

  template <size_t N>
  using make_index_sequence = typename make_index_sequence_impl<N, integer_sequence<size_t>>::type;

  template <typename Target, typename Seq>
  struct integer_sequence_convert_impl;

  template <typename Target, size_t... Is>
  struct integer_sequence_convert_impl<Target, integer_sequence<size_t, Is...>> {
    typedef integer_sequence<Target, Is...> type;
  };

  template <typename T, size_t N>
  struct make_integer_sequence_impl {
    typedef typename integer_sequence_convert_impl<T, make_index_sequence<N>>::type type;
  };

  template <typename T, size_t N>
  using make_integer_sequence = typename make_integer_sequence_impl<T, N>::type;

  // Helper alias template that converts any type parameter pack into an index sequence of the same length
  template <typename... T>
  using index_sequence_for = make_index_sequence<sizeof...(T)>;

  namespace internal {

    template <typename T>
    struct integer_sequence_size_helper;

    template <typename T, T... Ints>
    struct integer_sequence_size_helper<eastl::integer_sequence<T, Ints...>>
        : public integral_constant<size_t, sizeof...(Ints)> {};

    template <typename T>
    struct integer_sequence_size : public integer_sequence_size_helper<eastl::remove_cv_t<T>> {};

    template <typename T>
    struct index_sequence_size : public integer_sequence_size_helper<eastl::remove_cv_t<T>> {};

    template <typename T>
    EASTL_CPP17_INLINE_VARIABLE EA_CONSTEXPR size_t integer_sequence_size_v = integer_sequence_size<T>::value;

    template <typename T>
    EASTL_CPP17_INLINE_VARIABLE EA_CONSTEXPR size_t index_sequence_size_v = index_sequence_size<T>::value;

  }  // namespace internal

#endif  // EASTL_VARIADIC_TEMPLATES_ENABLED

}  // namespace eastl

#endif  // EASTL_INTEGER_SEQUENCE_H
