cmake_minimum_required(VERSION 3.17)
project(sgd)

set(CMAKE_CXX_STANDARD 14)

set(SDL2_INCLUDE_DIR C:/libs/SDL/include)
set(SDL2_LIB_DIR C:/libs/SDL/lib/x86)

include_directories(${SDL2_INCLUDE_DIR})
link_directories(${SDL2_LIB_DIR})

add_executable(sgd main.cpp GameLoop.cpp GameLoop.h)

target_link_libraries(${PROJECT_NAME} SDL2main SDL2)



