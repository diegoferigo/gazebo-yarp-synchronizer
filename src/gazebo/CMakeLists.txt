# Create new library
add_library(GazeboYarpSynchronizer
    ${CMAKE_CURRENT_SOURCE_DIR}/GazeboYarpSynchronizer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/GazeboYarpSynchronizer.cpp)
add_library(GazeboYarpSynchronizer::GazeboYarpSynchronizer ALIAS GazeboYarpSynchronizer)

# Add include directory
target_include_directories(GazeboYarpSynchronizer PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}>")

# Link against ClockRpc
target_link_libraries(GazeboYarpSynchronizer PUBLIC GazeboYarpSynchronizer::ClockRpc)

# Configure install
install(
    TARGETS GazeboYarpSynchronizer
    EXPORT GazeboYarpSynchronizer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
