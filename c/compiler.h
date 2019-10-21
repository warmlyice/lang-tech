//
// Created by warmlyice on 2019/10/2.
//

#ifndef C_COMPILER_H
#define C_COMPILER_H

#include "chunk.h"
#include "lexer.h"

typedef struct {
  Token previous;
  Token current;
} Parser;
typedef enum {
  PREC_NONE,
  PREC_ASSIGN,
  PREC_TERM,
  PREC_FACTOR,
  PREC_UNARY,
  PREC_PRIMARY,
} Precedence;
typedef void (*ParseFn)();  //

typedef struct {
  ParseFn prefix;
  ParseFn infix;
  Precedence precedence;
} ParseRule;
static void emitByte(uint8_t byte);
static void makeConstant();
static void parsePrecedence(Precedence precedence);
static ParseRule getRule(Token token);
void compile(Chunk *chunk, const char *source);

#endif //C_COMPILER_H
