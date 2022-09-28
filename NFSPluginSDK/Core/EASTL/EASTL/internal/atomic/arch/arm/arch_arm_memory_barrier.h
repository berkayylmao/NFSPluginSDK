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

#ifndef EASTL_ATOMIC_INTERNAL_ARCH_ARM_MEMORY_BARRIER_H
#define EASTL_ATOMIC_INTERNAL_ARCH_ARM_MEMORY_BARRIER_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#if defined(EA_COMPILER_MSVC) && !defined(EA_COMPILER_CLANG_CL)

	#if defined(EA_PROCESSOR_ARM32)

		#define EASTL_ARM_DMB_ISH _ARM_BARRIER_ISH

		#define EASTL_ARM_DMB_ISHST _ARM_BARRIER_ISHST

		#define EASTL_ARM_DMB_ISHLD _ARM_BARRIER_ISH

	#elif defined(EA_PROCESSOR_ARM64)

		#define EASTL_ARM_DMB_ISH _ARM64_BARRIER_ISH

		#define EASTL_ARM_DMB_ISHST _ARM64_BARRIER_ISHST

		#define EASTL_ARM_DMB_ISHLD _ARM64_BARRIER_ISHLD

	#endif


	/**
	 * NOTE:
	 *
	 * While it makes no sense for a hardware memory barrier to not imply a compiler barrier.
	 * MSVC docs do not explicitly state that, so better to be safe than sorry chasing down
	 * hard to find bugs due to the compiler deciding to reorder things.
	 */

	#define EASTL_ARCH_ATOMIC_ARM_EMIT_DMB(option)	\
		EASTL_ATOMIC_COMPILER_BARRIER();			\
		__dmb(option);								\
		EASTL_ATOMIC_COMPILER_BARRIER()


#elif defined(EA_COMPILER_GNUC) || defined(__clang__)

	#define EASTL_ARM_DMB_ISH ish

	#define EASTL_ARM_DMB_ISHST ishst

	#if defined(EA_PROCESSOR_ARM32)

		#define EASTL_ARM_DMB_ISHLD ish

	#elif defined(EA_PROCESSOR_ARM64)

		#define EASTL_ARM_DMB_ISHLD ishld

	#endif


	#define EASTL_ARCH_ATOMIC_ARM_EMIT_DMB(option)										\
		__asm__ __volatile__ ("dmb " EA_STRINGIFY(option) ::: "memory")


#endif


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_ARCH_ATOMIC_CPU_MB()
//
#define EASTL_ARCH_ATOMIC_CPU_MB()				\
	EASTL_ARCH_ATOMIC_ARM_EMIT_DMB(EASTL_ARM_DMB_ISH)


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_ARCH_ATOMIC_CPU_WMB()
//
#define EASTL_ARCH_ATOMIC_CPU_WMB()				\
	EASTL_ARCH_ATOMIC_ARM_EMIT_DMB(EASTL_ARM_DMB_ISHST)


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_ARCH_ATOMIC_CPU_RMB()
//
#define EASTL_ARCH_ATOMIC_CPU_RMB()				\
	EASTL_ARCH_ATOMIC_ARM_EMIT_DMB(EASTL_ARM_DMB_ISHLD)


#endif /* EASTL_ATOMIC_INTERNAL_ARCH_ARM_MEMORY_BARRIER_H */
