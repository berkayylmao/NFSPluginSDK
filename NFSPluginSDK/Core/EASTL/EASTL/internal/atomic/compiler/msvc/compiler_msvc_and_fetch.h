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

#ifndef EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_AND_FETCH_H
#define EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_AND_FETCH_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#if defined(EA_PROCESSOR_X86_64)

	#define EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_8 _InterlockedAnd8_np
	#define EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_16 _InterlockedAnd16_np
	#define EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_32 _InterlockedAnd_np
	#define EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_64 _InterlockedAnd64_np

#else

	#define EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_8 _InterlockedAnd8
	#define EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_16 _InterlockedAnd16
	#define EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_32 _InterlockedAnd
	#define EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_64 _InterlockedAnd64

#endif


#define EASTL_MSVC_AND_FETCH_POST_INTRIN_COMPUTE(ret, val, andend)	\
	ret = (val) & (andend)

#define EASTL_MSVC_ATOMIC_AND_FETCH_N(integralType, andIntrinsic, type, ret, ptr, val, MemoryOrder) \
	EASTL_MSVC_ATOMIC_OP_FETCH_N(integralType, andIntrinsic, type, ret, ptr, val, MemoryOrder, \
								 EASTL_MSVC_NOP_PRE_INTRIN_COMPUTE, EASTL_MSVC_AND_FETCH_POST_INTRIN_COMPUTE)


#define EASTL_MSVC_ATOMIC_AND_FETCH_8(type, ret, ptr, val, MemoryOrder)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_N(char, EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_8, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_AND_FETCH_16(type, ret, ptr, val, MemoryOrder) \
	EASTL_MSVC_ATOMIC_AND_FETCH_N(short, EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_16, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_AND_FETCH_32(type, ret, ptr, val, MemoryOrder) \
	EASTL_MSVC_ATOMIC_AND_FETCH_N(long, EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_32, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_AND_FETCH_64(type, ret, ptr, val, MemoryOrder) \
	EASTL_MSVC_ATOMIC_AND_FETCH_N(__int64, EASTL_MSVC_ATOMIC_AND_FETCH_INTRIN_64, type, ret, ptr, val, MemoryOrder)


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_COMPILER_ATOMIC_AND_FETCH_*_N(type, type ret, type * ptr, type val)
//
#define EASTL_COMPILER_ATOMIC_AND_FETCH_RELAXED_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_8(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_RELAXED_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_16(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_RELAXED_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_32(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_RELAXED_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_64(type, ret, ptr, val, RELAXED)


#define EASTL_COMPILER_ATOMIC_AND_FETCH_ACQUIRE_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_8(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_ACQUIRE_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_16(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_ACQUIRE_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_32(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_ACQUIRE_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_64(type, ret, ptr, val, ACQUIRE)


#define EASTL_COMPILER_ATOMIC_AND_FETCH_RELEASE_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_8(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_RELEASE_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_16(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_RELEASE_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_32(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_RELEASE_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_64(type, ret, ptr, val, RELEASE)


#define EASTL_COMPILER_ATOMIC_AND_FETCH_ACQ_REL_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_8(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_ACQ_REL_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_16(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_ACQ_REL_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_32(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_ACQ_REL_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_64(type, ret, ptr, val, ACQ_REL)


#define EASTL_COMPILER_ATOMIC_AND_FETCH_SEQ_CST_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_8(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_SEQ_CST_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_16(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_SEQ_CST_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_32(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_AND_FETCH_SEQ_CST_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_AND_FETCH_64(type, ret, ptr, val, SEQ_CST)


#endif /* EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_AND_FETCH_H */
