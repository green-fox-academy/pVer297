cmake_minimum_required(VERSION 3.13)
project(diagonals)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_EXE_LINKER_FLAGS -static)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
set(SDL2_PATH "c:/greenfox/SDL2/SDL2-2.0.8/i686-w64-mingw32")
set(SDL2_IMAGE_PATH "c:/greenfox/SDL2/SDL2_image-2.0.3/i686-w64-mingw32")
set(SDL2_TTF_PATH "c:/greenfox/SDL2/SDL2_ttf-2.0.14/i686-w64-mingw32")
set(SDL2_GFX "c:/greenfox/SDL2/SDL2_plugins/gfx")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})

include_directories(${SDL2_GFX}/inc)
file(GLOB gfx_inc "${SDL2_GFX}/inc/*.h")
file(GLOB gfx_src "${SDL2_GFX}/src/*.c")

add_executable(diagonals main.cpp ${gfx_inc} ${gfx_src})

target_link_libraries(diagonals ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARIES} ${SDL2_TTF_LIBRARIES})