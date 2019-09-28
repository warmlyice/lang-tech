#include "chunk.h"

void initChunk(Chunk *chunk) {
  chunk->capacity = 8;
  chunk->size = 0;
  chunk->code = reallocate(chunk->code, 0, chunk->capacity);
}
void writeChunk(Chunk *chunk, u_int8_t code) {
  if (chunk->size >= chunk->capacity) {
    chunk->code = reallocate(chunk->code, chunk->capacity, chunk->capacity * 2);
    chunk->capacity = chunk->capacity * 2;
  }
  chunk->code[chunk->size] = code;
  chunk->size++;
}
