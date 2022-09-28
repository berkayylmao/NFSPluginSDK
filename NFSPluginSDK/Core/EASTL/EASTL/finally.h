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

///////////////////////////////////////////////////////////////////////////////
// eastl::finally is an implementation of the popular cpp idiom RAII - Resource
// Acquisition Is Initialization. eastl::finally guarantees that the user
// provided callable will be executed upon whatever mechanism is used to leave
// the current scope. This can guard against user errors but this is a popular
// technique to write robust code in execution environments that have exceptions
// enabled.
//
// Example:
//     void foo()
//     {
//         void* p = malloc(128);
//         auto _ = eastl::make_finally([&] { free(p); });
//
//         // Code that may throw an exception...
//         
//     }  // eastl::finally guaranteed to call 'free' at scope exit.
//
// References:
// * https://www.bfilipek.com/2017/04/finalact.html
///////////////////////////////////////////////////////////////////////////////

#ifndef EASTL_FINALLY_H
#define EASTL_FINALLY_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif

#include <NFSPluginSDK/Core/EASTL/EASTL/internal/config.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/internal/move_help.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/type_traits.h>

namespace eastl
{
	///////////////////////////////////////////////////////////////////////////
	// finally
	//
	// finally is the type that calls the users callback on scope exit.
	//
	template <typename Functor>
	class finally
	{
		static_assert(!eastl::is_lvalue_reference_v<Functor>, "eastl::finally requires the callable is passed as an rvalue reference.");

		Functor m_functor;
		bool m_engaged = false;

	public:
		finally(Functor f) : m_functor(eastl::move(f)), m_engaged(true) {}

		finally(finally&& other) : m_functor(eastl::move(other.m_functor)), m_engaged(other.m_engaged)
		{
			other.dismiss();
		}

		~finally() { execute(); }

		finally(const finally&) = delete;
		finally& operator=(const finally&) = delete;
		finally& operator=(finally&&) = delete;

		inline void dismiss() { m_engaged = false; }

		inline void execute()
		{
			if (m_engaged)
				m_functor();

			dismiss();
		}
	};


	///////////////////////////////////////////////////////////////////////////
	// make_finally
	//
	// this utility function is the standard mechansim to perform the required
	// type deduction on the users provided callback inorder to create a
	// 'finally' object.
	//
	template <typename F>
	auto make_finally(F&& f)
	{
		return finally<F>(eastl::forward<F>(f));
	}
}

#endif // EASTL_FINALLY_H
