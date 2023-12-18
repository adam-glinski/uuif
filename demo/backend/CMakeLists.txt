cmake_minimum_required(VERSION 3.23)
project(uuif-demo-backend)
set(CMAKE_CXX_STANDARD 23)
#set(SPDLOG_WCHAR_TO_UTF8_SUPPORT ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(../../framework)

set(CMAKE_VERBOSE_MAKEFILE ON)
include_directories(/opt/homebrew/include)
add_compile_options(-v)

set(UUIF_LIB
        ../../framework/core/core.cpp
        ../../framework/widgets/widget.cpp
        ../../framework/widgets/window.cpp
        ../../framework/widgets/checkbox.cpp

        ../../framework/renderer/renderer.h
)
add_executable(${PROJECT_NAME} main.cpp ${UUIF_LIB})
target_link_libraries(${PROJECT_NAME} PUBLIC /opt/homebrew/include)