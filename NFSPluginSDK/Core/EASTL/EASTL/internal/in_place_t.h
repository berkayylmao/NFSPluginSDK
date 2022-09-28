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

#ifndef EASTL_INTERNAL_IN_PLACE_T_H
#define EASTL_INTERNAL_IN_PLACE_T_H


#include <NFSPluginSDK/Core/EASTL/EABase/eabase.h>
#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif

namespace eastl
{
	namespace Internal
	{
		struct in_place_tag {};
		template <class> struct in_place_type_tag {};
		template <size_t> struct in_place_index_tag {};
	}

	///////////////////////////////////////////////////////////////////////////////
	/// in_place_tag
	///
	/// http://en.cppreference.com/w/cpp/utility/in_place_tag
	///
	struct in_place_tag
	{
		in_place_tag() = delete;

	private:
		explicit in_place_tag(Internal::in_place_tag) {}
		friend inline in_place_tag Internal_ConstructInPlaceTag();
	};

	// internal factory function for in_place_tag
	inline in_place_tag Internal_ConstructInPlaceTag() { return in_place_tag(Internal::in_place_tag{}); }


	///////////////////////////////////////////////////////////////////////////////
	/// in_place_t / in_place_type_t / in_place_index_t
	///
	/// used to disambiguate overloads that take arguments (possibly a parameter
	/// pack) for in-place construction of some value.
	/// 
	/// http://en.cppreference.com/w/cpp/utility/optional/in_place_t
	///
	using in_place_t = in_place_tag(&)(Internal::in_place_tag);

	template <class T>
	using in_place_type_t = in_place_tag(&)(Internal::in_place_type_tag<T>);

	template <size_t N>
	using in_place_index_t = in_place_tag(&)(Internal::in_place_index_tag<N>);


	///////////////////////////////////////////////////////////////////////////////
	/// in_place / in_place<T> / in_place<size_t>
	/// 
	/// http://en.cppreference.com/w/cpp/utility/in_place
	///
	inline in_place_tag in_place(Internal::in_place_tag) { return Internal_ConstructInPlaceTag(); }

	template <class T>
	inline in_place_tag in_place(Internal::in_place_type_tag<T>) { return Internal_ConstructInPlaceTag(); }

	template <std::size_t I>
	inline in_place_tag in_place(Internal::in_place_index_tag<I>) { return Internal_ConstructInPlaceTag(); }


} // namespace eastl


#endif // Header include guard






