cmake_minimum_required(VERSION 3.25)
project(HashMap)

set(CMAKE_CXX_STANDARD 17)

add_executable(HashMap src/hashing.cpp src/Sequence/Sequence.cpp src/main.cpp src/main.h)
