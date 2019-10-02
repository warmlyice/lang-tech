//
// Created by warmlyice on 2019/10/2.
//

#ifndef C_COMPILER_H
#define C_COMPILER_H

#include "chunk.h"
#include "lexer.h"

void compile(Chunk *chunk, const char *source);

#endif //C_COMPILER_H
