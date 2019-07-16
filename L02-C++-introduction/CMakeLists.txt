cmake_minimum_required(VERSION 3.9)
project(Homework2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wpedantic -Wextra -Wconversion --std=c++17")

add_executable(pali palindrom.cpp)
add_executable(paliR palindrom_recursive.cpp testPalindrom.cpp)
add_executable(longInt long_int.cpp)
add_executable(stringView stringView.cpp)