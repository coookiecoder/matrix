cmake_minimum_required(VERSION 3.22)
set(CMAKE_CXX_STANDARD 23)

project(ex00)

add_executable(ex00_matrix ex00/main.cpp Class/Matrix.tpp)
include_directories(Class)

project(ex01)

add_executable(ex01_matrix ex01/main.cpp Class/Matrix.tpp)
include_directories(Class)

project(ex02)

add_executable(ex02_matrix ex02/main.cpp Class/Matrix.tpp)
include_directories(Class)

project(ex03)

add_executable(ex03_matrix ex03/main.cpp Class/Matrix.tpp)
include_directories(Class)

project(ex04)

add_executable(ex04_matrix ex04/main.cpp Class/Matrix.tpp)
include_directories(Class)