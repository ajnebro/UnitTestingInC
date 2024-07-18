# set cmake minimum required version
cmake_minimum_required(VERSION 3.26 FATAL_ERROR)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# define a c project with name provided as parameter (cmake CMakeLists.txt -DPRJCT_NAME=foo)
project(data_structures_c C)

# use c17 standard
set(CMAKE_C_STANDARD 17)

# Add the src directory
add_subdirectory(src)

