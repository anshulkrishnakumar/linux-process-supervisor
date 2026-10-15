cmake_minimum_required(VERSION 3.20)

project(linux_process_supervisor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(process-supervisor
    src/main.cpp
)

target_compile_options(process-supervisor PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)
