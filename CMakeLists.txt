cmake_minimum_required(VERSION 3.21)
project(untitled1)

set(CMAKE_CXX_STANDARD 14)

add_executable(ProgrammingSeminars src/main.c include/recursion.h src/recursion.c include/array.h src/array.c include/unidirectional_list.h src/unidirectional_list.c include/binary_search_tree.h src/binary_search_tree.c include/stack.h src/stack.c include/border_principle.h include/postfix_notation.h src/postfix_notation.c include/dynamic_array_of_char.h src/dynamic_array_of_char.c)
