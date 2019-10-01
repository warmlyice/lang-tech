//
// Created by warmlyice on 28/9/2019.
//

#include "util.h"

void *reallocate(void *p, size_t oldSize, size_t newSize) {
  if (newSize == 0) {
    free(p);
    return NULL;
  }
  return realloc(p, newSize);
}