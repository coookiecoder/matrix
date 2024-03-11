cmake_minimum_required(VERSION 3.27)
set(CMAKE_CXX_STANDARD 23)

project(ex00)

add_executable(ex00 ex00/main.cpp Class/Matrix.tpp)
include_directories(Class)

project(ex01)

add_executable(ex01 ex01/main.cpp Class/Matrix.tpp)
include_directories(Class)

project(ex02)

add_executable(ex02 ex02/main.cpp Class/Matrix.tpp)
include_directories(Class)

project(ex03)

add_executable(ex03 ex03/main.cpp Class/Matrix.tpp)
include_directories(Class)

project(ex04)

add_executable(ex04 ex04/main.cpp Class/Matrix.tpp)
include_directories(Class)