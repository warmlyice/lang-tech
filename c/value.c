//
// Created by warmlyice on 2019/9/30.
//

#include "value.h"
void initValueArray(ValueArray *valueArray) {
  valueArray->capacity = 0;
  valueArray->size = 0;
  valueArray->values = NULL;
}

int writeValueArray(ValueArray *valueArray, Value value) {
  if (valueArray->size >= valueArray->capacity) {
    valueArray->values = reallocate(valueArray->values,
        valueArray->capacity, GROW_CAPACITY(valueArray->capacity));
    valueArray->capacity = GROW_CAPACITY(valueArray->capacity);
  }
  valueArray->values[valueArray->size] = value;
  valueArray->size++;
  return valueArray->size - 1;
}
