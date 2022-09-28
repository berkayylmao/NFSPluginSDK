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

#ifndef EASTL_ATOMIC_INTERNA_ATOMIC_FLAG_H
#define EASTL_ATOMIC_INTERNA_ATOMIC_FLAG_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#include "atomic_push_compiler_options.h"


namespace eastl
{


class atomic_flag
{
public: /* ctors */

	EA_CONSTEXPR atomic_flag(bool desired) EA_NOEXCEPT
		: mFlag{ desired }
	{
	}

	EA_CONSTEXPR atomic_flag() EA_NOEXCEPT
		: mFlag{ false }
	{
	}

public: /* deleted ctors && assignment operators */

	atomic_flag(const atomic_flag&) EA_NOEXCEPT = delete;

	atomic_flag& operator=(const atomic_flag&)          EA_NOEXCEPT = delete;
	atomic_flag& operator=(const atomic_flag&) volatile EA_NOEXCEPT = delete;

public: /* clear */

	template <typename Order>
	void clear(Order /*order*/) volatile EA_NOEXCEPT
	{
		EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(Order);
	}

	template <typename Order>
	void clear(Order /*order*/) EA_NOEXCEPT
	{
		EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(Order);
	}

	void clear(eastl::internal::memory_order_relaxed_s) EA_NOEXCEPT
	{
		mFlag.store(false, eastl::memory_order_relaxed);
	}

	void clear(eastl::internal::memory_order_release_s) EA_NOEXCEPT
	{
		mFlag.store(false, eastl::memory_order_release);
	}

	void clear(eastl::internal::memory_order_seq_cst_s) EA_NOEXCEPT
	{
		mFlag.store(false, eastl::memory_order_seq_cst);
	}

	void clear() EA_NOEXCEPT
	{
		mFlag.store(false, eastl::memory_order_seq_cst);
	}

public: /* test_and_set */

	template <typename Order>
	bool test_and_set(Order /*order*/) volatile EA_NOEXCEPT
	{
		EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(Order);
		return false;
	}

	template <typename Order>
	bool test_and_set(Order /*order*/) EA_NOEXCEPT
	{
		EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(Order);
		return false;
	}

	bool test_and_set(eastl::internal::memory_order_relaxed_s) EA_NOEXCEPT
	{
		return mFlag.exchange(true, eastl::memory_order_relaxed);
	}

	bool test_and_set(eastl::internal::memory_order_acquire_s) EA_NOEXCEPT
	{
		return mFlag.exchange(true, eastl::memory_order_acquire);
	}

	bool test_and_set(eastl::internal::memory_order_release_s) EA_NOEXCEPT
	{
		return mFlag.exchange(true, eastl::memory_order_release);
	}

	bool test_and_set(eastl::internal::memory_order_acq_rel_s) EA_NOEXCEPT
	{
		return mFlag.exchange(true, eastl::memory_order_acq_rel);
	}

	bool test_and_set(eastl::internal::memory_order_seq_cst_s) EA_NOEXCEPT
	{
		return mFlag.exchange(true, eastl::memory_order_seq_cst);
	}

	bool test_and_set() EA_NOEXCEPT
	{
		return mFlag.exchange(true, eastl::memory_order_seq_cst);
	}

public: /* test */

	template <typename Order>
	bool test(Order /*order*/) const volatile EA_NOEXCEPT
	{
		EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(Order);
		return false;
	}

	template <typename Order>
	bool test(Order /*order*/) const EA_NOEXCEPT
	{
		EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(Order);
		return false;
	}

	bool test(eastl::internal::memory_order_relaxed_s) const EA_NOEXCEPT
	{
		return mFlag.load(eastl::memory_order_relaxed);
	}

	bool test(eastl::internal::memory_order_acquire_s) const EA_NOEXCEPT
	{
		return mFlag.load(eastl::memory_order_acquire);
	}

	bool test(eastl::internal::memory_order_seq_cst_s) const EA_NOEXCEPT
	{
		return mFlag.load(eastl::memory_order_seq_cst);
	}

	bool test() const EA_NOEXCEPT
	{
		return mFlag.load(eastl::memory_order_seq_cst);
	}

private:

	eastl::atomic<bool> mFlag;
};


} // namespace eastl


#include "atomic_pop_compiler_options.h"


#endif /* EASTL_ATOMIC_INTERNA_ATOMIC_FLAG_H */
