cmake_minimum_required(VERSION 3.24)

# 必须在 project() 之前，且建议写入 CACHE
set(CMAKE_CUDA_ARCHITECTURES 70 CACHE STRING "CUDA arch" FORCE)

project(matrix LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(CUDAToolkit REQUIRED)

add_library(matrix STATIC src/matrix.cu)
target_include_directories(matrix PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_link_libraries(matrix PRIVATE CUDA::cudart)

add_executable(main src/main.cpp)
target_link_libraries(main PRIVATE matrix)
