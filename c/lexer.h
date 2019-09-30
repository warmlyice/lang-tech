//
// Created by warmlyice on 22/9/2019.
//

#ifndef C_LEXER_H
#define C_LEXER_H

#include <stdio.h>
#include <ctype.h>

typedef enum {
  PLUS,
  NUMBER,
} TokenType;

typedef struct {
  TokenType type;
  char *text;
  int length;
  int size;
} Token;

void initLexer(char *code);
Token generateToken(TokenType type);
Token scanToken();

#endif //C_LEXER_H
