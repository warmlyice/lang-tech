#include "lexer.h"
#include "chunk.h"

int main(int argc, char const *argv[]) {
  Chunk chunk;
  initChunk(&chunk);
  int value = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, value);
  int value2 = addConstant(&chunk, 1.234);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, value2);

  int value3 = addConstant(&chunk, 1.23456);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, value3);
  writeChunk(&chunk, OP_RETURN);
  writeChunk(&chunk, OP_RETURN);

  disassembleChunk(&chunk);

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
