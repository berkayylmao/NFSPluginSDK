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

#ifndef EASTL_ATOMIC_INTERNAL_MACROS_H
#define EASTL_ATOMIC_INTERNAL_MACROS_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


/////////////////////////////////////////////////////////////////////////////////
//
// The reason for the implementation separating out into a compiler and architecture
// folder is as follows.
//
// The compiler directory is meant to implement atomics using the compiler provided
// intrinsics. This also implies that usually the same compiler instrinsic implementation
// can be used for any architecture the compiler supports. If a compiler provides intrinsics
// to support barriers or atomic operations, then that implementation should be in the
// compiler directory.
//
// The arch directory is meant to manually implement atomics for a specific architecture
// such as power or x86. There may be some compiler specific code in this directory because
// GCC inline assembly syntax may be different than another compiler as an example.
//
// The arch directory can also be used to implement some atomic operations ourselves
// if we deem the compiler provided implementation to be inefficient for the given
// architecture or we need to do some things manually for a given compiler.
//
// The atomic_macros directory implements the macros that the rest of the atomic
// library uses. These macros will expand to either the compiler or arch implemented
// macro. The arch implemented macro is given priority over the compiler implemented
// macro if both are implemented otherwise whichever is implemented is chosen or
// an error is emitted if none are implemented.
//
// The implementation being all macros has a couple nice side effects as well.
//
// 1. All the implementation ends up funneling into one low level macro implementation
//    which makes it easy to verify correctness, reduce copy-paste errors and differences
//    in various platform implementations.
//
// 2. Allows for the implementation to be implemented efficiently on compilers that do not
//    directly implement the C++ memory model in their intrinsics such as msvc.
//
// 3. Allows for the implementation of atomics that may not be supported on the given platform,
//    such as 128-bit atomics on 32-bit platforms since the macros will only ever be expanded
//    on platforms that support said features. This makes implementing said features pretty easy
//    since we do not have to worry about complicated feature detection in the low level implementations.
//
// The macro implementation may asume that all passed in types are trivially constructible thus it is
// free to create local variables of the passed in types as it may please.
// It may also assume that all passed in types are trivially copyable as well.
// It cannot assume any passed in type is any given type thus is a specific type if needed, it must do an
// EASTL_ATOMIC_TYPE_PUN_CAST() to the required type.
//


#include "compiler/compiler.h"
#include "arch/arch.h"

#include "atomic_macros/atomic_macros.h"


#endif /* EASTL_ATOMIC_INTERNAL_MACROS_H */
