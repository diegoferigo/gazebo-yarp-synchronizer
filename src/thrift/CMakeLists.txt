find_package(YARP 3.0.0 REQUIRED)

# Generate automatically the thrift service
yarp_add_idl(CLOCK_RPC_FILES clock_rpc.thrift)

# Add the library target
add_library(ClockRpc ${CLOCK_RPC_FILES} clock_rpc.thrift)
add_library(GazeboYarpSynchronizer::ClockRpc ALIAS ClockRpc)

# Link it against YARP
find_package(YARP 3.0.0 REQUIRED)
target_link_libraries(ClockRpc PUBLIC YARP::YARP_os YARP::YARP_init)
target_include_directories(ClockRpc PUBLIC "$<BUILD_INTERFACE:${YARP_ADD_IDL_INCLUDE_DIR}>")

# Configure install
install(
    TARGETS ClockRpc
    EXPORT GazeboYarpSynchronizer
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
