cmake_minimum_required(VERSION 3.23)

# set the project name and version
project(Template VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# conan related inject
include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup()

option(BUILD_EXAMPLES "Whether or not to build examples" ON)
option(BUILD_TESTS "Whether or not to build tests" ON)

# Add all subdirectories
add_subdirectory(include)
add_subdirectory(infra)
add_subdirectory(src)
add_subdirectory(app)

if (BUILD_TESTS)
    message(STATUS "Building Tests...")
    add_subdirectory(tests)
endif()

if (BUILD_EXAMPLES)
    message(STATUS "Building Examples...")
    add_subdirectory(examples)
endif()
