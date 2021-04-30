cmake_minimum_required(VERSION 3.16)
project(GazeboPythonSynchronizer VERSION 1.0 LANGUAGES CXX C)

# Add custom functions / macros
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src/cmake)
include(AddUninstallTarget)

# Add source directory
add_subdirectory(src)
