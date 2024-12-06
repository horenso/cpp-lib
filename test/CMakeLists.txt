# Collect test source files
set(TEST_FILES test_string.cpp)

# Create a test executable
add_executable(test_container ${TEST_FILES})

# Link the library to the test executable
target_link_libraries(test_container PRIVATE mylib)

# Add the include directories
target_include_directories(test_container PRIVATE ${CMAKE_SOURCE_DIR}/src/mylib)

# Add the test
add_test(NAME TestString COMMAND test_container)
