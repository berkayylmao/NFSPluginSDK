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

#ifndef EASTL_ATOMIC_INTERNAL_COMPILER_GCC_LOAD_H
#define EASTL_ATOMIC_INTERNAL_COMPILER_GCC_LOAD_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#define EASTL_GCC_ATOMIC_LOAD_N(integralType, type, ret, ptr, gccMemoryOrder) \
	{																	\
		integralType retIntegral;										\
		__atomic_load(EASTL_ATOMIC_VOLATILE_INTEGRAL_CAST(integralType, (ptr)), &retIntegral, gccMemoryOrder); \
																		\
		ret = EASTL_ATOMIC_TYPE_PUN_CAST(type, retIntegral);			\
	}

#define EASTL_GCC_ATOMIC_LOAD_8(type, ret, ptr, gccMemoryOrder)			\
	EASTL_GCC_ATOMIC_LOAD_N(uint8_t, type, ret, ptr, gccMemoryOrder)

#define EASTL_GCC_ATOMIC_LOAD_16(type, ret, ptr, gccMemoryOrder)		\
	EASTL_GCC_ATOMIC_LOAD_N(uint16_t, type, ret, ptr, gccMemoryOrder)

#define EASTL_GCC_ATOMIC_LOAD_32(type, ret, ptr, gccMemoryOrder)		\
	EASTL_GCC_ATOMIC_LOAD_N(uint32_t, type, ret, ptr, gccMemoryOrder)

#define EASTL_GCC_ATOMIC_LOAD_64(type, ret, ptr, gccMemoryOrder)		\
	EASTL_GCC_ATOMIC_LOAD_N(uint64_t, type, ret, ptr, gccMemoryOrder)

#define EASTL_GCC_ATOMIC_LOAD_128(type, ret, ptr, gccMemoryOrder)		\
	EASTL_GCC_ATOMIC_LOAD_N(__uint128_t, type, ret, ptr, gccMemoryOrder)


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_COMPILER_ATOMIC_LOAD_*_N(type, type ret, type * ptr)
//
#define EASTL_COMPILER_ATOMIC_LOAD_RELAXED_8(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_8(type, ret, ptr, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_LOAD_RELAXED_16(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_16(type, ret, ptr, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_LOAD_RELAXED_32(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_32(type, ret, ptr, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_LOAD_RELAXED_64(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_64(type, ret, ptr, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_LOAD_RELAXED_128(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_128(type, ret, ptr, __ATOMIC_RELAXED)


#define EASTL_COMPILER_ATOMIC_LOAD_ACQUIRE_8(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_8(type, ret, ptr, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_LOAD_ACQUIRE_16(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_16(type, ret, ptr, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_LOAD_ACQUIRE_32(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_32(type, ret, ptr, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_LOAD_ACQUIRE_64(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_64(type, ret, ptr, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_LOAD_ACQUIRE_128(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_128(type, ret, ptr, __ATOMIC_ACQUIRE)


#define EASTL_COMPILER_ATOMIC_LOAD_SEQ_CST_8(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_8(type, ret, ptr, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_LOAD_SEQ_CST_16(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_16(type, ret, ptr, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_LOAD_SEQ_CST_32(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_32(type, ret, ptr, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_LOAD_SEQ_CST_64(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_64(type, ret, ptr, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_LOAD_SEQ_CST_128(type, ret, ptr)	\
	EASTL_GCC_ATOMIC_LOAD_128(type, ret, ptr, __ATOMIC_SEQ_CST)


#endif /* EASTL_ATOMIC_INTERNAL_COMPILER_GCC_LOAD_H */
