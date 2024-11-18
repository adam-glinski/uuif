set(BINARY_NAME uuif-demo-backend)


add_executable(${BINARY_NAME} main.cpp)

target_link_libraries(${BINARY_NAME}
    PRIVATE
    spdlog::spdlog
    uuif
)

add_custom_target(run_backend
    COMMAND ${BINARY_NAME}
    DEPENDS ${BINARY_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
