cmake_minimum_required(VERSION 3.15)
project(Containers VERSION 0.1)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

set(SOURCES 
    src/main.cpp)

set_source_files_properties(
    ${RESOURCES}
    PROPERTIES
    MACOSX_PACKAGE_LOCATION Resources
)

if (APPLE)
    add_executable(Containers MACOSX_BUNDLE ${SOURCES})
elseif(WIN32)
    add_executable(Containers WIN32 ${SOURCES})
else()
    add_executable(Containers ${SOURCES})
endif()

if (APPLE) # not sure if this is the best way to do this, but it works for now
    set(RESOURCE_DIR res)
    target_sources(Containers PUBLIC ${RESOURCE_DIR})
    set_source_files_properties(${RESOURCE_DIR} PROPERTIES MACOSX_PACKAGE_LOCATION Resources)
endif()
