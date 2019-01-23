cmake_minimum_required(VERSION 3.13)
project(Print_Each_Line)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(Print_Each_Line main.cpp)