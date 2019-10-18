#include "lexer.h"
#include "chunk.h"
#include "vm.h"
#include "compiler.h"

int main(int argc, char const *argv[]) {
  initVM();
  Chunk chunk;

  initChunk(&chunk);

  char *source = "123+456";
  compile(&chunk, source);

//  interpreter(&chunk);

//  disassembleChunk(&chunk);
  return 0;
}
