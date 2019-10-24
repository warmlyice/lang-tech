//
// Created by warmlyice on 2019/10/1.
//

#include "vm.h"

VM vm;
void initVM() {
  vm.stackTop = vm.stack;
}
InterpreterResult run () {
#define READ_BYTE() (*vm.ip++)
#define READ_CONSTANT() (vm.chunk.constants.values[READ_BYTE()])
  for (;;) {
    uint8_t instruction;
    switch (instruction = READ_BYTE()) {
      case OP_RETURN: {
        Value value = pop();
        printValue(value);
        return INTERPRETER_OK;
      }
      case OP_CONSTANT: {
        Value value = READ_CONSTANT();
        push(value);
        break;
      }
      case OP_NEGATE: {
        push(-pop());
        break;
      }
      case OP_ADD: {
        push(ARITHMETIC(+, pop(), pop()));
        break;
      }
      case OP_MULTIPLY: {
        push(ARITHMETIC(*, pop(), pop()));
        break;
      }
      default:
        break;
    }
  }
  return NULL;
#undef READ_BYTE
#undef READ_CONSTANT
}

void push(Value value) {
  *vm.stackTop = value;
  vm.stackTop++;
}
Value pop() {
  Value value = *(vm.stackTop - 1);
  vm.stackTop--;
  return value;
}
InterpreterResult interpreter(Chunk *chunk) {
  vm.chunk = *chunk;
  vm.ip = chunk->code;
  return run();
}
