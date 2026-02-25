cmake_minimum_required(VERSION 3.10)
project(Linko VERSION 1.0)
set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(raylib REQUIRED)

file(GLOB SOURCES src/*.cpp)

add_executable(linko ${SOURCES})

target_link_libraries(linko PRIVATE raylib)
