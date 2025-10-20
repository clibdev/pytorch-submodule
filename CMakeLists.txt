cmake_minimum_required(VERSION 3.29)
project(pytorch_submodule)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(pytorch)

include_directories(pytorch/aten/src)
include_directories(${CMAKE_BINARY_DIR}/aten/src)

add_executable(${PROJECT_NAME} main.cpp)
add_executable(abs_torch examples/abs/main.cpp)

target_link_libraries(${PROJECT_NAME} torch)
target_link_libraries(abs_torch torch)
