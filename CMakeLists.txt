cmake_minimum_required(VERSION 3.24)
project(llmfs LANGUAGES CXX CUDA)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CUDA_STANDARD 17)
set(CMAKE_CUDA_STANDARD_REQUIRED ON)

set(CMAKE_CUDA_ARCHITECTURES native)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(CUDAToolkit REQUIRED)

add_library(llmfs STATIC
    src/tensor.cpp
    src/tensor_cuda.cu
)

target_include_directories(llmfs PUBLIC
    include
)

target_link_libraries(llmfs PRIVATE CUDA::cudart)

add_executable(main src/main.cpp)

target_link_libraries(main PRIVATE llmfs)