#ifndef C_CHUNK_H
#define C_CHUNK_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "util.h"
#include "value.h"

typedef enum {
  OP_CONSTANT,
  OP_RETURN,
} OP_CODE;

typedef struct {
  ValueArray constants;
  u_int8_t *code;
  int capacity;
  int size;
} Chunk;
void initChunk(Chunk *chunk);
int addConstant(Chunk *chunk, double value);
void writeChunk(Chunk *chunk, u_int8_t code);

void disassembleChunk(Chunk *chunk);

#endif //C_CHUNK_H
