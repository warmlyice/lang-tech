//
// Created by warmlyice on 2019/10/2.
//

#include "compiler.h"

static void emitByteCode(Chunk *chunk, type, Value value) {
  int v = addConstant(chunk, value);
  writeChunk(chunk, type);
  writeChunk(chunk, v);
}
static void emitReturn(Chunk *chunk) {
  writeChunk(chunk, OP_RETURN);
}
void compile(Chunk *chunk, const char *source) {
  initLexer(source);
//  advance();
//  expression();
//  consume(TOKEN_EOF);
  while (1) {
    Token token = scanToken();
    switch (token.type) {
      case NUMBER: {
        emitByteCode(chunk, OP_CONSTANT, atof(token.text));
        break;
      }
      case EOF:
        break;
      default:
        printf("unknown token");
    }
    if (token.type == EOF) {
      break;
    }
  }
  emitReturn(chunk);
}
