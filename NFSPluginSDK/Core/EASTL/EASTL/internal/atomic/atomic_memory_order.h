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

#ifndef EASTL_ATOMIC_INTERNAL_MEMORY_ORDER_H
#define EASTL_ATOMIC_INTERNAL_MEMORY_ORDER_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


namespace eastl
{


namespace internal
{


struct memory_order_relaxed_s {};
struct memory_order_read_depends_s {};
struct memory_order_acquire_s {};
struct memory_order_release_s {};
struct memory_order_acq_rel_s {};
struct memory_order_seq_cst_s {};


} // namespace internal


EASTL_CPP17_INLINE_VARIABLE EA_CONSTEXPR auto memory_order_relaxed = internal::memory_order_relaxed_s{};
EASTL_CPP17_INLINE_VARIABLE EA_CONSTEXPR auto memory_order_read_depends = internal::memory_order_read_depends_s{};
EASTL_CPP17_INLINE_VARIABLE EA_CONSTEXPR auto memory_order_acquire = internal::memory_order_acquire_s{};
EASTL_CPP17_INLINE_VARIABLE EA_CONSTEXPR auto memory_order_release = internal::memory_order_release_s{};
EASTL_CPP17_INLINE_VARIABLE EA_CONSTEXPR auto memory_order_acq_rel = internal::memory_order_acq_rel_s{};
EASTL_CPP17_INLINE_VARIABLE EA_CONSTEXPR auto memory_order_seq_cst = internal::memory_order_seq_cst_s{};


} // namespace eastl


#endif /* EASTL_ATOMIC_INTERNAL_MEMORY_ORDER_H */
