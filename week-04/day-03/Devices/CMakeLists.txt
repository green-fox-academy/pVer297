cmake_minimum_required(VERSION 3.13)
project(Devices)

set(CMAKE_CXX_STANDARD 14)

add_executable(Devices main.cpp scanner.cpp scanner.h printer.cpp printer.h printer2D.cpp printer2D.h printer3D.cpp printer3D.h copier.cpp copier.h)