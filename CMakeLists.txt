cmake_minimum_required(VERSION 3.23)
project(uuif_static)

set(CMAKE_CXX_STANDARD 20)
set(SOURCES
    core/core.cpp

    widgets/widget.cpp
    widgets/window.cpp
)
add_library(uuif STATIC ${SOURCES})
set_target_properties(uuif PROPERTIES LINKER_LANGUAGE CXX)