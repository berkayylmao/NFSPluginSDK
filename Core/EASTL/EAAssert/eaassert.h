// BSD 3-Clause License, https://github.com/electronicarts/EASTL

#ifndef EAASSERT_EAASSERT_H
#define EAASSERT_EAASSERT_H

#include <assert.h>
#define EA_ASSERT                     assert
#define EA_ASSERT_MSG(condition, msg) assert(condition)

#define EA_FAIL() assert(false)

#endif  // EAASSERT_EAASSERT_H
