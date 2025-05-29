cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 23)

project(matrix)
enable_testing()

macro(add_matrix_ex name)
    add_executable(${name}_matrix ${name}/main.cpp Class/Matrix.tpp)
    add_test(NAME ${name}_test COMMAND ${name}_matrix)
endmacro()

include_directories(Class)

# Add each exercise as a test
add_matrix_ex(ex00)
add_matrix_ex(ex01)
add_matrix_ex(ex02)
add_matrix_ex(ex03)
add_matrix_ex(ex04)
add_matrix_ex(ex05)
add_matrix_ex(ex06)
add_matrix_ex(ex07)
add_matrix_ex(ex08)
add_matrix_ex(ex09)
add_matrix_ex(ex10)
add_matrix_ex(ex11)
add_matrix_ex(ex12)
add_matrix_ex(ex13)