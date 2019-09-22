#include "lexer.h"

int main(int argc, char const *argv[]) {
  char *source = "123+456";
  initLexer(source);
  while (1) {
    Token token = scanToken();
    if (token.type == EOF) {
      break;
    }
    printf("%d---%.*s\n\n", token.type, token.size, token.text);
  }
  return 0;
}
