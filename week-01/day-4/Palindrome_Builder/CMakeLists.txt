cmake_minimum_required(VERSION 3.13)
project(Palindrome_Builder)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS -static)

add_executable(Palindrome_Builder main.cpp)