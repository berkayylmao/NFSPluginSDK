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

#ifndef EASTL_ATOMIC_INTERNAL_SIZE_ALIGNED_H
#define EASTL_ATOMIC_INTERNAL_SIZE_ALIGNED_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


#include "atomic_push_compiler_options.h"


namespace eastl
{


namespace internal
{


#define EASTL_ATOMIC_SIZE_ALIGNED_STATIC_ASSERT_CMPXCHG_IMPL(funcName)	\
	template <typename OrderSuccess, typename OrderFailure>				\
	bool funcName(T& /*expected*/, T /*desired*/,						\
				  OrderSuccess /*orderSuccess*/,						\
				  OrderFailure /*orderFailure*/) EA_NOEXCEPT			\
	{																	\
		EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(T);				\
		return false;													\
	}																	\
																		\
	template <typename OrderSuccess, typename OrderFailure>				\
	bool funcName(T& /*expected*/, T /*desired*/,						\
				  OrderSuccess /*orderSuccess*/,						\
				  OrderFailure /*orderFailure*/) volatile EA_NOEXCEPT	\
	{																	\
		EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);					\
		return false;													\
	}																	\
																		\
	template <typename Order>											\
	bool funcName(T& /*expected*/, T /*desired*/,						\
				  Order /*order*/) EA_NOEXCEPT							\
	{																	\
		EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(T);				\
		return false;													\
	}																	\
																		\
	template <typename Order>											\
	bool funcName(T& /*expected*/, T /*desired*/,						\
				  Order /*order*/) volatile EA_NOEXCEPT					\
	{																	\
		EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);					\
		return false;													\
	}																	\
																		\
	bool funcName(T& /*expected*/, T /*desired*/) volatile EA_NOEXCEPT	\
	{																	\
		EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);					\
		return false;													\
	}

#define EASTL_ATOMIC_SIZE_ALIGNED_STATIC_ASSERT_CMPXCHG_WEAK_IMPL()		\
	EASTL_ATOMIC_SIZE_ALIGNED_STATIC_ASSERT_CMPXCHG_IMPL(compare_exchange_weak)

#define EASTL_ATOMIC_SIZE_ALIGNED_STATIC_ASSERT_CMPXCHG_STRONG_IMPL()	\
	EASTL_ATOMIC_SIZE_ALIGNED_STATIC_ASSERT_CMPXCHG_IMPL(compare_exchange_strong)


	template<typename T>
	struct atomic_size_aligned
	{
	public: /* ctors */

		EA_CONSTEXPR atomic_size_aligned(T desired) EA_NOEXCEPT
			: mAtomic{ desired }
		{
		}

		EA_CONSTEXPR atomic_size_aligned() EA_NOEXCEPT_IF(eastl::is_nothrow_default_constructible_v<T>)
			: mAtomic{} /* Value-Initialize which will Zero-Initialize Trivial Constructible types */
		{
		}

		atomic_size_aligned(const atomic_size_aligned&) EA_NOEXCEPT = delete;

	public: /* store */

		template <typename Order>
		void store(T /*desired*/, Order /*order*/) EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(T);
		}

		template <typename Order>
		void store(T /*desired*/, Order /*order*/) volatile EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);
		}

		void store(T /*desired*/) volatile EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);
		}

	public: /* load */

		template <typename Order>
		T load(Order /*order*/) const EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(T);
		}

		template <typename Order>
		T load(Order /*order*/) const volatile EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);
		}

		T load() const volatile EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);
		}

	public: /* exchange */

		template <typename Order>
		T exchange(T /*desired*/, Order /*order*/) EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_INVALID_MEMORY_ORDER(T);
		}

		template <typename Order>
		T exchange(T /*desired*/, Order /*order*/) volatile EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);
		}

		T exchange(T /*desired*/) volatile EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);
		}

	public: /* compare_exchange_weak */

		EASTL_ATOMIC_SIZE_ALIGNED_STATIC_ASSERT_CMPXCHG_WEAK_IMPL()

	public: /* compare_exchange_strong */

		EASTL_ATOMIC_SIZE_ALIGNED_STATIC_ASSERT_CMPXCHG_STRONG_IMPL()

	public: /* assignment operator */

		T operator=(T /*desired*/) volatile EA_NOEXCEPT
		{
			EASTL_ATOMIC_STATIC_ASSERT_VOLATILE_MEM_FN(T);
		}

		atomic_size_aligned& operator=(const atomic_size_aligned&)          EA_NOEXCEPT = delete;
		atomic_size_aligned& operator=(const atomic_size_aligned&) volatile EA_NOEXCEPT = delete;

	protected: /* Accessors */

		T* GetAtomicAddress() const EA_NOEXCEPT
		{
			return eastl::addressof(mAtomic);
		}

	private:

		/**
		 * Some compilers such as MSVC will align 64-bit values on 32-bit machines on
		 * 4-byte boundaries which can ruin the atomicity guarantees.
		 *
		 * Ensure everything is size aligned.
		 *
		 * mutable is needed in cases such as when loads are only guaranteed to be atomic
		 * using a compare exchange, such as for 128-bit atomics, so we need to be able
		 * to have write access to the variable as one example.
		 */
		EA_ALIGN(sizeof(T)) mutable T mAtomic;
	};


} // namespace internal


} // namespace eastl


#include "atomic_pop_compiler_options.h"


#endif /* EASTL_ATOMIC_INTERNAL_SIZE_ALIGNED_H */
