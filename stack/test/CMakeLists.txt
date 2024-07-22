# Add Unity as a library
add_library(Unity STATIC unity/unity.c)

# Create an executable for the test suite
add_executable(run_tests test_stack.c)

# Include directories for the test suite
target_include_directories(run_tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src unity)

# Link the Unity library and stack library to the test suite
target_link_libraries(run_tests Unity stack)

