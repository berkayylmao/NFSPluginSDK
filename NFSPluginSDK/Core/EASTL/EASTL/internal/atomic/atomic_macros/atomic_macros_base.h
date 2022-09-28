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

#ifndef EASTL_ATOMIC_INTERNAL_MACROS_BASE_H
#define EASTL_ATOMIC_INTERNAL_MACROS_BASE_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#define EASTL_ATOMIC_INTERNAL_COMPILER_AVAILABLE(op)					\
	EA_PREPROCESSOR_JOIN(EA_PREPROCESSOR_JOIN(EASTL_COMPILER_, op), _AVAILABLE)

#define EASTL_ATOMIC_INTERNAL_ARCH_AVAILABLE(op)						\
	EA_PREPROCESSOR_JOIN(EA_PREPROCESSOR_JOIN(EASTL_ARCH_, op), _AVAILABLE)

#define EASTL_ATOMIC_INTERNAL_NOT_IMPLEMENTED_ERROR(...)				\
	static_assert(false, "eastl::atomic<T> atomic macro not implemented!")


/* Compiler && Arch Not Implemented */
#define EASTL_ATOMIC_INTERNAL_OP_PATTERN_00(op) \
	EASTL_ATOMIC_INTERNAL_NOT_IMPLEMENTED_ERROR

/* Arch Implemented */
#define EASTL_ATOMIC_INTERNAL_OP_PATTERN_01(op) \
	EA_PREPROCESSOR_JOIN(EASTL_ARCH_, op)

/* Compiler Implmented */
#define EASTL_ATOMIC_INTERNAL_OP_PATTERN_10(op) \
	EA_PREPROCESSOR_JOIN(EASTL_COMPILER_, op)

/* Compiler && Arch Implemented */
#define EASTL_ATOMIC_INTERNAL_OP_PATTERN_11(op) \
	EA_PREPROCESSOR_JOIN(EASTL_ARCH_, op)


/* This macro creates the pattern macros above for the 2x2 True-False truth table */
#define EASTL_ATOMIC_INTERNAL_OP_HELPER1(compiler, arch, op)			\
	EA_PREPROCESSOR_JOIN(EASTL_ATOMIC_INTERNAL_OP_PATTERN_, EA_PREPROCESSOR_JOIN(compiler, arch))(op)


/////////////////////////////////////////////////////////////////////////////////
//
// EASTL_ATOMIC_CHOOSE_OP_IMPL
//
// This macro chooses between the compiler or architecture implementation for a
// given atomic operation.
//
// USAGE:
//
// EASTL_ATOMIC_CHOOSE_OP_IMPL(ATOMIC_FETCH_ADD_RELAXED_8)(ret, ptr, val)
//
#define EASTL_ATOMIC_CHOOSE_OP_IMPL(op)					\
	EASTL_ATOMIC_INTERNAL_OP_HELPER1(					\
		EASTL_ATOMIC_INTERNAL_COMPILER_AVAILABLE(op),	\
		EASTL_ATOMIC_INTERNAL_ARCH_AVAILABLE(op),		\
		op												\
		)


#endif /* EASTL_ATOMIC_INTERNAL_MACROS_BASE_H */
