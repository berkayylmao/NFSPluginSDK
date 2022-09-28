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

#ifndef EASTL_ATOMIC_INTERNAL_ARCH_ARM_H
#define EASTL_ATOMIC_INTERNAL_ARCH_ARM_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


/**
 * NOTE: We use this mapping
 *
 * ARMv7 Mapping 'trailing sync;':
 *
 * Load Relaxed       : ldr
 * Load Acquire       : ldr; dmb ish
 * Load Seq_Cst       : ldr; dmb ish
 *
 * Store Relaxed      : str
 * Store Release      : dmb ish; str
 * Store Seq_Cst      : dmb ish; str; dmb ish
 *
 * Relaxed Fence      :
 * Acquire Fence      : dmb ish
 * Release Fence      : dmb ish
 * Acq_Rel Fence      : dmb ish
 * Seq_Cst Fence      : dmb ish
 */

/**
 * ARMv7 Mapping 'leading sync;';
 *
 * Load Relaxed       : ldr
 * Load Acquire       : ldr; dmb ish
 * Load Seq_Cst       : dmb ish; ldr; dmb ish
 *
 * Store Relaxed      : str
 * Store Release      : dmb ish; str
 * Store Seq_Cst      : dmb ish: str
 *
 * Relaxed Fence      :
 * Acquire Fence      : dmb ish
 * Release Fence      : dmb ish
 * Acq_Rel Fence      : dmb ish
 * Seq_Cst Fence      : dmb ish
 */

/**
 * NOTE:
 *
 * On ARM32/64, we use the 'trailing sync;' convention with the stricter load acquire that uses
 * a dmb instead of a control dependency + isb to ensure the IRIW litmus test is satisfied
 * as one reason. See EASTL/atomic.h for futher explanation and deep-dive.
 *
 * For ARMv8 we could move to use the new proper store release and load acquire, RCsc variant.
 * All ARMv7 approaches work on ARMv8 and this code path is only used on msvc which isn't used
 * heavily. Most of the ARM code will end up going thru clang or gcc since microsoft arm devices
 * aren't that abundant.
 */


/////////////////////////////////////////////////////////////////////////////////


#if defined(EA_COMPILER_MSVC)

	#if EA_PLATFORM_PTR_SIZE == 8
		#define EASTL_ARCH_ATOMIC_HAS_128BIT
	#endif

#endif


/////////////////////////////////////////////////////////////////////////////////


#include "arch_arm_load.h"
#include "arch_arm_store.h"

#include "arch_arm_memory_barrier.h"

#include "arch_arm_thread_fence.h"


#endif /* EASTL_ATOMIC_INTERNAL_ARCH_ARM_H */
