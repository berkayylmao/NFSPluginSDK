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

#ifndef EASTL_TUPLE_FWD_DECLS_H
#define EASTL_TUPLE_FWD_DECLS_H

#include <NFSPluginSDK/Core/EASTL/EASTL/internal/config.h>

#if EASTL_TUPLE_ENABLED

namespace eastl {
  template <typename... T>
  class tuple;

  template <typename Tuple>
  class tuple_size;

  template <size_t I, typename Tuple>
  class tuple_element;

  template <size_t I, typename Tuple>
  using tuple_element_t = typename tuple_element<I, Tuple>::type;

  // const typename for tuple_element_t, for when tuple or TupleImpl cannot itself be const
  template <size_t I, typename Tuple>
  using const_tuple_element_t =
      typename conditional<is_lvalue_reference<tuple_element_t<I, Tuple>>::value,
                           add_lvalue_reference_t<const remove_reference_t<tuple_element_t<I, Tuple>>>,
                           const tuple_element_t<I, Tuple>>::type;

  // get
  template <size_t I, typename... Ts_>
  tuple_element_t<I, tuple<Ts_...>>& get(tuple<Ts_...>& t);

  template <size_t I, typename... Ts_>
  const_tuple_element_t<I, tuple<Ts_...>>& get(const tuple<Ts_...>& t);

  template <size_t I, typename... Ts_>
  tuple_element_t<I, tuple<Ts_...>>&& get(tuple<Ts_...>&& t);

  template <typename T, typename... ts_>
  T& get(tuple<ts_...>& t);

  template <typename T, typename... ts_>
  const T& get(const tuple<ts_...>& t);

  template <typename T, typename... ts_>
  T&& get(tuple<ts_...>&& t);
}  // namespace eastl

#endif  // EASTL_VARIADIC_TEMPLATES_ENABLED

#endif  // EASTL_TUPLE_FWD_DECLS_H
