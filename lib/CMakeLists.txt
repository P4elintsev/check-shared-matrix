
set(MATH_SOURCES
    matrix.cpp
    matrix.h
    export.h
    c/c_api.cpp
    c/c_api.h
)

include(GenerateExportHeader)

# STATIC
add_library(static-matrixlib STATIC ${MATH_SOURCES})
target_include_directories(
    static-matrixlib 
    PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}  
)
target_compile_definitions(
    static-matrixlib 
    PUBLIC
    MATH_STATIC_DEFINE
    "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)
generate_export_header(
    static-matrixlib
    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/export_static.h"
    BASE_NAME matrixlib
)

# SHARED
add_library(shared-matrixlib SHARED ${MATH_SOURCES})
target_include_directories(
    shared-matrixlib 
    PUBLIC
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_BINARY_DIR}   
)
target_compile_definitions(
    shared-matrixlib 
    PUBLIC
    "$<$<BOOL:${MATH_USE_DOUBLE_PRECISION}>:MATH_DOUBLE_PREC_DEFINE>"
)
generate_export_header(
    shared-matrixlib
    EXPORT_FILE_NAME "${CMAKE_CURRENT_BINARY_DIR}/export_shared.h"
    BASE_NAME matrixlib
)

set_target_properties(shared-matrixlib PROPERTIES PREFIX "")
