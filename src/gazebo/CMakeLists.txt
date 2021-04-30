# Create new library
add_library(GazeboSynchronizer
    ${CMAKE_CURRENT_SOURCE_DIR}/GazeboSynchronizer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/GazeboSynchronizer.cpp)

# Add include directory
target_include_directories(GazeboSynchronizer PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>")

# Link against ClockRpc
target_link_libraries(GazeboSynchronizer PUBLIC ClockRpc)
