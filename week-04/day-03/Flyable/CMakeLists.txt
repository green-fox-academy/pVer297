cmake_minimum_required(VERSION 3.13)
project(Flyable)

set(CMAKE_CXX_STANDARD 14)

add_executable(Flyable main.cpp flyable.h vehicle.h helicopter.cpp helicopter.h animal.h animal.cpp bird.h bird.cpp)