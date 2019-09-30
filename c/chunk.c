#include "chunk.h"

void initChunk(Chunk *chunk) {
  chunk->capacity = 8;
  chunk->size = 0;
  chunk->code = reallocate(chunk->code, 0, chunk->capacity);
  chunk->code[0] = 120;

  chunk->constants.capacity = 8;
  chunk->constants.size = 0;
  chunk->constants.values = NULL;
  chunk->constants.values = (double *)reallocate(chunk->constants.values, 0, sizeof(double) * chunk->constants.capacity);
}
int addConstant(Chunk *chunk, double value) {
  if (chunk->constants.size >= chunk->constants.capacity) {
    chunk->constants.values = reallocate(chunk->constants.values, chunk->constants.capacity, chunk->constants.capacity * 2);
    chunk->constants.capacity = chunk->constants.capacity * 2;
  }
  chunk->constants.values[chunk->constants.size] = value;
  chunk->constants.size++;
  return chunk->constants.size - 1;
}
void writeChunk(Chunk *chunk, u_int8_t code) {
  if (chunk->size >= chunk->capacity) {
    chunk->code = reallocate(chunk->code, chunk->capacity, chunk->capacity * 2);
    chunk->capacity = chunk->capacity * 2;
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
