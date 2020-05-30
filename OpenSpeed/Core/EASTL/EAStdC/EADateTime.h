// BSD 3-Clause License, https://github.com/electronicarts/EASTL

#ifndef EASTDC_EADATETIME_H
#define EASTDC_EADATETIME_H

#include <chrono>

#define EASTDC_API

namespace EA {
  namespace StdC {

    inline EASTDC_API uint64_t GetTime() {
      using namespace std::chrono;
      nanoseconds ns = duration_cast<nanoseconds>(system_clock::now().time_since_epoch());
      return ns.count();
    }

  }  // namespace StdC
}  // namespace EA

#endif  // EASTDC_EADATETIME_H
