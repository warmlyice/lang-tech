//
// Created by warmlyice on 2019/10/2.
//

#include "common.h"
#include "compiler.h"
#include "lexer.h"

TokenTypeStr tokenTypeStr[] = {
  {"+"},
  {"*"},
  {"number"},
  {"EOF"},
};

Parser parser;
Chunk *compilingChunk;
static Chunk *currentChunk() {
  return compilingChunk;
}
static void advance() {
  parser.previous = parser.current;
  Token token = scanToken();
  parser.current = token;
}

static void unary() {
  printf("unary\n");
}
static void binary() {
  Token token = parser.previous;
  ParseRule rule = getRule(token);
  parsePrecedence(rule.precedence + 1);
  switch (token.type) {
    case TOKEN_PLUS: { emitByte(OP_ADD); break; }
    case TOKEN_MULTIPLY: {
      emitByte(OP_MULTIPLY); break;
    }
  }
}
static void number() {
  double value = strtod(parser.previous.text, NULL);
  makeConstant(value);
//  parsePrecedence(PREC_TERM);
}
ParseRule rules[] = {
  { NULL, binary, PREC_TERM },  // +
  { NULL, binary, PREC_FACTOR },  // *
  { number, NULL, PREC_NONE },  // number
  { NULL, NULL, PREC_NONE },    // EOF
};
static ParseRule getRule(Token token) {
  return rules[token.type];
}

static void printToken(Token token) {
  printf("%s\n", tokenTypeStr[token.type].str);
}
static void emitByte(uint8_t byte) {
  writeChunk(currentChunk(), byte);

}
static void emitByteCode(Chunk *chunk, type, Value value) {
  int v = addConstant(chunk, value);
  writeChunk(chunk, type);
  writeChunk(chunk, v);
}
static void emitReturn(Chunk *chunk) {
  writeChunk(chunk, OP_RETURN);
}
static void makeConstant(Value value) {
  emitByteCode(currentChunk(), OP_CONSTANT, value);
}
static void parsePrecedence(Precedence precedence) {
  advance();
  ParseRule rule = getRule(parser.previous);
  ParseFn prefix = rule.prefix;
  if (prefix == NULL) {
    printf("error");
  }
  prefix();
  while(precedence <= getRule(parser.current).precedence) {
    advance();
    ParseFn infix = getRule(parser.previous).infix;
    infix();
    printf("");
  }
}
void compile(Chunk *chunk, const char *source) {
  compilingChunk = chunk;
  initLexer(source);
  advance();
  parsePrecedence(PREC_ASSIGN);
  emitByte(OP_RETURN);
//  ParseRule rule = getRule(parser.current);
//  printToken(parser.current);
//  advance();
//  printToken(parser.current);
//  advance();
//  printToken(parser.current);
//  advance();
//  printToken(parser.current);

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
