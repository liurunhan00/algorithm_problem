cmake_minimum_required(VERSION 3.10)
project(SkipList)
set(CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_C_FLAGS "Wall")

include_directories(include/)


set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_executable(SkipList src/main.cpp)
