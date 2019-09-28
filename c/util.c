//
// Created by warmlyice on 28/9/2019.
//

#include "util.h"

char *reallocate(char *p, int oldSize, int newSize) {
  return realloc(p, newSize);
}