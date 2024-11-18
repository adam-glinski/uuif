set(BINARY_NAME uuif-demo-glfw)

add_executable(${BINARY_NAME} main.cpp)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_Declare(
    glad
    GIT_REPOSITORY https://github.com/Dav1dde/glad.git
)


FetchContent_MakeAvailable(glfw)
FetchContent_MakeAvailable(glad)

target_link_libraries(${BINARY_NAME}
    PRIVATE
    spdlog::spdlog
    glfw
    glad
    uuif
)

add_custom_target(run_glfw
    COMMAND ${BINARY_NAME}
    DEPENDS ${BINARY_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
