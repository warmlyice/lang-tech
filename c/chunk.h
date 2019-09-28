#ifndef C_CHUNK_H
#define C_CHUNK_H

#include <stdint.h>
#include <stdlib.h>
#include "util.h"

typedef enum {
  OP_RETURN,
} OP_CODE;

typedef struct {
  u_int8_t *code;
  int capacity;
  int size;
} Chunk;
void initChunk(Chunk *chunk);
void writeChunk(Chunk *chunk, u_int8_t code);

#endif //C_CHUNK_H
