set(BINARY ${CMAKE_PROJECT_NAME}_tst)

set(SOURCES
    main.cpp
    vector-test.cpp)

if (APPLE)
    add_executable(${BINARY} MACOSX_BUNDLE ${SOURCES})
elseif (WIN32)
    add_executable(${BINARY} WIN32 ${SOURCES})
else()
    add_executable(${BINARY} ${SOURCES})
endif()

add_test(NAME ${BINARY} COMMAND ${BINARY})

target_link_libraries(${BINARY} PUBLIC ${CMAKE_PROJECT_NAME}_lib gtest)


