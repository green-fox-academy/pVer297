cmake_minimum_required(VERSION 3.13)
project(Blog)

set(CMAKE_CXX_STANDARD 14)

add_executable(Blog main.cpp Blog.cpp Blog.h BlogPost.cpp BlogPost.h)