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

#ifndef EASTL_FIXED_FUNCTION_H
#define EASTL_FIXED_FUNCTION_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif

#include <NFSPluginSDK/Core/EASTL/EASTL/internal/function_detail.h>

namespace eastl
{
	template <int, typename>
	class fixed_function;

	namespace internal
	{
		template <typename>
		struct is_fixed_function
			: public eastl::false_type {};

		template <int SIZE_IN_BYTES, typename R, typename... Args>
		struct is_fixed_function<eastl::fixed_function<SIZE_IN_BYTES, R(Args...)>>
			: public eastl::true_type {};

		template<typename T>
		EA_CONSTEXPR bool is_fixed_function_v = is_fixed_function<T>::value;
	}

	#define EASTL_INTERNAL_FIXED_FUNCTION_STATIC_ASSERT(TYPE)                    \
		static_assert(sizeof(TYPE) <= sizeof(typename Base::FunctorStorageType), \
					  "fixed_function local buffer is not large enough to hold the callable object.")

    #define EASTL_INTERNAL_FIXED_FUNCTION_NEW_SIZE_STATIC_ASSERT(NEW_SIZE_IN_BYTES) \
		static_assert(SIZE_IN_BYTES >= NEW_SIZE_IN_BYTES,                           \
					  "fixed_function local buffer is not large enough to hold the new fixed_function type.")

	template <typename Functor>
	using EASTL_DISABLE_OVERLOAD_IF_FIXED_FUNCTION =
	    eastl::disable_if_t<internal::is_fixed_function_v<eastl::decay_t<Functor>>>;


	// fixed_function
	//
	template <int SIZE_IN_BYTES, typename R, typename... Args>
	class fixed_function<SIZE_IN_BYTES, R(Args...)> : public internal::function_detail<SIZE_IN_BYTES, R(Args...)>
	{
		using Base = internal::function_detail<SIZE_IN_BYTES, R(Args...)>;

	public:
		using typename Base::result_type;

		fixed_function() EA_NOEXCEPT = default;
		fixed_function(std::nullptr_t p) EA_NOEXCEPT
			: Base(p)
		{
		}

		fixed_function(const fixed_function& other)
			: Base(other)
		{
		}

		fixed_function(fixed_function&& other)
			: Base(eastl::move(other))
		{
		}

		template <typename Functor,
		          typename = EASTL_INTERNAL_FUNCTION_VALID_FUNCTION_ARGS(Functor, R, Args..., Base, fixed_function),
		          typename = EASTL_DISABLE_OVERLOAD_IF_FIXED_FUNCTION<Functor>>
		fixed_function(Functor functor)
		    : Base(eastl::move(functor))
		{
			EASTL_INTERNAL_FIXED_FUNCTION_STATIC_ASSERT(Functor);
		}

		template<int NEW_SIZE_IN_BYTES>
		fixed_function(const fixed_function<NEW_SIZE_IN_BYTES, R(Args...)>& other)
			: Base(other)
		{
			EASTL_INTERNAL_FIXED_FUNCTION_NEW_SIZE_STATIC_ASSERT(NEW_SIZE_IN_BYTES);
		}

		template<int NEW_SIZE_IN_BYTES>
		fixed_function(fixed_function<NEW_SIZE_IN_BYTES, R(Args...)>&& other)
			: Base(eastl::move(other))
		{
			EASTL_INTERNAL_FIXED_FUNCTION_NEW_SIZE_STATIC_ASSERT(NEW_SIZE_IN_BYTES);
		}

		~fixed_function() EA_NOEXCEPT = default;

		fixed_function& operator=(const fixed_function& other)
		{
			Base::operator=(other);
			return *this;
		}

		fixed_function& operator=(fixed_function&& other)
		{
			Base::operator=(eastl::move(other));
			return *this;
		}

		fixed_function& operator=(std::nullptr_t p) EA_NOEXCEPT
		{
			Base::operator=(p);
			return *this;
		}

		template<int NEW_SIZE_IN_BYTES>
		fixed_function& operator=(const fixed_function<NEW_SIZE_IN_BYTES, R(Args...)>& other)
		{
			EASTL_INTERNAL_FIXED_FUNCTION_NEW_SIZE_STATIC_ASSERT(NEW_SIZE_IN_BYTES);

			Base::operator=(other);
			return *this;
		}

		template<int NEW_SIZE_IN_BYTES>
		fixed_function& operator=(fixed_function<NEW_SIZE_IN_BYTES, R(Args...)>&& other)
		{
			EASTL_INTERNAL_FIXED_FUNCTION_NEW_SIZE_STATIC_ASSERT(NEW_SIZE_IN_BYTES);

			Base::operator=(eastl::move(other));
			return *this;
		}

		template <typename Functor,
		          typename = EASTL_INTERNAL_FUNCTION_VALID_FUNCTION_ARGS(Functor, R, Args..., Base, fixed_function),
		          typename = EASTL_DISABLE_OVERLOAD_IF_FIXED_FUNCTION<Functor>>
		fixed_function& operator=(Functor&& functor)
		{
			EASTL_INTERNAL_FIXED_FUNCTION_STATIC_ASSERT(eastl::decay_t<Functor>);
			Base::operator=(eastl::forward<Functor>(functor));
			return *this;
		}

		template <typename Functor>
		fixed_function& operator=(eastl::reference_wrapper<Functor> f) EA_NOEXCEPT
		{
			EASTL_INTERNAL_FIXED_FUNCTION_STATIC_ASSERT(eastl::reference_wrapper<Functor>);
			Base::operator=(f);
			return *this;
		}

		void swap(fixed_function& other) EA_NOEXCEPT
		{
			Base::swap(other);
		}

		explicit operator bool() const EA_NOEXCEPT
		{
			return Base::operator bool();
		}

		R operator ()(Args... args) const
		{
			return Base::operator ()(eastl::forward<Args>(args)...);
		}

	#if EASTL_RTTI_ENABLED
		const std::type_info& target_type() const EA_NOEXCEPT
		{
			return Base::target_type();
		}

		template <typename Functor>
		Functor* target() EA_NOEXCEPT
		{
			return Base::target();
		}

		template <typename Functor>
		const Functor* target() const EA_NOEXCEPT
		{
			return Base::target();
		}
	#endif
	};

	template <int S, typename R, typename... Args>
	bool operator==(const fixed_function<S, R(Args...)>& f, std::nullptr_t) EA_NOEXCEPT
	{
		return !f;
	}

	template <int S, typename R, typename... Args>
	bool operator==(std::nullptr_t, const fixed_function<S, R(Args...)>& f) EA_NOEXCEPT
	{
		return !f;
	}

	template <int S, typename R, typename... Args>
	bool operator!=(const fixed_function<S, R(Args...)>& f, std::nullptr_t) EA_NOEXCEPT
	{
		return !!f;
	}

	template <int S, typename R, typename... Args>
	bool operator!=(std::nullptr_t, const fixed_function<S, R(Args...)>& f) EA_NOEXCEPT
	{
		return !!f;
	}

	template <int S, typename R, typename... Args>
	void swap(fixed_function<S, R(Args...)>& lhs, fixed_function<S, R(Args...)>& rhs)
	{
		lhs.swap(rhs);
	}

} // namespace eastl

#endif // EASTL_FIXED_FUNCTION_H
