//
// Created by warmlyice on 2019/10/1.
//

#include "vm.h"

VM vm;
void initVM() {}
InterpreterResult run () {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk.constants.values[READ_BYTE()])
  for (;;) {
    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
      case OP_RETURN:
        return INTERPRETER_OK;
      case OP_CONSTANT: {
        Value value = READ_CONSTANT();
        printValue(value);
      }
      default:
        break;
    }
  }
  return NULL;
#undef READ_BYTE
#undef READ_CONSTANT
}

InterpreterResult interpreter(Chunk *chunk) {
  vm.chunk = *chunk;
  vm.ip = chunk->code;
  return run();
}
