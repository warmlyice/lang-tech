//
// Created by warmlyice on 28/9/2019.
//

#ifndef C_UTIL_H
#define C_UTIL_H

#include "common.h"


#define ARITHMETIC(operator, operand1, operand2) (operand1 operator operand2)
#define GROW_CAPACITY(capacity) (capacity == 0 ? 8 : capacity * 2)
void *reallocate(void *p, size_t oldSize, size_t newSize);

#define GROW_ARRAY(p, type, oldSize, newSize) reallocate(p, sizeof(type) * oldSize, sizeof(type) * newSize)

#endif //C_UTIL_H
