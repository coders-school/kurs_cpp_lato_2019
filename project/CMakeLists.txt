cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Users)

set(SRC_LIST
    Student.hpp
    Student.cpp
    Coach.hpp
    Coach.cpp
    main.cpp
    )
add_executable(${PROJECT_NAME} ${SRC_LIST})

