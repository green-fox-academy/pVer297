cmake_minimum_required(VERSION 3.13)
project(LinkedList C)

set(CMAKE_C_STANDARD 11)

add_executable(LinkedList main.c linked_list.c linked_list.h)