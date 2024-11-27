set(BINARY_NAME uuif-demo-raylib)


add_executable(${BINARY_NAME} main.cpp raylib_renderer.hpp)
#
# set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
# set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
# set(BUILD_TESTING OFF CACHE BOOL "" FORCE)
# set(CUSTOMIZE_BUILD OFF CACHE BOOL "" FORCE) 

FetchContent_Declare(
    raylib
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    GIT_TAG 5.5
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)

FetchContent_GetProperties(raylib)
if(NOT raylib_POPULATED)
    # configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/external/raylib/config.h ${CMAKE_CURRENT_SOURCE_DIR}/build/_deps/raylib-src/src/config.h COPYONLY)
    FetchContent_Populate(raylib)

    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})
endif()


target_link_libraries(${BINARY_NAME}
    PRIVATE
    spdlog::spdlog
    raylib
    uuif
)

add_custom_target(run_raylib
    COMMAND ${BINARY_NAME}
    DEPENDS ${BINARY_NAME}
    WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}
)
