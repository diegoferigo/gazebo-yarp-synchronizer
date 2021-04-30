find_package(YARP 3.0.0 REQUIRED)

# Generate automatically the thrift service
yarp_add_idl(CLOCK_RPC_FILES clock_rpc.thrift)

# Add the library target
add_library(ClockRpc STATIC ${CLOCK_RPC_FILES} clock_rpc.thrift)

# Link it against YARP
find_package(YARP 3.0.0 REQUIRED)
target_link_libraries(ClockRpc YARP::YARP_OS)
target_include_directories(ClockRpc PUBLIC ${YARP_ADD_IDL_INCLUDE_DIR})
