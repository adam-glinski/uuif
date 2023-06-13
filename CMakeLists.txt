cmake_minimum_required(VERSION 3.23)
project(uuif)
set(CMAKE_CXX_STANDARD 20)

include_directories(src)

enable_testing()

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(lib/googletest)