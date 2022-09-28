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

#ifndef INCLUDED_eaunits_h
#define INCLUDED_eaunits_h

#include <NFSPluginSDK/Core/EASTL/EABase/eabase.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once // Some compilers (e.g. VC++) benefit significantly from using this. We've measured 3-4% build speed improvements in apps as a result.
#endif

// Defining common SI unit macros.
//
// The mebibyte is a multiple of the unit byte for digital information. Technically a
// megabyte (MB) is a power of ten, while a mebibyte (MiB) is a power of two,
// appropriate for binary machines. Many Linux distributions use the unit, but it is
// not widely acknowledged within the industry or media.
// Reference: https://en.wikipedia.org/wiki/Mebibyte
//
// Examples:
// 	auto size1 = EA_KILOBYTE(16);
// 	auto size2 = EA_MEGABYTE(128);
// 	auto size3 = EA_MEBIBYTE(8);
// 	auto size4 = EA_GIBIBYTE(8);

// define byte for completeness
#define EA_BYTE(x) (x)

// Decimal SI units
#define EA_KILOBYTE(x) (size_t(x) * 1000)
#define EA_MEGABYTE(x) (size_t(x) * 1000 * 1000)
#define EA_GIGABYTE(x) (size_t(x) * 1000 * 1000 * 1000)
#define EA_TERABYTE(x) (size_t(x) * 1000 * 1000 * 1000 * 1000)
#define EA_PETABYTE(x) (size_t(x) * 1000 * 1000 * 1000 * 1000 * 1000)
#define EA_EXABYTE(x)  (size_t(x) * 1000 * 1000 * 1000 * 1000 * 1000 * 1000)

// Binary SI units
#define EA_KIBIBYTE(x) (size_t(x) * 1024)
#define EA_MEBIBYTE(x) (size_t(x) * 1024 * 1024)
#define EA_GIBIBYTE(x) (size_t(x) * 1024 * 1024 * 1024)
#define EA_TEBIBYTE(x) (size_t(x) * 1024 * 1024 * 1024 * 1024)
#define EA_PEBIBYTE(x) (size_t(x) * 1024 * 1024 * 1024 * 1024 * 1024)
#define EA_EXBIBYTE(x) (size_t(x) * 1024 * 1024 * 1024 * 1024 * 1024 * 1024)

#endif // INCLUDED_earesult_H




