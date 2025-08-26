cmake_minimum_required(VERSION 3.20)

project(Graphic)

set(CMAKE_CXX_STANDARD 17)

add_subdirectory(application)
add_subdirectory(gpu)

add_executable(softRenderer main.cpp
        gpu/frameBuffer.h
        gpu/frameBuffer.cpp
        gpu/gpu.h
        gpu/gpu.cpp)

target_link_libraries(softRenderer applicationlib gpulib)