cmake_minimum_required(VERSION 3.15)
project(Containers VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_subdirectory(src)
add_subdirectory(test)
add_subdirectory(lib/googletest)
