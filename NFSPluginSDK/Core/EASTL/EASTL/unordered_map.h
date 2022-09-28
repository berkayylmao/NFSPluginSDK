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

#ifndef EASTL_UNORDERED_MAP_H
#define EASTL_UNORDERED_MAP_H

#include <NFSPluginSDK/Core/EASTL/EASTL/internal/config.h>
#include <NFSPluginSDK/Core/EASTL/EASTL/hash_map.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once // Some compilers (e.g. VC++) benefit significantly from using this. We've measured 3-4% build speed improvements in apps as a result.
#endif

namespace eastl
{
	/// unordered_map 
	///
	/// The original TR1 (technical report 1) used "hash_map" to name a hash
	/// table backed associative container of unique key-value pairs.  When the
	/// container was added to the C++11 standard the committee chose the name
	/// "unordered_map" to clarify that internally the elements are NOT sorted in
	/// any particular order.  We provide a template alias here to ensure feature
	/// parity with the original eastl::hash_map.
	///
	#if !defined(EA_COMPILER_NO_TEMPLATE_ALIASES)
		template <typename Key,
				  typename T,
				  typename Hash = eastl::hash<Key>,
				  typename Predicate = eastl::equal_to<Key>,
				  typename Allocator = EASTLAllocatorType,
				  bool bCacheHashCode = false>
		using unordered_map = hash_map<Key, T, Hash, Predicate, Allocator, bCacheHashCode>;
    #endif


    /// unordered_multimap
	///
	/// Similar template alias as "unordered_map" except the contained elements
	/// need not be unique. See "hash_multimap" for more details.
	///
	#if !defined(EA_COMPILER_NO_TEMPLATE_ALIASES)
		template <typename Key,
				  typename T,
				  typename Hash = eastl::hash<Key>,
				  typename Predicate = eastl::equal_to<Key>,
				  typename Allocator = EASTLAllocatorType,
				  bool bCacheHashCode = false>
		using unordered_multimap = hash_multimap<Key, T, Hash, Predicate, Allocator, bCacheHashCode>;
    #endif

} // namespace eastl

#endif // Header include guard

