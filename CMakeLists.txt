cmake_minimum_required(VERSION 3.14)

# Project name and version
project(MyContainerPractice VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing if tests are included
option(ENABLE_TESTS "Enable tests" ON)

# Add the source directory
add_subdirectory(src)

# Add the test directory (if ENABLE_TESTS is ON)
if(ENABLE_TESTS)
    enable_testing()
    add_subdirectory(test)
endif()
