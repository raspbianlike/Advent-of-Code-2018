cmake_minimum_required(VERSION 3.11)
project(AoC2018)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp src/*.hpp)
add_executable(AoC2018 ${SOURCE_FILES})

