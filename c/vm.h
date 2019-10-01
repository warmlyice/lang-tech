//
// Created by warmlyice on 2019/10/1.
//

#ifndef C_VM_H
#define C_VM_H

#include "common.h"
#include "chunk.h"

typedef enum {
  INTERPRETER_OK,
} InterpreterResult;

typedef struct {
  Chunk chunk;
  uint8_t *ip;
} VM;

void initVM();

InterpreterResult interpreter(Chunk *chunk);

#endif //C_VM_H
