// BSD 3-Clause License, https://github.com/electronicarts/EASTL

#ifndef EASTDC_EASPRINTF_H
#define EASTDC_EASPRINTF_H

#include <OpenSpeed/Core/EASTL/EABase/eabase.h>
#include <OpenSpeed/Core/EASTL/EABase/eastdarg.h>
#include <cstdio>

#define EASTDC_API

namespace EA {
  namespace StdC {

    EASTDC_API int Vsnprintf(char8_t* EA_RESTRICT pDestination, size_t n, const char8_t* EA_RESTRICT pFormat,
                             va_list arguments);

#if defined(EA_CHAR16_NATIVE) && !defined(EA_COMPILER_MSVC_2012)
    EASTDC_API int Vsnprintf(char16_t* EA_RESTRICT pDestination, size_t n, const char16_t* EA_RESTRICT pFormat,
                             va_list arguments);
#endif

#if defined(EA_CHAR32_NATIVE)
    EASTDC_API int Vsnprintf(char32_t* EA_RESTRICT pDestination, size_t n, const char32_t* EA_RESTRICT pFormat,
                             va_list arguments);
#endif

#if defined(EA_WCHAR_UNIQUE)
    EASTDC_API int Vsnprintf(wchar_t* EA_RESTRICT pDestination, size_t n, const wchar_t* EA_RESTRICT pFormat,
                             va_list arguments);
#endif

    template <typename T>
    EASTDC_API int Sprintf(T* EA_RESTRICT pDestination, const T* EA_RESTRICT pFormat, ...) {
      va_list arguments;
      va_start(arguments, pFormat);

      auto result = std::vsprintf(pDestination, pFormat, arguments);

      va_end(arguments);

      return result;
    }

  }  // namespace StdC
}  // namespace EA

#endif  // EASTDC_EASPRINTF_H
