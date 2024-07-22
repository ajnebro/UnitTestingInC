# Create a library from the stack source files
add_library(stack STATIC stack.c)

# Create an executable for the main application
add_executable(stack_app main.c)

# Link the stack library to the main application
target_link_libraries(stack_app stack)

