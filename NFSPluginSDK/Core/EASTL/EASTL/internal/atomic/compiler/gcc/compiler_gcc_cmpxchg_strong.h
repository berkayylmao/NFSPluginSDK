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

#ifndef EASTL_ATOMIC_INTERNAL_COMPILER_GCC_CMPXCHG_STRONG_H
#define EASTL_ATOMIC_INTERNAL_COMPILER_GCC_CMPXCHG_STRONG_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#define EASTL_GCC_ATOMIC_CMPXCHG_STRONG_N(integralType, type, ret, ptr, expected, desired, successOrder, failOrder) \
	EASTL_GCC_ATOMIC_CMPXCHG_INTRIN_N(integralType, type, ret, ptr, expected, desired, false, successOrder, failOrder)


#define EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, successOrder, failOrder) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_N(uint8_t, type, ret, ptr, expected, desired, successOrder, failOrder)

#define EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, successOrder, failOrder) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_N(uint16_t, type, ret, ptr, expected, desired, successOrder, failOrder)

#define EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, successOrder, failOrder) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_N(uint32_t, type, ret, ptr, expected, desired, successOrder, failOrder)

#define EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, successOrder, failOrder) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_N(uint64_t, type, ret, ptr, expected, desired, successOrder, failOrder)

#define EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, successOrder, failOrder) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_N(__uint128_t, type, ret, ptr, expected, desired, successOrder, failOrder)


/////////////////////////////////////////////////////////////////////////////////
//
// void EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_*_*_N(type, bool ret, type * ptr, type * expected, type desired)
//
#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELAXED_RELAXED_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_RELAXED, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELAXED_RELAXED_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_RELAXED, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELAXED_RELAXED_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_RELAXED, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELAXED_RELAXED_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_RELAXED, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELAXED_RELAXED_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_RELAXED, __ATOMIC_RELAXED)


#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_RELAXED_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_RELAXED_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_RELAXED_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_RELAXED_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_RELAXED_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_RELAXED)


#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_ACQUIRE_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_ACQUIRE_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_ACQUIRE_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_ACQUIRE_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQUIRE_ACQUIRE_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_ACQUIRE, __ATOMIC_ACQUIRE)


#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELEASE_RELAXED_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_RELEASE, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELEASE_RELAXED_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_RELEASE, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELEASE_RELAXED_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_RELEASE, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELEASE_RELAXED_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_RELEASE, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_RELEASE_RELAXED_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_RELEASE, __ATOMIC_RELAXED)


#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_RELAXED_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_RELAXED_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_RELAXED_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_RELAXED_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_RELAXED_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_RELAXED)


#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_ACQUIRE_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_ACQUIRE_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_ACQUIRE_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_ACQUIRE_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_ACQ_REL_ACQUIRE_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_ACQ_REL, __ATOMIC_ACQUIRE)


#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_RELAXED_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_RELAXED_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_RELAXED_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_RELAXED_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_RELAXED)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_RELAXED_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_RELAXED)


#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_ACQUIRE_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_ACQUIRE_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_ACQUIRE_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_ACQUIRE_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_ACQUIRE)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_ACQUIRE_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_ACQUIRE)


#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_SEQ_CST_8(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_8(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_SEQ_CST_16(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_16(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_SEQ_CST_32(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_32(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_SEQ_CST_64(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_64(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)

#define EASTL_COMPILER_ATOMIC_CMPXCHG_STRONG_SEQ_CST_SEQ_CST_128(type, ret, ptr, expected, desired) \
	EASTL_GCC_ATOMIC_CMPXCHG_STRONG_128(type, ret, ptr, expected, desired, __ATOMIC_SEQ_CST, __ATOMIC_SEQ_CST)


#endif /* EASTL_ATOMIC_INTERNAL_COMPILER_GCC_CMPXCHG_STRONG_H */
