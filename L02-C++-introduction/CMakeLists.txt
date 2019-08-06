cmake_minimum_required(VERSION 2.8)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(palindrom_cpp)

set(SRC_LIST
    palindrom_recursive.hpp
    palindrom_recursive.cpp
    palindrom.hpp
    palindrom.cpp
    main.cpp
)

add_executable(${PROJECT_NAME} ${SRC_LIST})
add_compile_options(${PROJECT_NAME} -Wconversion)
target_compile_options(${PROJECT_NAME} PRIVATE -Wconversion)
