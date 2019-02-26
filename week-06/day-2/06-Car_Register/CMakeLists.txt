cmake_minimum_required(VERSION 3.13)
project(06_Car_Register C)

set(CMAKE_C_STANDARD 11)

add_executable(06_Car_Register main.c carRegister.h carRegister.c)