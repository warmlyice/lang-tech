//
// Created by warmlyice on 2019/10/1.
//

#ifndef C_VM_H
#define C_VM_H

#include "common.h"
#include "chunk.h"

#define STACK_MAX 256
//#define STACK_MAX = 256; // syntax error =========

typedef enum {
  INTERPRETER_OK,
} InterpreterResult;

typedef struct {
  Chunk chunk;
  uint8_t *ip;
  Value stack[STACK_MAX];
  Value *stackTop;
} VM;

void initVM();
void push(Value value);
Value pop();
InterpreterResult interpreter(Chunk *chunk);

#endif //C_VM_H
