cmake_minimum_required(VERSION 3.13)
project(11_Smartphones C)

set(CMAKE_C_STANDARD 11)

add_executable(11_Smartphones main.c phoneRegister.c phoneRegister.h fileIO.c fileIO.h)