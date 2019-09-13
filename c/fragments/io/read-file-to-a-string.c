#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
  char *name = "a.txt";
  FILE *fp;
  fp = fopen(name, "r");
  if (!fp) {
    printf("can not open file: %s", name);
  }
  char ch;
  fseek(fp, 0, SEEK_END);
  int length = ftell(fp);
  fseek(fp, 0, SEEK_SET);
  char *text;
  text = malloc(length);
  fread(text, 1, length, fp);
  // fseek(fp, 0, SEEK_SET);
  printf("%s", text);
  while(1) {
    ch = getc(fp);
    if (ch == EOF) break;
    printf("%c", ch);
  }
  fclose(fp);
  return 0;
}
