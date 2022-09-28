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

#ifndef EASTL_ATOMIC_INTERNAL_ARCH_X86_FETCH_OR_H
#define EASTL_ATOMIC_INTERNAL_ARCH_X86_FETCH_OR_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_ARCH_ATOMIC_FETCH_OR_*_N(type, type ret, type * ptr, type val)
//
#if defined(EA_COMPILER_MSVC) && defined(EA_PROCESSOR_X86)


	#define EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED(ret, observed, val) \
		ret = ((observed) | (val))


	#define EASTL_ARCH_ATOMIC_FETCH_OR_RELAXED_64(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_64_IMPL(type, ret, ptr, val, RELAXED,		\
										 EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										 EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)

	#define EASTL_ARCH_ATOMIC_FETCH_OR_ACQUIRE_64(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_64_IMPL(type, ret, ptr, val, ACQUIRE,		\
										 EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										 EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)

	#define EASTL_ARCH_ATOMIC_FETCH_OR_RELEASE_64(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_64_IMPL(type, ret, ptr, val, RELEASE,		\
										 EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										 EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)

	#define EASTL_ARCH_ATOMIC_FETCH_OR_ACQ_REL_64(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_64_IMPL(type, ret, ptr, val, ACQ_REL,		\
										 EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										 EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)

	#define EASTL_ARCH_ATOMIC_FETCH_OR_SEQ_CST_64(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_64_IMPL(type, ret, ptr, val, SEQ_CST,		\
										 EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										 EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)


#endif


#if ((defined(__clang__) || defined(EA_COMPILER_GNUC)) && defined(EA_PROCESSOR_X86_64))


	#define EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED(ret, observed, val) \
		ret = ((observed) | (val))


	#define EASTL_ARCH_ATOMIC_FETCH_OR_RELAXED_128(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_128_IMPL(type, ret, ptr, val, RELAXED,		\
										  EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										  EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)

	#define EASTL_ARCH_ATOMIC_FETCH_OR_ACQUIRE_128(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_128_IMPL(type, ret, ptr, val, ACQUIRE,		\
										  EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										  EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)

	#define EASTL_ARCH_ATOMIC_FETCH_OR_RELEASE_128(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_128_IMPL(type, ret, ptr, val, RELEASE,		\
										  EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										  EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)

	#define EASTL_ARCH_ATOMIC_FETCH_OR_ACQ_REL_128(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_128_IMPL(type, ret, ptr, val, ACQ_REL,		\
										  EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										  EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)

	#define EASTL_ARCH_ATOMIC_FETCH_OR_SEQ_CST_128(type, ret, ptr, val)		\
		EASTL_ARCH_ATOMIC_X86_OP_128_IMPL(type, ret, ptr, val, SEQ_CST,		\
										  EASTL_ARCH_ATOMIC_X86_FETCH_OR_PRE_COMPUTE_DESIRED, \
										  EASTL_ARCH_ATOMIC_X86_NOP_POST_COMPUTE_RET)


#endif


#endif /* EASTL_ATOMIC_INTERNAL_ARCH_X86_FETCH_OR_H */
