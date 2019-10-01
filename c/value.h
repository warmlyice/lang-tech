//
// Created by warmlyice on 2019/9/30.
//

#ifndef C_VALUE_H
#define C_VALUE_H

#include "common.h"
#include "util.h"

typedef struct {
  int size;
  int capacity;
  Value *values;
} ValueArray;

void initValueArray(ValueArray *valueArray);
int writeValueArray(ValueArray *valueArray, Value value);

#endif //C_VALUE_H
