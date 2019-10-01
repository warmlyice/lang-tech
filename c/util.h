//
// Created by warmlyice on 28/9/2019.
//

#ifndef C_UTIL_H
#define C_UTIL_H

#include "common.h"


#define GROW_CAPACITY(capacity) (capacity == 0 ? 8 : capacity * 2)
void *reallocate(void *p, size_t oldSize, size_t newSize);


#endif //C_UTIL_H
