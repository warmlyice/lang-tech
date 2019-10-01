#include "lexer.h"
#include "chunk.h"
#include "vm.h"

int main(int argc, char const *argv[]) {
  initVM();
  Chunk chunk;

  initChunk(&chunk);

  int value = addConstant(&chunk, 1.2);
  writeChunk(&chunk, OP_CONSTANT);
  writeChunk(&chunk, value);

  writeChunk(&chunk, OP_NEGATE);

  writeChunk(&chunk, OP_RETURN);

  interpreter(&chunk);

//  disassembleChunk(&chunk);
//
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
