cmake_minimum_required(VERSION 3.13)
project(Wireless_Adapter)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wireless_Adapter main.cpp device.h device.cpp usbDevice.cpp usbDevice.h networkDevice.cpp networkDevice.h wirelessAdapter.cpp wirelessAdapter.h)