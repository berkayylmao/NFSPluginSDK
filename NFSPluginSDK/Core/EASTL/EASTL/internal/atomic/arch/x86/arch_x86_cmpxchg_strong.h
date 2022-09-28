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

#ifndef EASTL_ATOMIC_INTERNAL_ARCH_X86_CMPXCHG_STRONG_H
#define EASTL_ATOMIC_INTERNAL_ARCH_X86_CMPXCHG_STRONG_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_*_*_N(type, bool ret, type * ptr, type * expected, type desired)
//
#if ((defined(__clang__) || defined(EA_COMPILER_GNUC)) && defined(EA_PROCESSOR_X86_64))


	#define EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired) \
		{																	\
			/* Compare RDX:RAX with m128. If equal, set ZF and load RCX:RBX into m128. Else, clear ZF and load m128 into RDX:RAX. */ \
			__asm__ __volatile__ ("lock; cmpxchg16b %2\n" /* cmpxchg16b sets/clears ZF */ \
								  "sete %3" /* If ZF == 1, set the return value to 1 */ \
								  /* Output  Operands */					\
								  : "=a"((EASTL_ATOMIC_TYPE_CAST(uint64_t, (expected)))[0]), "=d"((EASTL_ATOMIC_TYPE_CAST(uint64_t, (expected)))[1]), \
									"+m"(*(EASTL_ATOMIC_VOLATILE_INTEGRAL_CAST(__uint128_t, (ptr)))), \
									"=rm"((ret))							\
								  /* Input Operands */						\
								  : "b"((EASTL_ATOMIC_TYPE_CAST(uint64_t, &(desired)))[0]), "c"((EASTL_ATOMIC_TYPE_CAST(uint64_t, &(desired)))[1]), \
									"a"((EASTL_ATOMIC_TYPE_CAST(uint64_t, (expected)))[0]), "d"((EASTL_ATOMIC_TYPE_CAST(uint64_t, (expected)))[1]) \
								  /* Clobbers */							\
								  : "memory", "cc");						\
		}


	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_RELAXED_RELAXED_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)

	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_ACQUIRE_RELAXED_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)

	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_ACQUIRE_ACQUIRE_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)

	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_RELEASE_RELAXED_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)

	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_ACQ_REL_RELAXED_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)

	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_ACQ_REL_ACQUIRE_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)

	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_SEQ_CST_RELAXED_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)

	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_SEQ_CST_ACQUIRE_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)

	#define EASTL_ARCH_ATOMIC_CMPXCHG_STRONG_SEQ_CST_SEQ_CST_128(type, ret, ptr, expected, desired) \
		EASTL_ARCH_ATOMIC_X86_CMPXCHG_STRONG_128_IMPL(type, ret, ptr, expected, desired)


#endif


#endif /* EASTL_ATOMIC_INTERNAL_ARCH_X86_CMPXCHG_STRONG_H */
