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

#ifndef EASTL_ATOMIC_INTERNAL_ARCH_X86_MEMORY_BARRIER_H
#define EASTL_ATOMIC_INTERNAL_ARCH_X86_MEMORY_BARRIER_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif



/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_ARCH_ATOMIC_CPU_MB()
//
#if defined(EA_COMPILER_MSVC)

	/**
	 * NOTE:
	 * While it makes no sense for a hardware memory barrier to not imply a compiler barrier.
	 * MSVC docs do not explicitly state that, so better to be safe than sorry chasing down
	 * hard to find bugs due to the compiler deciding to reorder things.
	 */

	#if 1

		// 4459 : declaration of 'identifier' hides global declaration
		// 4456 : declaration of 'identifier' hides previous local declaration
		#define EASTL_ARCH_ATOMIC_CPU_MB()				\
			{											\
				EA_DISABLE_VC_WARNING(4459 4456);		\
				volatile long _;						\
				_InterlockedExchangeAdd(&_, 0);			\
				EA_RESTORE_VC_WARNING();				\
			}

	#else

		#define EASTL_ARCH_ATOMIC_CPU_MB()				\
			EASTL_ATOMIC_COMPILER_BARRIER();			\
			_mm_mfence();								\
			EASTL_ATOMIC_COMPILER_BARRIER()

	#endif

#elif defined(__clang__) || defined(EA_COMPILER_GNUC)

	/**
	* NOTE:
	*
	* mfence orders all loads/stores to/from all memory types.
	* We only care about ordinary cacheable memory so lighter weight locked instruction
	* is far faster than a mfence to get a full memory barrier.
	* lock; addl against the top of the stack is good because:
	*     distinct for every thread so prevents false sharing
	*     that cacheline is most likely cache hot
	*
	* We intentionally do it below the stack pointer to avoid false RAW register dependencies,
	* in cases where the compiler reads from the stack pointer after the lock; addl instruction
	*
	* Accounting for Red Zones or Cachelines doesn't provide extra benefit.
	*/

	#if defined(EA_PROCESSOR_X86)

		#define EASTL_ARCH_ATOMIC_CPU_MB()				\
			__asm__ __volatile__ ("lock; addl $0, -4(%%esp)" ::: "memory", "cc")

	#elif defined(EA_PROCESSOR_X86_64)

		#define EASTL_ARCH_ATOMIC_CPU_MB()				\
			__asm__ __volatile__ ("lock; addl $0, -8(%%rsp)" ::: "memory", "cc")

	#else

		#define EASTL_ARCH_ATOMIC_CPU_MB()				\
			__asm__ __volatile__ ("mfence" ::: "memory")

	#endif


#endif


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_ARCH_ATOMIC_CPU_WMB()
//
#define EASTL_ARCH_ATOMIC_CPU_WMB()				\
	EASTL_ATOMIC_COMPILER_BARRIER()


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_ARCH_ATOMIC_CPU_RMB()
//
#define EASTL_ARCH_ATOMIC_CPU_RMB()				\
	EASTL_ATOMIC_COMPILER_BARRIER()


#endif /* EASTL_ATOMIC_INTERNAL_ARCH_X86_MEMORY_BARRIER_H */
