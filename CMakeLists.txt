cmake_minimum_required(VERSION 3.11)
project(uuif LANGUAGES CXX VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)
# set(CMAKE_BUILD_TYPE Debug) # TODO: Remove later
set(CMAKE_MODULE_PATH "~/.cmake/modules/")
message("CMAKE_MODULE_PATH: " ${CMAKE_MODULE_PATH})

include(FetchContent)
include(FetchIfNeeded)

# Make debug only dependency
# FetchContent_Declare(
#         spdlog
#         GIT_REPOSITORY https://github.com/gabime/spdlog
#         GIT_TAG v1.15.0
# )

FetchIfNeeded(
    spdlog
    https://github.com/gabime/spdlog
    v1.15.0
)

# FetchContent_MakeAvailable(spdlog)

add_library(${PROJECT_NAME} STATIC
    ./src/widget.cpp
    ./src/checkbox.cpp
    ./src/window.cpp
    ./src/focus_manager.cpp
    ./src/core.cpp
)

target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog)

target_include_directories(${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

add_subdirectory(demo)
