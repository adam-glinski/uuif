set(BINARY ${CMAKE_PROJECT_NAME})
set(SOURCES
    core/core.cpp

    widgets/widget.cpp
    widgets/window.cpp
    widgets/checkbox.cpp
)
add_library(uuif STATIC ${SOURCES})
# set_target_properties(uuif PROPERTIES LINKER_LANGUAGE CXX)