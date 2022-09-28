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

#ifndef EASTL_ATOMIC_INTERNAL_ARCH_H
#define EASTL_ATOMIC_INTERNAL_ARCH_H

#if defined(EA_PRAGMA_ONCE_SUPPORTED)
	#pragma once
#endif


/////////////////////////////////////////////////////////////////////////////////
//
// Include the architecture specific implementations
//
#if defined(EA_PROCESSOR_X86) || defined(EA_PROCESSOR_X86_64)

	#include "x86/arch_x86.h"

#elif defined(EA_PROCESSOR_ARM32) || defined(EA_PROCESSOR_ARM64)

	#include "arm/arch_arm.h"

#endif


/////////////////////////////////////////////////////////////////////////////////


#include "arch_fetch_add.h"
#include "arch_fetch_sub.h"

#include "arch_fetch_and.h"
#include "arch_fetch_xor.h"
#include "arch_fetch_or.h"

#include "arch_add_fetch.h"
#include "arch_sub_fetch.h"

#include "arch_and_fetch.h"
#include "arch_xor_fetch.h"
#include "arch_or_fetch.h"

#include "arch_exchange.h"

#include "arch_cmpxchg_weak.h"
#include "arch_cmpxchg_strong.h"

#include "arch_load.h"
#include "arch_store.h"

#include "arch_compiler_barrier.h"

#include "arch_cpu_pause.h"

#include "arch_memory_barrier.h"

#include "arch_signal_fence.h"

#include "arch_thread_fence.h"


#endif /* EASTL_ATOMIC_INTERNAL_ARCH_H */
