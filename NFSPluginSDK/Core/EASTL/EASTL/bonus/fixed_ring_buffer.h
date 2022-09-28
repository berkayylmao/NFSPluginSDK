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

#ifndef EASTL_FIXED_RING_BUFFER_H
#define EASTL_FIXED_RING_BUFFER_H

#include <NFSPluginSDK/Core/EASTL/EASTL/internal/config.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/fixed_vector.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/bonus/ring_buffer.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once // Some compilers (e.g. VC++) benefit significantly from using this. We've measured 3-4% build speed improvements in apps as a result.
#endif

namespace eastl
{

	/// fixed_ring_buffer
	///
	/// This is a convenience template alias for creating a fixed-sized
	/// ring_buffer using eastl::fixed_vector as its storage container. This has
	/// been tricky for users to get correct due to the constructor requirements
	/// of eastl::ring_buffer leaking the implementation detail of the sentinel
	/// value being used internally.  In addition, it was not obvious what the
	/// correct allocator_type template parameter should be used for containers
	/// providing both a default allocator type and an overflow allocator type.
	///
	/// We are over-allocating the fixed_vector container to accommodate the
	/// ring_buffer sentinel to prevent that implementation detail leaking into
	/// user code.
	///
	/// Example usage:
	///
	/// 	fixed_ring_buffer<int, 8> rb = {0, 1, 2, 3, 4, 5, 6, 7};
	///  or
	/// 	fixed_ring_buffer<int, 8> rb(8); // capacity doesn't need to respect sentinel
	/// 	rb.push_back(0);
	///
	///
#if !defined(EA_COMPILER_NO_TEMPLATE_ALIASES)
	template <typename T, size_t N>
	using fixed_ring_buffer =
	    ring_buffer<T, fixed_vector<T, N + 1, false>, typename fixed_vector<T, N + 1, false>::overflow_allocator_type>;
#endif

} // namespace eastl

#endif // Header include guard

