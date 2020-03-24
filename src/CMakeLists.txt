set(BINARY ${CMAKE_PROJECT_NAME})

set(SOURCES 
    main.cpp)

if (APPLE)
    add_executable(Containers_run MACOSX_BUNDLE ${SOURCES})
elseif(WIN32)
    add_executable(Containers_run WIN32 ${SOURCES})
else()
    add_executable(Containers_run ${SOURCES})
endif()

add_library(${BINARY}_lib STATIC  ${SOURCES})
