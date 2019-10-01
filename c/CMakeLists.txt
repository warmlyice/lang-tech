cmake_minimum_required(VERSION 3.12)
project(c C)

set(CMAKE_C_STANDARD 99)

add_executable(c main.c lexer.c lexer.h chunk.c chunk.h util.c util.h value.c value.h common.h vm.c vm.h)