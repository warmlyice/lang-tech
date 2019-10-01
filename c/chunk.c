#include "chunk.h"

void initChunk(Chunk *chunk) {
  chunk->capacity = 0;
  chunk->size = 0;
  chunk->code = NULL;

  initValueArray(&chunk->constants);
}
int addConstant(Chunk *chunk, Value value) {
  int index = writeValueArray(&chunk->constants, value);
  return index;
}
void writeChunk(Chunk *chunk, u_int8_t code) {
  if (chunk->size >= chunk->capacity) {
    chunk->code = reallocate(chunk->code, chunk->capacity, GROW_CAPACITY(chunk->capacity));
    chunk->capacity = GROW_CAPACITY(chunk->capacity);
  }
  chunk->code[chunk->size] = code;
  chunk->size++;
}
void disassembleChunk(Chunk *chunk) {
  for (int i=0; i<chunk->size; i++) {
    printf("%04d  ", i);
    int op = chunk->code[i];
    switch(op) {
      case OP_RETURN:
        printf("OP_RETURN  %d size: %d    capacity: %d\n", i, chunk->size, chunk->capacity);
        break;
      case OP_CONSTANT:
        i++;
        printf("OP_CONSTANT: %lf    size: %d    capacity: %d\n", chunk->constants.values[chunk->code[i]], chunk->size, chunk->capacity);
        break;
      default:
        printf("unknown instruction: %d\n", op);
    }
  }
}
