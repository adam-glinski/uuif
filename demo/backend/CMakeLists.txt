cmake_minimum_required(VERSION 3.23)
project(uuif-demo-backend)
set(CMAKE_CXX_STANDARD 23)
#set(SPDLOG_WCHAR_TO_UTF8_SUPPORT ON)
#set(CMAKE_VERBOSE_MAKEFILE ON)

include_directories(../../framework)
include_directories(/opt/homebrew/include)
#include_directories(/opt/homebrew/Cellar/spdlog/1.12.0/include)
#include_directories(/opt/homebrew/Cellar/fmt/10.1.1/include)
#include_directories(/opt/homebrew/Cellar/magic_enum/0.9.5/include)

#get_cmake_property(_variableNames VARIABLES)
#list (SORT _variableNames)
#foreach (_variableName ${_variableNames})
#    message(STATUS "${_variableName}=${${_variableName}}")
#endforeach()

set(UUIF_LIB
        ../../framework/core/core.cpp
        ../../framework/widgets/widget.cpp
        ../../framework/widgets/window.cpp
        ../../framework/widgets/checkbox.cpp

        ../../framework/renderer/renderer.h
)

find_package(spdlog REQUIRED)
find_package(magic_enum CONFIG REQUIRED)

add_executable(${PROJECT_NAME} main.cpp ${UUIF_LIB})
target_link_libraries(${PROJECT_NAME} PRIVATE spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32> magic_enum::magic_enum)