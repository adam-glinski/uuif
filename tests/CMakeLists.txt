set(BINARY ${CMAKE_PROJECT_NAME}_test)
set(SOURCES
    main.cpp
    uuif-test.cpp
    ../src/core/core.cpp

    ../src/widgets/widget.cpp
    ../src/widgets/window.cpp
    ../src/widgets/checkbox.cpp
)

add_executable(${BINARY} ${SOURCES})
add_test(NAME ${BINARY} COMMAND ${BINARY})
target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME} gtest)