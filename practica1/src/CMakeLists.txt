# Create a library from the stack source files
add_library(doubly_linked_list STATIC doubly_linked_list.c)

# Create an executable for the main application
add_executable(app main.c)

# Link the stack library to the main application
target_link_libraries(app doubly_linked_list)