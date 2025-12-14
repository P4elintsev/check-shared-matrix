add_executable(check-shared-matrix
    main.cpp
)

target_include_directories(
    check-shared-matrix 
    PUBLIC
    ${CMAKE_SOURCE_DIR}/lib
    ${CMAKE_CURRENT_SOURCE_DIR}/lib
    ${CMAKE_CURRENT_BINARY_DIR}/lib
)

target_link_libraries(check-shared-matrix PRIVATE shared-matrixlib)

add_custom_command(
    TARGET 
    check-shared-matrix 
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    $<TARGET_FILE:shared-matrixlib>
    $<TARGET_FILE_DIR:check-shared-matrix>
)
