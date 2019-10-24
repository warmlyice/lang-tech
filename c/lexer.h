//
// Created by warmlyice on 22/9/2019.
//

#ifndef C_LEXER_H
#define C_LEXER_H

#include <stdio.h>
#include <ctype.h>

/**
 * sync with
 * 1. compiler.c  rules
 * 2. compiler.c  tokenTypeStr
 */
typedef enum {
  TOKEN_PLUS,
  TOKEN_MINUS,
  TOKEN_MULTIPLY,
  TOKEN_NUMBER,
  TOKEN_EOF,
} TokenType;
typedef struct {
  char str[20];
} TokenTypeStr;


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
