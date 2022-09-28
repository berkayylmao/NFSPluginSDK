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

#ifndef INCLUDED_earesult_H
#define INCLUDED_earesult_H

#include <NFSPluginSDK/Core/EASTL/EABase/eabase.h>

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
#pragma once /* Some compilers (e.g. VC++) benefit significantly from using this. We've measured 3-4% build speed \
                improvements in apps as a result. */
#endif

/* This result type is width-compatible with most systems. */
typedef int32_t ea_result_type;

namespace EA {
  typedef int32_t result_type;

  enum {
#ifndef SUCCESS
    // Deprecated
    // Note: a public MS header has created a define of this name which causes a build error. Fortunately they
    // define it to 0 which is compatible.
    // see: WindowsSDK\8.1.51641-fb\installed\Include\um\RasError.h
    SUCCESS = 0,
#endif
    // Deprecated
    FAILURE = -1,

    // These values are now the preferred constants
    EA_SUCCESS = 0,
    EA_FAILURE = -1,
  };
}  // namespace EA

/* Macro to simplify testing for success. */
#ifndef EA_SUCCEEDED
#define EA_SUCCEEDED(result) ((result) >= 0)
#endif

/* Macro to simplfify testing for general failure. */
#ifndef EA_FAILED
#define EA_FAILED(result) ((result) < 0)
#endif

#endif
