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
    int oldCapacity = valueArray->capacity;
    valueArray->capacity = GROW_CAPACITY(valueArray->capacity);
    valueArray->values = GROW_ARRAY(valueArray->values, Value, oldCapacity, valueArray->capacity);
  }
  valueArray->values[valueArray->size] = value;
  valueArray->size++;
  return valueArray->size - 1;
}
