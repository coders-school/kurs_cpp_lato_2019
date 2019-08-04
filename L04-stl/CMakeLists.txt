cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(PROJECT_NAME STL12B)
project(${PROJECT_NAME})

set(SRC_LIST
        task12B.cpp
        task12B.hpp Atkins.cpp Atkins.hpp)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Werror -Wpedantic -Wextra -Wconversion)
