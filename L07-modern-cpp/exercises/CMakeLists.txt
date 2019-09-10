cmake_minimum_required(VERSION 3.8)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(solid_cpp)

set(SUBDIRS "1-file-reader" "2-zip-file-reader")
foreach(DIR ${SUBDIRS})
    add_executable(${DIR} "${DIR}/main.cpp")
    target_compile_options(${DIR} PRIVATE -Wall -Werror -Wpedantic -Wextra)
    target_include_directories(${DIR} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/${DIR}")
endforeach()
