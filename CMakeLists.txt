cmake_minimum_required(VERSION 3.28)
project(cpp_big_o_workshop)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES fibonacci.cpp)

add_executable(fibonacci-variants ${SOURCE_FILES})