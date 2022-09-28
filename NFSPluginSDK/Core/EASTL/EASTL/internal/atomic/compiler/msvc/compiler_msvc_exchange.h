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

#ifndef EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_EXCHANGE_H
#define EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_EXCHANGE_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#define EASTL_MSVC_ATOMIC_EXCHANGE_8(type, ret, ptr, val, MemoryOrder)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_OP_N(char, _InterlockedExchange8, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_EXCHANGE_16(type, ret, ptr, val, MemoryOrder)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_OP_N(short, _InterlockedExchange16, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_EXCHANGE_32(type, ret, ptr, val, MemoryOrder)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_OP_N(long, _InterlockedExchange, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_EXCHANGE_64(type, ret, ptr, val, MemoryOrder)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_OP_N(__int64, _InterlockedExchange64, type, ret, ptr, val, MemoryOrder)

#define EASTL_MSVC_ATOMIC_EXCHANGE_128(type, ret, ptr, val, MemoryOrder) \
	{																	\
		bool cmpxchgRet;												\
		/* This is intentionally a non-atomic 128-bit load which may observe shearing. */ \
		/* Either we do not observe *(ptr) but then the cmpxchg will fail and the observed */ \
		/* atomic load will be returned. Or the non-atomic load got lucky and the cmpxchg succeeds */ \
		/* because the observed value equals the value in *(ptr) thus we optimistically do a non-atomic load. */ \
		ret = *(ptr);													\
		do																\
		{																\
			EA_PREPROCESSOR_JOIN(EA_PREPROCESSOR_JOIN(EASTL_ATOMIC_CMPXCHG_STRONG_, MemoryOrder), _128)(type, cmpxchgRet, ptr, &(ret), val); \
		} while (!cmpxchgRet);											\
	}


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_COMPILER_ATOMIC_EXCHANGE_*_N(type, type ret, type * ptr, type val)
//
#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELAXED_8(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_8(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELAXED_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_16(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELAXED_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_32(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELAXED_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_64(type, ret, ptr, val, RELAXED)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELAXED_128(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_128(type, ret, ptr, val, RELAXED)


#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQUIRE_8(type, ret, ptr, val) \
	EASTL_MSVC_ATOMIC_EXCHANGE_8(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQUIRE_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_16(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQUIRE_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_32(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQUIRE_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_64(type, ret, ptr, val, ACQUIRE)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQUIRE_128(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_128(type, ret, ptr, val, ACQUIRE)


#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELEASE_8(type, ret, ptr, val) \
	EASTL_MSVC_ATOMIC_EXCHANGE_8(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELEASE_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_16(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELEASE_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_32(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELEASE_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_64(type, ret, ptr, val, RELEASE)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_RELEASE_128(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_128(type, ret, ptr, val, RELEASE)


#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQ_REL_8(type, ret, ptr, val) \
	EASTL_MSVC_ATOMIC_EXCHANGE_8(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQ_REL_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_16(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQ_REL_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_32(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQ_REL_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_64(type, ret, ptr, val, ACQ_REL)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_ACQ_REL_128(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_128(type, ret, ptr, val, ACQ_REL)


#define EASTL_COMPILER_ATOMIC_EXCHANGE_SEQ_CST_8(type, ret, ptr, val) \
	EASTL_MSVC_ATOMIC_EXCHANGE_8(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_SEQ_CST_16(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_16(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_SEQ_CST_32(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_32(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_SEQ_CST_64(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_64(type, ret, ptr, val, SEQ_CST)

#define EASTL_COMPILER_ATOMIC_EXCHANGE_SEQ_CST_128(type, ret, ptr, val)	\
	EASTL_MSVC_ATOMIC_EXCHANGE_128(type, ret, ptr, val, SEQ_CST)


#endif /* EASTL_ATOMIC_INTERNAL_COMPILER_MSVC_EXCHANGE_H */
