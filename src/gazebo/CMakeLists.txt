# Create new library
add_library(GazeboYarpSynchronizer
    ${CMAKE_CURRENT_SOURCE_DIR}/include/gys/GazeboYarpSynchronizer.h
    ${CMAKE_CURRENT_SOURCE_DIR}/GazeboYarpSynchronizer.cpp)
add_library(GazeboYarpSynchronizer::GazeboYarpSynchronizer ALIAS GazeboYarpSynchronizer)

# Add include directory
target_include_directories(GazeboYarpSynchronizer PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
    "$<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>")

# Mark the header as public
set_target_properties(GazeboYarpSynchronizer PROPERTIES
    PUBLIC_HEADER "${CMAKE_CURRENT_SOURCE_DIR}/include/gys/GazeboYarpSynchronizer.h")

# Link against ClockRpc
target_link_libraries(GazeboYarpSynchronizer PUBLIC GazeboYarpSynchronizer::ClockRpc)

# Configure install
install(
    TARGETS GazeboYarpSynchronizer
    EXPORT GazeboYarpSynchronizer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    PUBLIC_HEADER DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}/gys)
