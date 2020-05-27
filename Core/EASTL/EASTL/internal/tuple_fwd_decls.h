// BSD 3-Clause License, https://github.com/electronicarts/EASTL

#ifndef EASTL_TUPLE_FWD_DECLS_H
#define EASTL_TUPLE_FWD_DECLS_H

#include <Core/EASTL/EASTL/internal/config.h>

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
}  // namespace eastl

#endif  // EASTL_VARIADIC_TEMPLATES_ENABLED

#endif  // EASTL_TUPLE_FWD_DECLS_H
