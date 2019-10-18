//
// Created by warmlyice on 2019/10/2.
//

#ifndef C_COMPILER_H
#define C_COMPILER_H

#include "chunk.h"
#include "lexer.h"

typedef struct {
  Token current;
} Parser;
typedef enum {
  PREC_NONE,
  PREC_TERM,
  PREC_UNARY,
  PREC_PRIMARY,
} Precedence;
typedef void (*ParseFn)();  //

typedef struct {
  ParseFn prefix;
  ParseFn infix;
  Precedence precedence;
} ParseRule;

void compile(Chunk *chunk, const char *source);

#endif //C_COMPILER_H
