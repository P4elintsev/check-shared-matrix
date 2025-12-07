cmake_minimum_required(VERSION 3.18)      
project(    
    check-shared-matrix
    VERSION 0.0.0
    DESCRIPTION "cpp library"
    LANGUAGES CXX
)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BUILD_TYPE Debug)


## Add the path where our external library will be found
# set(CMAKE_PREFIX_PATH ${CMAKE_CURRENT_SOURCE_DIR}/matrixlib/matrix)

# # Find the library we created earlier
# find_package(Matrix REQUIRED)

# # ??????? ???????? exe-???? ??? ???????????? ??????????
# add_executable(matrixlib-use
#     src/main.cpp
# )
# target_include_directories(matrixlib-use  PUBLIC 
#     "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
#     "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
#     "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
# )

# target_link_libraries(matrixlib-use PRIVATE "${CMAKE_SOURCE_DIR}/libs/matrixlib/libshared-matrixlib.dll.a")

add_executable(
    check-shared-matrix
    src/main.cpp
)   

target_include_directories(
    check-shared-matrix 
    PUBLIC 
        "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
)

target_link_libraries(check-shared-matrix PRIVATE shared-matrixlib)