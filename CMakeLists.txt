# CMake version recommended by pybind11
# https://pybind11.readthedocs.io/en/stable/compiling.html#findpython-mode
cmake_minimum_required(VERSION 3.18.2)
project(GazeboYarpSynchronizer VERSION 0.9 LANGUAGES CXX C)

# Add custom functions / macros
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(AddUninstallTarget)

# Add source directory
add_subdirectory(src)
