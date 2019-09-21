#include<stdio.h>
#include <ctype.h>
typedef enum {
  PLUS,
  NUMBER,
} TokenType ;

char *source = "123+456";
int start = 0;
int current = 0;
int ch;
typedef struct {
   TokenType type;
   char *text;
   int length;
   int size;
} Token;
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
  return generateToken(NUMBER);
}


int main(int argc, char const *argv[]) {
  while (1) {
    Token token;
    ch = source[current];
    if (ch == '\0') break;
    switch (ch) {
      case '+':
        token = generateToken(PLUS);
        break;
      default:
        if (isdigit(ch)){
          token = number();
        }
    }
//    printf("%d---%s\n\n", token.size, token.text);
    printf("%d---%.*s\n\n", token.type, token.size, token.text);
    current++;
    start = current;
  }
  return 0;
}
