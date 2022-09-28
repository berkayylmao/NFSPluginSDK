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

#ifndef EASTL_ATOMIC_INTERNAL_ATOMIC_MACROS_H
#define EASTL_ATOMIC_INTERNAL_ATOMIC_MACROS_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#include "atomic_macros_base.h"

#include "atomic_macros_fetch_add.h"
#include "atomic_macros_fetch_sub.h"

#include "atomic_macros_fetch_and.h"
#include "atomic_macros_fetch_xor.h"
#include "atomic_macros_fetch_or.h"

#include "atomic_macros_add_fetch.h"
#include "atomic_macros_sub_fetch.h"

#include "atomic_macros_and_fetch.h"
#include "atomic_macros_xor_fetch.h"
#include "atomic_macros_or_fetch.h"

#include "atomic_macros_exchange.h"

#include "atomic_macros_cmpxchg_weak.h"
#include "atomic_macros_cmpxchg_strong.h"

#include "atomic_macros_load.h"
#include "atomic_macros_store.h"

#include "atomic_macros_compiler_barrier.h"

#include "atomic_macros_cpu_pause.h"

#include "atomic_macros_memory_barrier.h"

#include "atomic_macros_signal_fence.h"

#include "atomic_macros_thread_fence.h"


/////////////////////////////////////////////////////////////////////////////////


#if defined(EASTL_COMPILER_ATOMIC_HAS_8BIT) || defined(EASTL_ARCH_ATOMIC_HAS_8BIT)

	#define EASTL_ATOMIC_HAS_8BIT

#endif


#if defined(EASTL_COMPILER_ATOMIC_HAS_16BIT) || defined(EASTL_ARCH_ATOMIC_HAS_16BIT)

	#define EASTL_ATOMIC_HAS_16BIT

#endif


#if defined(EASTL_COMPILER_ATOMIC_HAS_32BIT) || defined(EASTL_ARCH_ATOMIC_HAS_32BIT)

	#define EASTL_ATOMIC_HAS_32BIT

#endif


#if defined(EASTL_COMPILER_ATOMIC_HAS_64BIT) || defined(EASTL_ARCH_ATOMIC_HAS_64BIT)

	#define EASTL_ATOMIC_HAS_64BIT

#endif


#if defined(EASTL_COMPILER_ATOMIC_HAS_128BIT) || defined(EASTL_ARCH_ATOMIC_HAS_128BIT)

	#define EASTL_ATOMIC_HAS_128BIT

#endif


/////////////////////////////////////////////////////////////////////////////////


#if defined(EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_8)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_8 EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_8

#elif defined(EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_8)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_8 EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_8

#endif


#if defined(EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_16)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_16 EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_16

#elif defined(EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_16)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_16 EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_16

#endif


#if defined(EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_32)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_32 EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_32

#elif defined(EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_32)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_32 EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_32

#endif


#if defined(EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_64)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_64 EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_64

#elif defined(EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_64)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_64 EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_64

#endif


#if defined(EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_128)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_128 EASTL_ARCH_ATOMIC_FIXED_WIDTH_TYPE_128

#elif defined(EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_128)

	#define EASTL_ATOMIC_FIXED_WIDTH_TYPE_128 EASTL_COMPILER_ATOMIC_FIXED_WIDTH_TYPE_128

#endif


#endif /* EASTL_ATOMIC_INTERNAL_ATOMIC_MACROS_H */
