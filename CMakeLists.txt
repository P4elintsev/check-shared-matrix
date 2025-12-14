cmake_minimum_required(VERSION 3.18)

project(
    matrixlib
    VERSION 0.0.1
    DESCRIPTION "Matrix example"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(MATH_USE_DOUBLE_PRECISION "Use double precision for calculations" ON)

add_subdirectory(lib)
add_subdirectory(exe)
