//
// Created by warmlyice on 2019/10/2.
//

#include "common.h"
#include "compiler.h"
#include "lexer.h"

TokenTypeStr tokenTypeStr[] = {
    {"+"},
    {"number"},
    {"EOF"},
};

Parser parser;
static void advance() {
  Token token = scanToken();
  parser.current = token;
}

static void unary() {
  printf("unary\n");
}
static void binary() {
  printf("binary\n");
}
static void number() {
  printf("number\n");
}
ParseRule rules[] = {
    { unary, binary, PREC_TERM },
    { number, NULL, PREC_NONE },
};
static ParseRule getRule(Token token) {
  return rules[token.type];
}

static void printToken(Token token) {
  printf("%s\n", tokenTypeStr[token.type].str);
}

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
  advance();
  ParseRule rule = getRule(parser.current);
  printToken(parser.current);
  advance();
  printToken(parser.current);
  advance();
  printToken(parser.current);
  advance();
  printToken(parser.current);

//  printf("%s", rule);
//  ParseRule *rule = &rules[0];
//  rule->infix();
//  printf("\n");
//  advance();
//  expression();
//  consume(TOKEN_EOF);
//  while (1) {
//    Token token = scanToken();
//    switch (token.type) {
//      case NUMBER: {
//        emitByteCode(chunk, OP_CONSTANT, atof(token.text));
//        break;
//      }
//      case EOF:
//        break;
//      default:
//        printf("unknown token");
//    }
//    if (token.type == EOF) {
//      break;
//    }
//  }
//  emitReturn(chunk);
}
