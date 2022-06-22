cmake_minimum_required(VERSION 3.17)
project(sgd)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_IMAGE_INCLUDE_DIR C:/libs/SDL2_image/include)
set(SDL2_IMAGE_LIB_DIR C:/libs/SDL/lib/x86)
set(SDL2_LIB_DIR C:/libs/SDL2_image/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_IMAGE_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})
link_directories(${SDL2_IMAGE_LIB_DIR})

add_executable(sgd main.cpp GameLoop.cpp GameLoop.h Texture.cpp Texture.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)



