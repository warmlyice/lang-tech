#include "lexer.h"
#include "chunk.h"

int main(int argc, char const *argv[]) {
  Chunk chunk;
  initChunk(&chunk);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);
  for (int i=0; i<chunk.size; i++) {
    printf("code: %d    size: %d    capacity: %d\n", chunk.code[i], chunk.size, chunk.capacity);
  }
//  printf("%d\n", sizeof(char));
//  printf("%d\n", ABS(-3));
//  printf("%d\n", ABS(-0));
//  printf("%d\n", ABS(0));

//  char *source = "123+456";
//  initLexer(source);
//  while (1) {
//    Token token = scanToken();
//    if (token.type == EOF) {
//      break;
//    }
//    printf("%d---%.*s\n\n", token.type, token.size, token.text);
//  }
  return 0;
}
