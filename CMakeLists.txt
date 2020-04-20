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
    src/libs/tinyexpr.h
    src/libs/tinyexpr.c
)

add_executable(cpp_union          src/CppUnion.cpp)
add_executable(expr_eval          src/ExprEvaluator.cpp)
add_executable(lexical_parser     src/LexicalParser.cpp)
add_executable(linked_list_parser src/LinkedListParser.cpp)
add_executable(tm1                src/TuringMachine1.cpp)
add_executable(tm2                src/TuringMachine2.cpp)

target_link_libraries(expr_eval PRIVATE tiny_expr)