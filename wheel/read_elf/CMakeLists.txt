cmake_minimum_required(VERSION 3.10)
project(read_elf)
set(CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_FLAGS "Wall")

include_directories(include/)

# generate .a attach lib
link_directories()
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/result/lib)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
add_subdirectory(fmt)
add_library(func src/func.cpp)
target_link_libraries(func fmt::fmt)

add_executable(read_elf src/main.cpp)
target_link_libraries(read_elf func)

