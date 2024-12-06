# Collect all source files for the library
set(SRC_FILES
    mylib/MyString.cpp
    mylib/MyUniquePtr.cpp
)

# Define a library called "mylib"
add_library(mylib ${SRC_FILES})

# Add the main executable
add_executable(my_container main.cpp)

# Link the library to the main executable
target_link_libraries(my_container PRIVATE mylib)

# Include the header files
target_include_directories(mylib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/mylib)
