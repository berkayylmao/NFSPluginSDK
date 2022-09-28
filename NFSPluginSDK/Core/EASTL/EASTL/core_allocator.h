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

#ifndef EASTL_CORE_ALLOCATOR_H
#define EASTL_CORE_ALLOCATOR_H

#if EASTL_CORE_ALLOCATOR_ENABLED

#include <coreallocator/icoreallocator.h>

namespace EA {
  namespace Allocator {
    /// EASTLCoreAllocatorImpl
    ///
    /// EASTL provides an out of the box implementation of the
    /// ICoreAllocator interface.  This is provided as a convenience for
    /// users who wish to provide ICoreAllocator implementations for EASTL to use.
    ///
    /// EASTL has a dependency on coreallocator so to provide an out of
    /// the box implementation for EASTLCoreAlloctor and EASTLCoreDeleter
    /// that can be used and tested.  Historically we could not test
    /// ICoreAllocator interface because we relied on the code being linked
    /// in user code.
    ///

    class EASTLCoreAllocatorImpl : public ICoreAllocator {
     public:
      virtual void* Alloc(size_t size, const char* name, unsigned int flags) {
        return ::operator new[](size, name, flags, 0, __FILE__, __LINE__);
      }

      virtual void* Alloc(size_t size, const char* name, unsigned int flags, unsigned int alignment,
                          unsigned int alignOffset = 0) {
        return ::operator new[](size, alignment, alignOffset, name, flags, 0, __FILE__, __LINE__);
      }

      virtual void Free(void* ptr, size_t size = 0) { ::operator delete(static_cast<char*>(ptr)); }

      virtual void* AllocDebug(size_t size, const DebugParams debugParams, unsigned int flags) {
        return Alloc(size, debugParams.mName, flags);
      }

      virtual void* AllocDebug(size_t size, const DebugParams debugParams, unsigned int flags, unsigned int align,
                               unsigned int alignOffset = 0) {
        return Alloc(size, debugParams.mName, flags, align, alignOffset);
      }

      static EASTLCoreAllocatorImpl* GetDefaultAllocator();
    };

    inline EASTLCoreAllocatorImpl* EASTLCoreAllocatorImpl::GetDefaultAllocator() {
      static EASTLCoreAllocatorImpl allocator;
      return &allocator;
    }
  }  // namespace Allocator
}  // namespace EA

#endif  // EASTL_CORE_ALLOCATOR_ENABLED
#endif  // EASTL_CORE_ALLOCATOR_H
