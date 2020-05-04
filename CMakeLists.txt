cmake_minimum_required(VERSION 3.15)
project(compilers_101)

# C Flags
set(CMAKE_C_COMPILER gcc)
set(CMAKE_C_STANDARD 11)

# C++ Flags
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Werror")

add_library(tiny_expr
        src/tinyexpr/libs/tinyexpr.h
        src/tinyexpr/libs/tinyexpr.c
)

add_executable(cpp_union            src/simpleparser/CppUnion.cpp)
add_executable(lexical_parser       src/simpleparser/LexicalParser.cpp)
add_executable(linked_list_parser   src/simpleparser/LinkedListParser.cpp)

add_executable(expr_eval            src/tinyexpr/ExprEvaluator.cpp)
target_link_libraries(expr_eval PRIVATE tiny_expr)

add_executable(brainfuck            src/brainfuck/Brainfuck.cpp)
