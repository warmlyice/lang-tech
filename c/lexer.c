#include "lexer.h"



int start = 0;
int current = 0;
int ch;
char *source;

void initLexer(char *code) {
  source = code;
}
char peek () {
  return source[current + 1];
}
Token generateToken(TokenType type) {
  Token token;
  token.type = type;
  token.text = source + start;
  token.size = current - start + 1;
  return token;
}
Token number() {
  while (1) {
    if (!isdigit(peek())) {
      break;
    }
    current++;
  }
  return generateToken(TOKEN_NUMBER);
}
Token scanToken() {
  while (1) {
    Token token;
    token.type = TOKEN_EOF;
    ch = source[current];
    if (ch == '\0') break;
    switch (ch) {
      case '+':
        token = generateToken(TOKEN_PLUS);
        break;
      case '*':
        token = generateToken(TOKEN_MULTIPLY);
        break;
      default:
        if (isdigit(ch)){
          token = number();
        }
    }
//    printf("%d---%.*s\n\n", token.type, token.size, token.text);
    current++;
    start = current;
    return token;
  }
}
