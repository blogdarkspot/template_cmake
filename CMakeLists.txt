CMAKE_MINIMUM_REQUIRED(VERSION 3.20)

project(sample)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(src)

option(PACKAGE_TESTS "Build the tests" ON)
if(PACKAGE_TESTS)
    enable_testing()
    include(GoogleTest)
    add_subdirectory(tests)
endif()
